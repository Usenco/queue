#pragma once
#include "list_of_offenses.h"
#include <set>
class systems
{
	set<list_of_offenses*> s;
public:
	systems();

	void addnewoffer(offense *o,int number);
	void deloffer(int id,int number);
	void show();
	void show_by_number(int number);
	void save(string name_file);
	void load(string name_file);
	void clear();

	~systems();
};

