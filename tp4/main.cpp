/************************************************************************************
*	Fichier					: main.cpp                                              *
*	Auteurs					: Samuel Rondeau & Pierre-Olivier Guimond-Cataford      *
*	Description				: Simulation d'une equipe de Hockey sur glace           *
*	Date de creation		: 23 octobre 2014                                       *
*	Date de modification	: 26 octobre 2014                                       *
************************************************************************************/

/************************************************************************************
*	Question: Imaginons que l�on veuille impl�menter une classe JoueurSpecial       *
*	qui h�riterait � la fois de la classe Attaquant et de la classe Defenseur.      *
*	Quel est le probl�me potentiel? Expliquer en d�tail et donnez un exemple.       *
*                                                                                   *
*	Il y aurait des conflits, notamment � cause des fonctions c�l�brer(), avancer() *
*	et reculer(), qui sont diff�rentes dans les classes Attaquant et Defenseur.     *
*	Quoi h�riter? Tel est le probl�me. Le compilateur ne sait pas laquelle des deux *
*	JoueurSpecial doit h�riter, et ne peut les fusionner non plus.                  *
************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Equipe.h"
#include "Attaquant.h"
#include "Defenseur.h"
#include "Gardien.h"

using namespace std;

int main() {

	// Creation d'une equipe de hockey vide
	Equipe equipe;

	// Inserer deux defenseurs, trois attaquants et un gardien dans l'equipe en initialisant leurs positions � 0
	equipe.ajouterJoueur(new Defenseur("Defendos", "Mister", 29, 0));
	equipe.ajouterJoueur(new Defenseur("Puel", "Senor", 47, 0));
	equipe.ajouterJoueur(new Attaquant("Arrache-dents", "Frappeur", 26, 0));
	equipe.ajouterJoueur(new Attaquant("Commotionneur", "Gentil", 28, 0));
	equipe.ajouterJoueur(new Attaquant("Mechant", "Maitre", 32, 0));
	equipe.ajouterJoueur(new Gardien("Petropoulos", "Pedro", 33, 0));

	// Afficher l'ensemble de l'equipe
	cout << endl << "==============================================" << endl;
	cout << "Presentation de l'equipe :" << endl << endl;
	equipe.afficherEquipe();

	// Lancer le jeu de l'equipe
	cout << endl << "==============================================" << endl;
	cout << "Le match debute" << endl << endl;
	equipe.jouer();

	// Si l'equipe a gagne, celebrez la victoire
	if (equipe.victorieuse()) equipe.celebrer();

	equipe.killAll();

	return 0;
}