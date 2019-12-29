#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<utility>
#include<map>
using namespace std;

int main() {
	map<string, vector<pair<string, string>>> famalies;
	string lastName, firstName;
	string birthday;
	while ([&]()->bool {
		cout << "Please input lastName: " << endl;
		return cin >> lastName && (lastName != "quit");
	}()) {
		cout << "Please input firstNames: " << endl;
		while (cin >> firstName && (firstName != "quit")) {
			cin >> birthday;
			famalies[lastName].push_back({firstName, birthday});
		}

	}
	for (auto f : famalies) {
		cout << f.first << ": " << endl;
		for (auto s : f.second) {
			cout << s.first << "  " << s.second << "\n";
		}
		cout << "\n";
	}
	return 0;
}