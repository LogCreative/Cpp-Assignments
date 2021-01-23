//CS154-HW08-P1.cpp

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