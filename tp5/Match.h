/*******************************************************************************
*	Fichier					: Match.h                                          *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford *
*	Description				: Declaration de la classe Match                   *
*	Date de creation		: 6 novembre 2014                                  *
*	Date de modification	: 23 novembre 2014                                 *
*******************************************************************************/

#ifndef MATCH_
#define MATCH_

#include "Date.h"
#include "EquipeHockey.h"
#include <stdio.h>
#include <ostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <typename E>
class Match{
public:
	// Constructeur par defaut
	Match();
	// Constructeur par parametres
	Match(const Date& date, E* e1_, E* e2_);
	// Constructeur par copie
	Match(const Match& match);
	// Destructeur
	~Match();

	/*
	*  Operateur d'affectation (shallow-copy)
	*  \param	match	un match a copier
	*  \return	un match qui est la copie du Match match
	*/
	Match<E>& operator= (const Match& match);

	// Getters

	/*
	*  Retourne la date du match
	*  \return	la date du match
	*/
	Date& getDate() const;

	/*
	*  Retourne la premiere equipe
	*  \return	la premiere equipe
	*/
	E* getEquipe1() const;

	/*
	*  Retourne la seconde equipe
	*  \return	la seconde equipe
	*/
	E* getEquipe2() const;

	/*
	*  Retourne le pointage de la premiere equipe
	*  \return	le pointage de la premiere equipe
	*/
	int getScoreEquipe1() const;

	/*
	*  Retourne le pointage de la seconde equipe
	*  \return	le pointage de la seconde equipe
	*/
	int getScoreEquipe2() const;

	// Setters

	/*
	*  Modifie la date du match
	*  \param	date	la date du match
	*/
	void setDate(const Date& date);

	/*
	*  Modifie la premiere equipe
	*  \param	e	la premiere equipe
	*/
	void setEquipe1(const E& e);

	/*
	*  Modifie la seconde equipe
	*  \param	e	la seconde equipe
	*/
	void setEquipe2(const E& e);

	/*
	*  Modifie le pointage de la premiere equipe
	*  \param	score	le pointage de la premiere equipe
	*/
	void setScore1(const int score);

	/*
	*  Modifie le pointage de la seconde equipe
	*  \param	score	le pointage de la seconde equipe
	*/
	void setScore2(const int score);

	// Methodes et fonctions

	/*
	*  Operateur << pour afficher les details du match
	*  \param	os	ostream recevant/affichant les informations
	*  \return	os	ostream contenant les informations
	*/
	friend ostream& operator<< (ostream& os, const Match& match);

	/*
	*  Détermine si une equipe e gagne le match
	*  \param	e	equipe a verifier si elle gagne
	*  \return	true si e gagne; false sinon
	*/
	bool estVictorieuse(const E* e) const;

	/*
	*  Simule le deroulement d'un match
	*/
	void simuler();

private:
	Date date_;
	E* e1_, e2_;
	int score1_, score2_;
};

#endif
