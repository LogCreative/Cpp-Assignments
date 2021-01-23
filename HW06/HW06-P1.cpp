//CS154-HW06-P1.cpp
/*
设计一个程序，让用户 输入 一行句子 数出句子中有多少个单词并输出 再
让用户输入一串数字表示单词重新排序的顺序，最后按用户设定的顺序来 输
出 一行新的句子 。 要求 所有 数组 都 只能用 new来 定义。
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAXLINE 101 // 100+'\0'

//所有数组用 new 定义

int atoi(char k) {
	switch (k) {
	case '0':return 0;
	case '1':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case '8':return 8;
	case '9':return 9;
	}
}

int main()
{
	cout << "Input:";
	char* input = new char[MAXLINE];		//输入数组
	cin.getline(input, MAXLINE);

	//按空格分隔单词
	int* wordend = new int[10];								//用于记录单词的末尾位置
	int i = 0;												//用于记录单词序号
	wordend[0] = -2;

	for (int j = 0; input[j] != '\0'; ++j) {



			if (input[j + 1] == ' ') {
				++i;
				wordend[i] = j;
			}
			if (input[j + 1] == '\0') {
				++i;
				wordend[i] = j;
				break;
			}

	}

	//输出单词数
	cout << "Output:" << i << endl;

	//输入数字对其排序
	cout << "Input:";
	char* order = new char[i+1];							//排序号码
	cin.getline(order, i+1);

	//排序并输出
	cout << "Output:";
	int k, m;


	for (k = 0; k < i; ++k) {
		for (m = wordend[atoi(order[k])] + 2; m <= wordend[atoi(order[k]) + 1]; ++m)
			cout<<input[m];
		cout << " ";
	}
	cout << endl;

	//回收动态变量
	delete input;
	delete order;
	delete wordend;

	return 0;
}
