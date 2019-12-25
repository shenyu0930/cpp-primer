#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool check_size(string& s1, string::size_type sz) {
	return s1.size() < sz;
}
auto findFirstBigger(const vector<int>& svec, const string& s) {
	return find_if(svec.begin(), svec.end(), bind(check_size, s, _1));
}
int main() {
	string str("hello");
	vector<int> svec{ 1,2,3,4,5,6,7 };
	//vector<string> svec{ "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa" };
	cout << *findFirstBigger(svec, str);
	return 0;
}