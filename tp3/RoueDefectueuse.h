/************************************************************************************
* Fichier               : RoueDefectueuse.h                                         *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Roue défectueuse                                          *
* Date de creation      : 2 octobre 2014                                            *
* Date de modification  : 13 octobre 2014                                           *
************************************************************************************/

#ifndef ROUE_DEFECTUEUSE_H
#define ROUE_DEFECTUEUSE_H

#include <string>
#include "Roue.h"
#include "Piece.h"
using namespace std;

class RoueDefectueuse : public Roue {
public:
	// Constructeur par défaut
	RoueDefectueuse();

	// Constructeur par paramètres
	RoueDefectueuse(string, string, int, int, int);

	// Destructeur
	~RoueDefectueuse();
};
#endif