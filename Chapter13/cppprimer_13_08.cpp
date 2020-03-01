#include<string>
#include<iostream>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {};
	HasPtr(const HasPtr& hp) :ps(new std::string(*hp.ps)), i(hp.i) {};
	HasPtr& operator=(const HasPtr& hp_eq) {
		std::string* p = new std::string(*hp_eq.ps);
		delete ps;
		ps = p;
		i = hp_eq.i;
		return *this;
	}
private:
	std::string* ps;
	int i;
};
int main()
{
	return 0;
}