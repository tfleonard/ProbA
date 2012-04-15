//
// lexer for ProbA
//

#include <cctype>
#include <cstdlib>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
#include "mytypes.h"
#include "token.h"
#include "symtab.h"
#include "lexer.h"



token::token(void) {
	radix = 10;
	tok = TOK_UNINITIALIZED;
	lexeme = "";
}

token::token(TOKEN t) {
	radix = 10;
	tok = t;	
}

token::token(TOKEN t, string s, uint32 v) {
	radix = 10;
	tok = t;
	lexeme = s;
	value = v;
}

token::token(TOKEN t, string s) {
	radix = 10;
	tok = t;
	lexeme = s;
}

string token::getLexeme(void) {
	return lexeme;
}

void token::setLexeme(string s) {
	lexeme = s;
}

void token::setLexeme(char c) {
	lexeme += c;
}

void token::appendLexeme(string s) {
	lexeme += s;
}

void token::appendLexeme(char c) {
	lexeme += c;
}

uint32 token::getValue(void) {
	return value;
}

void token::setValue(uint32 v) {
	value = v;
}

TOKEN token::getToken(void) {
	return tok;
}

void token::setToken(TOKEN t) {
	tok = t;
}

void token::setRadix (int r) {
	radix = r;
}

int token::getRadix(void) {
	return radix;
}


//
// deep copy of one token to another
//
void token::operator=(token *t) {
	this->tok = t->tok;
	this->lexeme = t->lexeme;
	this->value = t->value;
	this->radix = t->radix;
}


//
// compare two tokens
//
bool token::operator==(token *t) {
	if (( this->tok == t->tok) &&
		(this->lexeme == t->lexeme) &&
		(this->value == t->value) &&
		(this->radix == t->radix) ) {
		return true;
	}
	return false;
}



void token::display(ostream& os) {

string tokString;

	switch (tok) {
		case TOK_PLUS :
			tokString = "TOK_PLUS";
			break;
		case TOK_MINUS:
			tokString = "TOK_MINUS";
			break;
		case TOK_STAR:
			tokString = "TOK_STAR";
			break; 
		case TOK_LPAREN:
			tokString = "TOK_LPAREN";
			break;
		case TOK_RPAREN:
			tokString = "TOK_RPAREN";
			break; 
		case TOK_EQ:
			tokString = "TOK_EQ";
			break;
		case TOK_FSLASH:
			tokString = "TOK_FSLASH";
			break;
		case TOK_ID:
			tokString = "TOK_ID";
			break;
		case TOK_NUM:
			tokString = "TOK_NUM";
			break;
		case TOK_IOTA:
			tokString = "TOK_IOTA";
			break;
		case TOK_RHO:
			tokString = "TOK_RHO";
			break;
		case TOK_DROP:
			tokString = "TOK_DROP";
			break;
		case TOK_POUND:
			tokString = "TOK_POUND";
			break;
		case TOK_EOF:
			tokString = "TOK_EOF";
			break;
		case TOK_EOL:
			tokString = "TOK_EOL";
			break;		
		case TOK_ILLEGAL:
			tokString = "TOK_ILLEGAL";
			break;
		case TOK_UNINITIALIZED:
			tokString = "TOK_UNINITIALIZED";
			break;

			
		default:
			tokString = "TOK_UNKNOWN";
			break;	
	}

	os << "Token: " << tokString << "  lexeme: " << lexeme << endl; 
}







//
// lexer methods
//

lexer::lexer(stringstream& i,symtab *st ) {
	is = &i;
	stab = st;
	
}

