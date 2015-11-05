/************************************************************************************
*	Fichier					: Joueur.cpp                                            *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Implementation de la classe Joueur                    *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 23 octobre 2014                                       *
************************************************************************************/

#include <string>
#include <iostream>
#include "Joueur.h"
using namespace std;

// Constructeur par défaut
Joueur::Joueur(){}

// Constructeur par paramètres (sans position)
Joueur::Joueur(string nom, string prenom, unsigned int age){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
}

// Constructeur par paramètres (avec position)
Joueur::Joueur(string nom, string prenom, unsigned int age, int position){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
	position_ = position;
}

// Destructeur
Joueur::~Joueur(){}

bool Joueur::operator==(const Joueur& individu)const {
	return nom_ == individu.nom_ && prenom_ == individu.prenom_ && age_ == individu.age_;
}

// Setters

void Joueur::setNom(string nom){
	nom_ = nom;
}

void Joueur::setPrenom(string prenom){
	prenom_ = prenom;
}

void Joueur::setAge(unsigned int age){
	age_ = age;
}

// Getters

string Joueur::getNom() const{
	return nom_;
}

string Joueur::getPrenom() const{
	return prenom_;
}

unsigned int Joueur::getAge() const{
	return age_;
}


ostream& operator<<(ostream& os, const Joueur& individu){		// friend
	os << individu.prenom_ << " " << individu.nom_;
	return os;
}

// Fonctions et méthodes

void Joueur::avancer(){
	position_++;
}

void Joueur::reculer(){
	position_--;
}

bool Joueur::marquer() const {
	if (position_ >= 7) {
		cout << *this << " tire et marque un goal!" << endl;
		return true;
	}
	return false;
}