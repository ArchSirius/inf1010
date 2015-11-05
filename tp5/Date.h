//
//  Date.h
//  TP5
//
//  Created by PO on 2014-11-06.
//  Copyright (c) 2014 PO. All rights reserved.
//

#ifndef __TP5__Date__
#define __TP5__Date__

#include <stdio.h>
#include <ostream>

// TODO julian day

using namespace std;

class Date {
public:
	Date();
	Date(int jour, int mois, int annee);
	Date(const Date& date);
	~Date();

	Date& operator= (const Date& date);
	bool operator== (const Date& date) const;
	Date& operator+ (int nbJours) const;
	Date& operator+= (int nbJours);
	Date& operator++ ();
	friend ostream& operator<< (ostream& os, const Date& date);
	int joursMois(int mois, int annee) const;
	bool operator< (const Date& d2);

private:
	int jour_;
	int mois_;
	int annee_;
};

#endif /* defined(__TP5__Date__) */