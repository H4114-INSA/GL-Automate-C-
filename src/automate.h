#include <iostream>
#include <string>
#include <deque>
#include "lexer.h"
#include <vector>
class Etat;

using namespace std;

class Automate {
	public : 
		Automate(string chaine);
		virtual ~Automate();

		void eval();
		void decalage(Symbole * s, Etat * e);
		void reduction(int n, Symbole * s);
		int calcul( vector<Symbole * > symboleDepile);
		
	protected : 
		deque<Symbole * > symbolestack;
		deque<Etat * > etatstack;
		
		Lexer * lexer;
		int resultat;
};
