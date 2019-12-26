#include<iostream>
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
	vector<int> num{ 1,2,3,4,5,6,7,8,9 };
	vector<int> svec1, svec2;
	deque<int> deq1;
	//123456789
	copy(num.begin(), num.end(), inserter(svec1, svec1.begin()));
	//123456789
	copy(num.begin(), num.end(), back_inserter(svec2));
	//987654321
	copy(num.begin(), num.end(), front_inserter(deq1));
	return 0;
}