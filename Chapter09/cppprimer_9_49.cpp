#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main() {
	string ss = "bdfghijklpqty";
	ifstream in("cppprimer_9_49.txt");
	string str;
	int count = 0;
	vector<string> res;
	while (in >> str) {
		if (str.find_first_of(ss) == string::npos) {
			if (str.size() > count) {
				res.clear();
				res.push_back(str);
			}
			if(str.size() == count){
				res.push_back(str);
			}
			count = str.size();
		}
			
	}
	for (auto s : res) {
		cout << s << endl;
	}
	return 0;
}