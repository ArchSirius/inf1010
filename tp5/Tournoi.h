//
//  Tournoi.h
//
//  Created by PO on 2014-11-15.
//  Copyright (c) 2014 PO. All rights reserved.
//

#ifndef __Tournoi__h__
#define __Tournoi__h__

#include <map>
#include <list>
#include "Date.h"
#include "Match.h"
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename E>
class Tournoi{
public:
	Tournoi();
	Tournoi(const Tournoi& tournoi);
	~Tournoi();
	
	// Methodes
	bool ajouterEquipe(E* equipe);
	void afficherMatchs();
	void afficherClassementVictoire();
	void afficherClassementBut();
	void simuler();
	
private:
	void attribuerMatchs();
	
	multimap<Date, Match<E>> tournoi_;
	list<E*> liste_;
	Date next_;
	bool isStarted_;
};

// Constructeur par defaut
template <typename E>
Tournoi<E>::Tournoi()
: tournoi_(), liste_(), next_(Date(23, 11, 2014)), isStarted_(false){}		// Supposons today

// Destructeur
template <typename E>
Tournoi<E>::~Tournoi(){}

// Methodes et fonctions

template <typename E>
void Tournoi<E>::attribuerMatchs(){
	// Si le match n'est pas commence
	if (!isStarted_){
		vector<E*> vectorEquipe {begin(liste_), end(liste_)};
		random_shuffle (vectorEquipe.begin(), vectorEquipe.end());
		liste_ = { vectorEquipe.begin(), vectorEquipe.end() };
		isStarted_ = true;
	}
	tournoi_.clear();
	// S'il reste au moins deux equipes
	if(liste_.size() > 1){
		list<E*>::const_iterator cIt = liste_.begin();
		while (cIt != liste_.end()){
			Match<E> match;
			match.setEquipe1(*cIt);
			++cIt;	// On suppose un nombre pair d'equipes
			match.setEquipe2(*cIt);
			match.setDate(next_);
			tournoi_.insert(make_pair(next_, match));
			next_++;	// Date
			
			++cIt;
		}
	}
}

template <typename E>
bool Tournoi<E>::ajouterEquipe(E* equipe){
	list<E*>::iterator cIt = liste_.begin();
	bool existe = false;
	while (cIt != liste_.end() && !existe){
		if (*cIt == equipe){
			existe = true;
		}
		++cIt;
	}
	if (!existe){
		liste_.push_back(equipe);
	}
	return !existe;
}

template <typename E>
void Tournoi<E>::afficherMatchs(){
	multimap<Date, Match<E>>::const_iterator cIt = tournoi_.begin();
	while (cIt != tournoi_.end()){
		cout << (*cIt).second << endl;
		++cIt;
	}
}

template <typename E>
void Tournoi<E>::afficherClassementVictoire(){
	struct comparateur{
		comparateur(){}
		bool operator() (const E* equipe1, const E* equipe2){
			return (equipe1->getVictoires() < equipe1->getVictoires());
		}
	};
	
	multimap<int, E*, comparateur> classement;
	list<E*>::const_iterator cIt = liste_.begin();
	while (cIt != liste_.end()) {
		classement.insert(make_pair((*cIt)->getVictoires(), *cIt));
		++cIt;
	}
	multimap<int, E*>::const_iterator cIts = classement.begin();
	while (cIts != classement.end()){
		cout << (*cIts).first << " : " << ((*cIts).second)->getNom() << endl;
		++cIts;
	}
}

template <typename E>
void Tournoi<E>::afficherClassementBut(){
	struct comparateur{
		comparateur(){}
		bool operator() (const E* equipe1, const E* equipe2){
			return (equipe1->getScore() < equipe1->getScore());
		}
	};
	
	multimap<int, E*, comparateur> classement;
	list<E*>::const_iterator cIt = liste_.begin();
	while (cIt != liste_.end()) {
		classement.insert(make_pair((*cIt)->getScore(), *cIt));
		++cIt;
	}
	multimap<int, E*>::const_iterator cIts = classement.begin();
	while (cIts != classement.end()){
		cout << (*cIts).first << " : " << ((*cIts).second)->getNom() << endl;
		++cIts;
	}
}

template <typename E>
void Tournoi<E>::simuler(){
	multimap<Date, Match<E>>::iterator it = tournoi_.begin();
	//list<E*> listeTournoi {liste_.begin(), liste.end()};	// on copie la liste pour ne pas delete les equipe dans la liste pour le classement
															// pourquoi pas list<E*> listeTournoi = liste_; ?
	list<E*> listeTournoi = liste_;
	
	attribuerMatchs();
	
	// Tant qu'il reste au moins un match à jouer
	while (tournoi_.size() > 0){
		it = tournoi_.begin();
		// Pour chaque match
		while (it != tournoi_.end()){
			(it->second).simuler();
			
			// Si la premiere equipe du match est victorieuse...
			if ( (it->second).estVictorieuse((it->second).getEquipe1()) ) {
				// ... on retire de liste_ la seconde equipe
				liste_.remove((it->second).getEquipe2());
				// Sinon, alors la seconde equipe a gagne...
			} else {
				// ... et on retire de liste_ la premiere equipe
				liste_.remove((it->second).getEquipe1());
			}
			++it;
		}
		// Maintenant que tous les matchs d'un niveau sont joues, on reattribue
		// les equipes gagnantes a leurs nouveaux matchs...
		attribuerMatchs();
		// ... et on recommence a simuler un palier sauf si c'etait la finale
	}
	// A ce moment, liste_ ne contient qu'une equipe: la gagnante
	cout << "L'equipe gagnante est : " << (*(liste_.begin()))->getNom() << endl;
}


#endif