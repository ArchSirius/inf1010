/************************************************************************************
*	Fichier					: Defenseur.h                                           *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Declaration de la classe Defenseur                    *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include <string>
#include "Joueur.h"
using namespace std;

class Defenseur : public Joueur
{
public:
	// Constructeur par defaut
	Defenseur();
	// Constructeur par parametres sans position
	Defenseur(string nom, string prenom, unsigned int age);
	// Constructeur par parametres avec position
	Defenseur(string nom, string prenom, unsigned int age, int position);
	// Destructeur
	~Defenseur();

	/**
	 *	Affiche la celebration du Defenseur
	 */
	virtual void celebrer() const;

	/**
	 *	Avance le Defenseur d'une distance de 2
	 */
	virtual void avancer();

	/**
	 *	Recule le Defenseur d'une distance de 2
	 */
	virtual void reculer();

	/**
	 *	Retourne le type du joueur
	 *	\return type du joueur (Defenseur)
	 */
	virtual string getType() const;
};

#endif
