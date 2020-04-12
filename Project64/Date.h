#pragma once
#include <mylib/lib.h>

class Date
{
	int d;
	int m;
	int y;
public:
	Date();
	Date(int month);
	Date(int month, int day);
	Date(int month, int day, int year);
	Date(const Date&obj);
	//~Date();

	void setDay(int d);
	int getDay();

	void setMonth(int m);
	int getMonth();

	void setYear(int y);
	int getYear();
	
	const char * getSMonth();

	void print();
	bool leap();
	int countm();
	int gigeday();
	Date givedata(int day);
	Date& operator ++();
	Date& operator --();
	/*Date operator -(Date &other);*/
	Date operator +(Date &other);
	int operator -(Date &other);
	//int operator +(Date &other);
	bool operator == (const Date&obj);
	bool operator != (const Date&obj);
	bool operator > (const Date&obj);
	bool operator < (const Date&obj);
	bool operator <= (const Date&obj);
	bool operator >= (const Date&obj);

	Date& operator = (const Date&obj);
	Date& operator += (int n);
	Date& operator -= (int n);
    void getNowDate();

	int monthDays();
	void tonextDate();

	void toprevDate();
	Date  operator +(int n);
	Date operator -(int n);

	friend ofstream& operator << (ofstream & out, Date& st);
	friend ifstream& operator >> (ifstream & out, Date& st);
	friend ostream& operator << (ostream & out, Date& st);
	friend istream& operator >> (istream & out, Date& st);

};