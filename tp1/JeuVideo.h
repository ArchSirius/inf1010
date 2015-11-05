/************************************************************************************
* Fichier               : JeuVideo.h                                                *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Objet jeu video                                           *
* Date de creation      : 11 septembre 2014                                         *
* Date de modification  : 21 septembre 2014                                         *
************************************************************************************/

#ifndef JEUVIDEO_H_
#define JEUVIDEO_H_

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class JeuVideo
{
public:
	// Constructeur par défaut
	JeuVideo();
	// Constructeur par paramètre
	JeuVideo(string titre, Date dateSortie, string nomEditeur, string genre, string plateforme,string description, double evaluation);
	// Destructeur (par défaut)
	~JeuVideo();

	// GETTERS
	string JeuVideo::getTitre() const;
	Date JeuVideo::getDateSortie() const;
	string getNomEditeur() const;
	string getGenre() const;
	string getPlateforme() const;
	string getDescription() const;
	double getEvaluation() const;

	// SETTERS
	void setTitre(string titre);
	void setDateSortie(Date dateSortie);
	void setNomEditeur(string nomEditeur);
	void setGenre(string genre);
	void setPlateforme(string plateforme);
	void setDescription(string description);
	void setEvaluation(double evaluation);

	/** Affiche les details d'un jeu
	*   
	*/
	void afficherJeu() const;

// Variables privées
private:
	string titre_;
	Date dateSortie_;
	string nomEditeur_;
	string genre_;
	string plateforme_;
	string description_;
	double evaluation_;
};

#endif // JEUVIDEO_H_
