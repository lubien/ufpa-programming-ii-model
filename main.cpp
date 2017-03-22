#include <iostream>
#include <string>
#include <vector>
#include "Model.h"
#include "User.h"
#include "Todo.h"
#include "Post.h"
using namespace std;

int main() {
	vector<Model*> models(3);
	models[0] = new User;
	models[1] = new Todo;
	models[2] = new Post;

	for (size_t i = 0; i < models.size(); i++) {
		cout << i << endl;
		cout << (*models[i]) << endl;

		Model *derivedPtr = dynamic_cast<Model*>(models[i]);

		if (derivedPtr != 0) {
			cout << (*derivedPtr) << endl << endl;
		}
	}

	for (size_t i = 0; i < models.size(); i++) {
		// There's none cout since destructors print messages
		delete models[i];
	}
}
