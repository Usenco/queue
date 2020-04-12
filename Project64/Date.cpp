#include "Date.h"

Date::Date()
{

	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);
	y = 1900 + tim->tm_year;
	m = 1 + tim->tm_mon;
	d = tim->tm_mday;
}
const char * Date::getSMonth()
{

	char*mon = new char[17];
	switch (this->m) {
	case 1:
		strcpy(mon, "Sichen");
		return mon;
		break;
	case 2:
		strcpy(mon, "Gruden");
		return mon;
		break;
	case 3:
		strcpy(mon, "Berezen");
		return mon;
		break;
	case 4:
		strcpy(mon, "Kviten");
		return mon;
		break;

	case 5:
		strcpy(mon, "Traven");
		return mon;
		break;
	case 6:
		strcpy(mon, "Cherven");
		return mon;
		break;
	case 7:
		strcpy(mon, "Lipen");
		return mon;
		break;
	case 8:
		strcpy(mon, "Serpen");
		return mon;
		break;
	case 9:
		strcpy(mon, "Veresen");
		return mon;
		break;
	case 10:
		strcpy(mon, "Jovten");
		return mon;
		break;
	case 11:
		strcpy(mon, "Listopad");
		return mon;
		break;
	case 12:
		strcpy(mon, "Gruden");
		return mon;
		break;
	}
	return nullptr;
}
Date::Date(int day) :Date() {
	if(day >0 && day < 32)
	   this->d = day;
}
Date::Date(int day, int month) : Date(day) {
	if (month > 0 && month < 12)
	    this->m = month;
}
Date::Date(int day, int month, int year) : Date(day, month) {
	if (month > 0 )
	     this->y = year;
}

Date::Date(const Date & obj)
{
	this->d = obj.d;
	this->m = obj.m;
	this->y = obj.y;
}

void Date::setDay(int d)
{
	this->d = d;
}

