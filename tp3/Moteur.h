/************************************************************************************
* Fichier               : Piece.h                                                   *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Moteur                                                    *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#ifndef MOTEUR_H
#define MOTEUR_H

#include <string>
#include "Piece.h"
using namespace std;

class Moteur : public Piece {
public:
	// Constructeur par défaut
	Moteur();
	// Constructeur par paramètres
	Moteur(string, string, int, int, int, int);
	// Destructeur
	~Moteur();

	// Fonctions

	/**
	* Calcule la puissance du moteur
	* \return puissance du moteur
	*/
	double calculerPuissance() const;

	/**
	* Affiche les information du moteur
	*/
	void afficherInformations() const;

	// Getters

	/**
	* Accesseur chevauxVapeurs
	* \return nombre de chevaux vapeurs
	*/
	int getChevauxVapeurs() const;

	/**
	* Accesseur kilometrage
	* \return kilometrage du moteur
	*/
	int getKilometrage() const;
	
	// Setters

	/**
	* Modificateur chevauxVapeur
	* \param chevauxVapeurs nombre de chevaux vapeurs
	*/
	void setChevauxVapeurs(int chevauxVapeurs);

	/**
	* Modificateur kilometrage_
	* \param kilometrage nombre de kilomètres
	*/
	void setKilometrage(int kilometrage);

private:
	int chevauxVapeurs_;
	int kilometrage_;
};
#endif