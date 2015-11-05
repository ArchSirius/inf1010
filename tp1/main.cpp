/************************************************************************************
* Fichier               : main.cpp                                                  *
* Auteurs               : Samuel Rondeau & Pierre-Olivier Guimond-Cataford          *
* Description           : Programme de gestion de jeux video                        *
* Date de creation      : 11 septembre 2014                                         *
* Date de modification  : 21 septembre 2014                                         *
************************************************************************************/


/** Question: Dans votre programme, quelle est la relation entre
 *  la classe JeuVideo et la classe Editeur ? Justifier.
 *
 *  Reponse: Il s'agit d'une relation d'agregation. La classe Editeur est composee
 *  d'instances de la classe JeuVideo, mais qui ne lui appartiennent pas. En effet,
 *  la classe Editeur ne contient qu'une liste de pointeurs vers des objets JeuVideo,
 *  et non les objets eux-meme. Concretement, cela implique que la destruction de
 *  la classe Editeur n'entraine pas la destruction des instances de JeuVideo liees.
 *  Par analogie, il s'agit du meme principe que la destruction d'un departement
 *  n'entrene pas la destruction de ses employes, qui pourront etres relocalises
 *  (reference aux notes du cours.)
 */

/** NOTE
* Par entente avec les correcteurs, un seul accesseur et un seul modificateur
* sont commentes de leur en-tête afin d'alleger le code pour autant de repetition.
*/


#include <iostream>
#include <string>
#include "Editeur.h"
#include "date.h"
#include "jeuVideo.h"
  
using namespace std;
  
/** MAIN
* \return 0 fin du programme
*/
int main()
  
{
    // Remarque d'ordre generale
    // Utiliser les noms des objets et les valeurs des arguments
    // tels que fournis en commentaires
      
    // 1) Creer statiquement un objet JeuVideo avec son constructeur par defaut ;
      
    JeuVideo unJeuVideo = JeuVideo();
      
    // 2) Creer statiquement un objet Editeur avec son constructeur par defaut et modifier ses attributs ;
    // Utiliser les arguments suivants :
    //      nom="Microsoft Game Studios",
    //      date de creation=01/08/2002,
    //      site web="www.microsoft.com/games"
      
    Date uneDate1 = Date(1, 8, 2002);
    Editeur microsoftGameStudios = Editeur("Microsoft Game Studios", uneDate1, "www.microsoft.com/games");
      
    // 3) Creer statiquement un objet JeuVideo avec constructeur par parametres ;
    // Utiliser les arguments suivants :
    //      titre="Halo: Combat Evolved",
    //      date de creation=14/03/2002,
    //      editeur="Microsoft Game Studios"
    //      genre="Jeu de tir subjectif"
    //      plate-forme="Mac OSX, Windows, Xbox, Xbox 360"
    //      description="Premier episode de serie Halo"
    //      evaluation=4.2
      
    Date uneDate2 = Date(14, 3, 2002);
    JeuVideo halo = JeuVideo("Halo: Combat Evolved", uneDate2, "Microsoft Game Studios",
                                   "Jeu de tir subjectif", "Mac OSX, Windows, Xbox, Xbox 360", "Premier episode de serie Halo", 4.2);
      
    // 4) Creer dynamiquement un objet Editeur avec son constructeur par parametre ;
    // Utiliser les arguments suivants :
    //      nom="Ubisoft",
    //      date de creation=01/06/1986,
    //      site web="www.ubi.com"
      
    Date uneDate3 = Date(1, 6, 1986);
    Editeur* ubisoft = new Editeur("Ubisoft", uneDate3, "www.ubi.com");
      
    // 5) Modifier tous les attributs du JeuVideo crees dans 1)
    // Utilisant les arguments suivants:
    //      titre="Assassin's Creed",
    //      date de creation=13/11/2007,
    //      editeur="Ubisoft" cree en 4)
    //      genre="Action, aventure, infiltration"
    //      plate-forme="Mac OSX, Windows, Xbox, Xbox 360"
    //      description="Assassin's Creed est un jeu d'action-aventure au gameplay non-lineaire, incorporant des elements d'infiltration"
    //      evaluation=4.9
      
    unJeuVideo.setTitre("Assassin's Creed");
    Date uneDate4 = Date(13, 11, 2007);
    unJeuVideo.setDateSortie(uneDate4);
    unJeuVideo.setNomEditeur("Ubisoft");
    unJeuVideo.setGenre("Action, aventure, infiltration");
    unJeuVideo.setPlateforme("Mac OSX, Windows, Xbox, Xbox 360");
    unJeuVideo.setDescription("Assassin's Creed est un jeu d'action-aventure au gameplay non-lineaire, incorporant des elements d'infiltration");
    unJeuVideo.setEvaluation(4.9);
      
    // 6) Ajouter le JeuVideo cree en 1) a l'Editeur cree en 4)
      
    ubisoft->ajouterJeu(unJeuVideo);
      
    // 7) Ajouter le JeuVideo cree en 3) a l'Editeur cree en 2)
 
    microsoftGameStudios.ajouterJeu(halo);
      
    // 8) Creer dynamiquement un objet JeuVideo avec son constructeur par parametre ;
    // Utilisant les arguments suivants:
    //      titre="Assassin's Creed",
    //      date de creation=13/11/2007,
    //      editeur="Ubisoft" cree en 4)
    //      genre="Action, aventure, infiltration"
    //      plate-forme="Mac OSX, Windows, Xbox, Xbox 360"
    //      description="Assassin's Creed est un jeu d'action-aventure au gameplay non-lineaire, incorporant des elements d'infiltration"
    //      evaluation=4.9
 
    Date uneDate5 = Date(13,11,2007);
    JeuVideo* assassinCreed = new JeuVideo("Assassin's Creed", uneDate5, "ubisoft",
                                           "Action, aventure, infiltration",
                                           "Mac OSX, Windows, Xbox, Xbox 360",
                                           "Assassin's Creed est un jeu d'action-aventure au gameplay non-lineaire, incorporant des elements d'infiltration",
                                           4.9);
 
    // 9) Essayer d'ajouter le JeuVideo cree en 8) a l'Editeur cree en 4)
 
    ubisoft->ajouterJeu(*assassinCreed);										// on doit passer une adresse/pointeur
      
    // 10) Modifier le titre du JeuVideo cree en 8) : titre="Assassin's Creed 2"
      
    assassinCreed->setTitre("Assassin's Creed 2");
      
    // 11) Ajouter le JeuVideo cree en 8) et modife en 10) a l'Editeur cree en 4)
 
    ubisoft->ajouterJeu(*assassinCreed);										// ainsi on n'utilise qu'un seul objet dans le main
																				// mais l'editeur aura AC1 et AC2
    // 12) Afficher les editeurs crees en 2) et en 4)
      
    microsoftGameStudios.afficherEditeur();            
    ubisoft->afficherEditeur();
      
    // 12) Liberer toute la memoire
    delete ubisoft;
    delete assassinCreed;
      
    return 0;
}