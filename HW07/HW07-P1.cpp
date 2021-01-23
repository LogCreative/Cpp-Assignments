// CS154-HW07-P1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/* 写出右侧代码中的两个函数funA 和funB 的
定义与声明，使得funA 能实现通过指针p 来
访问用户输入的字符串，funB 能将该字符串
中的数字全部变成字符‘0’，并在main 函数
中输出该字符串。要求每个程序块结束时都
要保证没有内存泄漏。
*/

#include <iostream>
#include <cstring>

using namespace std;
// 写出两个函数的声明
char*& funA(char** p);
char* funB(char* b, char* p);

int main() {
	char a[10], b[10];
	for (int i = 0; i < 2; ++i) {
		char** p;
		cout << "Input: ";
		cin >> a;
		funA(p) = a;
		cout << "Output: ";
		cout << funB(b, *p);
	}
	return 0;
}
// 写出两个函数的定义
char*& funA(char** p) {
	return *p; //通过指针p访问用户输入的字符串
}

char* funB(char* b, char* p) {
	int j;
	for (j = 0; j < 10; ++j) {
		if (isdigit(p[j]) == false)
			b[j] = p[j];
		else if (p[j] != '0')
			b[j] = '0';
		else
			b[j] = p[j];
	}
	cout << b << endl;
	return "";
}
