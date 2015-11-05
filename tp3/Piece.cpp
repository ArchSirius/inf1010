/************************************************************************************
* Fichier               : Piece.cpp                                                 *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Pièce automobile                                          *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;

// Constructeur par défaut
Piece::Piece(){};

// Constructeur par paramètres
Piece::Piece(string manufacturier, string description, int prix, int anneeFabrication){
	manufacturier_ = manufacturier;
	description_ = description;
	prix_ = prix;
	anneeFabrication_ = anneeFabrication;
};

// Destructeur
Piece::~Piece(){};

// Fonctions

void Piece::afficherInformations() const{
	cout << "====================" << endl
	     << "Manufacturier : " << manufacturier_ << endl
		 << "Description : " << description_ << endl
		 << "Prix : " << prix_ << endl
		 << "Année de fabrication : " << anneeFabrication_ << endl;
};

// Getters

string Piece::getManufacturier() const{
	return manufacturier_;
};

string Piece::getDescription() const{
	return description_;
};

int Piece::getPrix() const{
	return prix_;
};

int Piece::getAnneeFabrication() const{
	return anneeFabrication_;
};

// Setters

void Piece::setManufacturier(string manufacturier){
	manufacturier_ = manufacturier;
};

void Piece::setDescription(string description){
	description_ = description;
};

void Piece::setPrix(int prix){
	prix_ = prix;
};

void Piece::setAnneeFabrication(int anneeFabrication){
	anneeFabrication_ = anneeFabrication;
};