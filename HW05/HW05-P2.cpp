// CS154-HW05-p2.cpp

#include <iostream>
#include <cstring>
using namespace std;

bool func(char array[], int len);	//�������ж�

int main() {
	char ch[20];	//�û�������ض�Ϊһ������������ ������ 20 ���ַ������Իس��������
	bool result;	

	cout << "Input:";
	cin >> ch;		

	//�����
	result = func(ch, strlen(ch));
	cout << "Output:" << (result == 1 ? "Yes" : "No") << endl;
	//---����---��4�У�

	return 0;
}

bool func(char array[], int len) {
	//���ɶ����µı��� ���������������, ����ʹ��ѭ��
	//func�����Ķ����в��ɵ��ÿ⺯��
	//����ֵĴ����ܹ������� 10 ��
	
	//�����
	if (len == 0 || len == 1)	return 1;
	else {
		if (*array == *(array + len - 1))	func(array + 1, len - 2);
		else	return 0;
	}
	//---����---��3�У�

	//�ܼƣ�7��

}