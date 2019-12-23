#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;

int main() {
	vector<string> s{ "hello","123","hello","ddd","eee" };
	list<string> lst(s.cbegin(), s.cend());
	cout << count(lst.cbegin(), lst.cend(), string("hello"));
	return 0;
}