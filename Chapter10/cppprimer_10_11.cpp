#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;
bool isShorter(const string& s1, const string& s2) {
	/*const is compulsory*/
	return s1.size() < s2.size();
}
void elimDups(vector<string>& s) {
	sort(s.begin(), s.end());
	auto iter = unique(s.begin(), s.end());
	s.erase(iter, s.end());
}
int main() {
	vector<string> svec{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(svec);
	stable_sort(svec.begin(), svec.end(), isShorter);
	for (auto s : svec) {
		cout << s << "  ";
	}
	return 0;
}