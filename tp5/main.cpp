/************************************************************************************
 *	Fichier					: main.cpp
 *	Auteurs					: Benjamin De Leener
 *	Description				: Simulation d'un tournoi de Hockey sur glace
 *	Date de creation		: 24 octobre 2014
 *	Date de modification	:
 ************************************************************************************/

#include <iostream>
#include <time.h>
#include <vector>

#include "Attaquant.h"
#include "Defenseur.h"
#include "Gardien.h"
#include "Joueur.h"
#include "EquipeHockey.h"
#include "Tournoi.h"


using namespace std;

int main(int argc, const char * argv[])
{
	
	srand((unsigned)time(NULL)); // Cette ligne permet d'initialiser le generateur de nombre aleatoire
	
	// Creer quatre (ou huit) equipes de hockey avec differents joueurs.
	
	Joueur* attaquants[12];
	attaquants[0] = new Attaquant(99, "Minautore", "Terre", 32, 87, 78, 80);
	attaquants[1] = new Attaquant(48, "Ive", "Explos", 21, 77, 76, 87);
	attaquants[2] = new Attaquant(96, "Cule", "Mole", 30, 76, 77, 85);
	attaquants[3] = new Attaquant(59, "Cope", "Robo", 50, 90, 88, 87);
	attaquants[4] = new Attaquant(35, "Baumier", "Sapin", 40, 88, 75, 81);
	attaquants[5] = new Attaquant(14, "Tamononc", "Laboi", 32, 87, 78, 80);
	attaquants[6] = new Attaquant(66, "Erfroid", "Bie", 32, 87, 78, 80);
	attaquants[7] = new Attaquant(74, "Re", "Enfoit", 32, 87, 78, 80);
	attaquants[8] = new Attaquant(52, "Toshe", "Macin", 32, 87, 78, 80);
	attaquants[9] = new Attaquant(85, "Rosoft", "Mic", 32, 87, 78, 80);
	attaquants[10] = new Attaquant(11, "Ion", "Cam", 32, 87, 78, 80);
	attaquants[11] = new Attaquant(40, "Ora", "Fed", 32, 87, 78, 80);
	
	Joueur* defenseur[8];
	defenseur[0] = new Defenseur(42, "Shop", "Future", 32, 88, 87.0);
	defenseur[1] = new Defenseur(11, "Buy", "Best", 32, 88, 87.0);
	defenseur[2] = new Defenseur(15, "Ore", "Mete", 32, 88, 87.0);
	defenseur[3] = new Defenseur(18, "Obus", "Aut", 32, 88, 87.0);
	defenseur[4] = new Defenseur(84, "Demarde", "Criss", 32, 88, 87.0);
	defenseur[5] = new Defenseur(52, "Cool", "Pas", 32, 88, 87.0);
	defenseur[6] = new Defenseur(74, "Lation", "Compi", 32, 88, 87.0);
	defenseur[7] = new Defenseur(07, "I", "Etat", 32, 88, 87.0);
	
	Joueur* gardiens[4];
	gardiens[0] = new Gardien(24, "Turco", "Echangeur", 32, 88, 87.0);
	gardiens[1] = new Gardien(35, "Politaine", "Metro", 32, 88, 87.0);
	gardiens[2] = new Gardien(36, "Gne", "Monta", 32, 88, 87.0);
	gardiens[3] = new Gardien(47, "Ite", "Gran", 32, 88, 87.0);
	
	EquipeHockey* equipe[4];
	equipe[0] = new EquipeHockey("Canadiens");
	equipe[1] = new EquipeHockey("Bruins");
	equipe[2] = new EquipeHockey("Rangers");
	equipe[3] = new EquipeHockey("Maple Leaf");
	
	for (int i = 0; i < 4; i++) {
		equipe[i]->ajouterJoueur(*attaquants[i * 3]);
		equipe[i]->ajouterJoueur(*attaquants[i * 3 + 1]);
		equipe[i]->ajouterJoueur(*attaquants[i * 3 + 2]);
		equipe[i]->ajouterJoueur(*defenseur[i * 2]);
		equipe[i]->ajouterJoueur(*defenseur[i * 2 + 1]);
		equipe[i]->ajouterJoueur(*gardiens[i]);
	}
	
	// Creer un tournoi et inserer les equipes precedemment crees.
	Tournoi<EquipeHockey> tournoi;
	for (int i = 0; i < 4; i++) {
		tournoi.ajouterEquipe(equipe[i]);
	}
	
	// Afficher l'ensemble du tournoi
	cout << "##############################" << endl;
	cout << "Matchs prevus : " << endl;
	tournoi.afficherMatchs();
	
	// Simuler le tournoi
	cout << "##############################" << endl;
	cout << "Simulation du tournoi : " << endl;
	tournoi.simuler();
	
	// Afficher les equipes par classement
	cout << "##############################" << endl;
	cout << "Affichage des equipes par classement : " << endl;
	tournoi.afficherClassementVictoire();
	
	// Afficher les equipes par score total
	cout << "##############################" << endl;
	cout << "Affichage des equipes par score : " << endl;
	tournoi.afficherClassementBut();
	
	return 0;
}
