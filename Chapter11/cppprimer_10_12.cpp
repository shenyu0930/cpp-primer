#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<utility>
#include<map>
using namespace std;

int main() {
	string str;
	int i;
	vector<pair<string, int>> res;
	while (cin >> str && str != "quit") {
		cin >> i;
		res.push_back(make_pair(str, i));
	}
	for (auto s : res) {
		cout << s.first << " " << s.second << "   " << endl;
	}
	return 0;
}