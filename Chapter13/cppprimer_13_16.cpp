#include<string>
#include<iostream>
#include<vector>
class numbered {
public:
	numbered() {
		static int n = 0;
		mysn = n++;
	}
	numbered(const numbered& s) {
		mysn = s.mysn + 1;
	}
	int mysn=0;
};
void f(const numbered &s) {
	std::cout << s.mysn << std::endl;
}
int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}