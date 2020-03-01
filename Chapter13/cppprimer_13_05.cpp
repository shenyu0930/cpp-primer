#include<string>
#include<iostream>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {};
	HasPtr(HasPtr& hp) :ps(new std::string(*hp.ps)), i(hp.i) {};
private:
	std::string* ps;
	int i;
};
int main()
{
	return 0;
}