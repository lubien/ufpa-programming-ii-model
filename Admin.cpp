#include "Admin.h"
using namespace std;

Admin::Admin()
:User() {
	this->role = 10;
}

Admin::Admin(unsigned int id)
:User(id) {
	this->role = 10;
}

Admin::Admin(const string &name)
:User(name, 10) {}

Admin::Admin(const Admin &admin)
:User(static_cast<User>(admin)) {
	this->role = 10;
}

Admin::~Admin() {
	cout << "Destroying " << *this << endl;
}

// Operators

ostream &operator<<(ostream &out, const Admin &admin) {
	out << static_cast<User>(admin);
	return out;
}

const Admin &Admin::operator=(const Admin &right) {
	static_cast<User>(*this) = static_cast<User>(right);
	return *this;
}

bool Admin::operator==(const Admin &right) const {
	return static_cast<User>(*this) == static_cast<User>(right);
}

bool Admin::operator!=(const Admin &right) const {
	return !(static_cast<User>(*this) == static_cast<User>(right));
}

// Public

int Admin::getRole() {
	return 10;
}

void Admin::setRole(int role) {
	// Always 10
}
