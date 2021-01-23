// CS154-HW04-P1.cpp
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int arr[7];
	int i;
	int myfun(int arr[7]);

	cout << "Input:";
	for (i = 0; i < 7; ++i)
		cin >> arr[i];			// 7 个小于 15 的正整数

	cout << myfun(arr);

	return 0;
}

int myfun(int arr[7]) {			//不能有判断语句

	int k;
	int sum = 0;
	int product = 1;
	int nonzero = 0;			//记录非零整数的个数
	int counter;
	int output = 0;

	for (k = 0; k < 7; ++k) {
		sum += arr[k];							//这些非零整数的和（不被零影响）

		counter = (int)((arr[k] / ((double)(arr[k] + 1))) + 0.5);
		//是0加0，不是零加1
		//采用小数部分被强制转换时被舍弃的特性，x/(x+1)+0.5 -> 0 1 1....<2

		nonzero += counter;
		product *= ((arr[k] - 1)* counter + 1);
												//新数为0时，将会维持原乘积
	}

	//output是一个关于 sum 和 product 的函数：使用取模函数%2，非零整数个数为奇数时，取和
	output = sum * (nonzero % 2) + product * ((nonzero + 1) % 2);

	return output;
}
