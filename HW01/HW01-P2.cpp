// CS154-HW01-Problem 2.cpp

#include <iostream>

using namespace std;

int main() {

	char alp1, alp2;
	int output1 = 0, output2 = 0;

	//输入
	cout << "Input:";
	cin >> alp1;

	cout << "Input:";
	cin >> alp2;

	//运算
	if (alp1 >= 'A' && alp1 <= 'Z') {
		output1 = (int)alp1 - 64;
	}
	else if (alp1 >= 'a' && alp1 <= 'z') {
		output1 = (int)alp1 - 96;
	}

	if (alp2 >= 'A' && alp2 <= 'Z') {
		output2 = (int)alp2 - 64;
	}
	else if (alp2 >= 'a' && alp2 <= 'z') {
		output2 = (int)alp2 - 96;
	}

	//输出
	cout << "Output:" << (output1 > 0 && output1 < 10 ? "0" : "") << output1
		<< (output2 > 0 && output2 < 10 ? "0" : "") << output2 << endl;

	return 0;
}
