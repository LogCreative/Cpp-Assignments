//CS154-HW08-P1.cpp
/*写出右侧代码中的函数myfun 的定义与声明，并
填补main 函数中的两处代码，使得该程序能进
行两个矩阵A 和B 叉乘的计算，并将计算结果
矩阵显示出来。其中，矩阵A 为3 行n 列，矩阵
B 为n 行3 列。要求A 和B 中的一个矩阵用数
组指针来表示，另一个矩阵用指针数组来表示，
且矩阵B 的所有元素在内存中是连续的。*/

#include <iostream>
using namespace std;

//写出函数myfun 的声明
void myfun(int A[], int* B, int n);

int main() {
	int n;
	cout << "Input n: ";
	cin >> n;
	cout << "Input A: ";
	//在此处填补代码
	
	//定义数组指针
	int** A;
	A = new int* [3];
	for (int i = 0; i < 3; ++i)
		A[i] = new int[n];

	//输入A
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> A[i][j];
	}

	cout << "Input B: ";
	//在此处填补代码
	int* B = new int[n * 3];
	for (int k = 0; k < 3 * n; ++k)
		cin >> B[k];

	cout << "Output:\n";
	for (int i = 0; i < 3; ++i)
		myfun(A[i], B, n);
	return 0;
}
//写出函数myfun 的定义
void myfun(int A[], int* B, int n) {
	int element;
	for (int j = 0; j < 3; ++j) {
		element = 0;
		for (int i = 0; i < n; ++i) {
			element += A[i] * B[i * 3 + j];
		}
		cout << element << " ";
	}
	cout << endl;
}