#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>

using namespace std;
void elimDups(vector<string>& s) {
	sort(s.begin(), s.end());
	auto iter = unique(s.begin(), s.end());
	s.erase(iter, s.end());
}
void biggies(vector<string>& s, vector<string>::size_type sz, 
	ostream& os = cout, char c=' ') {
	elimDups(s);
	stable_sort(s.begin(), s.end(), [](const string& s1, const string& s2) {return s1.size() < s2.size(); });
	auto n = count_if(s.begin(), s.end(), [](string& s) {return s.size() > 6; });
	cout << n;
}

int main() {
	vector<string> svec{ "pretext","ensemble","notion","reassure","avocation","I","LOVE","YOU!",
		"pretext","ensemble"};
	biggies(svec, 4);

	return 0;
}