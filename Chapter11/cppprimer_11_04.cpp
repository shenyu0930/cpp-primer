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
	string word;
	while (cin >> word) {
		for (auto& ch : word) ch = tolower(ch);
		word.erase(std::remove_if(word.begin(), word.end(), ispunct),
			word.end());
		++word_count[word];
	}
	for (const auto& w : word_count) {
		cout << w.first << " occurs " << w.second << " times.";
	}
	return 0;
}