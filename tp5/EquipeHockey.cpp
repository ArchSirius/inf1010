/*******************************************************************************
*	Fichier					: EquipeHockey.h                                   *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford *
*	Description				: Implementation de la classe EquipeHockey         *
*	Date de creation		: 6 novembre 2014                                  *
*	Date de modification	: 23 novembre 2014                                 *
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include "EquipeHockey.h"
#define MAXJ 6
using namespace std;

// Constructeur par défaut
EquipeHockey::EquipeHockey()
	: joueurs_(), nom_(""), score_(0), victoires_(0){}

// Constructeur par paramètres
EquipeHockey::EquipeHockey(string nom)
	: joueurs_(), nom_(nom), score_(0), victoires_(0){}

// Constructeur par copie
EquipeHockey::EquipeHockey(const EquipeHockey& eq1)
	: joueurs_(eq1.joueurs_), nom_(eq1.nom_), score_(eq1.score_), victoires_(eq1.victoires_){}

// Destructeur
EquipeHockey::~EquipeHockey(){}

// Opérateur d'affectation
EquipeHockey& EquipeHockey::operator=(const EquipeHockey& eq1){
	joueurs_ = eq1.joueurs_;
	nom_ = eq1.nom_;
	score_ = eq1.score_;
	victoires_ = eq1.victoires_;
	return *this;
}

// Méthodes et fonctions

bool EquipeHockey::ajouterJoueur(Joueur& joueur){
	if (joueurs_.size() < MAXJ){
		joueurs_.push_back(&joueur);
		return true;
	}
	return false;
}

bool EquipeHockey::supprimerJoueur(string nom, string prenom){
	// Foncteur
	struct FoncteurExiste{
		string nom_, prenom_;
		FoncteurExiste(string nom, string prenom) : nom_(nom), prenom_(prenom){};
		bool operator()(Joueur* joueur){
			if (joueur->getNom() == nom_ && joueur->getPrenom() == prenom_)
				return true;
			return false;
		}
	};

	// Fonction
	FoncteurExiste foncteurExiste(nom, prenom);
	vector<Joueur*>::const_iterator cIt = joueurs_.end();
	vector<Joueur*>::iterator it;
	it = remove_if(joueurs_.begin(), joueurs_.end(), foncteurExiste);
	return it != cIt;
}

void EquipeHockey::afficherJoueursAlpha() const{
	// Foncteur
	struct JoueurAlpha{
		JoueurAlpha(){}
		bool operator() (const Joueur* j1, const Joueur* j2){
			return (j1->getNom() < j2->getNom());
		}
	};

	// Fonction
	set<Joueur*, JoueurAlpha> temp;
	vector<Joueur*>::const_iterator cIt = joueurs_.begin();
	// Tri
	while (cIt != joueurs_.end()){
		temp.insert(*cIt);
		++cIt;
	}
	// Affichage
	set<Joueur*>::const_iterator cIts = temp.begin();
	while (cIts != temp.end()){
		cout << *cIts << endl;
		++cIts;
	}
}

void EquipeHockey::afficherJoueursNum() const{
	// Foncteur
	struct JoueurNum{
		JoueurNum(){}
		bool operator() (const Joueur* j1, const Joueur* j2){
			return (j1->getNum() < j2->getNum());
		}
	};

	// Fonction
	set<Joueur*, JoueurNum> temp;
	vector<Joueur*>::const_iterator cIt = joueurs_.begin();
	// Tri
	while (cIt != joueurs_.end()){
		temp.insert(*cIt);
		++cIt;
	}
	// Affichage
	set<Joueur*>::const_iterator cIts = temp.begin();
	while (cIts != temp.end()){
		cout << *cIts << endl;
		++cIts;
	}
}

void EquipeHockey::afficherEquipe() const{
	vector<Joueur*>::const_iterator cIt = joueurs_.begin();
	while (cIt != joueurs_.end()){
		cout << *cIt << endl;
		++cIt;
	}
}

void EquipeHockey::incrementerButs(){
	score_++;
}

void EquipeHockey::incrementerVictoires(){
	victoires_++;
}

void EquipeHockey::celebrer() const{
	vector<Joueur*>::const_iterator cIt = joueurs_.begin();
	while (cIt != joueurs_.end()){
		(*cIt)->celebrer();
		++cIt;
	}
}

int EquipeHockey::calculerAttaque() const{
	// Foncteur
	struct FoncteurAttaque{
		double somme_;
		FoncteurAttaque() :somme_(0.0){};
		void operator()(Joueur* joueur){
			somme_ += joueur->getAttaque() * 0.1 * (rand() % 5 + 8);	// rand entre 0.8 et 1.2
		}
	};

	// Foncteur
	FoncteurAttaque foncteurAttaque;
	foncteurAttaque = for_each(joueurs_.begin(), joueurs_.end(), foncteurAttaque);
	return foncteurAttaque.somme_;
}

int EquipeHockey::calculerDefense() const{
	// Foncteur
	struct FoncteurDefense{
		double somme_;
		FoncteurDefense() :somme_(0.0){};
		void operator()(Joueur* joueur){
			somme_ += joueur->getDefense() * 0.1 * (rand() % 5 + 8);	// rand entre 0.8 et 1.2
		}
	};

	// Fonction
	FoncteurDefense foncteurDefense;
	foncteurDefense = for_each(joueurs_.begin(), joueurs_.end(), foncteurDefense);
	return foncteurDefense.somme_;
}

// Getters

string EquipeHockey::getNom() const{
	return nom_;
}

int EquipeHockey::getScore() const{
	return score_;
}
int EquipeHockey::getVictoires() const{
	return victoires_;
}

// Setters

void EquipeHockey::setNom(string nom){
	nom_ = nom;
}

void EquipeHockey::setScore(int score){
	score_ = score;
}
void EquipeHockey::setVictoires(int victoires){
	victoires_ = victoires;
}
