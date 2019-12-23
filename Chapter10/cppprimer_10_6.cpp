#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;

int main() {
	list<int> lst{ 1,2,3 };
	vector<int> svec;
	svec.resize(3);
	copy(lst.cbegin(), lst.cend(), svec.begin());
	return 0;
}