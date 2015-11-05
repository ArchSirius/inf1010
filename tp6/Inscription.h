/*******************************************************************************
*   Fichier                 : Inscription.h                                    *
*   Auteurs                 : Samuel Rondeau                                   *
*   Description             : Déclaration de la classe Inscription             *
*   Date de creation        : 27 novembre 2014                                 *
*   Date de modification    : 6 décembre 2014                                  *
*******************************************************************************/

#ifndef INSCRIPTION_H
#define INSCRIPTION_H
#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QFormLayout>
#include <QComboBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
 
class Inscription : public QWidget
{
    Q_OBJECT
public:
    // Constructeur par défaut
    Inscription();
    // Destructeur
    ~Inscription();
 
public slots:
    /*
    *  Vérifie si les informations entrées sont correctes
    */
    void verifier();

    /*
    *  Confirme les informations et les enregistre si elles sont valides
    */
    void confirmer();

    /*
    *  Ferme la fenêtre Inscription
    */
    void quitter();
 
private:
    /*
    *  Règle les configurations de la fenêtre
    */
    void setFenetre();

    /*
    *  Ajoute à la fenêtre la section des informations personnelles
    */
    void perso();

    /*
    *  Ajoute à la fenêtre la section des informations d'adresse
    */
    void addr();

    /*
    *  Ajoute à la fenêtre la section du statut
    */
    void statut();

    /*
    *  Ajoute à la fenêtre la section des langues
    */
    void langue();

    /*
    *  Ajoute à la fenêtre la section des informations de connexion
    */
    void connexion();

    /*
    *  Ajoute à la fenêtre la section de confirmation
    */
    void confirmation();

    /*
    *  Vérifie si les informations entrées sont correctes
    */
    bool verifierInformations();

    /*
    *  Enregistre les informations
    */
    bool ecrireFichier();

    // Fenêtre 
    QVBoxLayout * vboxMain;
 
    // Section des informations personnelles
    QFormLayout * formPerso;
    QGroupBox * grbPerso;
    QLineEdit * txtPersoNom;
    QLineEdit * txtPersoPrenom;
    QDateEdit * datePersoNaissance;
    QLineEdit * txtPersoTelephone;
 
    // Section des informations d'adresse
    QFormLayout * formAddr;
    QGroupBox * grbAddr;
    QLineEdit * txtAddrNumero;
    QLineEdit * txtAddrRue;
    QLineEdit * txtAddrVille;
    QComboBox * comboAddrProvince;
    QLineEdit * txtAddrCodePostal;
    //QDateEdit * dateAddrNaissance;
    //QLineEdit * txtAddrTelephone;
 
    // Section du statut
    QFormLayout * formStatut;
    QGroupBox * grbStatut;
    QRadioButton * radioStatutCanadien;
    QRadioButton * radioStatutNonCanadien;
 
    // Section des langues
    QFormLayout * formLangue;
    QGroupBox * grbLangue;
    QCheckBox * checkLangueFrancais;
    QCheckBox * checkLangueAnglais;
 
    // Section des informations de connexion
    QFormLayout * formConnexion;
    //QVBoxLayout * vboxConnexion;
    QGroupBox * grbConnexion;
    QLineEdit * txtConnectionUsager;
    QLineEdit * txtConnectionMDP;
    QLineEdit * txtConnectionConfMDP;
 
    // Section de confirmation
    //QFormLayout * formConfirm;
    QHBoxLayout * hboxConfirm;
    QGroupBox * grbConfirm;
    QPushButton * btnConfirmConfirmer;
    QPushButton * btnConfirmVerifier;
    QPushButton * btnConfirmSortir;
};