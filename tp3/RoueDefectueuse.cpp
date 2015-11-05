/************************************************************************************
* Fichier               : RoueDefectueuse.cpp                                       *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Roue d�fectueuse                                          *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include "RoueDefectueuse.h"
#include "Roue.h"
#include "Piece.h"
using namespace std;

// Constructeur par d�faut
RoueDefectueuse::RoueDefectueuse(){};

// Constructeur par param�tres
RoueDefectueuse::RoueDefectueuse(string manufacturier, string description, int prix, int anneeFabrication, int vitesseReguliere){
	manufacturier_ = manufacturier;
	description_ = description;
	prix_ = prix;
	anneeFabrication_ = anneeFabrication;
	vitesse_ = vitesseReguliere / 2;
};

// Destructeur
RoueDefectueuse::~RoueDefectueuse(){};