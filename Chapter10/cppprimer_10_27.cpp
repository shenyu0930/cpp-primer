#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
#include<functional>
using namespace std;


int main() {
	vector<string> svec{ "I","love","you!!","forever","I","love","you__" };
	list<string> lst;
	sort(svec.begin(), svec.end(), [](string& s1, string& s2) {return s1.size() < s2.size(); });
	unique_copy(svec.begin(), svec.end(), inserter(lst, lst.begin()));
	for_each(lst.begin(), lst.end(), [](const string& s) {cout << s << "  "; });
	return 0;
}