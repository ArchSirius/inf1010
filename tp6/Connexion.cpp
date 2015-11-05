/*******************************************************************************
*   Fichier                 : Connexion.h                                      *
*   Auteurs                 : Samuel Rondeau                                   *
*   Description             : Implémentation de la classe Connexion            *
*   Date de creation        : 27 novembre 2014                                 *
*   Date de modification    : 6 décembre 2014                                  *
*******************************************************************************/

#include "Connexion.h"
#include "VotreCompte.h"
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
 
// Constructeur par défaut
Connexion::Connexion(){
    setFenetre();
    connexion();
    confirmation();
}

// Destructeur
Connexion::~Connexion(){}
 
// Création

void Connexion::setFenetre(){
    setWindowTitle("Connexion");
    vboxMain = new QVBoxLayout(this);
    this->setLayout(vboxMain);
}
 
void Connexion::connexion(){
    grbConnexion = new QGroupBox("Veuillez entrer vos paramètres de connexion", this);
    formConnexion = new QFormLayout(this);
    grbConnexion->setLayout(formConnexion);
 
    txtConnectionUsager = new QLineEdit(this);
    formConnexion->addRow(tr("&Nom d'usager :"), txtConnectionUsager);
 
    txtConnectionMDP = new QLineEdit(this);
    txtConnectionMDP->setEchoMode(QLineEdit::Password);
    formConnexion->addRow(tr("&Mot de passe :"), txtConnectionMDP);
 
    vboxMain->addWidget(grbConnexion);
}
 
void Connexion::confirmation(){
    grbConfirm = new QGroupBox("Confirmation", this);
    vboxConfirm = new QVBoxLayout(this);
    grbConfirm->setLayout(vboxConfirm);
 
    btnConfirmConnexion = new QPushButton("Connexion", this);
    vboxConfirm->addWidget(btnConfirmConnexion);
    connect(btnConfirmConnexion, SIGNAL(clicked()), this, SLOT(seConnecter()));
 
    btnConfirmAnnuler = new QPushButton("Sortir", this);
    vboxConfirm->addWidget(btnConfirmAnnuler);
    connect(btnConfirmAnnuler, SIGNAL(clicked()), this, SLOT(quitter()));
 
    vboxMain->addWidget(grbConfirm);
}
 
// Slots

bool Connexion::seConnecter(){
    QFile file(txtConnectionUsager->text() + ".bin");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(0, "Avertissement", "Vous n'êtes pas inscrit dans notre base de données.");
        return false;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    if(txtConnectionMDP->text() != line){
        QMessageBox::critical(0, "Avertissement", "Votre mot de passe est erroné.");
        file.close();
        return false;
    }
    file.close();
    VotreCompte *votreCompte = new VotreCompte(txtConnectionUsager->text());
    votreCompte->show();
    quitter();
    return true;
}
 
void Connexion::quitter(){
    close();
    delete this;
}
