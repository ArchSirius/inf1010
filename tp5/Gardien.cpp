/************************************************************************************
*	Fichier					: Gardien.cpp
*	Auteurs					: Benjamin De Leener
*	Description				: Implementation de la classe Gardien
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#include "Gardien.h"
#include <iostream>
using namespace std;

Gardien::Gardien()
    : Joueur()
{
    attaque_ = 0.1;
    defense_ = 1.0;
	stabilite_ = 0.9;
	reflexe_ = 1.2;
}

Gardien::Gardien(unsigned int num, string nom, string prenom, unsigned int age, double stabilite, double reflexe)
    : Joueur(num, nom, prenom, age, 0.1, 1.0), stabilite_(stabilite), reflexe_(reflexe)
{
}

Gardien::~Gardien()
{
}

double Gardien::getAttaque() const
{
    return attaque_*(stabilite_+reflexe_)/2;
}

double Gardien::getDefense() const
{
    return defense_*(stabilite_+reflexe_)/2;
}

void Gardien::celebrer() const
{
    cout << *this << " : Victoire!!" << endl;
}

string Gardien::getType() const
{
	return "Gardien";
}
