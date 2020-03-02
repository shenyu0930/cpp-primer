#include<string>
#include<iostream>
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string& s = std::string()) :sp(new std::string(s)), val(0) {}
	HasPtr(HasPtr& hp):sp(new std::string(*hp.sp)), val(hp.val) {}
	HasPtr& operator= (HasPtr hp) {
		std::cout << "call for" << std::endl;
		swap(*this, hp);
		return *this;
	}
	~HasPtr() {
		delete sp;
	}
private:
	std::string* sp;
	int val;
};
inline void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.sp, rhs.sp);
	swap(lhs.val, rhs.val);
}
int main()
{
	HasPtr p1;
	HasPtr p2;
	p2 = p1;
	return 0;
}