void Date::print() {
	cout << d << "\\" << m << "\\" << y << endl;
}
bool Date::leap() {
	if (y % 4 == 0) {
		if (y % 100 == 0) {
			if (y % 400 == 0)return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}
int Date::countm() {
	if (leap()) {
		if (m <= 7) {
			if (m % 2 == 0) {
				if (m == 2)return 29;
				else return 30;
			}
			else return 31;
		}
		else {
			if (m % 2 == 0)return 31;
			else return 30;
		}
	}
	else {
		if (m <= 7) {
			if (m % 2 == 0) {
				if (m == 2)return 28;
				else return 30;
			}
			else return 31;
		}
		else {
			if (m % 2 == 0)return 31;
			else return 30;
		}
	}
}
int Date::gigeday()
{
	Date date(d, m, y);
	int days = 0;
	while (date.m != 1 || date.d != 1 || date.y != 1) {
		days++;
		--days;
	}
	return days;
}
Date Date::givedata(int d)
{
	Date date;
	Date date1;
	date.d = 0;
	date.m = 0;
	date.y = 0;
	d = gigeday() - d;
	d = abs(d);
	cout << "day = " << d << endl;
	while (date.countm()<d) {
		date.m++;
		if (date.m==1&&date.countm() == 29|| date.m == 1 && date.countm() == 28)d -= 30;
		else d -= date.countm();
		if (date.m > 12) {
			date.y++;
			date.m = 0;
		}
	}
	date.d = d;
	for (; d > 0; d--) {
		++date1;
	}
	return date1;
}
Date& Date::operator++() {
	tonextDate();
	return *this;
}
Date& Date::operator--() {
	/*d--;
	if (d < 1) {
		m--;
		if (m == 0) {
			m = 12;
			y--;
		}
		d = countm();
	}*/
	toprevDate();
	return *this;
}
int Date::operator-(Date & other)
{
	int n = 0;
	if (*this > other) {
		while (*this != other) {
			this->toprevDate();
			n++;
		}
	}
	else if(*this < other) {
		while (*this != other) {
			this->tonextDate();
			n++;
		}
	}
	n--;
	return n;
}
Date Date::operator+(Date & other)
{
	Date date(1,1,0);
	Date date1;
	date1 = *this;
	//this->m -=  1;
	//other.m -= 1;
	while (date != other)
	{
		++date1;
		++date;
	}
	/*for(int i = 0; i < 32;i++)
	{
		++date1;
		++date;
	}*/
	return date1;
}
bool Date::operator==(const Date & obj)
{
	if (this->d == obj.d && this->m == obj.m && this->y == obj.y)return 1;
	else return 0;
}
bool Date::operator!=(const Date & obj)
{
	if (this->d != obj.d || this->m != obj.m || this->y != obj.y)return 1;
	else return 0;
}
bool Date::operator>(const Date & obj)
{
	if (this->y > obj.y)return 1;
	else if (this->y == obj.y) {
		if (this->m > obj.m)return 1;
		else if (this->m == obj.m) {
			if (this->d > obj.d)return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}
bool Date::operator<(const Date & obj)
{
	if (this->y < obj.y)return 1;
	else if (this->y == obj.y) {
		if (this->m < obj.m)return 1;
		else if (this->m == obj.m) {
			if (this->d < obj.d)return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}
bool Date::operator<=(const Date & obj)
{
	if (this->y <= obj.y)return 1;
	else if (this->y == obj.y) {
		if (this->m <= obj.m)return 1;
		else if (this->m == obj.m) {
			if (this->d <= obj.d)return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}
bool Date::operator>=(const Date & obj)
{
	if (this->y >= obj.y)return 1;
	else if (this->y == obj.y) {
		if (this->m >= obj.m)return 1;
		else if (this->m == obj.m) {
			if (this->d >= obj.d)return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}
Date & Date::operator=(const Date & obj)
{
	this->d = obj.d;
	this->m = obj.m;
	this->y = obj.y;
	return *this;
}
Date & Date::operator+=(int n)
{
	for (int i = 0; i < n; i++) {
		this->tonextDate();
	}
	return *this;
}
Date & Date::operator-=(int n)
{
	for (int i = 0; i < n; i++) {
		this->toprevDate();
	}
	return *this;
}
void Date::getNowDate() {
	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);
	y = 1900 + tim->tm_year;
	m = 1 + tim->tm_mon;
	d = tim->tm_mday;
}

int Date::monthDays()
{
	return 0;
}

void Date::tonextDate()
{
	d++;
	if (m >= 12 && d > 31) {
		m = 1;
		y++;
		d = 1;
	}
	if (monthDays() < d) {
		m++;
		d = 1;
	}
}

void Date::toprevDate()
{
	/*overwrites the previous date*/
	d--;
	if (m == 1 && d == 0) {
		m = 12;
		y--;
		d = 31;
	}
	if (d == 1) {
		m--;
		d = monthDays();
	}
}

Date Date::operator+(int n)
{
	Date date;
	date = *this;
	return date.operator+=(n);
}

Date Date::operator-(int n)
{
	Date date;
	date = *this;
	return date.operator-=(n);
}

int Date::getDay()
{
	return d;
}

void Date::setMonth(int m)
{
	this->m = m;
}

int Date::getMonth()
{
	return m;
}

void Date::setYear(int y)
{
	this->y = y;
}

int Date::getYear()
{
	return y;
}


ofstream & operator<<(ofstream & fout, Date & st)
{
	fout << " " << st.d << " " << st.m << " "
		<< st.y;
	return fout;
}

ifstream & operator>>(ifstream & fin, Date & st)
{
	fin >> st.d >> st.m >> st.y;
	return fin;
}
ostream & operator<<(ostream & fout, Date & st)
{
	fout << "day: " << st.d << "month: " << st.m << "year: "
		<< st.y<<endl;
	return fout;
}

istream & operator>>(istream & fin, Date & st)
{
	cout << "Enter day, month, year: "<<endl;
	fin >> st.d >> st.m >> st.y;
	return fin;
}

