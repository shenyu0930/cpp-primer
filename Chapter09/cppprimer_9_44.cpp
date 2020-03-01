#include<iostream>
#include<string>
using namespace std;

void func(string& s, const string& oldVal, const string& newVal) {
	/*index and replace, replace oldVal with newVal.*/
	int index = 0;
	while (index != s.size()) {
		string strtmp(s, index, oldVal.size());
		if (strtmp == oldVal) {
			s.replace(index, oldVal.size(), newVal);
			index += newVal.size();
		}
		else {
			++index;
		}
	}
}


int main() {
	string s = "thozzzzzzzzzzzzzthothozzzztho";
	string oldVal = "tho";
	string newVal = "though";
	func(s, oldVal, newVal);
	cout << s;
	return 0;
}