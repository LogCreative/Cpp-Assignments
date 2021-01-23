// CS154-HW05-p1.cpp

#include <iostream>								//不可包含其它库

using namespace std;

int main()
{
	char str1[20] = { 0 }, str2[20] = { 0 };	//两个长度为 20 的字符数组
	char c;										//一个字符变量,只能进行赋值运算
	char* ptr;									//一个字符指针

	cout << "Input:";	cin.getline(str1, 20);
	cout << "Input:";	cin.getline(str2, 20);

	for (ptr = str1; *ptr != '\0'; ++ptr) {
		if (*(str2 + (ptr - str1)) != '\0') {
			c = *ptr;
			*ptr = *(str2 + (ptr - str1));
			*(str2 + (ptr - str1)) = c;
		}
		else
			break;
	}

	cout << "Output:" << str1 << endl;
	cout << "Output:" << str2 << endl;

	return 0;
}