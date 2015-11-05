/*******************************************************************************
*   Fichier                 : Inscription.cpp                                  *
*   Auteurs                 : Samuel Rondeau                                   *
*   Description             : Implémentation de la classe Inscription          *
*   Date de creation        : 27 novembre 2014                                 *
*   Date de modification    : 6 décembre 2014                                  *
*******************************************************************************/

#include "Inscription.h"
#include <QMessageBox>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>

// Constructeur par défaut
Inscription::Inscription(){
    setFenetre();
    perso();
    addr();
    statut();
    langue();
    connexion();
    confirmation();
}

// Destructeur
Inscription::~Inscription(){}

// Création

void Inscription::setFenetre(){
    setWindowTitle("Inscription");
    vboxMain = new QVBoxLayout(this);
    this->setLayout(vboxMain);
}
 
void Inscription::perso(){
    grbPerso = new QGroupBox("Vos informations personnelles", this);
    formPerso = new QFormLayout(this);
    grbPerso->setLayout(formPerso);
 
    txtPersoNom = new QLineEdit(this);
    formPerso->addRow(tr("&Nom :"), txtPersoNom);
 
    txtPersoPrenom = new QLineEdit(this);
    formPerso->addRow(tr("&Prénom :"), txtPersoPrenom);
 
    datePersoNaissance = new QDateEdit(this);
    formPerso->addRow(tr("&Date de naissance :"), datePersoNaissance);
 
    txtPersoTelephone = new QLineEdit(this);
    formPerso->addRow(tr("&Téléphone :"), txtPersoTelephone);
 
    vboxMain->addWidget(grbPerso);
}
 
void Inscription::addr(){
    grbAddr = new QGroupBox("Votre adresse", this);
    formAddr = new QFormLayout(this);
    grbAddr->setLayout(formAddr);
 
    txtAddrNumero = new QLineEdit(this);
    formAddr->addRow(tr("&Numéro :"), txtAddrNumero);
 
    txtAddrRue = new QLineEdit(this);
    formAddr->addRow(tr("&Rue :"), txtAddrRue);
 
    txtAddrVille = new QLineEdit(this);
    formAddr->addRow(tr("&Ville :"), txtAddrVille);
 
    comboAddrProvince = new QComboBox(this);
    comboAddrProvince->addItem("Alberta");
    comboAddrProvince->addItem("Colombie-Britannique");
    comboAddrProvince->addItem("Île-du-Prince-Édouard");
    comboAddrProvince->addItem("Manitoba");
    comboAddrProvince->addItem("Nouveau-Brunswick");
    comboAddrProvince->addItem("Nouvelle-Écosse");
    comboAddrProvince->addItem("Ontario");
    comboAddrProvince->addItem("Québec");
    comboAddrProvince->addItem("Saskatchewan");
    comboAddrProvince->addItem("Terre-Neuve-et-Labrador");
    comboAddrProvince->addItem("Nunavut");
    comboAddrProvince->addItem("Territoires du Nord-Ouest");
    comboAddrProvince->addItem("Yukon");
    formAddr->addRow(tr("&Province :"), comboAddrProvince);
 
    txtAddrCodePostal = new QLineEdit(this);
    formAddr->addRow(tr("&Code postal :"), txtAddrCodePostal);
 
    vboxMain->addWidget(grbAddr);
}
 
void Inscription::statut(){
    grbStatut = new QGroupBox("Votre statut", this);
    formStatut = new QFormLayout(this);
    grbStatut->setLayout(formStatut);
 
    radioStatutCanadien = new QRadioButton("Canadien", this);
    formStatut->addRow(radioStatutCanadien);
 
    radioStatutNonCanadien = new QRadioButton("Non canadien", this);
    formStatut->addRow(radioStatutNonCanadien);
 
    vboxMain->addWidget(grbStatut);
}
 
void Inscription::langue(){
    grbLangue = new QGroupBox("En quelle langue souhaitez-vous être servi ?", this);
    formLangue = new QFormLayout(this);
    grbLangue->setLayout(formLangue);
 
    checkLangueFrancais = new QCheckBox("Français (french)", this);
    formLangue->addRow(checkLangueFrancais);
 
    checkLangueAnglais = new QCheckBox("Anglais (english)", this);
    formLangue->addRow(checkLangueAnglais);
 
    vboxMain->addWidget(grbLangue);
}
 
void Inscription::connexion(){
    grbConnexion = new QGroupBox("Informations de connexion", this);
    formConnexion = new QFormLayout(this);
    grbConnexion->setLayout(formConnexion);
 
    txtConnectionUsager = new QLineEdit(this);
    formConnexion->addRow(tr("&Nom d'usager :"), txtConnectionUsager);
 
    txtConnectionMDP = new QLineEdit(this);
    txtConnectionMDP->setEchoMode(QLineEdit::Password);
    formConnexion->addRow(tr("&Mot de passe :"), txtConnectionMDP);
 
    txtConnectionConfMDP = new QLineEdit(this);
    txtConnectionConfMDP->setEchoMode(QLineEdit::Password);
    formConnexion->addRow(tr("&Confirmez votre mot de passe :"), txtConnectionConfMDP);
 
    vboxMain->addWidget(grbConnexion);
}
 
