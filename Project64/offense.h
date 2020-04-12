#pragma once
#include <mylib/lib.h>
#include "Date.h"

class offense
{
	string name_offense;
	Date date_offense;
	string description;
	int id;
public:
	offense();
	offense(string name_offense);
	offense(string name_offense ,Date date_offense);
	offense(string name_offense, Date date_offense, string description);

	void setname(string name);
	void setdate(Date date);
	void setdescription(string description);

	string getname();
	Date getdate();
	string getdescription();

	int getid();
	void setid(int id);

	friend istream & operator>>(istream & out, offense & st);
	friend ostream & operator<<(ostream & out, offense & st);
	friend ofstream & operator<<(ofstream & out, offense & st);
	friend ifstream & operator>>(ifstream & out, offense & st);

	~offense();
};

