#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {

    string chaine;
    cout << "Entrez une expression à calculer :" <<endl;
    cin >> chaine;

    Lexer l(chaine);
    Automate automate(chaine);
    automate.eval();

    return 0;
}

