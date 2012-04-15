/* 
 * File:   lexer.h
 * Author: tleonard
 *
 * Created on February 25, 2012, 5:08 PM
 */

#ifndef LEXER_H
#define	LEXER_H


class lexer {
private:	
	stringstream* is;
	symtab *stab;
	
public:
	lexer(stringstream& i, symtab *st);
	token* getNextToken(void); 
	
};


typedef enum {
	STATE_START,
	STATE_IN_ID,
	STATE_NUM_FIRST_DIGIT,
	STATE_IN_INT,
	STATE_IN_HEX_INT,
	STATE_LEXEME_COMPLETE
}LEX_STATE;







#endif	/* LEXER_H */

