#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "User.h"
using namespace std;

class Admin : public User {
	friend ostream &operator<<(ostream &, const Admin &);

	public:
		const Admin &operator=(const Admin &);
		bool operator==(const Admin &) const;
		bool operator!=(const Admin &) const;

		Admin();
		Admin(unsigned int);
		Admin(const string &);
		Admin(const Admin &);
		~Admin();

		int getRole();
		void setRole(int);
};
#endif
