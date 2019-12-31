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
	map<string, string::size_type> word_count;
	set<string> exclude = { "The", "But", "And", "Or", "An", "A",
		"the", "but", "and", "or", "an", "a" };
	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			auto iter = word_count.insert({ word, 1 });
			if (!iter.second) {
				++iter.first->second;
			}
		}
	}
	for (auto ele : word_count) {
		cout << ele.first << "  " << ele.second << "\n";
	}
	return 0;
}