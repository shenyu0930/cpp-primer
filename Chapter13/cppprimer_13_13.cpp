#include<string>
#include<iostream>
#include<vector>
struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator= (const X&) {
		std::cout << "operator=" << std::endl;
		return *this;
	}
	~X() { std::cout << "~X()" << std::endl; }
};
void f(X x1) {

}
void rf(X& x2) {

}
void vf(X x1, X& x2) {
	std::vector<X> vecx;
	vecx.reserve(2);
	vecx.emplace_back();
	vecx.push_back(x2);
}
int main()
{
	X* x = new X;
	vf(*x, *x);
	delete x;

	return 0;
}