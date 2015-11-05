/************************************************************************************
* Fichier               : Liste.cpp                                                 *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Liste contenant un vecteur de strings                     *
* Date de creation      : 22 septembre 2014                                         *
* Date de modification  : 28 septembre 2014                                         *
************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Liste.h"
using namespace std;

Liste::Liste() :listeInterne_(0){
	titre_ = "Titre";
};

Liste::Liste(string titre) :listeInterne_(0){
	titre_ = titre;
};

Liste::Liste(Liste& liste) :listeInterne_(0){
	titre_ = liste.getTitre();
	listeInterne_ = liste.listeInterne_;
};

Liste::~Liste(){};

Liste& Liste::operator= (Liste& rhs){
	if (*this != rhs){
		listeInterne_ = rhs.listeInterne_;
		titre_ = rhs.titre_;
	}
	return *this;
};

Liste Liste::operator+ (string ligne){
	Liste temp = *this;
	temp.listeInterne_.push_back(ligne);
	return temp;
};

Liste Liste::operator+ (Liste autreListe){
	Liste temp = *this;
	for (unsigned int i = 0; i < autreListe.getTaille(); i++){
		temp.listeInterne_.push_back(autreListe.listeInterne_[i]);
	}
	return temp;
};

Liste Liste::operator- (string ligne){
	Liste temp = *this;
	for (unsigned int i = 0; i < getTaille(); i++){
		if (temp.listeInterne_[i] == ligne){
			temp.listeInterne_.erase(listeInterne_.begin() + i);
			i--;
		}
	}
	return temp;
};

void Liste::operator+= (string ligne){
	listeInterne_.push_back(ligne);
};

void Liste::operator+= (Liste autreListe){
	for (unsigned int i = 0; i < autreListe.getTaille(); i++){
		listeInterne_.push_back(autreListe.listeInterne_[i]);
	}
};

void Liste::operator-= (string ligne){
	for (unsigned int i = 0; i < getTaille(); i++){
		if (listeInterne_[i] == ligne){
			listeInterne_.erase(listeInterne_.begin() + i);
			i--;
		}
	}
};

bool Liste::operator== (Liste autreListe) const{
	return listeInterne_ == autreListe.listeInterne_;
};

bool Liste::operator!= (Liste autreListe) const{
	return listeInterne_ != autreListe.listeInterne_;
};

string Liste::getTitre() const{
	return titre_;
};

size_t Liste::getTaille() const{
	return listeInterne_.size();
};

string Liste::acceder(int position) const{
	return listeInterne_[position];
};

ostream& operator<< (ostream& os, Liste liste){
	os << "====================" << endl;
	for (unsigned int i = 0; i < liste.getTaille(); i++){
		os << liste.listeInterne_[i] << endl;
	}
	cout << endl;
	return os;
};

istream& operator>> (istream& is, Liste& liste){
	string temp;
	is >> temp;
	liste.listeInterne_.push_back(temp);
	return is;
};