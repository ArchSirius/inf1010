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
	// Constructeur par d�faut
	Liste();
	// Constructeur par param�tre
	Liste(string titre);
	// Constructeur par copie
	Liste(Liste& liste);
	// Destructeur
	~Liste();

	/**
	* Surcharge de l'op�reteur =
	* Copie une liste
	* \param  rhs �l�ment de droite � copier
	* \return �l�ment copi�
	*/
	Liste& operator= (Liste& rhs);

	/**
	* Surcharge de l'op�reteur + (Liste + string)
	* Ajoute un string � une liste
	* \param  ligne string de droite � ajouter � la liste
	* \return liste r�sultante
	*/
	Liste operator+ (string ligne);

	/**
	* Surcharge de l'op�reteur + (Liste + Liste)
	* Ajoute une liste � une liste
	* \param  autreListe Liste de droite � ajouter � la liste
	* \return liste r�sultante
	*/
	Liste operator+ (Liste autreListe);

	/**
	* Surcharge de l'op�reteur -
	* Retire un string d'une liste
	* \param  ligne string de droite � retirer de la liste
	* \return liste r�sultante
	*/
	Liste operator- (string ligne);

	/**
	* Surcharge de l'op�reteur += (Liste+= string)
	* Ajoute un string � une liste automatiquement
	* \param  ligne string de droite � ajouter � la liste
	*/
	void operator+= (string ligne);

	/**
	* Surcharge de l'op�reteur += (Liste+= Liste)
	* Ajoute une liste � une liste automatiquement
	* \param  autreListe Liste de droite � ajouter � la liste
	*/
	void operator+= (Liste autreListe);

	/**
	* Surcharge de l'op�reteur -=
	* Retire un string � une liste automatiquement
	* \param  ligne string de droite � retirer de la liste
	*/
	void operator-= (string ligne);

	/**
	* Surcharge de l'op�reteur ==
	* D�termine si deux objets Liste ont le m�me vecteur
	* \param  autreListe liste de droite � comparer
	* \return true si �gales; false sinon
	*/
	bool operator== (Liste autreListe) const;

	/**
	* Surcharge de l'op�reteur !=
	* D�termine si deux objets Liste sont diff�rents
	* \param  autreListe liste de droite � comparer
	* \return true si diff�rents; false sinon
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
	* Surcharge de l'op�reteur <<
	* Permet l'affichage de la liste
	* \param  os   stream de sortie
	* \param liste la liste � envoyer dans os
	* \return la liste format�e � entrer dans os
	*/
	friend ostream& operator<< (ostream& os, Liste liste);

	/**
	* Surcharge de l'op�reteur >>
	* Ajoute une entr�e utilisateur dans la liste
	* \param  is   stream d'entr�e
	* \param liste la liste qui recevoit l'entr�e
	* \return l'Entr�e
	*/
	friend istream& operator>> (istream& is, Liste& liste);

private:
	string titre_;
	vector<string> listeInterne_;
};

#endif