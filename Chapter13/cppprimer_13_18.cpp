#include<string>
#include<iostream>
#include<vector>
int id = 0;
class Employee {
public:
	Employee() {
		ID = id++;
	}
	Employee(const std::string& n) {
		ID = id++;
		name = n;
	}
private:
	int ID;
	std::string name;
};
int main()
{
	return 0;
}