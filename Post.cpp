#include "Post.h"
using namespace std;

const string Post::RESOURCE = "post";
vector<Post*> posts;

Post::Post()
:title("") {
	this->id = -1;
	this->revisionCount = 1;
	this->revisions = new string[1];
	this->revisions[0] = "";
}

Post::Post(unsigned int id) {
	if (Post::has(id)) {
		this->title = posts.at(id)->title;
		this->revisionCount = posts.at(id)->revisionCount;
		this->revisions = posts.at(id)->revisions;
	} else {
		this->id = -1;
		this->revisionCount = 1;
		this->revisions = new string[1];
		this->revisions[0] = "";
	}
}

Post::Post(const string &title, int role)
:title(title) {
	this->id = -1;
	this->revisionCount = 1;
	this->revisions = new string[1];
	this->revisions[0] = title;
}

Post::Post(const Post &post)
:title(post.title) {
	this->id = post.id;
	this->revisionCount = post.revisionCount;

	for (int i = 0; i < this->revisionCount; i++)
		this->revisions[i] = post.revisions[i];
}

Post::~Post() {
	delete [] this->revisions;
	cout << "Destroying " << *this << endl;
}

// Operators

ostream &operator<<(ostream &out, Post &post) {
	out << "Post(";

	if (post.id != -1) {
		out << post.id << ", '" << post.title << "'";
		out << (post.isPublished() ? "[Published]" : "[Draft]");
	}

	out << ")";
	return out;
}

const Post &Post::operator=(const Post &right) {
	this->id = right.id;
	this->title = right.title;
	this->published = right.published;
	this->modified = right.modified;
	return *this;
}

bool Post::operator==(const Post &right) const {
	return (this->id == right.id) && (this->id != -1);
}

bool Post::operator!=(const Post &right) const {
	return !(*this == right);
}

// Public

bool Post::has(int id) {
	if (id == -1) {
		return false;
	}

	try {
		return posts.at(id) != NULL;
	} catch (out_of_range e) {
		return false;
	}
	return true;
}

bool Post::save() {
	if (this->id == -1) {
		this->id = posts.size();
		posts.push_back(this);
		this->modified = Date::now();
		return true;
	} else if (!Post::has(this->id)) {
		posts.at(this->id) = this;
		this->modified = Date::now();
		return true;
	}

	return false;
}

bool Post::remove() {
	if (Post::has(this->id)) {
		posts.at(this->id) = NULL;
		return true;
	}
	return false;
}

bool Post::update() {
	if (Post::has(this->id)) {
		posts.at(this->id) = this;
		this->modified = Date::now();
		return true;
	}
	return false;
}

string Post::getTitle() {
	return this->title;
}

void Post::setTitle(const string &title) {
	this->title = title;

	string *aux = new string[this->revisionCount];

	for (int i = 0; i < this->revisionCount; i++)
		aux[i] = this->revisions[i];

	delete [] this->revisions;

	this->revisionCount++;

	this->revisions = new string[this->revisionCount];

	for (int i = 0; i < this->revisionCount - 1; i++)
		this->revisions[i] = aux[i];

	this->revisions[this->revisionCount] = title;
}

bool Post::isPublished() {
	return this->published != NULL;
}

void Post::publish() {
	this->published = Date::now();
}

const string Post::resource() {
	return Post::RESOURCE;
}
