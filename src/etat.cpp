#include "etat.h"
#include "automate.h"

bool E0::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case EXPR :
			automate.decalage(s,new E1);
			cout << " -> ETAT 1" << endl;
			break;
		case OPENPAR :
			automate.decalage(s, new E2);
			cout << " -> ETAT 2" << endl;
			break;
		case INT : 
			automate.decalage(s, new E3);
			cout << " -> ETAT 3" << endl;
			break;
		default :
			return false;
			break;
	}
	return true;
}

bool E1::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.decalage(s,new E4);
			cout << " -> ETAT 4" << endl;
			break;
		case MULT :
			automate.decalage(s, new E5);
			cout << " -> ETAT 5" << endl;
			break;
		case FIN :
			exit(10);
			break;
		default :
			return false;
			break;
	}
	return true;
}

bool E2::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case OPENPAR :
			automate.decalage(s,new E2);
			cout << " -> ETAT 2" << endl;
			break;
		case INT :
			automate.decalage(s, new E3);
			cout << "  -> ETAT 3" << endl;
			break;
		case EXPR :
			automate.decalage(s, new E6);
			cout << " -> ETAT 6" << endl;
			break;
		default :
			return false;
			break;
	}

	return true;
}

bool E3::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
		case MULT :	
		case CLOSEPAR :
		case FIN :
			automate.reduction(1,s);
			break;
		default :
			return false;
			break;
	}

	return true;
}

bool E4::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case EXPR :
			automate.decalage(s,new E7);
			cout << " -> ETAT 7" << endl;
			break;
		case OPENPAR :
			automate.decalage(s, new E2);
			cout << " -> ETAT 2" << endl;
			break;
		case INT : 
			automate.decalage(s, new E3);
			cout << " -> ETAT 3" << endl;
			break;
		default :
			return false;
			break;
	}

	return true;
}

bool E5::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case EXPR :
			automate.decalage(s,new E8);
			cout << " -> ETAT 8" << endl;
			break;
		case OPENPAR :
			automate.decalage(s, new E2);
			cout << " -> ETAT 2" << endl;
			break;
		case INT : 
			automate.decalage(s, new E3);
			cout << " -> ETAT 3" << endl;
			break;
		default :
			return false;
			break;
	}
	return true;
}

bool E6::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.decalage(s,new E4);
			cout << " -> ETAT 4" << endl;
			break;
		case MULT :
			automate.decalage(s, new E5);
			cout << " -> ETAT 5" << endl;
			break;
		case CLOSEPAR : 
			automate.decalage(s, new E9);
			cout << " -> ETAT 9" << endl;
			break;
		default :
			return false;
			break;
	}
	return true;
}

bool E7::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.reduction(3,s);
			break;
		case MULT :
			automate.decalage(s, new E5);
			cout << " -> ETAT 5" << endl;
			break;
		case CLOSEPAR :
			automate.reduction(3, s);
			break;
		case FIN :
			automate.reduction(3, s);
			break;
		default :
			return false;
			break;
	}
	return true;
}

bool E8::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.reduction(3,s);
			break;
		case MULT :
			automate.reduction(3, s);
			break;
		case CLOSEPAR :
			automate.reduction(3, s);
			break;
		case FIN :
			automate.reduction(3, s);
			break;
		default :
			return false;
			break;
	}
	return true;
}

bool E9::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.reduction(3,s);
			break;
		case MULT :
			automate.reduction(3, s);
			break;
		case CLOSEPAR :
			automate.reduction(3, s);
			break;
		case FIN :
			automate.reduction(3, s);
			break;
		default :
			return false;
			break;
	}
	return true;
}
