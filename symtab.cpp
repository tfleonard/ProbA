/* 
 * File:   symtab.cpp
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


symEntry::symEntry(token t) {
	
	
}

symEntry::~symEntry(void) {
	
	
}

token *symEntry::findSymbol(string s) {
	

	
	return 0;
}





symtab::symtab(void) {

	
	
}


token *symtab::addSym(token *t) {

//map<string,token *>::iterator it;
string lexeme = t->getLexeme();
pair<map<string,token *>::iterator,bool> ret;

	ret = symMap.insert(pair<string,token *>(lexeme,t));
	if (ret.second == false) {
		delete t;
		return ret.first->second;
	} 
	return t;
}


void symtab::display(void) {

map<string,token *>::iterator it;
token *pToken;
	cout << "Symbol Table:\n";
	for (it=symMap.begin(); it!= symMap.end() ;it++) {
		it->second->display(cout);		
	}
	
}

