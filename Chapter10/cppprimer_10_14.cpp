#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;

int main() {
	auto f = [](int a, int b) {return a + b; };
	cout << f(1, 2);
	return 0;
}