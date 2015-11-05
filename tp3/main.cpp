/************************************************************************************
* Fichier               : main.cpp                                                  *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Boucle d'exécution principale                             *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#include <iostream>
#include <string>
#include "Piece.h"
#include "Roue.h"
#include "RoueDefectueuse.h"
#include "Voiture.h"
#include "Moteur.h"

int main() {

	// 1) Créez 3 roues normales
	Roue roue1 = Roue("Michelin", "Une roue ordinaire", 200, 2010, 81);
	Roue roue2 = Roue("Michelin", "Une autre roue des plus normales", 250, 2009, 77);
	Roue roue3 = Roue("BMW", "Une roue extraordinaire", 600, 2011, 86);

	// 2) Créez 1 roue défectueuse
	RoueDefectueuse roue4 = RoueDefectueuse("Dollarama", "Une roue assez nulle", 50, 2005, 62);

	// 3) Créez une voiture avec un moteur et les 4 roues créées précédemment
	Voiture voiture = Voiture("Mazda", 3100, Moteur("Mazda", "Un moteur pas comme les autres", 1000, 2005, 200, 100000),
																								&roue1, &roue2, &roue3, &roue4);

	// 4) Affichez les informations de la voiture
	voiture.afficherInformationVoiture();

	return 0;
}