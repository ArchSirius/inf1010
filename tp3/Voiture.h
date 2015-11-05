/************************************************************************************
* Fichier               : Voiture.h                                                 *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Voiture                                                   *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include <string>
#include "Moteur.h"
#include "Roue.h"
#include "Piece.h"

using namespace std;

class Voiture {
public:

	// Constructeur par paramètre
	Voiture(string, int, Moteur, Roue*, Roue*, Roue*, Roue*);

	// Destructeur
	~Voiture();

	// Fonctions

	/**
	* Affiche les informations de la voiture
	*/
	void afficherInformationVoiture() const;

	/**
	* Calcule la vitesse de la voiture
	* \return vitesse
	*/
	int calculerVitesseVoiture();

	/**
	* Calcule le coût de la voiture
	* \return coût
	*/
	int calculerCoutVoiture();

	// Getters

	/** 
	* Accesseur marque
	* \return marque de la voiture
	*/
	string getMarque() const; 

	/** 
	* Accesseur prix
	* \return prix de la voiture
	*/
	int getPrix() const;

	/** 
	* Accesseur moteur
	* \return Moteur de la voiture
	*/
	Moteur getMoteur() const;

	/** 
	* Accesseur roue[]
	* \return tableau de roues de la voiture
	*/
	Roue* getRoue() const;

	//Setters

	/**
	* Modificateur marque
	* \param marque marque de la voiture
	*/
	void setMarque(string marque);

	/**
	* Modificateur prix
	* \param prix prix de la voiture
	*/
	void setPrix(int prix);

	/**
	* Modificateur moteur
	* \param Moteur le moteur de la voiture
	*/
	void setMoteur(Moteur moteur);

	/**
	* Modificateur roue[]
	* \param *roue[] tableau de roues de la voiture
	*/
	void setRoues(Roue *roue[]);

	/**
	* Modificateur roue[x]
	* \param i la ième roue
	* \param roue* une roue à changer
	*/
	void setRoues(int i, Roue* roue);

private:
	string marque_;
	int prix_;
	Moteur moteur_;
	Roue* roues_[4]; 
};

#endif