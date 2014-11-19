//
//  main.cpp
//  smarties
//
//  Created by Bob Polis on 11/11/14. <= echt heel gek :-)
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Ding {
private:
	int val;
	char c;
};

int main(int argc, const char * argv[]) {
	vector<unique_ptr<Ding>> dingen;
	for (int i = 0; i < 10; ++i) {
		unique_ptr<Ding> ding{ new Ding };
		dingen.push_back(ding);
	}
	return 0;
}