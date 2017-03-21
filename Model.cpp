#include "Model.h"
using namespace std;

const string Model::RESOURCE = "none";

Model::Model()
:id(-1) {}

Model::Model(int id)
:id(id) {}

Model::Model(const Model &model)
:id(model.id) {}

Model::~Model() {
	cout << "Destroying " << *this << endl;
}

// Operators

ostream &operator<<(ostream &out, const Model &model) {
	out << "Model(" << model.id << ")";
	return out;
}

const Model &Model::operator=(const Model &right) {
	this->id = right.id;
	return *this;
}

bool Model::operator==(const Model &right) const {
	return (this->id == right.id) && (this->id != -1);
}

bool Model::operator!=(const Model &right) const {
	return !(*this == right);
}

// Public

int Model::getId() {
	return this->id;
}

const string Model::resource() {
	return Model::RESOURCE;
}
