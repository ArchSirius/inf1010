/************************************************************************************
*	Fichier					: Gardien.cpp                                           *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Implementation de la classe Gardien                   *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

#include <string>
#include <iostream>
#include "Gardien.h"
using namespace std;

// Constructeur par defaut
Gardien::Gardien(){}

// Constructeur par parametres sans position
Gardien::Gardien(string nom, string prenom, unsigned int age){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
}

// Constructeur par parametres avec position
Gardien::Gardien(string nom, string prenom, unsigned int age, int position){
	nom_ = nom;
	prenom_ = prenom;
	age_ = age;
	position_ = position;
}

// Destructeur
Gardien::~Gardien(){}

// Fonctions et methodes

void Gardien::celebrer() const {
	cout << "Nice" << endl;
}

void Gardien::avancer(){
	position_ += 1;
}

void Gardien::reculer(){
	position_ -= 1;
}

string Gardien::getType() const {
	return "Gardien";
}