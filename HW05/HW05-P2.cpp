// CS154-HW05-p2.cpp

#include <iostream>
#include <cstring>
using namespace std;

bool func(char array[], int len);	//回文数判定

int main() {
	char ch[20];	//用户的输入必定为一串正整数数字 （少于 20 个字符），以回车完成输入
	bool result;	

	cout << "Input:";
	cin >> ch;		

	//填补代码
	result = func(ch, strlen(ch));
	cout << "Output:" << (result == 1 ? "Yes" : "No") << endl;
	//---结束---（4行）

	return 0;
}

bool func(char array[], int len) {
	//不可定义新的变量 、数组或其它对象, 不可使用循环
	//func函数的定义中不可调用库函数
	//填补部分的代码总共不超过 10 行
	
	//填补代码
	if (len == 0 || len == 1)	return 1;
	else {
		if (*array == *(array + len - 1))	func(array + 1, len - 2);
		else	return 0;
	}
	//---结束---（3行）

	//总计：7行

}