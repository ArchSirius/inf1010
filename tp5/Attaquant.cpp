/************************************************************************************
*	Fichier					: Attaquant.cpp
*	Auteurs					: Benjamin De Leener
*	Description				: Implementation de la classe Attaquant
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#include "Attaquant.h"
#include <iostream>
using namespace std;

Attaquant::Attaquant()
    : Joueur()
{
    attaque_ = 1.0;
    defense_ = 0.3;
	vitesse_ = 1.0;
	agilite_ = 0.8;
	precision_ = 1.0;
}

Attaquant::Attaquant(unsigned int num, string nom, string prenom, unsigned int age, double vitesse, double agilite, double precision)
    : Joueur(num, nom, prenom, age, 1.0, 0.3), vitesse_(vitesse), agilite_(agilite), precision_(precision)
{
}

Attaquant::~Attaquant()
{
}

void Attaquant::celebrer() const 
{
    cout << *this << " : YEAAAAAAH!!!" << endl;
}

string Attaquant::getType() const
{
	return "Attaquant";
}

double Attaquant::getAttaque() const
{
    return attaque_*(vitesse_+agilite_+precision_)/3;
}

double Attaquant::getDefense() const
{
    return defense_*(vitesse_+agilite_+precision_)/3;
}

