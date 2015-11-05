/************************************************************************************
*	Fichier					: Attaquant.h                                           *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Declaration de la classe Attaquant                    *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

#ifndef ATTAQUANT_H
#define ATTAQUANT_H

#include <string>
#include "Joueur.h"
using namespace std;

class Attaquant : public Joueur
{
public:
	// Constructeur par defaut
	Attaquant();
	// Constructeur par parametres sans position
	Attaquant(string nom, string prenom, unsigned int age);
	// Constructeur par parametres avec position
	Attaquant(string nom, string prenom, unsigned int age, int position);
	// Destructeur
	~Attaquant();

	/**
	 *	Affiche la celebration de l'Attaquant
	 */
	virtual void celebrer() const;

	/**
	 *	Avance l'Attaquant d'une distance de 5
	 */
	virtual void avancer();

	/**
	 *	Recule l'Attaquant d'une distance de 3
	 */
	virtual void reculer();

	/**
	 *	Retourne le type du joueur
	 *	\return type du joueur (Attaquant)
	 */
	virtual string getType() const;
};

#endif
