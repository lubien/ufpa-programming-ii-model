#include "User.h"
using namespace std;

const string User::RESOURCE = "user";
vector<User*> users;

User::User()
:username(""), role(0) {
	this->id = -1;
	this->todoCount = 0;
	this->todos = new Todo[0];
}

User::User(unsigned int id) {
	if (User::has(id)) {
		this->username = users.at(id)->username;
		this->role = users.at(id)->role;
		this->todoCount = users.at(id)->todoCount;
		this->todos = users.at(id)->todos;
	} else {
		this->id = -1;
		this->todoCount = 0;
		this->todos = new Todo[0];
	}
}

User::User(const string &username, int role)
:username(username), role(role) {
	this->id = -1;
	this->todoCount = 0;
	this->todos = new Todo[0];
}

User::User(const User &user)
:username(user.username), role(user.role) {
	this->id = user.id;
	this->todoCount = user.todoCount;

	for (int i = 0; i < this->todoCount; i++)
		this->todos[i] = user.todos[i];
}

User::~User() {
	delete [] this->todos;
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

void User::addTodo(Todo &todo) {
	Todo *aux = new Todo[this->todoCount];

	for (int i = 0; i < this->todoCount; i++)
		aux[i] = this->todos[i];

	delete [] this->todos;

	this->todoCount++;

	this->todos = new Todo[this->todoCount];

	for (int i = 0; i < this->todoCount - 1; i++)
		this->todos[i] = aux[i];

	this->todos[this->todoCount - 1] = todo;
}

void User::removeTodo(int id) {
	Todo *aux = new Todo[this->todoCount];

	for (int i = 0; i < this->todoCount; i++)
		aux[i] = this->todos[i];

	delete [] this->todos;

	this->todoCount--;

	this->todos = new Todo[this->todoCount];

	for (int i = 0, j = 0; i < this->todoCount; j++) {
		if (aux[j].getId() != id) {
			this->todos[i] = aux[j];
			i++;
		}
	}
}

const string User::resource() {
	return User::RESOURCE;
}
