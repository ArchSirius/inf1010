/************************************************************************************
*	Fichier					: Joueur.h                                              *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Declaration de la classe Joueur                       *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

class Joueur
{
public:
	// Constructeur par defaut
	Joueur();
	// Constructeur par parametres sans position
	Joueur(string nom, string prenom, unsigned int age);
	// Constructeur par parametres avec position
	Joueur(string nom, string prenom, unsigned int age, int position);
	// Destructeur
	virtual ~Joueur();
	
	/**
	 *	Operateur de comparaison pour comparer le nom, le prenom et l'age
	 *	\param individu  un joueur B à comparer avec A appellant
	 *	\return true si le joueur est identique a celui en parametre; false sinon
	 */
	bool operator==(const Joueur& individu) const;

	// Setters
	void setNom(string nom);
	void setPrenom(string prenom);
	void setAge(unsigned int age);

	// Getters
	string getNom() const;
	string getPrenom() const;
	unsigned int getAge() const;

	/**
	 *	Operateur "<<" pour afficher le joueur
	 *	\param os        ostream recevant l'affichage, habituellement cout
	 *	\param individu  le joueur a afficher
	 *	\return ostream affichage du joueur
	 */
	friend ostream& operator<<(ostream& os, const Joueur& individu);

	// Fonctions et methodes
	
	/**
	 *	Affiche la celebration du joueur
	 */
	virtual void celebrer() const = 0;
	
	/**
	 *	Avance le joueur d'une distance associee a son type
	 */
	virtual void avancer();
	
	/**
	 *	Recule le joueur d'une distance associe a son type
	 */
	virtual void reculer();
	
	/**
	 *	Le joueur tente de marquer un but
	 * \return true si le joueur a compter un but; false sinon
	 */
	bool marquer() const;

	/**
	 *	Retourne le type du joueur
	 *	\return type du joueur (Attaquant, Defenseur, Gardien)
	 */
	virtual string getType() const = 0;

protected:
	string nom_;
	string prenom_;
	unsigned int age_;
	int position_;
};

#endif
