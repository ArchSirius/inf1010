/************************************************************************************
*	Fichier					: Attaquant.cpp                                         *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Implementation de la classe Attaquant                 *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

#include <string>
#include <iostream>
#include "Attaquant.h"
using namespace std;

// Constructeur par defaut
Attaquant::Attaquant(){}

// Constructeur par parametres sans position
Attaquant::Attaquant(string nom, string prenom, unsigned int age){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
}

// Constructeur par parametres avec position
Attaquant::Attaquant(string nom, string prenom, unsigned int age, int position){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
	position_ = position;
}

// Destructeur
Attaquant::~Attaquant(){}

// Fonctions et methodes

void Attaquant::celebrer() const {
	cout << "Yarr!" << endl;
}

void Attaquant::avancer(){
	position_ += 5;
}

void Attaquant::reculer(){
	position_ -= 3;
}

string Attaquant::getType() const {
	return "Attaquant";
}