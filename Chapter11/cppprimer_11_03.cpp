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
	map<string, size_t> word_count;
	set<string> exclude = { "hi","hello" };
	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
	}
	for (const auto& w : word_count) {
		cout << w.first << " occurs " << w.second << " times.";
	}
	return 0;
}