//CS154-HW02-李子龙-518070910095-P1.cpp

#include<iostream>

using namespace std;

int main() {
	
	int input;
	int sum = 0;
	bool start = false, end = false;//起止判定符

	while (end == false) {

		cout << "Input:";
		cin >> input;

		if (input == 0 && start == false) {
			start = true; //如果没开始就开始
		}
		else if (input == 0 && end == false) {
			end = true;	//如果没结束就结束
		}
		else {
			if (start == true)
				sum += input;
		}
		
	}

	cout << "Output:" << sum << endl;

	return 0;
}