void Inscription::confirmation(){
    grbConfirm = new QGroupBox("Confirmation", this);
    hboxConfirm = new QHBoxLayout(this);
    grbConfirm->setLayout(hboxConfirm);
 
    btnConfirmConfirmer = new QPushButton("Confirmer", this);
    hboxConfirm->addWidget(btnConfirmConfirmer);
    connect(btnConfirmConfirmer, SIGNAL(clicked()), this, SLOT(confirmer()));
 
    btnConfirmVerifier = new QPushButton("Vérifier", this);
    hboxConfirm->addWidget(btnConfirmVerifier);
    connect(btnConfirmVerifier, SIGNAL(clicked()), this, SLOT(verifier()));
 
    btnConfirmSortir = new QPushButton("Sortir", this);
    hboxConfirm->addWidget(btnConfirmSortir);
    connect(btnConfirmSortir, SIGNAL(clicked()), this, SLOT(quitter()));
 
    vboxMain->addWidget(grbConfirm);
}
 
// Slots

void Inscription::confirmer(){
    if(verifierInformations()){
        ecrireFichier();
        quitter();
    }
}
 
void Inscription::verifier(){
    if(verifierInformations()){
        QMessageBox::information(0, "Confirmer", "Vérification terminée. Toutes vos informations sont acceptées. Vous pouvez maintenant confirmer.");
    }
}

void Inscription::quitter(){
    close();
    delete this;
}

// Logique et exécution
 
bool Inscription::verifierInformations(){
    if(txtPersoNom->text() == "" ||
       txtPersoPrenom->text() == "" ||
       txtPersoTelephone->text() == ""){
        QMessageBox::critical(0, "Avertissement", "Veuillez remplir toutes vos informations personnelles.");
        return false;
    }
    if(txtAddrNumero->text() == "" ||
            txtAddrRue->text() == "" ||
            txtAddrVille->text() == "" ||
            txtAddrCodePostal->text() == ""){
        QMessageBox::critical(0, "Avertissement", "Veuillez remplir vos informations d'adresse.");
        return false;
    }
    if(!radioStatutCanadien->isChecked() && !radioStatutNonCanadien->isChecked()){
        QMessageBox::critical(0, "Avertissement", "Vous devez choisir votre statut.");
        return false;
    }
    if(!checkLangueFrancais->isChecked() && !checkLangueAnglais->isChecked()){
        QMessageBox::critical(0, "Avertissement", "Vous devez choisir au moins une langue.");
        return false;
    }
    if(txtConnectionUsager->text() == "" ||
            txtConnectionMDP->text() == "" ||
            txtConnectionConfMDP->text() == ""){
        QMessageBox::critical(0, "Avertissement", "Veuillez remplir toutes vos informations de connexion.");
        return false;
    }
    if(txtConnectionMDP->text() != txtConnectionConfMDP->text()){
        QMessageBox::critical(0, "Avertissement", "La confirmation du mot de passe ne concorde pas.");
        return false;
    }
    return true;
}
 
bool Inscription::ecrireFichier(){
    QString statut;
    if(radioStatutCanadien->isChecked()){
        statut = "Canadien";
    }
    else{
        statut = "Non canadien";
    }
 
    QString langue;
    if(checkLangueFrancais->isChecked()){
        langue = "Français";
        if(checkLangueAnglais->isChecked()){
            langue += ", anglais";
        }
    }
    else{
        langue = "Anglais";
    }
 
    QFile fileInfos(txtConnectionUsager->text() + ".txt");
    if (!fileInfos.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QTextStream outInfos(&fileInfos);
    outInfos << "Nom : " << txtPersoNom->text() << "\n"
             << "Prénom : " << txtPersoPrenom->text() << "\n"
             << "Date de naissance : " << datePersoNaissance->date().toString() << "\n"
             << "Numéro de téléphone : " << txtPersoTelephone->text() << "\n"
             << "\n"
             << "Numéro civique : " << txtAddrNumero->text() << "\n"
             << "Rue : " << txtAddrRue->text() << "\n"
             << "Ville : " << txtAddrVille->text() << "\n"
             << "Province : " << comboAddrProvince->currentText() << "\n"
             << "Code postal : " << txtAddrCodePostal->text() << "\n"
             << "\n"
             << "Statut : " << statut << "\n"
             << "\n"
             << "Langue(s) : " << langue << "\n";
    fileInfos.close();
 
    QFile fileLogin(txtConnectionUsager->text() + ".bin");
    if (!fileLogin.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QTextStream outLogin(&fileLogin);
    outLogin << txtConnectionMDP->text();
    fileLogin.close();
 
    QFile fileCash(txtConnectionUsager->text() + ".dat");
    if (!fileCash.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QTextStream outCash(&fileCash);
    outCash << 0;
    fileCash.close();
    return true;
}
