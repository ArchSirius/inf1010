/************************************************************************************
*	Fichier					: Attaquant.h
*	Auteurs					: Benjamin De Leener
*	Description				: Declaration de la classe Attaquant
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#ifndef ATTAQUANT_
#define ATTAQUANT_

#include "Joueur.h"
#include <string>
using namespace std;

class Attaquant: public Joueur
{
public:
	Attaquant();
    Attaquant(unsigned int num, string nom, string prenom, unsigned int age, double vitesse, double agilite, double precision);
	~Attaquant();
    
    virtual double getAttaque() const;
    virtual double getDefense() const;

	virtual void celebrer() const;
	virtual string getType() const;

private:
	double vitesse_;
	double agilite_;
	double precision_;
};

#endif
