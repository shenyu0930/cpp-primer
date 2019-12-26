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
	ifstream inf("cppprimer_10_33.txt");
	ofstream outf1("cppprimer_10_33_out1.txt");
	ofstream outf2("cppprimer_10_33_out2.txt");
	istream_iterator<int> in_iter(inf);
	istream_iterator<int> eof;
	ostream_iterator<int> out_iter1(outf1, " ");
	ostream_iterator<int> out_iter2(outf2, " ");
	for_each(in_iter, eof, [&out_iter1, &out_iter2](int i) {return *(i % 2 ? out_iter1 : out_iter2) = i; });
	//while (in_iter != eof) {
	//	//odd
	//	if (*in_iter % 2) {
	//		*out_iter1 = *in_iter;
	//	}
	//	else {
	//		*out_iter2 = *in_iter;
	//	}
	//	++in_iter;
	//}

	return 0;
}