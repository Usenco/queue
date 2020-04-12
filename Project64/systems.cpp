#include "systems.h"



systems::systems()
{
}

void systems::addnewoffer(offense *o,int number)
{
	list_of_offenses *p = new list_of_offenses(number);
	p->addnewoffenses(o);
	bool si = true;
	for (auto st = s.begin(); st != s.end(); st++) {
		if ((*st)->getnumber() == number) {
			(*st)->addnewoffenses(o); si = false;
			break;
		}
	}
	if (si)s.insert(p);
}

void systems::deloffer(int id,int number)
{
	for (auto st = s.begin(); st != s.end(); st++) {
		if ((*st)->getnumber() == number) {
			(*st)->deloffenses(id); 
			if ((*st)->getsize() == 0) {
				s.erase(st);
			}
			break;
		}
	}
}

void systems::show()
{
	for (auto st = s.begin(); st != s.end(); st++) {
		cout << "\t-----------------------\n";
		cout << "\tномер: "<<(*st)->getnumber()<<endl;
		cout << "-----------------------\n";
		(*st)->show();
		cout << "-----------------------\n";
		cout << "\t-----------------------\n";
	}
}

void systems::show_by_number(int number)
{
	for (auto st = s.begin(); st != s.end(); st++) {
		if ((*st)->getnumber() == number) {
			(*st)->show();
			break;
		}
	}
}

void systems::save(string name_file)
{
	ofstream file(name_file);
	if (file.is_open()) {
		file << s.size()<<endl;
		for (auto st = s.begin(); st != s.end(); st++) {
			file << (*(*st));
		}
	}
	file.close();
}

void systems::load(string name_file)
{
	ifstream file(name_file);
	if (file.is_open()) {
		int n;
		file >> n;
		for (int i = 0; i < n;i++) {
			list_of_offenses *new_list = new list_of_offenses(123);
			file >> (*new_list);
			s.insert(new_list);
		}
	}
	file.close();
}

void systems::clear()
{
	s.clear();
}


systems::~systems()
{
}
