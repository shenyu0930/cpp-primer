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
	ifstream in("cppprimer_10_29.txt");
	istream_iterator<string> in_iter(in);
	istream_iterator<string> eof;
	ostream_iterator<string> out_iter(std::cout," ");
	vector<string> svec;
	copy(in_iter, eof, back_inserter(svec));
	copy(svec.cbegin(), svec.cend(), out_iter);
	return 0;
}