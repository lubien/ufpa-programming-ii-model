#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <ostream>
using namespace std;

class Date {
	friend ostream &operator<<(ostream &, const Date &);

	public:
		const Date &operator=(const Date &);
		bool operator==(const Date &) const;
		bool operator!=(const Date &) const;

		Date();
		Date(int, int, int);
		Date(const Date &);
		~Date();

	private:
		int month;
		int day;
		int year;

		void check() const;
};
#endif
