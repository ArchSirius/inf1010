/************************************************************************************
* Fichier				: Editeur.cpp                                               *
* Auteurs				: Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description			: Éditeur de jeux vidéo                                     *
* Date de creation		: 11 septembre 2014                                         *
* Date de modification	: 18 septembre 2014                                         *
************************************************************************************/

#include <iostream>
#include <string>
#include "Date.h"
#include "JeuVideo.h"
#include "Editeur.h"

using namespace std;

const short NB_MAX_JEUX = 10;	// nombre maximal de jeux par Editeur

// Constructeur par défaut
Editeur::Editeur(){};
// Constructeur par paramètres
Editeur::Editeur(string nomEditeur, Date dateCreation, string siteWeb){
	nom_ = nomEditeur;
	date_creation_ = dateCreation;
	site_web_ = siteWeb;
	liste_jeux_ = new JeuVideo[NB_MAX_JEUX];
	nombre_jeux_ = 0;
};
// Destructeur
Editeur::~Editeur(){
	delete [] liste_jeux_;
};

// GETTERS

/** Accesseur nom_
* \return nom de l'éditeur
*/
string Editeur::getNom() const {
	return nom_;
}

Date Editeur::getDateCreation() const {
	return date_creation_;
}

string Editeur::getSiteWeb() const {
	return site_web_;
}

unsigned int Editeur::getNombreJeux() const{
	return nombre_jeux_;
}

// SETTERS

/** Modificateur nom_
* \param nom nouveau nom de l'éditeur
*/
void Editeur::setNom(string nom){
	nom_ = nom;
}

void Editeur::setDateCreation(Date date_creation){
	date_creation_ = date_creation;
}

void Editeur::setSiteWeb(string site_web){
	site_web_ = site_web;
}

bool Editeur::ajouterJeu(const JeuVideo& jeu){
	if (nombre_jeux_ >= NB_MAX_JEUX)
		return false;
	liste_jeux_[nombre_jeux_] = jeu;
	nombre_jeux_ ++;
	return true;
}

void Editeur::afficherJeux() const {
	for(unsigned int i = 0; i < nombre_jeux_; i++){
		liste_jeux_[i].afficherJeu();
	}
}

/** Affiche les details d'un editeur
*   
*/
void Editeur::afficherEditeur() const {
	cout << "=========================" << endl 
		 << "Nom de l'editeur : " << nom_ << endl 
		 << "Date de creation : "; date_creation_.afficherDate();
	cout << "Site web : " << site_web_ << endl 
		 << "Jeux : " << endl;
	afficherJeux();
}
