/************************************************************************************
* Fichier               : Roue.h                                                    *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Roue                                                      *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#ifndef ROUE_H
#define ROUE_H

#include <string>
#include "Piece.h"
using namespace std;

class Roue : public Piece {
public:
	// Constructeur par défaut
	Roue();

	// Constructeur par paramètres
	Roue(string, string, int, int, int);

	// Destructeur
	~Roue();

	// Fonctions

	/**
	* Calcule la vraie vitesse de la roue
	* \return vitesse
	*/
	int calculerVraieVitesse() const;

	/**
	* Affiche les informations de la roue
	*/
	void afficherInformations() const;

	// Getters

	/**
	* Accesseur vitesse
	* \return vitesse
	*/
	int getVitesse() const;

	// Setters

	/**
	* Modificateur vitesse
	* \param vitesse la vitesse normale
	*/
	void setVitesse(int vitesse);

protected:
	int vitesse_;
};
#endif