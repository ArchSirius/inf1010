#include"Principale.h"


    Principale::Principale()
    {
        setFixedSize(250, 150);
        boutonInscription = new  QPushButton("Ouvrir un nouveau compte bancaire", this);
        boutonConnexion = new  QPushButton("Connexion à votre compte", this);
        sortir = new  QPushButton("Sortir", this);
        vboxPrincipale = new QVBoxLayout(this);

        vboxPrincipale->addWidget(boutonInscription);
        vboxPrincipale->addWidget(boutonConnexion);
        vboxPrincipale->addWidget(sortir);

        general = new QGroupBox("Clicquez sur un bouton", this);
        general->setLayout(vboxPrincipale);

        layoutPrincipal = new QVBoxLayout(this);
        layoutPrincipal->addWidget(general);

        setLayout(layoutPrincipal);
        setWindowTitle("Bienvenu chez votre banque");

        connect(boutonInscription, SIGNAL(clicked()), this, SLOT(inscription()));
        connect(boutonConnexion, SIGNAL(clicked()), this, SLOT(connexion()));
        connect(sortir, SIGNAL(clicked()), qApp, SLOT(quit()));


    }

    void Principale::inscription()
    {

        Inscription *uneInscription = new Inscription();
        uneInscription->show();
    }

    void Principale::connexion()
    {
        Connexion *uneConnexion = new Connexion();
        uneConnexion->show();

    }


