#include<string>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :sp(new std::string(s)), val(0), use_count(new size_t(1)) {}
	HasPtr(HasPtr& hp):sp(hp.sp), val(hp.val), use_count(hp.use_count) {
		++*use_count;
	}
	HasPtr& operator= (HasPtr& hp) {
		++*hp.use_count;
		--*use_count;
		if (*use_count == 0) {
			delete sp;
			delete use_count;
		}
		sp = hp.sp;
		val = hp.val;
		use_count = hp.use_count;
		return *this;
	}
	~HasPtr() {
		--*use_count;
		if (use_count == 0) {
			delete use_count;
			delete sp;
		}
	}
private:
	std::string* sp;
	int val;
	size_t* use_count;
};
int main()
{
	return 0;
}