#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include<QApplication>
#include<QPushButton>
#include<QBoxLayout>
#include<QGroupBox>


#include"Inscription.h"
#include"Connexion.h"

class Principale: public QWidget
{
    Q_OBJECT
public:
    Principale();
public slots:
    void inscription();
    void connexion();

private:
    QPushButton * boutonInscription;
    QPushButton * boutonConnexion;
    QPushButton * sortir;
    QVBoxLayout * vboxPrincipale;
    QVBoxLayout * layoutPrincipal;
    QGroupBox * general;
    QGroupBox* groupPrincipal;


};
#endif // PRINCIPALE_H
