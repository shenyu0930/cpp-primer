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
	multimap<string, string> smmap;
	smmap = { {"Charles Dickens","Oliver Twist"},
	{"Charles Dickens", "Nicholas Nickleby"},
	{"Charles Dickens", "Bleak House"},
	{"Victor Hugo", "Les Orientales"},
	{"Victor Hugo", "Les Feuilles d'automne"},
	{"Hemingway","The Old Man and the Sea"},
	{"Hemingway","Cat in the Rain"} };
	auto iter1 = smmap.lower_bound("Victor Hugo");
	auto iter2 = smmap.upper_bound("Victor Hugo");
	smmap.erase(iter1, iter2);
	for (auto s : smmap) {
		cout << s.first << "  " << s.second << endl;
	}
	return 0;
}