// CS154-HW03-P2.cpp

#include <iostream>
#include <cstring>

#define MAXLINE 110							//10单词*10字母+9空格+‘\0’

using namespace std;

int main() {

	cout << "Input:";
	char input[MAXLINE];
	cin.getline(input, MAXLINE);

	//按空格分隔单词

	int i = 0;								//字符串下标
	char word[11] = { 0 };					//临时存储单词
	int j = 0;								//单词下标

	char lengroup[10][101] = { 0 };			//以单词长度为标准编组：'\0'
	int colcount[10] = { 0 };				//编组行计数
	int linewordnum[10] = { 0 };			//行单词数
	int k;									//单词列计数


	bool flag = false;						//这个flag用了两次

	for (i = 0; input[i] != '\0'; ++i) {	//字符串下标增加，到\0为止

		if (input[i + 1] == '\0')			//即将结束
			flag = true;

		word[j] = input[i];					//存储字符到word中
		++j;								//移动下标j
		if (input[i + 1] == ' '				//如果下一个是空格
			|| flag == true) {				//或者是即将结束

			if(!flag)
				++i;						//跳过空格

			for (k = 0; k <= j; ++k) {		//把word存储到lengroup中
				lengroup[j][colcount[j]] = word[k];
				colcount[j]++;				//colcount刷新
				word[k] = 0;				//清空word
			}
			colcount[j]--;					//多进一格退一
			j = 0;							//初始化j
			++linewordnum[j];				//增加单词数

		}									//继续上述过程
	}

	//冒泡排序法：对字符串长度排序

	//建立记录长度数组
	int grouplen[2][10] = { 0 };
	for (k = 0; k < 10; ++k) {
		grouplen[0][k] = k;					//第一行为单词长度组序号
		grouplen[1][k] = colcount[k];		//第二行为该组字符串长度
	}

	int tmp;
	for (i = 1; i < 10; ++i) {
		flag = false;
		for (j = 0; j < 10 - i; ++j) {
			if (grouplen[1][j + 1] < grouplen[1][j]			//绝对大小关系
				||(grouplen[1][j + 1] == grouplen[1][j]		//相等时
					&& linewordnum[j + 1] > linewordnum[j]))//合并单词数大的排前面
			{												//交换两列
				for (k = 0; k <= 1; ++k) {
					tmp = grouplen[k][j + 1];
					grouplen[k][j + 1] = grouplen[k][j];
					grouplen[k][j] = tmp;
				}
				flag = true;
			}
		}
		if (!flag)
			break;
	}

	//把字符串拼一起
	for (k = 0; k < 10; ++k) {							    //排序序号层
		if (colcount[grouplen[0][k]] == 0)
			continue;									    //跳过空行
		for (j = 0; j <= colcount[grouplen[0][k]]-1; ++j)	//长度组层
			cout << lengroup[grouplen[0][k]][j];
		cout << " ";
	}

}
