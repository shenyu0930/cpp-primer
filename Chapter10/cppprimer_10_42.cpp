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
	list<string> lst{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	lst.sort();
	cout << lst.size();
	lst.unique();
	cout << lst.size();
	for_each(lst.begin(), lst.end(), [](string& s) {cout << s << "  "; });
	return 0;
}