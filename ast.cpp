
#include <cstdlib>
#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
#include "mytypes.h"
#include "token.h"
#include "ast.h"




ast::ast(void) {
	
}

ast::ast(token *t) {
	opr = t;
}

ast::~ast(void) {
	
}

void ast::setOpr(token *t) {
	opr = t;
}

token *ast::getOpr(void) {
	return opr;	
}


//
// default get Operand value function - return opr for this ast
//
token *ast::getOprValue(void) {
	
token *ret = new token();
	ret = opr;
}



void ast::addOprnd(ast *a) {
vector<ast *>::iterator it;
	it = oprndList.end();
	oprndList.insert(it,a);	
}


//
// default eval returns the ast
//
ast *ast::eval(void) {
	
	return this;
}














