/*******************************************************************************
 *   Fichier                 : Inscription.cpp                                 *
 *   Auteurs                 : Samuel Rondeau                                  *
 *   Description             : Implémentation de la classe VotreCompte         *
 *   Date de creation        : 27 novembre 2014                                *
 *   Date de modification    : 6 décembre 2014                                 *
 ******************************************************************************/

#include "VotreCompte.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#define UNIT 100

// Constructeur par défaut
VotreCompte::VotreCompte(QString username) : username_(username){
    lireSolde();
    labelCompteFonds = new QLabel("Solde courant dans le compte:");
	
    spinCompteSoldeCourant = new QSpinBox();
    spinCompteSoldeCourant->setSuffix("$");
    spinCompteSoldeCourant->setRange(0,1000000000);
    spinCompteSoldeCourant->setMaximum(1000000000);
    spinCompteSoldeCourant->setValue(fonds_);
	
    hboxCompteSolde = new QHBoxLayout;
    hboxCompteSolde->addWidget(labelCompteFonds);
    hboxCompteSolde->addWidget(spinCompteSoldeCourant);

    btnCompteAjout = new QPushButton("Ajouter des fonds")
    btnCompteRetirer = new QPushButton("Retirer des fonds");
	
    hboxCompteBtn = new QHBoxLayout;
    hboxCompteBtn->addWidget(btnCompteAjout);
    hboxCompteBtn->addWidget(btnCompteRetirer);

    vboxCompteSolde = new QVBoxLayout;
    vboxCompteSolde->addLayout(hboxCompteSolde);
    vboxCompteSolde->addLayout(hboxCompteBtn);

    btnCompteSortir = new QPushButton("Sortir");
	
    vboxCompteBtn = new QVBoxLayout;
    vboxCompteBtn->addWidget(btnCompteSortir);

    grbCompte = new QGroupBox("Transaction");
    grbCompte->setLayout(vboxCompteSolde);
	
    grbCompteBtn = new QGroupBox("Confirmation");
    grbCompteBtn->setLayout(vboxCompteBtn);

    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(grbCompte);
    layoutPrincipal->addWidget(grbCompteBtn);

    setWindowTitle("Votre compte");
    this->setLayout(layoutPrincipal);

    connect(btnCompteSortir, SIGNAL(clicked()), this, SLOT(sortir()));
    connect(btnCompteAjout, SIGNAL(clicked()), this, SLOT(ajouterFonds()));
    connect(btnCompteRetirer, SIGNAL(clicked()), this, SLOT(retirerFonds()));
}

// Destructeur
VotreCompte::~VotreCompte(){}

// Slots

void VotreCompte::sortir(){
	sauvegarderSolde();
	this->close();
	delete this;
}

void VotreCompte::ajouterFonds(){
    fonds_+=UNIT;
    spinCompteSoldeCourant->setValue(fonds_);
}

void VotreCompte::retirerFonds(){
    fonds_-=UNIT;
    if(fonds_ < 0){
        fonds_ = 0;
    }
    spinCompteSoldeCourant->setValue(fonds_);
}

// Logique et exécution

bool VotreCompte::sauvegarderSolde(){
    QFile file(username_ + ".dat");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QTextStream out(&file);
    out << fonds_;
    file.close();
    return true;
}

bool VotreCompte::lireSolde(){
    QFile file(username_ + ".dat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(0, "Erreur fatale", "Un fraudeur a volÈ tout votre argent.");
        return false;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    fonds_ = line.toInt();
    file.close();
    return true;
}