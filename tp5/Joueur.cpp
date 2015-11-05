/************************************************************************************
*	Fichier					: Joueur.cpp
*	Auteurs					: Benjamin De Leener
*	Description				: Implementation de la classe Joueur
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#include "Joueur.h"
#include <iostream>
using namespace std;

Joueur::Joueur()
	: num_(0), age_(0), attaque_(0.0), defense_(0.0)
{
}

Joueur::Joueur(unsigned int num, string nom, string prenom, unsigned int age, double attaque, double defense)
    : num_(num), nom_(nom), prenom_(prenom), age_(age), attaque_(attaque), defense_(defense)
{
}

Joueur::~Joueur()
{
}

unsigned int Joueur::getNum() const{
	return num_;
}

void Joueur::setNom(string nom)
{
	nom_ = nom;
}

void Joueur::setPrenom(string prenom)
{
	prenom_ = prenom;
}

void Joueur::setAge(unsigned int age)
{
	age_ = age;
}

void Joueur::setAttaque(double attaque)
{
	attaque_ = attaque;
}

void Joueur::setDefense(double defense)
{
	defense_ = defense;
}


string Joueur::getNom() const
{
	return nom_;
}

string Joueur::getPrenom() const
{
	return prenom_;
}

unsigned int Joueur::getAge() const
{
	return age_;
}

double Joueur::getAttaque() const
{
	return attaque_;
}

double Joueur::getDefense() const
{
	return defense_;
}

void Joueur::celebrer() const 
{
    cout << *this << " : Youpie!!!" << endl;
}

bool Joueur::operator==(const Joueur& ind)
{
    return (nom_==ind.nom_ && prenom_==ind.prenom_ && age_==ind.age_);
}

ostream& operator<<(ostream& os, const Joueur& individu)
{
	return os << individu.prenom_ << " " << individu.nom_;
}
