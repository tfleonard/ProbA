/* 
 * File:   asttypes.h
 * Author: tleonard
 *
 * Created on April 6, 2012, 9:33 PM
 */

#ifndef ASTTYPES_H
#define	ASTTYPES_H


class astAdd : ast {
	
	ast *eval(void);
		
};


class astVect : ast {
	
	ast *eval(void);
};


class astNum : ast {
	
	ast *eval(void);
};

class ast2dArray : ast {
	
	ast *eval(void);
};






#endif	/* ASTTYPES_H */