//
// get the next token from the input stream
//
token* lexer::getNextToken(void) {
char c;
LEX_STATE state = STATE_START;
token* t = new token(TOK_EOF);
bool loop = true;

	while (loop) {
		is->get(c);

		if(!(is->good())) {
			t->setToken(TOK_EOF);
			t->setLexeme("End of File");
			loop = false;
			break; 
		}
		
		switch(state) {

			case STATE_START:

				if (isdigit(c)) {
					if (c == '0') {
						state = STATE_NUM_FIRST_DIGIT;
					} else {
						state = STATE_IN_INT;
					}
					t->setLexeme(c);

				} else if (c == '\n') {
					t->setToken(TOK_EOL);
;					t->setLexeme("EOL");
					loop = false;

				} else if (isspace(c)) {
					break;

				} else if (c == '(') {
					t->setToken(TOK_LPAREN);
					t->setLexeme(c);
					loop = false;

				} else if (c == ')') {
					t->setToken(TOK_RPAREN);
					t->setLexeme(c);
					loop = false;

				} else if (c == '+') {
					t->setToken(TOK_PLUS);
					t->setLexeme(c);
					loop = false;

				} else if (c == '*') {
					t->setToken(TOK_STAR);
					t->setLexeme(c);
					loop = false;

				} else if (c == '-') {
					t->setToken(TOK_MINUS);
					t->setLexeme(c);
					loop = false;

				} else if (c == '=') {
					t->setToken(TOK_EQ);
					t->setLexeme(c);
					loop = false;

				} else if (c == '/') {
					t->setToken(TOK_FSLASH);
					t->setLexeme(c);
					loop = false;

				} else if (c == '#') {
					t->setToken(TOK_POUND);
					t->setLexeme(c);
					loop = false;

				} else if (isalpha(c)) {
					t->setToken(TOK_RPAREN);
					t->setLexeme(c);
					state = STATE_IN_ID;
					
				} else {
					t->setToken(TOK_ILLEGAL);
					t->setLexeme(c);
					loop = false;
				}

				break;

			case STATE_IN_ID:
				if (isspace(c)) {
					is->putback(c);
					string s = t->getLexeme();
					if (s == "iota") {
						t->setToken(TOK_IOTA);
						loop = false;
					} else if (s == "rho") {
						t->setToken(TOK_RHO);
						loop = false;
					} else if (s == "drop") {
						t->setToken(TOK_DROP);
						loop = false;
					} else {
						t->setToken(TOK_ID);
						loop = false;
					}
				} else {
					t->appendLexeme(c);
				}
				break;

			case STATE_NUM_FIRST_DIGIT:
				if ( (c == 'x') || (c == 'X') ) {
					state = STATE_IN_HEX_INT;
					t->setRadix(16);
				} else if (isspace(c)) {
					is->putback(c);
					string s = t->getLexeme();
					int i = atoi(s.c_str());
					t->setValue(i);
					t->setToken(TOK_NUM);
					loop = false;
				} else {
					state = STATE_IN_INT;
				}
				t->appendLexeme(c);
				break;

			case STATE_IN_INT:
				 if (isspace(c)) {
					is->putback(c);
					string s = t->getLexeme();
					int i = atoi(s.c_str());
					t->setValue(i);
					t->setToken(TOK_NUM);
					loop = false;
					break;
				 }
				t->appendLexeme(c);
				if (!isdigit(c)) {
					t->setToken(TOK_ILLEGAL);
					loop = false;
				}
				break;

			case STATE_IN_HEX_INT:
				if (isspace(c)) {
					is->putback(c);
					// strip the 0x prefix off
					string s = t->getLexeme();
					int val = 0;
					for (uint32 i=2; i<s.length(); i++) {
						int ci = (int)s[i];
						if (ci > 0x60) {
							ci = ci - 0x57;
						} else if (ci > 0x40) {
							ci = ci - 0x37;
						} else {
							ci = ci - 0x30;
						}
						val = (val << 4) + ci;
					}
					t->setValue(val);
					t->setToken(TOK_NUM);
					loop = false;
					break;
				}
				t->appendLexeme(c);
				if (!isdigit(c)) {
					int ci = toupper(c);
					if ( (ci  != 'A') &&
						(ci != 'B') &&
						(ci != 'C') &&
						(ci != 'D') &&
						(ci != 'E') &&
						(ci != 'F') ) {
						t->setToken(TOK_ILLEGAL);
						loop = false;
					}
				}
				break;

			case STATE_LEXEME_COMPLETE:


				break;
		
		}

	}
	t = stab->addSym(t);	
	return t;
}
















