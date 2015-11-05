/************************************************************************************
* Fichier               : main.cpp                                                  *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Boucle d'ex�cution principale                             *
* Date de creation      : 22 septembre 2014                                         *
* Date de modification  : 28 septembre 2014                                         *
************************************************************************************/

#include <iostream>
#include "Liste.h"
#include "string"

using namespace std;

int main() {

	// 1. Cr�ez une liste vide
	Liste liste1 = Liste();

	// 2. Cr�ez une liste et donner lui un titre
	Liste liste2 = Liste("maListe");

	// 3. Demandez � l'utilisateur d'entrer 3 lignes dans la premi�re liste � l'aide du clavier
	cout << "veuillez entrer 3 lignes dans la premiere liste" << endl << "premiere ligne: ";
	cin >> liste1;
	cout << "deuxieme ligne: ";
	cin >> liste1;
	cout << "troisieme ligne: ";
	cin >> liste1;

	// 4. Affichez la premi�re liste
	cout << endl << "premiere liste : " << endl << liste1;

	// 5. Ajoutez une ligne � la seconde liste avec l'op�rateur + et l'op�rateur d'affectation =
	cout << "ajouter une ligne a la seconde liste: ";
	string ligne1;
	cin >> ligne1;
	liste2 = (liste2 + ligne1);

	// 6. Ajoutez une seconde ligne � la seconde liste avec l'op�rateur +=
	cout << "ajouter une seconde ligne a la seconde liste: ";
	cin >> ligne1;
	liste2 += ligne1;

	// 7. Affichez la seconde liste
	cout << "Deuxieme liste: " << endl << liste2;

	// 8. Tentez de retirer une ligne qui n'existe pas dans la seconde liste avec l'op�rateur - et l'op�rateur d'affectation =
	liste2 = liste2 - "Une ligne pas rapport!";

	// 9. Affichez la seconde liste pour v�rifier que les deux lignes sont toujours pr�sentes
	cout << "Affichage de la liste2: " << endl << liste2;

	// 10. Retirez maintenant une ligne qui existe dans la seconde liste avec l'op�rateur -=
	liste2 -= liste2.acceder(0);

	// 11. Affichez la seconde liste pour v�rifier que la ligne a bien �t� retir�e
	cout << endl << liste2;
	cout << "======================================================" << endl << endl;

	// 12. V�rifiez l'in�galit� des deux listes avec l'op�rateur != et afficher inegale si elles le sont (ce qui devrait l'�tre)
	if (liste1 != liste2) {
		cout << "INEGALES" << endl;
	}
	else {
		cout << "EGALES... mais pas suppos�" << endl;
	}

	// 13. Ajouter la seconde liste � la premi�re avec l'op�rateur +=
	liste1 += liste2;

	// 14. Affichez la premi�re liste
	cout << liste1;

	// 15. Cr�ez une troisi�me liste avec le constructeur par copie qui prend en param�tre la premi�re liste
	Liste liste3 = Liste(liste1);

	// 16. Cr�ez une quatri�me liste vide puis ensuite assignez-lui la premi�re liste.
	Liste liste4;
	liste4 = liste1;
	cout << "======================================================" << endl << endl;

	// 17. V�rifiez l'�galit� de la troisi�me liste avec la quatri�me � l'aide de l'op�rateur == et afficher egale si elles le sont (ce qui devrait �tre le cas)
	if (liste3 == liste4) {
		cout << "liste3 est egale a la liste4" << endl;
	}
	else {
		cout << "liste3 N'est PAS egale a la liste4" << endl;
	}

	return 0;
}