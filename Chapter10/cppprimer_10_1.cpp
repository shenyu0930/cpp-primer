#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;

int main() {
	vector<int> svec{ 1,2,3,4,1,1,1 };
	cout << count(svec.cbegin(), svec.cend(), 1);
	return 0;
}