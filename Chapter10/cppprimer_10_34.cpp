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
	for_each(vec.rbegin(), vec.rend(), [](int& i) {cout << i << " "; });
	return 0;
}