/************************************************************************************
* Fichier               : main.cpp                                                  *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Boucle d'exécution principale                             *
* Date de creation      : 22 septembre 2014                                         *
* Date de modification  : 28 septembre 2014                                         *
************************************************************************************/

#include <iostream>
#include "Liste.h"
#include "string"

using namespace std;

int main() {

	// 1. Créez une liste vide
	Liste liste1 = Liste();

	// 2. Créez une liste et donner lui un titre
	Liste liste2 = Liste("maListe");

	// 3. Demandez à l'utilisateur d'entrer 3 lignes dans la première liste à l'aide du clavier
	cout << "veuillez entrer 3 lignes dans la premiere liste" << endl << "premiere ligne: ";
	cin >> liste1;
	cout << "deuxieme ligne: ";
	cin >> liste1;
	cout << "troisieme ligne: ";
	cin >> liste1;

	// 4. Affichez la première liste
	cout << endl << "premiere liste : " << endl << liste1;

	// 5. Ajoutez une ligne à la seconde liste avec l'opérateur + et l'opérateur d'affectation =
	cout << "ajouter une ligne a la seconde liste: ";
	string ligne1;
	cin >> ligne1;
	liste2 = (liste2 + ligne1);

	// 6. Ajoutez une seconde ligne à la seconde liste avec l'opérateur +=
	cout << "ajouter une seconde ligne a la seconde liste: ";
	cin >> ligne1;
	liste2 += ligne1;

	// 7. Affichez la seconde liste
	cout << "Deuxieme liste: " << endl << liste2;

	// 8. Tentez de retirer une ligne qui n'existe pas dans la seconde liste avec l'opérateur - et l'opérateur d'affectation =
	liste2 = liste2 - "Une ligne pas rapport!";

	// 9. Affichez la seconde liste pour vérifier que les deux lignes sont toujours présentes
	cout << "Affichage de la liste2: " << endl << liste2;

	// 10. Retirez maintenant une ligne qui existe dans la seconde liste avec l'opérateur -=
	liste2 -= liste2.acceder(0);

	// 11. Affichez la seconde liste pour vérifier que la ligne a bien été retirée
	cout << endl << liste2;
	cout << "======================================================" << endl << endl;

	// 12. Vérifiez l'inégalité des deux listes avec l'opérateur != et afficher inegale si elles le sont (ce qui devrait l'être)
	if (liste1 != liste2) {
		cout << "INEGALES" << endl;
	}
	else {
		cout << "EGALES... mais pas supposé" << endl;
	}

	// 13. Ajouter la seconde liste à la première avec l'opérateur +=
	liste1 += liste2;

	// 14. Affichez la première liste
	cout << liste1;

	// 15. Créez une troisième liste avec le constructeur par copie qui prend en paramètre la première liste
	Liste liste3 = Liste(liste1);

	// 16. Créez une quatrième liste vide puis ensuite assignez-lui la première liste.
	Liste liste4;
	liste4 = liste1;
	cout << "======================================================" << endl << endl;

	// 17. Vérifiez l'égalité de la troisième liste avec la quatrième à l'aide de l'opérateur == et afficher egale si elles le sont (ce qui devrait être le cas)
	if (liste3 == liste4) {
		cout << "liste3 est egale a la liste4" << endl;
	}
	else {
		cout << "liste3 N'est PAS egale a la liste4" << endl;
	}

	return 0;
}