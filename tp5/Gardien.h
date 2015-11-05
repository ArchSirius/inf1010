/************************************************************************************
*	Fichier					: Gardien.h
*	Auteurs					: Benjamin De Leener
*	Description				: Declaration de la classe Gardien
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#ifndef GARDIEN_H_
#define GARDIEN_H_

#include "Joueur.h"
#include <string>
using namespace std;

class Gardien: public Joueur
{
public:
	Gardien();
    Gardien(unsigned int num, string nom, string prenom, unsigned int age, double stabilite, double reflexe);
	~Gardien();

	virtual double getAttaque() const;
    virtual double getDefense() const;
    
    virtual void celebrer() const;
	virtual string getType() const;

private:
	double stabilite_;
	double reflexe_;
};

#endif

