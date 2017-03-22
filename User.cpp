#include "User.h"
using namespace std;

const string User::RESOURCE = "user";
vector<User*> users;

User::User()
:username(""), role(0) {
	this->id = -1;
}

User::User(unsigned int id) {
	if (User::has(id)) {
		this->username = users.at(id)->username;
		this->role = users.at(id)->role;
	} else {
		this->id = -1;
	}
}

User::User(const string &username, int role)
:username(username), role(role) {
	this->id = -1;
}

User::User(const User &user)
:username(user.username), role(user.role) {
	this->id = user.id;
}

User::~User() {
	cout << "Destroying " << *this << endl;
}

// Operators

ostream &operator<<(ostream &out, const User &user) {
	out << "User(";

	if (user.id != -1) {
		out << user.id << ", '" << user.username << "'";
	}

	out << ")";
	return out;
}

const User &User::operator=(const User &right) {
	this->id = right.id;
	this->username = right.username;
	this->role = right.role;
	return *this;
}

bool User::operator==(const User &right) const {
	return (this->id == right.id) && (this->id != -1);
}

bool User::operator!=(const User &right) const {
	return !(*this == right);
}

// Public

bool User::has(int id) {
	if (id == -1) {
		return false;
	}

	try {
		return users.at(id) != NULL;
	} catch (out_of_range e) {
		return false;
	}
	return true;
}

bool User::save() {
	if (this->id == -1) {
		this->id = users.size();
		users.push_back(this);
		return true;
	} else if (!User::has(this->id)) {
		users.at(this->id) = this;
		return true;
	}

	return false;
}

bool User::remove() {
	if (User::has(this->id)) {
		users.at(this->id) = NULL;
		return true;
	}
	return false;
}

bool User::update() {
	if (User::has(this->id)) {
		users.at(this->id) = this;
		return true;
	}
	return false;
}

string User::getUsername() {
	return this->username;
}

void User::setUsername(const string &username) {
	this->username = username;
}

int User::getRole() {
	return this->role;
}

void User::setRole(int role) {
	this->role = role;
}

const string User::resource() {
	return User::RESOURCE;
}
