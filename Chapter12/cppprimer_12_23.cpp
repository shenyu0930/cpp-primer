
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
	const char* p1 = "hello";
	const char* p2 = "world";
	int len = strlen(p1) + strlen(p2) + 1;
	char* p = new char[len]();
	strcat_s(p, len, p1);
	strcat_s(p, len, p2);
	cout << p << endl;

	string s1{ "hello" };
	string s2{ "world" };
	int len2 = (s1 + s2).size() + 1;
	char* s = new char[len]();
	strcpy_s(s, len2, (s1 + s2).c_str());
	cout << s << endl;

	delete[] p;
	delete[] s;
	return 0;
}