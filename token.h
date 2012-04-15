
/* 
 * File:   token.h
 * Author: tleonard
 *
 * Created on March 23, 2012, 5:34 PM
 */

#ifndef TOKEN_H
#define	TOKEN_H

typedef enum {TOK_PLUS, 
		TOK_MINUS, 
		TOK_STAR, 
		TOK_LPAREN, 
		TOK_RPAREN, 
		TOK_EQ, 
		TOK_FSLASH, 
		TOK_ID, 
		TOK_NUM, 
		TOK_IOTA, 
		TOK_RHO, 
		TOK_DROP,
		TOK_POUND,
		TOK_EOL,
//
// these tokens never occur in the input stream
//
		TOK_VECT,
		TOK_ARRAY,
		TOK_3D_ARRAY,		
//		
		TOK_ILLEGAL,
		TOK_UNINITIALIZED,
		TOK_EOF
}TOKEN;

//
// TOK_VECT, TOK_ARRAY, and TOK_3D_ARRAY are all operators.  The are never created by the lexer, 
// they are always created by the parser as an operator for the AST.
// for vectors, the value is the number of elements in the vector, the lexeme is set to []
// for arrays, the value is the number of vectors, the lexeme is set to [[]]
// for 3D arrays, the value is the number of arrays, the lexeme is set to [[[]]]
//

class token {
	TOKEN tok;
	string lexeme;
	uint32	value;
	uint32 radix;

public:
	token(void);
	token(TOKEN t);
	token(TOKEN t, string s, uint32 v);
	token(TOKEN t, string s);

	string getLexeme(void);
	void setLexeme(string s);
	void setLexeme(char c);
	void appendLexeme(string s);
	void appendLexeme(char c);
	uint32 getValue(void);
	void setValue(uint32 v);
	TOKEN getToken(void);
	void setToken(TOKEN t);
	void setRadix(int r);
	int getRadix(void);
	void operator=(token*);
	bool operator==(token*);
	void display(ostream& o);
};


#endif	/* TOKEN_H */

