/*
 * parser.h
 *
 *  Created on: Mar 9, 2012
 *      Author: tleonard
 */

#ifndef PARSER_H_
#define PARSER_H_


class parser {

private:
	lexer *lex;
	symtab *stab;
	stringstream ss;
	ast *root;


public:
	parser();
	~parser(void);
	ast *buildAst(string s);

};


#endif /* PARSER_H_ */
