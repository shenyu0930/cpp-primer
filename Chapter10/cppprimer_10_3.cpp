#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;

int main() {
	vector<int> svec{ 1,2,3,4,5,6,7,8,9,10 };
	cout << accumulate(svec.cbegin(), svec.cend(), 0);
	return 0;
}