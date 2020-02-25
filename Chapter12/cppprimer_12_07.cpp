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
using namespace std;
shared_ptr<vector<int>> dynamic_vector_generator() {
	return make_shared<vector<int>>();
}
void dynamic_vector_processor(shared_ptr<vector<int>> vec) {
	int i;
	cout << "print numbers:" << endl;
	while (cin >> i && i != 999) {
		vec->push_back(i);
	}
}
void dynamic_vector_printer(shared_ptr<vector<int>> vec) {
	for (auto& i : (*vec)) {
		cout << i << endl;
	}
}
int main() {
	shared_ptr<vector<int>> vec = dynamic_vector_generator();
	dynamic_vector_processor(vec);
	dynamic_vector_printer(vec);
	return 0;
}