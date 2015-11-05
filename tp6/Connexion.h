/*******************************************************************************
*   Fichier                 : Connexion.h                                      *
*   Auteurs                 : Samuel Rondeau                                   *
*   Description             : Déclaration de la classe Connexion               *
*   Date de creation        : 27 novembre 2014                                 *
*   Date de modification    : 6 décembre 2014                                  *
*******************************************************************************/
 
#ifndef CONNEXION_H
#define CONNEXION_H
#include <QWidget>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
 
class Connexion : public QWidget
{
    Q_OBJECT
public:
    // Constructeur par défaut
    Connexion();
    // Destructeur
    ~Connexion();
 
public slots:
    /*
    *  Permet à l'utilisateur de se connecter si ses informations sont valides
    */
    bool seConnecter();

    /*
    *  Ferme la fenêtre Connexion
    */
    void quitter();
 
private:
    /*
    *  Règle les configurations de la fenêtre
    */
    void setFenetre();

    /*
    *  Ajoute à la fenêtre la section des informations de connexion
    */
    void connexion();

    /*
    *  Ajoute à la fenêtre la section de confirmation
    */
    void confirmation();

    // Fenêtre
    QVBoxLayout * vboxMain;
 
    // Section des informations de connexion
    QFormLayout * formConnexion;
    QGroupBox * grbConnexion;
    QLineEdit * txtConnectionUsager;
    QLineEdit * txtConnectionMDP;
 
    // Section des informations de confirmation
    QVBoxLayout * vboxConfirm;
    QGroupBox * grbConfirm;
    QPushButton * btnConfirmConnexion;
    QPushButton * btnConfirmAnnuler;
};
 
 
 
#endif // CONNEXION_H