#include<iostream>
#include<fstream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<numeric>
#include<iterator>
#include<functional>
#include<map>
#include<set>
using namespace std;

int main() {
	map<string, vector<string>> famalies;
	string lastName, firstName;
	while ([&]()->bool {
		cout << "Please input lastName: " << endl;
		return cin >> lastName && (lastName != "quit");
	}()) {
		cout << "Please input firstNames: " << endl;
		while (cin >> firstName && (firstName != "quit")) {
			famalies[lastName].push_back(firstName);
		}

	}
	for (auto f : famalies) {
		cout << f.first << ": " << endl;
		for (auto s : f.second) {
			cout << s << "  ";
		}
		cout << "\n";
	}
	return 0;
}