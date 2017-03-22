#ifndef _POST_H_
#define _POST_H_

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "Model.h"
#include "Date.h"
using namespace std;

class Post : public Model {
	friend ostream &operator<<(ostream &, Post &);

	public:
		const Post &operator=(const Post &);
		bool operator==(const Post &) const;
		bool operator!=(const Post &right) const;

		Post();
		Post(unsigned int);
		Post(const string &, int);
		Post(const Post &);
		~Post();

		static bool has(int);
		bool save();
		bool remove();
		bool update();

		string getTitle();
		void setTitle(const string &);
		bool isPublished();
		void publish();

		const string resource();

	private:
		string title;
		Date* published;
		Date* modified;
		int revisionCount;
		string *revisions;
		const static string RESOURCE;
};
#endif
