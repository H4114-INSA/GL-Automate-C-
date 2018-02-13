#include <iostream>
#include "symbole.h"
#include <string>

class Automate;

using namespace std; 

class Etat { 

public : 
	Etat (){}
	virtual ~Etat(){}
	void print() const;
	virtual bool transition(Automate & automate, Symbole * s)=0;
	
};


class E0 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E1 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E2 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E3 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E4 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E5 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E6 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E7 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E8 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};

class E9 : public Etat {
	bool transition(Automate & automate, Symbole * s);
};
