/************************************************************************************
*   Fichier                 : Equipe.h                                              *
*   Auteurs                 : Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*   Description             : Declaration de la classe Equipe                       *
*   Date de creation        : 23 octobre 2014                                       *
*   Date de modification    : 26 octobre 2014                                       *
************************************************************************************/

#ifndef EQUIPE_H
#define EQUIPE_H

#include <vector>
#include "Joueur.h"

using namespace std;

class Equipe
{
public:
	// Constructeur par defaut
	Equipe();
	// Constructeur par copie
	Equipe(const Equipe& eq);
	// Destructeur
	~Equipe();

	/**
	 *	Operateur d'affectation
	 *	\param eq  une equipe a copier
	 *	\return une equipe qui est la copie de l'equipe eq
	 */
	Equipe& operator=(const Equipe& eq);
	
	/**
	 *	Operateur de non-egalite
	 *	\param eq  une equipe B a comparer avec l'equipe A appellante
	 *	\return false si les equipes ne sont pas pareilles; true si oui
	 */
	bool operator!=(const Equipe& eq);

	// Fonctions et methodes
	
	/**
	 *	Ajoute un joueur a l'equipe
	 *	\param individu  le joueur a ajouter a l'equipe
	 *	\return true si le joueur a bien ete ajoute
	 */
	bool ajouterJoueur(Joueur* individu);
	
	/**
	 *	Supprime un joueur de l'equipe
	 /	\param individu  le joueur a supprimer de l'equipe
	 *	\return true si le joueur a bien ete suprime
	 */
	bool supprimerJoueur(Joueur* individu);
	
	/**
	 *	Affiche tous les joueurs de l'equipe
	 */
	void afficherEquipe();

	/**
	 *	Deroulement du jeu
	 * \return true suite a la victoire de l'equipe; false sinon
	 */
	bool jouer();

	/**
	 *	Active la celebration des joueurs de l'equipe
	 */
	void celebrer();

	/**
	 *	Determine si l'equipe est victorieuse
	 *	\return true si oui; false sinon
	 */
	bool victorieuse();
	
	/**
	 *	Retourne le pointage de l'equipe
	 *	\return le pointage de l'equipe
	 */
	int getScore();

	/**
	 *	Operateur "<<" pour afficher l'equipe
	 *	\param os  ostream recevant l'affichage, habituellement cout
	 *	\param eq  l'equipe a afficher
	 *	\return ostream affichage de l'equipe
	 */
	friend ostream& operator<<(ostream& os, const Equipe& eq);

	/**
	 *	Supprime de la memoire les joueurs. N'est pas dans le destructeur car la relation est d'agregation. Utilisee en fin de programme dans notre cas particulier.
	 */
	void killAll();

private:
	/**
	 *	Avance tous les joueurs de l'equipe selon leurs methodes propres
	 */
	void avancer();

	/**
	 *	Recule tous les joueurs de l'equipe selon leurs methodes propres
	 */
	void reculer();

	/**
	 *	Appelle la fonction marquer() des joueurs de l'equipe
	 */
	void marquer();

	// Les joueurs et l'entraineur sont en relation d'agregation
	vector<Joueur*> joueurs_;

	int score_;
	bool victoire_;
};

#endif
