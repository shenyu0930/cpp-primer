#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>

using namespace std;
void func() {
	int i = 10;
	auto f = [&i]()->int {while (i != 0) { --i; }; return i; };
	cout << f();
}
int main() {
	func();

	return 0;
}