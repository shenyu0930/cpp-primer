#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<utility>
#include<map>
#include<typeinfo>
using namespace std;

int main() {
	map<string, string::size_type> word_count{ {"dahuang", 10} };
	auto iter = word_count.begin();
	cout << iter->second << endl;
	iter->second = 13;
	cout << iter->second << endl;
	return 0;
}