/************************************************************************************
* Fichier               : Piece.cpp                                                 *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Moteur                                                    *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include "Moteur.h"
#include "Piece.h"
using namespace std;

// Constructeur par défaut
Moteur::Moteur(){};

// Constructeur par paramètres
Moteur::Moteur(string manufacturier, string description, int prix, int anneeFabrication, int chevauxVapeurs, int kilometrage){
	manufacturier_ = manufacturier;
	description_ = description;
	prix_ = prix;
	anneeFabrication_ = anneeFabrication;
	chevauxVapeurs_ = chevauxVapeurs;
	kilometrage_ = kilometrage;
};

// Destructeur
Moteur::~Moteur(){};

// Fonctions

double Moteur::calculerPuissance() const{
	return 100.0 * chevauxVapeurs_ / 200.0 / exp(max(0, 2014 - anneeFabrication_) * 0.015);
};

void Moteur::afficherInformations() const{
	Piece::afficherInformations();
	cout << "Chevaux vapeurs : " << chevauxVapeurs_ << endl
		 << "Kilometrage : " << kilometrage_ << endl
		 << "Puissance : " << calculerPuissance() << endl;
};

// Getters

int Moteur::getChevauxVapeurs() const{
	return chevauxVapeurs_;
};

int Moteur::getKilometrage() const{
	return kilometrage_;
};

// Setters

void Moteur::setChevauxVapeurs(int chevauxVapeurs){
	chevauxVapeurs_ = chevauxVapeurs;
};

void Moteur::setKilometrage(int kilometrage){
	kilometrage_ = kilometrage;
};