#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;

void elimDups(vector<string>& s) {
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << "  ";
	}
	cout << s.size() << endl;
	sort(s.begin(), s.end());
	auto iter = unique(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << "  ";
	}
	cout << s.size() << endl;
	s.erase(iter, s.end());
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << "  ";
	}
	cout << s.size() << endl;
}
int main() {
	vector<string> svec{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(svec);
	return 0;
}