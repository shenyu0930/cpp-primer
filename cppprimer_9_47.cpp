#include<iostream>
#include<string>
using namespace std;

int main() {
	const string str("ab2c3d7R4E6");
	const string numbers("0123456789");
	string::size_type pos = 0;
	while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
		cout << "number is: " << str.at(pos) << ", index is: " << pos << "." << endl;
		pos++;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
		cout << "letter is: " << str.at(pos) << ", index is: " << pos << "." << endl;
		pos++;
	}
	return 0;
}