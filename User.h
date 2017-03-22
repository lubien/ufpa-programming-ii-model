#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "Model.h"
#include "Todo.h"
using namespace std;

class User : public Model {
	friend ostream &operator<<(ostream &, const User &);

	public:
		const User &operator=(const User &);
		bool operator==(const User &) const;
		bool operator!=(const User &) const;

		User();
		User(unsigned int);
		User(const string &, int);
		User(const User &);
		~User();

		static bool has(int);
		bool save();
		bool remove();
		bool update();

		string getUsername();
		void setUsername(const string &);
		int getRole();
		void setRole(int);
		void addTodo(Todo &);
		void removeTodo(int);

		const string resource();

	private:
		string username;
		int role;
		Todo *todos;
		int todoCount;
		const static string RESOURCE;
};
#endif
