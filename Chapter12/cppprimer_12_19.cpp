
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

class StrBlobPtr;
class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	friend class StrBlobPtr;
	StrBlob();
	StrBlob(std::initializer_list<std::string> i1);


	StrBlobPtr begin(); 
	StrBlobPtr end(); 
	size_type size() const { return data->size(); };
	bool empty() const { return data->empty(); };

	void pop_back();
	void push_back(const std::string& s);
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string msg) const;

};
StrBlob::StrBlob() :data(make_shared<std::vector<std::string>>()) {};
StrBlob::StrBlob(std::initializer_list<std::string> i1) :data(make_shared<std::vector<std::string>>(i1)) {};
void StrBlob::check(size_type i, const std::string msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}
string& StrBlob::front() {
	check(0, "front on an empty strBlob");
	return data->front();
}
string& StrBlob::back() {
	check(0, "back on an empty strBlob");
	return data->back();
}
const string& StrBlob::front() const {
	check(0, "front on an empty strBlob");
	return data->front();
}
const string& StrBlob::back() const {
	check(0, "back on an empty strBlob");
	return data->back();
}
void StrBlob::pop_back() {
	check(0, "pop_back on an empty strBlob");
	data->pop_back();
}
void StrBlob::push_back(const string& s) {
	data->push_back(s);
}

class StrBlobPtr {
public:
	StrBlobPtr() :curr(0) {};
	StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {};
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (sz >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	curr++;
	return *this;
}
StrBlobPtr StrBlob::begin() {
	 return StrBlobPtr(*this); 
}
StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, this->size() - 1);
}
int main()
{
	StrBlob t{ "hello", "kano" };
	cout << t.begin().deref();
	cout << t.end().incr();
	return 0;
}