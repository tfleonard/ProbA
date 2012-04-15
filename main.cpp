/* 
 * File:   main.cpp
 * Author: tleonard
 *
 * Created on February 25, 2012, 5:06 PM
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


/*
 * 
 */
int main(int argc, char** argv) {

string fname;	
fstream f;	
string line;
char iline[512];
bool useFile;
int lineNum = 0;

	//
	// Select the input stream - file or stdin
	//
	if (argc > 1) {
		//
		// open the requested file
		//
		fname = argv[1];
		f.open(fname.c_str(), fstream::in);
		if (f.fail()) {
			cerr << "failed to open file " + fname << endl;
			exit(1);
		}
		useFile = true;
	} else {
		//
		// default to cin
		//
		useFile = false;
	}
	istream &input = useFile ? f : cin;

	//
	// new expression evaluator
	//
	evaluator *eval = new evaluator();

	//
	// REPL
	//
	while (1) {
		//
		// Read
		//
		input.getline(iline,511);
		if (input.eof()) {
			break;
		}
		lineNum++;
		line = iline;
		line += "\n";
		if (line.length() > 511) {
			cerr << " Input line " << lineNum << " exceeds input buffer size: " << line;
			if (useFile) {
				f.close();
				return 1;
			}
		}
		//
		//evaluate
		//
		eval->eval(line);

		//
		// print
		//
		
		
	}
	if (useFile) {
		f.close();
	}
	return 0;
}

