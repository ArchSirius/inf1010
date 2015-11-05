/************************************************************************************
* Fichier				: Date.h                                                    *
* Auteurs				: Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description			: Date en format mm/jj/aaaa                                 *
* Date de creation		: 11 septembre 2014                                         *
* Date de modification	: 18 septembre 2014                                         *
************************************************************************************/

#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using namespace std;

class Date
{
public:
	// Constructeur par défaut
	Date();
	// Constructeur par paramètre
	Date(unsigned int jour, unsigned int mois, unsigned int annee);
	// Destructeur (par défaut)
	~Date();

	// GETTERS
	unsigned int getJour() const;
	unsigned int getMois() const;
	unsigned int getAnnee() const;

	// SETTERS
	void setJour(unsigned int jour);
	void setMois(unsigned int mois);
	void setAnnee(unsigned int annee);

	/** Affiche la date au format jour/mois/annee
	*   
	*/
	void afficherDate() const ;

// Variables privées
private:
	unsigned int jour_, mois_, annee_;
};

#endif // DATE_H_
