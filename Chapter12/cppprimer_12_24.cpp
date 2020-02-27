
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
	string s;
	cin >> s;
	unsigned len = s.size() + 1;
	char* p = new char[len];
	strcpy_s(p, len, s.c_str());
	cout << p << endl;

	delete[] p;
	return 0;
}