#include "automate.h"
#include "etat.h"
#include "symbole.h"
#include <algorithm>

using namespace std;

Automate::Automate(string chaine) {
    lexer = new Lexer (chaine);
    Etat* e0 = new E0();
    etatstack.push_back(e0);
}

Automate::~Automate() {
    delete lexer;
}

void Automate::decalage(Symbole * s, Etat * e)
{
	symbolestack.push_back(s);
	etatstack.push_back(e);
	if((int)*s !=EXPR)
		lexer->Avancer();
}


void Automate::reduction(int n, Symbole * s)
{
    vector<Symbole*> depile;

	for(int i=0; i<n; i++)
	{
		delete(etatstack.back());
		etatstack.pop_back();
        depile.push_back(symbolestack.back());
        symbolestack.pop_back();
	}

    reverse(depile.begin(), depile.end());
    int val = calcul(depile);

	etatstack.back()->transition(*this, new Expr(val));
    cout << "valeur de réduction : "<< val << endl;
}

int Automate::calcul( vector<Symbole * > symboleDepile)
{

	switch(symboleDepile.size()) {
        case 1 :
            return symboleDepile.at(0)->eval();
            break;
        case 3 :
            if((int)(*symboleDepile.at(0)) == OPENPAR) {
                return symboleDepile.at(1)->eval();
            }
            else if ((int)(*symboleDepile.at(1)) == PLUS) {
                return symboleDepile.at(0)->eval() + symboleDepile.at(2)->eval();
            }
            else if ((int)(*symboleDepile.at(1)) == MULT) {
                return symboleDepile.at(0)->eval()*symboleDepile.at(2)->eval();
            }
            else if ((int)(*symboleDepile.at(0)) == CLOSEPAR) {
                return symboleDepile.at(1)->eval();
            }
            break;
        default :
            break;
	}
	return 0;
}

void Automate::eval()
{
    bool finTransition = true;
    while(finTransition )
    {
        Symbole * s = lexer->Consulter();
        //cout << "symbole en analyse " ;
        //s->Affiche(); cout << endl;
        finTransition = etatstack.back()->transition(*this, s);
    }
}
