// CS154-HW02-P1.cpp

#include <iostream>

using namespace std;

int main()
{
	int m, n, x;
	int i;
	int sumsquare = 0;
	
	//输入

	cout << "Input:";
	cin >> m;

	cout << "Input:";
	cin >> n;

	cout << "Input:";
	cin >> x;

	//输出

	cout << "Outputs:" << endl;
	for (i = m; i <= n; ++i) {
		if (i % x < 5) {
			cout << i << endl;
			sumsquare += i * i;
		}
	}

	cout << "Sum of Squares:" << sumsquare << endl;

	return 0;
}