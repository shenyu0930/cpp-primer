#include<iostream>
#include<string>
using namespace std;

void func(string& s, const string& oldVal, const string& newVal) {
	/*insert and erase, replace oldVal with newVal.*/
	auto iter = s.begin();
	while (s.end() - iter >= oldVal.size()) {
		string strtmp(iter, iter + oldVal.size());
		if (strtmp == oldVal) {
			iter = s.erase(iter, iter + oldVal.size());
			iter = s.insert(iter, newVal.begin(), newVal.end());
			++iter;
		}
		else
			++iter;
	}
}


int main() {
	string s = "thozzzzzzzzzzzzzthozzzzzzztho";
	string oldVal = "tho";
	string newVal = "though";
	func(s, oldVal, newVal);
	cout << s;
	return 0;
}