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
	vector<string> svec;
	string word;
	while (cin >> word && word != "quit") {
		if (find(svec.begin(), svec.end(), word) == svec.end()) {
			svec.push_back(word);
		}
	}
	for_each(svec.begin(), svec.end(), [](const string& s) {cout << s << " "; });
	return 0;
}