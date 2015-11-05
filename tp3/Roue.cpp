/************************************************************************************
* Fichier               : Roue.cpp                                                  *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Roue                                                      *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include "Roue.h"
#include "Piece.h"
using namespace std;

// Constructeur par défaut
Roue::Roue(){};

// Constructeur par paramètres
Roue::Roue(string manufacturier, string description, int prix, int anneeFabrication, int vitesse){
	manufacturier_ = manufacturier;
	description_ = description;
	prix_ = prix;
	anneeFabrication_ = anneeFabrication;
	vitesse_ = vitesse;
};

// Destructeur
Roue::~Roue(){};

// Fonctions

int Roue::calculerVraieVitesse() const{
	return vitesse_ / exp(max(0, 2014 - anneeFabrication_) * 0.05);
};

void Roue::afficherInformations() const{
	Piece::afficherInformations();
	cout << "Vitesse : " << vitesse_ << endl
		 << "Vraie vitesse : " << calculerVraieVitesse() << endl;
};

// Getters

int Roue::getVitesse() const{
	return vitesse_;
};

// Setters

void Roue::setVitesse(int vitesse){
	vitesse_ = vitesse;
};