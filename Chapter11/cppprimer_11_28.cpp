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
	map<string, vector<int>> smap;
	smap = { {"Tom",{1,2,3,4,5}},
				{"Jerry",{6,7,8,9}} };
	map<string, vector<int>>::iterator iter;
	iter = smap.find("Jerry");
	cout << (*iter).second.at(0);
	return 0;
}