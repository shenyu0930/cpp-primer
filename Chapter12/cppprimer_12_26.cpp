
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<utility>
#include<map>
#include<set>
#include<typeinfo>
#include<iterator>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include<memory>
#include<cstring>
using namespace std;

int main()
{
	allocator<string> alloc;
	unsigned n = 10;
	auto const p = alloc.allocate(n);
	auto q = p;
	string s;
	while (cin >> s && q != p + n) {
		alloc.construct(q++, s);
	}

	while (q != p) {
		cout << (*(--q));
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
	return 0;
}