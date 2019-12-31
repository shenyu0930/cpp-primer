#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<utility>
#include<map>
#include<set>
#include<typeinfo>
#include<iterator>
using namespace std;

int main() {
	multimap<string, string> families;
	string firstName, lastName;
	while ([&]()->bool {return cin >> firstName && firstName != "quit"; }()) {
		cin >> lastName;
		families.insert({ firstName, lastName });
	}
	for (auto family : families) {
		cout << family.first << "  " << family.second << endl;
	}
	return 0;
}