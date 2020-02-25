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
	for (auto iter = smmap.begin(); iter != smmap.end(); ++iter) {
		cout << iter->first << ": " << iter->second << endl;
	}
	return 0;
}