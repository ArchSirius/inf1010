/************************************************************************************
*	Fichier					: Defenseur.cpp
*	Auteurs					: Benjamin De Leener
*	Description				: Implementation de la classe Defenseur
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#include "Defenseur.h"
#include <iostream>
using namespace std;

Defenseur::Defenseur()
    : Joueur()
{
    attaque_ = 0.3;
    defense_ = 0.8;
	reactivite_ = 0.8;
	vision_ = 1.0;
}

Defenseur::Defenseur(unsigned int num, string nom, string prenom, unsigned int age, double reactivite, double vision)
	: Joueur(num, nom, prenom, age, 0.3, 0.8), reactivite_(reactivite), vision_(vision)
{
}

Defenseur::~Defenseur()
{
}

void Defenseur::celebrer() const
{
    cout << *this << " : YAHOOOOOO!!!" << endl;
}

double Defenseur::getAttaque() const
{
    return attaque_*(reactivite_+vision_)/2;
}

double Defenseur::getDefense() const
{
    return defense_*(reactivite_+vision_)/2;
}

string Defenseur::getType() const
{
	return "Defenseur";
}
