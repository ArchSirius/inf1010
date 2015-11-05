/************************************************************************************
* Fichier				: JeuVideo.cpp                                              *
* Auteurs				: Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description			: Objet jeu video                                           *
* Date de creation		: 11 septembre 2014                                         *
* Date de modification	: 18 septembre 2014                                         *
************************************************************************************/

#include <iostream>
#include <string>
#include "Date.h"
#include "JeuVideo.h"

using namespace std;

// Constructeur par défaut
JeuVideo::JeuVideo(){};
// Constructeur par paramètre
JeuVideo::JeuVideo(string titre, Date dateSortie, string nomEditeur, string genre, string plateforme, string description, double evaluation){
	titre_ = titre;
	dateSortie_ = dateSortie;
	nomEditeur_ = nomEditeur;
	genre_ = genre;
	plateforme_ = plateforme;
	description_ = description;
	evaluation_ = evaluation;
};
// Destructeur (par défaut)
JeuVideo::~JeuVideo(){};

// GETTERS

/**
 *  Permet de voir le titre du jeu sans y avoir acces.
 *  \return un string du titre du jeu
 */

string JeuVideo::getTitre() const {
	return titre_;
}

/**
 *  Permet de voir la date de sortie du jeu sans y avoir acces.
 *  \return un objet de la classe Date.
 */

Date JeuVideo::getDateSortie() const {
	return dateSortie_;
}

string JeuVideo::getNomEditeur() const {
	return nomEditeur_;
}

string JeuVideo::getGenre() const {
	return genre_;
}

string JeuVideo::getPlateforme() const {
	return plateforme_;
}

string JeuVideo::getDescription() const {
	return description_;
}

double JeuVideo::getEvaluation() const {
	return evaluation_;
}

// SETTERS

/**
 *  modificateur de 'titre_'
 *  \param          string du titre du jeu
 */

void JeuVideo::setTitre(string titre){
	titre_ = titre;
}

void JeuVideo::setDateSortie(Date dateSortie){
	dateSortie_ = dateSortie;
}

void JeuVideo::setNomEditeur(string nomEditeur){
	nomEditeur_ = nomEditeur;
}
void JeuVideo::setGenre(string genre){
	genre_ = genre;
}

void JeuVideo::setPlateforme(string plateforme){
	plateforme_ = plateforme;
}

void JeuVideo::setDescription(string description){
	description_ = description;
}

void JeuVideo::setEvaluation(double evaluation){
	evaluation_ = evaluation;
}

// FONCTIONS ET METHODES PROPRES

void JeuVideo::afficherJeu() const {
	cout << "=========================" << endl 
		 << "Titre du jeu : " << titre_ << endl 
		 << "Date de sortie : "; dateSortie_.afficherDate();
	cout << endl 
		 << "Editeur : " << nomEditeur_ << endl 
		 << "Plate-forme : " << plateforme_ << endl 
		 << "Description : " << endl << description_ << endl 
		 << "Evaluation : " << evaluation_ << endl 
		 << "=========================" << endl;
}
