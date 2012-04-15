/* 
 * File:   ast.h
 * Author: tleonard
 *
 * Created on March 10, 2012, 6:56 PM
 */

#ifndef AST_H
#define	AST_H


class ast {
	
private:
	vector<ast *> oprndList;
	token *opr;
	
public:
	ast(void);
	ast(token *t);
	~ast(void);
	void setOpr(token *t);
	token *getOpr(void);
	virtual token *getOprValue(void);
	void addOprnd(ast *);
	virtual ast *eval(void);
	int depth(void);
	
};





#endif	/* AST_H */

