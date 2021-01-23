#include <iostream>
using namespace std;

//此处填补两行代码 x>y
char myfun(int& a, int& b);

int myfun(int* a, int* b);

int main() {
	int x, y;
	cout << "Input:";
	cin >> x >> y;
	cout << "Output:";
	cout << myfun(x, y);
	cout << x << ' ' << y;
	return 0;
}

int myfun(int* a, int* b) {
	int c = *a - *b;
	*a *= 2;
	*b *= 3;
	return c;
}

//此处定义一个函数，只有两行代码，不包含任何数组名
char myfun(int& a, int& b) {
	cout << -myfun(&b, &a) % 10;
	return ' ';
}