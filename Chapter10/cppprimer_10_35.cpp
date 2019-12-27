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
	vector<int> vec{ 1,2,3,4,5,6 };
	for (auto i = vec.end(); i != vec.begin();) {
		cout << *(--i) << "  ";
	}
	return 0;
}