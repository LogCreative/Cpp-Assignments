// CS154-HW03-P2.cpp

#include <iostream>
#include <cstring>

#define MAXLINE 110							//10����*10��ĸ+9�ո�+��\0��

using namespace std;

int main() {

	cout << "Input:";
	char input[MAXLINE];
	cin.getline(input, MAXLINE);

	//���ո�ָ�����

	int i = 0;								//�ַ����±�
	char word[11] = { 0 };					//��ʱ�洢����
	int j = 0;								//�����±�

	char lengroup[10][101] = { 0 };			//�Ե��ʳ���Ϊ��׼���飺'\0'
	int colcount[10] = { 0 };				//�����м���
	int linewordnum[10] = { 0 };			//�е�����
	int k;									//�����м���


	bool flag = false;						//���flag��������

	for (i = 0; input[i] != '\0'; ++i) {	//�ַ����±����ӣ���\0Ϊֹ

		if (input[i + 1] == '\0')			//��������
			flag = true;

		word[j] = input[i];					//�洢�ַ���word��
		++j;								//�ƶ��±�j
		if (input[i + 1] == ' '				//�����һ���ǿո�
			|| flag == true) {				//�����Ǽ�������

			if(!flag)
				++i;						//�����ո�

			for (k = 0; k <= j; ++k) {		//��word�洢��lengroup��
				lengroup[j][colcount[j]] = word[k];
				colcount[j]++;				//colcountˢ��
				word[k] = 0;				//���word
			}
			colcount[j]--;					//���һ����һ
			j = 0;							//��ʼ��j
			++linewordnum[j];				//���ӵ�����

		}									//������������
	}

	//ð�����򷨣����ַ�����������

	//������¼��������
	int grouplen[2][10] = { 0 };
	for (k = 0; k < 10; ++k) {
		grouplen[0][k] = k;					//��һ��Ϊ���ʳ��������
		grouplen[1][k] = colcount[k];		//�ڶ���Ϊ�����ַ�������
	}

	int tmp;
	for (i = 1; i < 10; ++i) {
		flag = false;
		for (j = 0; j < 10 - i; ++j) {
			if (grouplen[1][j + 1] < grouplen[1][j]			//���Դ�С��ϵ
				||(grouplen[1][j + 1] == grouplen[1][j]		//���ʱ
					&& linewordnum[j + 1] > linewordnum[j]))//�ϲ������������ǰ��
			{												//��������
				for (k = 0; k <= 1; ++k) {
					tmp = grouplen[k][j + 1];
					grouplen[k][j + 1] = grouplen[k][j];
					grouplen[k][j] = tmp;
				}
				flag = true;
			}
		}
		if (!flag)
			break;
	}

	//���ַ���ƴһ��
	for (k = 0; k < 10; ++k) {							    //������Ų�
		if (colcount[grouplen[0][k]] == 0)
			continue;									    //��������
		for (j = 0; j <= colcount[grouplen[0][k]]-1; ++j)	//�������
			cout << lengroup[grouplen[0][k]][j];
		cout << " ";
	}

}
