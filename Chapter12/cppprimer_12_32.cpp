
#include<iostream>
#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<memory>
#include<sstream>
using line_no = std::vector<std::string>::size_type;
class QueryResult;
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
StrBlob::StrBlob() :data(std::make_shared<std::vector<std::string>>()) {};
StrBlob::StrBlob(std::initializer_list<std::string> i1) :data(std::make_shared<std::vector<std::string>>(i1)) {};
void StrBlob::check(size_type i, const std::string msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}
std::string& StrBlob::front() {
	check(0, "front on an empty strBlob");
	return data->front();
}
std::string& StrBlob::back() {
	check(0, "back on an empty strBlob");
	return data->back();
}
const std::string& StrBlob::front() const {
	check(0, "front on an empty strBlob");
	return data->front();
}
const std::string& StrBlob::back() const {
	check(0, "back on an empty strBlob");
	return data->back();
}
void StrBlob::pop_back() {
	check(0, "pop_back on an empty strBlob");
	data->pop_back();
}
void StrBlob::push_back(const std::string& s) {
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
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t sz, const std::string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
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
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	//std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<StrBlob> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
}; TextQuery::TextQuery(std::ifstream& ifs) :file(new StrBlob) {
	std::string text;
	while (getline(ifs, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<StrBlob> f,
		std::shared_ptr<std::set<line_no>> l);
private:
	std::string sought;
	std::shared_ptr<StrBlob> file;
	std::shared_ptr<std::set<line_no>> lines;
};
QueryResult::QueryResult(std::string s, std::shared_ptr<StrBlob> f,
	std::shared_ptr<std::set<line_no>> l):sought(s), file(f), lines(l) {
}
QueryResult TextQuery::query(const std::string& sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, file, nodata);
	else
		return QueryResult(sought, file, loc->second);
}
std::ostream& print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " << ((qr.lines->size() > 1) ? "times":"time")
		<< std::endl;
	for (auto& it : *qr.lines) {
		StrBlobPtr ptr(*qr.file, it);
		os << "\t(line " << it + 1 << ")" << ptr.deref() << std::endl;
	}
	return os;
}
void runQueries(std::ifstream& ifs) {
	TextQuery tq(ifs);
	while (true) {
		std::cout << "enter word to look for, or q to quit:";
		std::string s;
		if (!(std::cin >> s) || s == "q") {
			break;
		}
		print(std::cout, tq.query(s)) << std::endl;
	}
}
int main()
{
	std::ifstream ifs("D:/C++test/leetcode_test/cppprimer_12_21.txt");
	runQueries(ifs);
	return 0;
}