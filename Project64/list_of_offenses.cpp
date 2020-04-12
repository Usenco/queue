#include "list_of_offenses.h"



list_of_offenses::list_of_offenses(int number)
{
	if (number > 0) {
		this->number = number;
	}
	index = 0;
	this->size = 0;
}

bool list_of_offenses::operator<(const list_of_offenses* number) const &
{
	if (this->number < number->number)return 1;
	else return 0;
}

bool list_of_offenses::operator>(const list_of_offenses* number) const &
{
	if (this->number > number->number)return 1;
	else return 0;
}

bool list_of_offenses::operator<=(const list_of_offenses* number) const &
{
	if (number->number >= this->number)return 1;
	else return 0;
}

bool list_of_offenses::operator>=(const list_of_offenses* number) const &
{
	if (this->number >= number->number)return 1;
	else return 0;
}

bool list_of_offenses::operator==(const list_of_offenses* number) const &
{
	if (this->number == number->number)return 1;
	else return 0;
}

bool list_of_offenses::operator!=(const list_of_offenses* number) const &
{
	if (this->number != number->number)return 1;
	else return 0;
}

void list_of_offenses::addnewoffenses(offense * o)
{
	size++;
	index++;
	offense u = *o;
	l.push_back(u);
	l.back().setid(index);
}

void list_of_offenses::deloffenses(int id)
{
	if (l.size() > 0) {
		int i = 0;
		for (list<offense>::iterator it = l.begin();
			it != l.end(); it++) {
			if ((*it).getid() == id) {
				l.erase(it); size--; break;
			}
		}
	}
}

void list_of_offenses::show()
{
	int i =0;
	for (offense &s : l) {
		i++;
		cout << "\tØòğàô ¹" << i << endl;
		cout << s;
	}
}

int list_of_offenses::getnumber()
{
	return number;
}

int list_of_offenses::getsize()
{
	return size;
}


list_of_offenses::~list_of_offenses()
{
}

ofstream & operator<<(ofstream & out, list_of_offenses & st)
{
	out << st.index<<endl;
	out << st.number<<endl;
	out << st.l.size()<<endl;
	for (int i = 0; i < st.l.size(); i++) {
		out << st.l.back();
	}
	return out;
}

ifstream & operator>>(ifstream & out, list_of_offenses & st)
{
	out >> st.index;
	out >> st.number;
	int n;
	out >> n;
	for (int i = 0; i < n; i++) {
		offense u;
		out >> u;
		st.l.push_back(u);
	}
	return out;
}
