#include "Todo.h"
using namespace std;

const string Todo::RESOURCE = "todo";
vector<Todo*> todos;

Todo::Todo()
:title("") {
	this->id = -1;
	this->start = Date::now();
}

Todo::Todo(unsigned int id) {
	if (Todo::has(id)) {
		this->title = todos.at(id)->title;
		this->start = todos.at(id)->start;
		this->end = todos.at(id)->end;
	} else {
		this->id = -1;
		this->start = Date::now();
	}
}

Todo::Todo(const string &title)
:title(title) {
	this->id = -1;
	this->start = Date::now();
}

Todo::Todo(const Todo &todo)
:title(todo.title), start(todo.start), end(todo.end) {
	this->id = todo.id;
}

Todo::~Todo() {
	cout << "Destroying " << *this << endl;
}

// Operators

ostream &operator<<(ostream &out, Todo &todo) {
	out << "Todo(";

	if (todo.id != -1) {
		out << todo.id << ", '" << todo.title << "', "
				<< (todo.finished() ? "[Finished]" : "[In Progress]");
	}

	out << ")";
	return out;
}

const Todo &Todo::operator=(const Todo &right) {
	this->id = right.id;
	this->title = right.title;
	this->start = right.start;
	this->end = right.end;
	return *this;
}

bool Todo::operator==(const Todo &right) const {
	return (this->id == right.id) && (this->id != -1);
}

bool Todo::operator!=(const Todo &right) const {
	return !(*this == right);
}

// Public

bool Todo::has(int id) {
	if (id == -1) {
		return false;
	}

	try {
		return todos.at(id) != NULL;
	} catch (out_of_range e) {
		return false;
	}
	return true;
}

bool Todo::save() {
	if (this->id == -1) {
		this->id = todos.size();
		todos.push_back(this);
		return true;
	} else if (!Todo::has(this->id)) {
		todos.at(this->id) = this;
		return true;
	}

	return false;
}

bool Todo::remove() {
	if (Todo::has(this->id)) {
		todos.at(this->id) = NULL;
		return true;
	}
	return false;
}

bool Todo::update() {
	if (Todo::has(this->id)) {
		todos.at(this->id) = this;
		return true;
	}
	return false;
}

string Todo::getTitle() {
	return this->title;
}

void Todo::setTitle(const string &title) {
	this->title = title;
}

void Todo::finish() {
	this->end = Date::now();
}

bool Todo::finished() {
	return this->end != NULL;
}

const string Todo::resource() {
	return Todo::RESOURCE;
}
