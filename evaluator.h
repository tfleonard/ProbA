/*
 * evaluator.h
 *
 *  Created on: Mar 9, 2012
 *      Author: tleonard
 */

#ifndef EVALUATOR_H_
#define EVALUATOR_H_


class evaluator {

private:
	parser	*parse;
	symtab	*stab;
	ast	*root;
	
public:
	evaluator(void);

	string eval (string s);

};












#endif /* EVALUATOR_H_ */
