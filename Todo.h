#ifndef _TODO_H_
#define _TODO_H_

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "Model.h"
#include "Date.h"
using namespace std;

class Todo : public Model {
	friend ostream &operator<<(ostream &, Todo &);

	public:
		const Todo &operator=(const Todo &);
		bool operator==(const Todo &) const;
		bool operator!=(const Todo &right) const;

		Todo();
		Todo(unsigned int);
		Todo(const string &);
		Todo(const Todo &);
		~Todo();

		static bool has(int);
		bool save();
		bool remove();
		bool update();

		string getTitle();
		void setTitle(const string &);
		void finish();
		bool finished();

		const string resource();

	private:
		string title;
		Date* start;
		Date* end;
		const static string RESOURCE;
};
#endif
