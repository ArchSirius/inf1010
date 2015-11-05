/************************************************************************************
*   Fichier                 : Equipe.cpp                                            *
*   Auteurs                 : Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*   Description             : Implementation de la classe Equipe                    *
*   Date de creation        : 23 octobre 2014                                       *
*   Date de modification    : 26 octobre 2014                                       *
************************************************************************************/

#include "Equipe.h"
#include <iostream>

using namespace std;

// Constructeur par defaut
Equipe::Equipe(){};

// Constructeur par copie
Equipe::Equipe(const Equipe& eq) {
	joueurs_ = eq.joueurs_;
}

// Destructeur
Equipe::~Equipe(){}

// Fonctions et methodes

Equipe& Equipe::operator=(const Equipe& eq) {
	if (*this != eq){
		for (unsigned int i = 0; i < eq.joueurs_.size(); i++) {
			supprimerJoueur(joueurs_[i]);
			joueurs_[i] = eq.joueurs_[i];
		}
	}
	return *this;
}

bool Equipe::operator!=(const Equipe& eq) {
	return !(joueurs_ == eq.joueurs_);
}

bool Equipe::jouer(){
	avancer();
	reculer();
	avancer();
	marquer();

	return victoire_;
}

void Equipe::afficherEquipe() {
	for (unsigned int i = 0; i < joueurs_.size(); i++) {
		cout << *joueurs_[i] << ", " << joueurs_[i]->getAge()
			 << " ans" << endl;
	}
}

bool Equipe::ajouterJoueur(Joueur* individu) {
	joueurs_.push_back(individu);
	return true;
}

bool Equipe::supprimerJoueur(Joueur* individu){
	for (unsigned int i = 0; i < joueurs_.size(); i++){
		if (joueurs_[i] == individu)
			delete joueurs_[i];
	}
	return true;
}

bool Equipe::victorieuse(){
	return victoire_;
}

int Equipe::getScore(){
	return score_;
}

void Equipe::avancer(){
	for (unsigned int i = 0; i<joueurs_.size(); i++)
		joueurs_[i]->avancer();
}

void Equipe::reculer(){
	for (unsigned int i = 0; i<joueurs_.size(); i++)
		joueurs_[i]->reculer();
}

void Equipe::marquer(){
	for (unsigned int i = 0; i<joueurs_.size(); i++){
		bool goal = joueurs_[i]->marquer();
		if (goal){
			score_++;
			victoire_ = true;
		}
	}
}

void Equipe::celebrer(){
	for (unsigned int i = 0; i<joueurs_.size(); i++)
		joueurs_[i]->celebrer();
}

void Equipe::killAll(){
	for (unsigned int i = 0; i<joueurs_.size(); i++)
		delete joueurs_[i];
}