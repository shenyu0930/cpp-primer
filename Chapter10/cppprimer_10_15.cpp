#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;
int func(int n) {
	auto f = [n](int m) {return m + n; };
	return f(2);
}
int main() {
	cout << func(1);
	return 0;
}