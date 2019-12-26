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

bool check_size(const string& s, string::size_type sz) {
	return s.size() >= sz;
}
void biggies(vector<string>& s, vector<string>::size_type sz) {
	auto iter = partition(s.begin(), s.end(), bind(check_size, _1, sz));
	for_each(s.begin(), iter, [](const string& s) {cout << s << "  "; });
}
int main() {
	vector<string> svec{ "hello","I","love","you","forever" };
	biggies(svec, 5);
	return 0;
}