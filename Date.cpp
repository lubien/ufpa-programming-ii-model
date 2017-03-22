#include "Date.h"
using namespace std;

int validDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
:month(11), day(15), year(1996) {
	this->check();
}

Date::Date(int month, int day, int year)
:month(month), day(day), year(year) {
	this->check();
}

Date::Date(const Date &date)
:month(date.month), day(date.day), year(date.year) {
	this->check();
}

Date::~Date() {
	cout << "Destroying " << *this << endl;
}

// Operators

ostream &operator<<(ostream &out, const Date &date) {
	out << date.month << "/" << date.day << "/" << date.year;
	return out;
}

const Date &Date::operator=(const Date &right) {
	this->month = right.month;
	this->day   = right.day;
	this->year  = right.year;
	this->check();
	return *this;
}

bool Date::operator==(const Date &right) const {
	return (this->month == right.month) &&
				 (this->day   == right.day  ) &&
				 (this->year  == right.year );
}

bool Date::operator!=(const Date &right) const {
	return !(*this == right);
}

// Public

Date* Date::now() {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	Date *date = new Date(now->tm_mon + 1, now->tm_mday, now->tm_year + 1900);
	return date;
}

// Private

void Date::check() const {
	if (this->month < 1 || this->month > 12) {
		throw "Invalid month";
	}

	if (this->day < 1 || this->day > validDays[this->day - 1]) {
		throw "Invalid day";
	}
}
