/* 
 * File:   parser.cpp
 * Author: tleonard
 *
 * Created on March 10, 2012, 5:06 PM
 */

#include <cstdlib>
#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
#include "mytypes.h"
#include "token.h"
#include "symtab.h"
#include "ast.h"
#include "lexer.h"
#include "parser.h"

parser::parser() {
	stab = new symtab();
	lex = new lexer(ss, stab);
	root = 0;
}


//
// free up resources allocated by parser
//
parser::~parser(void) {
	if (root) {
		delete root;
		root = 0;
	}
	if (lex) {
		delete lex;
		lex =0;
	}
	if (stab) {
		delete stab;
		stab = 0;
	}
}



ast *parser::buildAst(string line) {
	
token *t;

	if (root) { 
		delete root;
	}
	root = new ast();

	ss.str(line);
	cout << ss.str();
	ss.clear();
	ss.seekp(0,ios::beg);

	//
	// evaluate the input line
	//
	do {
		t = lex->getNextToken();
		t->display(cout);
	} while ((t->getToken() != TOK_EOF) && (t->getToken() != TOK_EOL));
	stab->display();
	return root;
}








