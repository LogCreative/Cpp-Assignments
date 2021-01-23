/*把右侧代码补充完整，包括在 main函数之前
添加 2行代码以及在最后添加一个函数的定
义，使得 该程序能在一行里输出三个数 输出
的 第一个 数是 x（即用户输入的第一个数）减
去 y（即用户输入的第二个数）的差的个位数
第二个数是 x的 3倍，第三个数是 y的 2倍。*/

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