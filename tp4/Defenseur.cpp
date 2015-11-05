/************************************************************************************
*	Fichier					: Defenseur.cpp                                         *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Implementation de la classe Defenseur                 *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

#include <string>
#include <iostream>
#include "Defenseur.h"
using namespace std;

// Constructeur par defaut
Defenseur::Defenseur(){}

// Constructeur par parametres sans position
Defenseur::Defenseur(string nom, string prenom, unsigned int age){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
}

// Constructeur par parametres avec position
Defenseur::Defenseur(string nom, string prenom, unsigned int age, int position){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
	position_ = position;
}

// Destructeur
Defenseur::~Defenseur(){}

// Fonctions et methodes

void Defenseur::celebrer() const {
	cout << "Not bad." << endl;
}

void Defenseur::avancer(){
	position_ += 2;
}

void Defenseur::reculer(){
	position_ -= 2;
}

string Defenseur::getType() const {
	return "Defenseur";
}