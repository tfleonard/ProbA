/*
 * symtab.h
 *
 *  Created on: Mar 9, 2012
 *      Author: tleonard
 */

#ifndef SYMTAB_H_
#define SYMTAB_H_

class symEntry {

	token *t;


public:
	symEntry(token t);
	~symEntry(void);
	token *findSymbol(string s);

};



class symtab {

private:
	vector<token> symVect;
	map<string,token *> symMap;

public:
	symtab(void);
	token *addSym(token *t); 
	void display(void);
};




#endif /* SYMTAB_H_ */
