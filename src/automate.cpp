#include "automate.h"
#include "etat.h"

using namespace std;


void Automate::decalage(Symbole * s, Etat * e)
{
	symbolestack.push_back(s);
	etatstack.push_back(e);
	if((int)*s==EXPR)
		lexer->Avancer();
}


void Automate::reduction(int n, Symbole * s)
{
	for(int i=0; i<n; i++)
	{
		delete(etatstack.back());
		etatstack.pop_back();
	}
	etatstack.back()->transition(*this, s);
}
