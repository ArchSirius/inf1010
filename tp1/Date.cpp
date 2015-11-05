/************************************************************************************
* Fichier				: Date.cpp                                                  *
* Auteurs				: Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description			: Date en format mm/jj/aaaa                                 *
* Date de creation		: 11 septembre 2014                                         *
* Date de modification	: 18 septembre 2014                                         *
************************************************************************************/

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

// Constructeur par défaut
Date::Date(){};
// Constructeur par paramètre
Date::Date(unsigned int jour, unsigned int mois, unsigned int annee){
	jour_ = jour;
	mois_ = mois;
	annee_ = annee;
};
// Destructeur (par défaut)
Date::~Date(){};

// GETTERS

unsigned int Date::getJour() const {
	return jour_;
}

unsigned int Date::getMois() const {
	return mois_;
}

unsigned int Date::getAnnee() const {
	return annee_;
}

// SETTERS

void Date::setJour(unsigned int jour){
	jour_ = jour;
}

void Date::setMois(unsigned int mois){
	mois_ = mois;
}

void Date::setAnnee(unsigned int annee){
	annee_ = annee;
}

void Date::afficherDate() const {
	cout << /**setw(2) << setfill('0') <<*/ jour_
		 << /**setw(2) << setfill('0') <<*/ "/" << mois_
		 << "/" << annee_ << endl;
}
