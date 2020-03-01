#include<string>
#include<iostream>
#include<vector>
class numbered {
public:
	numbered() {
		static int n = 0;
		mysn = n++;
	}
	int mysn;
};
void f(numbered s) {
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