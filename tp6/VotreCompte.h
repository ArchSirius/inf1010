/*******************************************************************************
 *   Fichier                 : Inscription.h                                   *
 *   Auteurs                 : Samuel Rondeau                                  *
 *   Description             : Déclaration de la classe VotreCompte            *
 *   Date de creation        : 27 novembre 2014                                *
 *   Date de modification    : 6 décembre 2014                                 *
 ******************************************************************************/

#ifndef VOTRECOMPTE_H
#define VOTRECOMPTE_H

#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QGroupBox>
#include <QString>

class VotreCompte : public QWidget
{
    Q_OBJECT
public:
	// Constructeur par default
    VotreCompte(QString username);
	// Destructeur
	~VotreCompte();

	/*
	 *	Lit le fonds du compte dans le fichier et le stock dans l'attribut fonds_
	 */
    bool lireSolde();
	
	/*
	 *	Sauvegarde à la sortie la valeur du fonds dans le fichier externe.
	 */
    bool sauvegarderSolde();

public slots:
	/*
	 *	Sort de la fenêtre active et appelle la fonction sauvegarderSolde().
	 */
    void sortir();
	
	/*
	 *	Ajoute par tranche de 100$ aux fonds actuels.
	 */
    void ajouterFonds();
	
	/*
	 *	Retire par tranche de 100$ aux fonds actuels.
	 */
    void retirerFonds();

private:
	// Boite pour solde du compte
    QGroupBox * grbCompte;
    QVBoxLayout * vboxCompteSolde;

	// Section de la spinBox
    QHBoxLayout * hboxCompteSolde;
    QLabel * labelCompteFonds;
    QSpinBox * spinCompteSoldeCourant;

	// Section des boutons pour l'ajout et le retrait de fonds
    QHBoxLayout * hboxCompteBtn;
    QPushButton * btnCompteAjout;
    QPushButton * btnCompteRetirer;

	// Boite pour la sortie
	QGroupBox * grbCompteBtn;

	// Section pour le bouton de sortie
    QVBoxLayout * vboxCompteBtn;
    QPushButton * btnCompteSortir;

	// Boite principale
    QVBoxLayout * layoutPrincipal;

    int fonds_;
    const QString username_;
};
#endif // VOTRECOMPTE_H
