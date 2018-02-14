#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Symbole::eval(){
   return 0;
}

int Entier::eval() {
   return this->valeur;
}

int Expr::eval() {
   return this->valeur;
}



