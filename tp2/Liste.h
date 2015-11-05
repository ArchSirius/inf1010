/************************************************************************************
* Fichier               : Liste.h                                                   *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Liste contenant un vecteur de strings                     *
* Date de creation      : 22 septembre 2014                                         *
* Date de modification  : 28 septembre 2014                                         *
************************************************************************************/

#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Liste {
public:
	// Constructeur par défaut
	Liste();
	// Constructeur par paramètre
	Liste(string titre);
	// Constructeur par copie
	Liste(Liste& liste);
	// Destructeur
	~Liste();

	/**
	* Surcharge de l'opéreteur =
	* Copie une liste
	* \param  rhs élément de droite à copier
	* \return élément copié
	*/
	Liste& operator= (Liste& rhs);

	/**
	* Surcharge de l'opéreteur + (Liste + string)
	* Ajoute un string à une liste
	* \param  ligne string de droite à ajouter à la liste
	* \return liste résultante
	*/
	Liste operator+ (string ligne);

	/**
	* Surcharge de l'opéreteur + (Liste + Liste)
	* Ajoute une liste à une liste
	* \param  autreListe Liste de droite à ajouter à la liste
	* \return liste résultante
	*/
	Liste operator+ (Liste autreListe);

	/**
	* Surcharge de l'opéreteur -
	* Retire un string d'une liste
	* \param  ligne string de droite à retirer de la liste
	* \return liste résultante
	*/
	Liste operator- (string ligne);

	/**
	* Surcharge de l'opéreteur += (Liste+= string)
	* Ajoute un string à une liste automatiquement
	* \param  ligne string de droite à ajouter à la liste
	*/
	void operator+= (string ligne);

	/**
	* Surcharge de l'opéreteur += (Liste+= Liste)
	* Ajoute une liste à une liste automatiquement
	* \param  autreListe Liste de droite à ajouter à la liste
	*/
	void operator+= (Liste autreListe);

	/**
	* Surcharge de l'opéreteur -=
	* Retire un string à une liste automatiquement
	* \param  ligne string de droite à retirer de la liste
	*/
	void operator-= (string ligne);

	/**
	* Surcharge de l'opéreteur ==
	* Détermine si deux objets Liste ont le même vecteur
	* \param  autreListe liste de droite à comparer
	* \return true si égales; false sinon
	*/
	bool operator== (Liste autreListe) const;

	/**
	* Surcharge de l'opéreteur !=
	* Détermine si deux objets Liste sont différents
	* \param  autreListe liste de droite à comparer
	* \return true si différents; false sinon
	*/
	bool operator!= (Liste autreListe) const;

	/**
	* Retourne le titre de la Liste
	* \return titre_
	*/
	string getTitre() const;

	/**
	* Retourne la taille du vecteur listeInterne_
	* \return listeInterne_.size()
	*/
	size_t getTaille() const;

	/**
	* Retourne le contenu d'une certaine position du vecteur
	* \param  position position
	* \return contenu de listeInterne_[position]
	*/
	string acceder(int position) const;

	/**
	* Surcharge de l'opéreteur <<
	* Permet l'affichage de la liste
	* \param  os   stream de sortie
	* \param liste la liste à envoyer dans os
	* \return la liste formatée à entrer dans os
	*/
	friend ostream& operator<< (ostream& os, Liste liste);

	/**
	* Surcharge de l'opéreteur >>
	* Ajoute une entrée utilisateur dans la liste
	* \param  is   stream d'entrée
	* \param liste la liste qui recevoit l'entrée
	* \return l'Entrée
	*/
	friend istream& operator>> (istream& is, Liste& liste);

private:
	string titre_;
	vector<string> listeInterne_;
};

#endif