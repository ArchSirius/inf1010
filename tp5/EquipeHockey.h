/*******************************************************************************
*	Fichier					: EquipeHockey.h                                   *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford *
*	Description				: Declaration de la classe EquipeHockey            *
*	Date de creation		: 6 novembre 2014                                  *
*	Date de modification	: 23 novembre 2014                                 *
*******************************************************************************/

#ifndef EQUIPEHOCKEY_
#define EQUIPEHOCKEY_

#include <string>
#include <vector>
#include "Joueur.h"
using namespace std;

class EquipeHockey{
public:
	// Constructeur par défaut
	EquipeHockey();
	// Constructeur par paramètres
	EquipeHockey(string nom);
	// Constructeur par copie
	EquipeHockey(const EquipeHockey& eq1);
	// Destructeur
	~EquipeHockey();

	/*
	*  Operateur d'affectation (shallow-copy)
	*  \param	eq1		une equipe a copier
	*  \return	une equipe qui est la copie de l'equipe eq
	*/
	EquipeHockey& operator=(const EquipeHockey& eq1);

	// Méthodes et fonctions

	/*
	*  Ajoute un joueur a l'equipe
	*  \param	joueur		le joueur a ajouter a l'equipe
	*  \return	true si le joueur a bien ete ajoute; false sinon
	*/
	bool ajouterJoueur(Joueur& joueur);

	/*
	*  Supprime un joueur de l'equipe
	*  \param	nom		le nom du joueur a supprimer de l'equipe
	*  \param	prenom	le prenom du joueur a supprimer de l'equipe
	*  \return	true si le joueur a bien ete supprime; false sinon
	*/
	bool supprimerJoueur(string nom, string prenom);

	/*
	*  Affiche les joueurs de l'equipe en ordre alphabetique
	*/
	void afficherJoueursAlpha() const;

	/*
	*  Affiche les joueurs de l'equipe en ordre numerique
	*/
	void afficherJoueursNum() const;

	/*
	*  Affiche les joueurs de l'equipe en ordre d'insertion
	*/
	void afficherEquipe() const;

	/*
	*  Incremente le nombre de buts marques par une equipe
	*/
	void incrementerButs();

	/*
	*  Incremente le nombre de victoires d'une equipe
	*/
	void incrementerVictoires();

	/*
	*  Active la celebration des joueurs de l'equipe
	*/
	void celebrer() const;

	/*
	*  Calcule la puissance d'attaque de l'equipe
	*  \return	attaque cumulative
	*/
	int calculerAttaque() const;

	/*
	*  Calcule la puissance de defense de l'equipe
	*  \return	defense cumulative
	*/
	int calculerDefense() const;

	// Getters

	/*
	*  Retourne le nom de l'equipe
	*  \return	le nom de l'equipe
	*/
	string getNom() const;

	/*
	*  Retourne le pointage de l'equipe
	*  \return	le pointage de l'equipe
	*/
	int getScore() const;

	/*
	*  Retourne les victoires de l'equipe
	*  \return	les victoires de l'equipe
	*/
	int getVictoires() const;

	// Setters

	/*
	*  Modifie le nom de l'equipe
	*  \param	nom		le nom de l'equipe
	*/
	void setNom(string nom);

	/*
	*  Modifie le pointage de l'equipe
	*  \param	score	le pointage de l'equipe
	*/
	void setScore(int score);

	/*
	*  Modifie les victoires de l'equipe
	*  \param	victoires	les victoires de l'equipe
	*/
	void setVictoires(int victoires);

private:
	vector<Joueur*> joueurs_;
	string nom_;
	int score_;
	int victoires_;
};

#endif
