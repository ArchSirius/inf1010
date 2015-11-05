/************************************************************************************
* Fichier               : voiture.cpp                                               *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Voiture                                                   *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#include <iostream>
#include <string>
#include "Voiture.h"
#include "Moteur.h"
#include "Roue.h"
#include "Piece.h"

using namespace std;

// Constructeur par paramètre
Voiture::Voiture(string marque, int prix, Moteur moteur, Roue* roue1, Roue* roue2, Roue* roue3, Roue* roue4 ) {
	marque_ = marque;
	prix_ = prix;
	moteur_ = moteur;
	roues_[0] = roue1;
	roues_[1] = roue2;
	roues_[2] = roue3;
	roues_[3] = roue4;
};

// Destructeur
Voiture::~Voiture(){};

//affichage de la voiture
void Voiture::afficherInformationVoiture() const {
	cout << "Marque: " << marque_ << endl << endl <<
		"Information sur le moteur: " << endl;
	moteur_.afficherInformations();
	for (int i = 0; i < 4; i++)
		roues_[i]->afficherInformations();
	cout << "====================" << endl << "Prix  : " << prix_ << endl;
};

string Voiture::getMarque() const {
	return marque_;
};

int Voiture::getPrix() const {
	return prix_;
};

Moteur Voiture::getMoteur() const {
	return moteur_;
};

Roue* Voiture::getRoue() const{
	return *roues_;
};

void Voiture::setMarque(string marque){
	marque_ = marque;
};

void Voiture::setPrix(int prix){
	prix_ = prix;
};

void Voiture::setMoteur(Moteur moteur){
	moteur_ = moteur;
};

void Voiture::setRoues(Roue *roue[]){
	*roues_ = *roue;
};

void Voiture::setRoues(int i, Roue* roue){
	if(i < 4){
		roues_[i] = roue;
	}
};

int Voiture::calculerVitesseVoiture(){
	int vitesseTotal = 0;
	for (int i = 0; i < 4; i++)
		vitesseTotal += roues_[i]->getVitesse();
	return vitesseTotal;
};

int Voiture::calculerCoutVoiture(){
	int coutTotal;
	coutTotal = prix_;
	for (int i = 0; i < 4; i++)
		coutTotal += roues_[i]->getPrix();
	return coutTotal;
};