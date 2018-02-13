#include <iostream>
#include <string>
#include <deque>
#include "lexer.h"
class Etat;

using namespace std;

class Automate {
	public : 
		Automate(){};
		virtual ~Automate();
		
		void decalage(Symbole * s, Etat * e);
		void reduction(int n, Symbole * s);
		
	protected : 
		deque<Symbole * > symbolestack;
		deque<Etat * > etatstack;
		
		Lexer * lexer;
};
