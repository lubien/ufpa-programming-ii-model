#ifndef _MODEL_H_
#define _MODEL_H_

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Model {
	friend ostream &operator<<(ostream &, const Model &);

	public:
		const Model &operator=(const Model &);
		bool operator==(const Model &) const;
		bool operator!=(const Model &right) const;

		Model();
		Model(int);
		Model(const Model &);
		~Model();

		virtual bool save() = 0;
		virtual bool remove() = 0;
		virtual bool update() = 0;
		virtual void printJson() = 0;

		const string resource();

	private:
		const static string RESOURCE;

	protected:
		int id;
};
#endif
