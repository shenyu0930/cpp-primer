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
using namespace std;


int main() {
	vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };
	list<int> lst;
	lst.resize(5);
	reverse_copy(vec.begin() + 3, vec.begin() + 8, lst.begin());
	for_each(lst.begin(), lst.end(), [](int i) {cout << i << "  "; });
	return 0;
}