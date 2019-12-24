#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;
bool isShorterThan5(const string& s1) {
	/*const is compulsory*/
	return s1.size() < 5;
}

int main() {
	vector<string> svec{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	auto iter = partition(svec.begin(), svec.end(), isShorterThan5);
	for (auto s = iter; iter != svec.end(); ++iter) {
		cout << *iter << "   ";
	}
	return 0;
}