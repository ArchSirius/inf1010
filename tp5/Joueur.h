/************************************************************************************
*	Fichier					: Joueur.h
*	Auteurs					: Benjamin De Leener
*	Description				: Declaration de la classe Joueur
*	Date de creation		: 11 octobre 2014
*	Date de modification	: 
************************************************************************************/

#ifndef JOUEUR_
#define JOUEUR_

#include <string>
using namespace std;

class Joueur
{
public:
	Joueur();
    Joueur(unsigned int num, string nom, string prenom, unsigned int age, double attaque, double defense);
	~Joueur();
    
    bool operator==(const Joueur& individu);

    void setNum(unsigned int num);
	void setNom(string nom);
	void setPrenom(string prenom);
	void setAge(unsigned int age);
    void setAttaque(double attaque);
    void setDefense(double defense);

    unsigned int getNum() const;
	string getNom() const;
	string getPrenom() const;
	unsigned int getAge() const;
    virtual double getAttaque() const;
    virtual double getDefense() const;

	friend ostream& operator<<(ostream& os, const Joueur& individu);

	virtual void celebrer() const;
	virtual string getType() const = 0;

protected:
    unsigned int num_;
    string nom_;
    string prenom_;
    unsigned int age_;
    
    double attaque_;
    double defense_;
};

#endif
