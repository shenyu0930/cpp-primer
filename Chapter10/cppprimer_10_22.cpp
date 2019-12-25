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
bool func(string& s) {
	return s.size() <= 6;
}
int main() {
	vector<string> svec{ "I","love","you","forever" };
	auto n = count_if(svec.begin(), svec.end(), func);
	cout << n;

	return 0;
}