#include "offense.h"



offense::offense()
{
	this->date_offense = Date();
	this->name_offense = "����������� ������� ��������";
	this->description = "���������� ������� �������� �� ��.������� ����� ���� �����������";
}

offense::offense(string name_offense):offense()
{
	if (name_offense.length() > 0) {
		this->name_offense = name_offense;
	}
}

offense::offense(string name_offense, Date date_offense):offense(name_offense)
{
	if (Date() >= date_offense) {
		this->date_offense = date_offense;
	}
}

offense::offense(string name_offense, Date date_offense, string description):offense(name_offense,date_offense)
{
	if (description.length() > 0) {
		this->description = description;
	}
}

void offense::setname(string name)
{
	if (name.length() > 0) {
		this->name_offense = name;
	}
}

void offense::setdate(Date date)
{
	if (Date() >= date) {
		this->date_offense = date;
	}
}

void offense::setdescription(string description)
{
	if (description.length() > 0) {
		this->description = description;
	}
}

string offense::getname()
{
	return this->name_offense;
}

Date offense::getdate()
{
	return this->date_offense;
}

string offense::getdescription()
{
	return this->description;
}

int offense::getid()
{
	return this->id;
}

void offense::setid(int id)
{
	this->id = id;
}


offense::~offense()
{
}

istream & operator>>(istream & out, offense & st)
{
	cout << "������� �������� ������: "; getline(out,st.name_offense);
	cout << "������� �������� ������: "; getline(out,st.description);
	cout << "������� ���� ���������� ������: "; out >> st.date_offense;
	return out;
}

ostream & operator<<(ostream & out, offense & st)
{
	out << "�������� ������: " << st.name_offense << endl;
	out << "�������� ������: " << st.description << endl;
	out << "���� ���������� ������: "<<st.date_offense<<endl;
	out << "id: " << st.id << endl;
	return out;
}

ofstream & operator<<(ofstream & out, offense & st)
{
	out << st.date_offense << endl;
	out << st.description << endl;
	out << st.id << endl;
	out << st.name_offense << endl;
	return out;
}

ifstream & operator>>(ifstream & out, offense & st)
{
	out >> st.date_offense;
	out >> st.description;
	out >> st.id;
	out >> st.name_offense;
	return out;
}
