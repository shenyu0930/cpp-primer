#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string& s = std::string()) :sp(new std::string(s)), val(0) {}
	HasPtr(const HasPtr& hp):sp(new std::string(*hp.sp)), val(hp.val) {}
	HasPtr& operator= (HasPtr hp) {
		std::cout << "call for" << std::endl;
		swap(*this, hp);
		return *this;
	}
	bool operator< (HasPtr& hp) {
		return this->val < hp.val;
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
	std::vector<HasPtr> vec;
	HasPtr p1(std::string("I"));
	HasPtr p2(std::string("love"));
	HasPtr p3(std::string("you"));
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);

	std::sort(vec.begin(), vec.end());
	return 0;
}