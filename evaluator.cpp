/* 
 * File:   evaluator.cpp
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
#include "evaluator.h"


evaluator::evaluator (void) {
	
	//
	// new parser
	//

	parse = new parser();
	
		
}



string evaluator::eval (string s) {

string rs = "";	
	root = parse->buildAst(s);

	return rs;
}






