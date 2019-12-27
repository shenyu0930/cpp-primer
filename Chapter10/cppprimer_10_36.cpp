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
	list<int> vec{ 0,1,2,3,4,5,6,0,1,2,3 };
	auto iter = find(vec.crbegin(), vec.crend(), 0);
	cout << "最后一个0在" << *(iter.base()) << "之前";
	return 0;
}