#include "etat.h"
#include "automate.h"

bool E0::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case EXPR :
			automate.decalage(s,new E1);
			break;
		case OPENPAR :
			automate.decalage(s, new E2);
			break;
		case INT : 
			automate.decalage(s, new E3);
			break;
		default :
		break;
	}
}

bool E1::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.decalage(s,new E4);
			break;
		case MULT :
			automate.decalage(s, new E5);
			break;
		case FIN :
			exit(10);
			break;
		default :
			break;
	}
}

bool E2::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case OPENPAR :
			automate.decalage(s,new E2);
			break;
		case INT :
			automate.decalage(s, new E3);
			break;
		case EXPR :
			automate.decalage(s, new E6);
			break;
		default :
			break;
	}
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
			break;
	}
}

bool E4::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case EXPR :
			automate.decalage(s,new E7);
			break;
		case OPENPAR :
			automate.decalage(s, new E2);
			break;
		case INT : 
			automate.decalage(s, new E3);
			break;
		default :
		break;
	}
}

bool E5::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case EXPR :
			automate.decalage(s,new E8);
			break;
		case OPENPAR :
			automate.decalage(s, new E2);
			break;
		case INT : 
			automate.decalage(s, new E3);
			break;
		default :
		break;
	}
}

bool E6::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.decalage(s,new E4);
			break;
		case MULT :
			automate.decalage(s, new E5);
			break;
		case CLOSEPAR : 
			automate.decalage(s, new E9);
			break;
		default :
		break;
	}
}

bool E7::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.reduction(2,s);
			break;
		case MULT :
			automate.decalage(s, new E5);
			break;
		case CLOSEPAR :
			automate.reduction(2, s);
			break;
		case FIN :
			automate.reduction(2, s);
			break;
		default :
			break;
	}
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
			break;
	}
}

bool E9::transition(Automate & automate, Symbole * s)
{
	switch(*s)
	{
		case PLUS :
			automate.reduction(4,s);
			break;
		case MULT :
			automate.reduction(4, s);
			break;
		case CLOSEPAR :
			automate.reduction(4, s);
			break;
		case FIN :
			automate.reduction(4, s);
			break;
		default :
			break;
	}
}
