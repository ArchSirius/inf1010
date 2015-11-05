/************************************************************************************
*	Fichier					: Defenseur.h
*	Auteurs					: Benjamin De Leener
*	Description				: Declaration de la classe Defenseur
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#ifndef DEFENSEUR_H_
#define DEFENSEUR_H_

#include "Joueur.h"
#include <string>
using namespace std;

class Defenseur: public Joueur
{
public:
	Defenseur();
    Defenseur(unsigned int num, string nom, string prenom, unsigned int age, double reactivite, double vision);
	~Defenseur();

	virtual double getAttaque() const;
    virtual double getDefense() const;
    
    virtual void celebrer() const;
    virtual string getType() const;

private:
	double reactivite_;
	double vision_;
};

#endif


