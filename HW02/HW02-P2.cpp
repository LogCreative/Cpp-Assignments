//CS154-HW02-������-518070910095-P1.cpp

#include<iostream>

using namespace std;

int main() {
	
	int input;
	int sum = 0;
	bool start = false, end = false;//��ֹ�ж���

	while (end == false) {

		cout << "Input:";
		cin >> input;

		if (input == 0 && start == false) {
			start = true; //���û��ʼ�Ϳ�ʼ
		}
		else if (input == 0 && end == false) {
			end = true;	//���û�����ͽ���
		}
		else {
			if (start == true)
				sum += input;
		}
		
	}

	cout << "Output:" << sum << endl;

	return 0;
}