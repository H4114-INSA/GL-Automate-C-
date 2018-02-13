#include <map>
#include "symbole.h"
#include <iostream>

class Expr : public Symbole {
	public : 
		Expr() : Symbole(EXPR){}
		virtual ~Expr(){}
		virtual double eval(const map<string, double> &valeur) = 0;
};
