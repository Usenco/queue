#pragma once
#include "offense.h"
#include <list>

class list_of_offenses
{
	list<offense> l;
	int number;
	int size;//количество нарушений
	int index;
public:
	list_of_offenses(int number);

	bool operator<(const list_of_offenses* number)const&;
	bool operator>(const list_of_offenses* number)const&;
	bool operator<=(const list_of_offenses* number)const&;
	bool operator>=(const list_of_offenses* number)const&;
	bool operator==(const list_of_offenses* number)const&;
	bool operator!=(const list_of_offenses* number)const&;

	void addnewoffenses(offense *o);
	void deloffenses(int id);
	void show();

    int getnumber();
	int getsize();

	friend ofstream & operator<<(ofstream & out, list_of_offenses & st);
	friend ifstream & operator>>(ifstream & out, list_of_offenses & st);

	~list_of_offenses();
};

