#include<iostream>
#include<string>
using namespace std;

void func(string& name, const string& prefix, const string& suffix) {
	/*add prefix and suffix*/
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(" " + suffix);
}


int main() {
	string name = "dahuang";
	string prefix = "Mr.";
	string suffix = "Jr.";
	func(name, prefix, suffix);
	cout << name;
	return 0;
}