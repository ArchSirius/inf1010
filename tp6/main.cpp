#include"Principale.h"
//#include"Inscription.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Principale fenetrePrincipale;
    fenetrePrincipale.show();
    //Inscription uneInscription;
    //uneInscription.show();

    return app.exec();
}
