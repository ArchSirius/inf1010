/************************************************************************************
* Fichier				: Editeur.h                                                 *
* Auteurs				: Benjamin De Leener                                        *
* Description			: Definition de la classe Editeur                           *
* Date de creation		: 11 septembre 2014                                         *
* Date de modification	: 21 septembre 2014                                         *
************************************************************************************/

/*  Les normes demandees dans cette classe ne respectent pas le guide de codage point #3
 *  Les autres classes sans contraintes n'utiliseront donc pas les contraintes de celle-ci
 */


#ifndef EDITEUR_H_
#define EDITEUR_H_

#include <iostream>
#include <string>
#include "Date.h"
#include "JeuVideo.h"

using namespace std;

//const short NB_MAX_JEUX = 10;

class Editeur
{
public:
	Editeur();
	Editeur(string nom, Date date_creation, string site_web);
	~Editeur();

	string getNom() const;
	Date getDateCreation() const;
	string getSiteWeb() const;

	void setNom(string nom);
	void setDateCreation(Date date_creation);
	void setSiteWeb(string site_web);

	unsigned int getNombreJeux() const;

	bool ajouterJeu(const JeuVideo& jeu);

	void afficherJeux() const;
	void afficherEditeur() const;

private:
	string nom_;
	Date date_creation_;
	string site_web_;

	JeuVideo* liste_jeux_;
	unsigned int nombre_jeux_;
};

#endif // EDITEUR_H_
