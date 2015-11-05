//
//  Date.cpp
//  TP5
//
//  Created by PO on 2014-11-06.
//  Copyright (c) 2014 PO. All rights reserved.
//

#include "Date.h"
#include <ostream>

using namespace std;

Date::Date() : jour_(1), mois_(1), annee_(1970){}
Date::Date(int jour, int mois, int annee) : jour_(jour), mois_(mois), annee_(annee){}
Date::Date(const Date& date) : jour_(date.jour_), mois_(date.mois_), annee_(date.annee_){}
Date::~Date(){}

Date& Date::operator= (const Date& date){
	annee_ = date.annee_;
	mois_ = date.mois_;
	jour_ = date.jour_;
	return *this;
}

bool Date::operator== (const Date& date) const{
	if (annee_ == date.annee_ && mois_ == date.mois_ && jour_ == date.jour_){
		return true;
	}
	return false;
}

// Ajoute le nombre de jours en incrementant le mois et l'année au besoin
Date& Date::operator+ (int nbJours) const{
	Date temp = *this;
	temp += nbJours;
	return temp;
}

// Ajoute le nombre de jours en incrementant le mois et l'année au besoin
Date& Date::operator+= (int nbJours){
	while (nbJours > 0){
		if (jour_ == joursMois(mois_, annee_)){
			jour_ = 1;
			if (mois_ == 12){
				mois_ = 1;
				annee_++;
			}
			else{
				mois_++;
			}
		}
		else{
			jour_++;
		}
		nbJours--;
	}
	return *this;
}

Date& Date::operator++ (){
	return *this += 1;
}

ostream& operator<< (ostream& os, const Date& date){
	os << date.jour_ << "/" << date.mois_ << "/" << date.annee_ << endl;
	return os;
}

int Date::joursMois(int mois, int annee) const{
	switch (mois){
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;

		case 2:
			if (!(annee % 400) || (!(annee % 4) && (annee % 100))){
				return 29;
			}
			return 28;
			break;

		default:
			return 31;
	}
}

bool Date::operator< (const Date& d2){
	if (annee_ != d2.annee_){
		return annee_ < d2.annee_;
	}
	if (mois_ != d2.mois_){
		return mois_ < d2.mois_;
	}
	if (jour_ != d2.jour_){
		return jour_ < d2.jour_;
	}
	return true;
}
