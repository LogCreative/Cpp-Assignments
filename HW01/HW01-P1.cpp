// CS154-HW01-Problem 1.cpp

#include <iostream>

using namespace std;

int main()
{
	int a, b;
	float c, d;
	float average;
	int app_average;

	//输入
    cout << "Input:";
	cin >> a;

	cout << "Input:";
	cin >> b;

	cout << "Input:";
	cin >> c;

	cout << "Input:";
	cin >> d;

	//运算
	average = ((float)a + (float)b + c + d) / 4.0;
	(average - (int)average) >= 0.5 ? app_average = (int)average + 1 : app_average = (int)average;

	//输出
	cout << "Output:" << average << endl;
	cout << "Output:" << app_average << endl;

	return 0;
}

