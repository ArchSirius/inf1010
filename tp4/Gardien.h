/************************************************************************************
*	Fichier					: Gardien.h                                             *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Declaration de la classe Gardien                      *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

#ifndef GARDIEN_H
#define GARDIEN_H

#include <string>
#include "Joueur.h"
using namespace std;

class Gardien : public Joueur
{
public:
	// Constructeur par defaut
	Gardien();
	// Constructeur par parametres sans position
	Gardien(string nom, string prenom, unsigned int age);
	// Constructeur par parametres avec position
	Gardien(string nom, string prenom, unsigned int age, int position);
	// Destructeur
	~Gardien();

	/**
	 *	Affiche la celebration du Gardien
	 */
	virtual void celebrer() const;

	/**
	 *	Avance le Gardien d'une distance de 1
	 */
	virtual void avancer();

	/**
	 *	Recule le Gardien d'une distance de 1
	 */
	virtual void reculer();

	/**
	 *	Retourne le type du joueur
	 * \return type du joueur (Gardien)
	 */
	virtual string getType() const;
};

#endif
