/*���Ҳ���벹�������������� main����֮ǰ
��� 2�д����Լ���������һ�������Ķ�
�壬ʹ�� �ó�������һ������������� ���
�� ��һ�� ���� x�����û�����ĵ�һ��������
ȥ y�����û�����ĵڶ��������Ĳ�ĸ�λ��
�ڶ������� x�� 3�������������� y�� 2����*/

#include <iostream>
using namespace std;

//�˴�����д��� x>y
char myfun(int& a, int& b);

int myfun(int* a, int* b);

int main() {
	int x, y;
	cout << "Input:";
	cin >> x >> y;
	cout << "Output:";
	cout << myfun(x, y);
	cout << x << ' ' << y;
	return 0;
}

int myfun(int* a, int* b) {
	int c = *a - *b;
	*a *= 2;
	*b *= 3;
	return c;
}

//�˴�����һ��������ֻ�����д��룬�������κ�������
char myfun(int& a, int& b) {
	cout << -myfun(&b, &a) % 10;
	return ' ';
}