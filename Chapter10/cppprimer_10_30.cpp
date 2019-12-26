#include<iostream>
#include<fstream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<numeric>
#include<iterator>
#include<functional>
using namespace std;


int main() {
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	ostream_iterator<int> out_iter(std::cout," ");
	vector<int> svec;
	copy(in_iter, eof, back_inserter(svec));
	sort(svec.begin(), svec.end());
	copy(svec.cbegin(), svec.cend(), out_iter);

	return 0;
}