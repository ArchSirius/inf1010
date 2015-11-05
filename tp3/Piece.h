/************************************************************************************
* Fichier               : Piece.h                                                   *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Pi�ce automobile                                          *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

class Piece {
public:
	// Constructeur par d�faut
	Piece();

	// Constructeur par param�tres
	Piece(string, string, int, int);

	// Destructeur
	~Piece();

	// Fonctions

	/**
	* Affiche les informations de la pi�ce
	*/
	void afficherInformations() const;

	// Getters

	/**
	* Accesseur manufacturier
	* \return manifacturier de la piece
	*/
	string getManufacturier() const;

	/**
	* Accesseur description
	* \return description de la piece
	*/
	string getDescription() const;

	/**
	* Accesseur prix
	* \return prix de la piece
	*/
	int getPrix() const;

	/**
	* Accesseur anneeFabrication
	* \return ann�e de fabrication de la piece
	*/
	int getAnneeFabrication() const;

	// Setters

	/**
	* Modificateur manufacturier
	* \param manufacturier nom du manifacturier
	*/
	void setManufacturier(string manufacturier);

	/**
	* Modificateur description
	* \param description description de la piece
	*/
	void setDescription(string description);

	/**
	* Modificateur prix
	* \param prix prix de la pi�ce
	*/
	void setPrix(int prix);

	/**
	* Modificateur anneeFabrication
	* \param anneeFabrication ann�e de fabrication
	*/
	void setAnneeFabrication(int anneeFabrication);

protected:
	string manufacturier_;
	string description_;
	int prix_;
	int anneeFabrication_;
};
#endif