// CS154-HW03-P1.cpp
/*
连续输入16 个两位整数（在10~99 范围内，都不重复），将它们放在4x4 的
矩阵中，使得它们依下图所示顺序从大到小排列。再新输入一个两位整数，
在这16 个整数中查找该新整数。如果能找到它，则输出它在矩阵中的坐标
（第几行、第几列），否则输出“Not Found”。
*/

#include <iostream>

#define MAXLINE 16
#define SCALE 4

using namespace std;

int main(){

	int input[MAXLINE]; //输入数组
	int i, j, tmp; //循环变量与临时变量
	bool flag;

	//输入数组

    cout << "Input:";
	for (i = 0; i < MAXLINE; ++i) {
		cin >> input[i];
	}


	//冒泡排序法：从大到小排列

	for (i = 1; i < MAXLINE; ++i) {
		flag = false;
		for (j = 0; j < MAXLINE - i; ++j) {
			if (input[j + 1] > input[j]) {
				tmp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = tmp;
				flag = true;
			}
		}
		if (!flag)
			break;
	}


	//二分查找法：寻找新整数

	int find;
	cout << "Input:";
	cin >> find;

	int low = 0, high = MAXLINE - 1, mid;//mid将是数据在一维数组的位置
	while (low <= high) {
		mid = (low + high) / 2;
		if (find == input[mid])
			break;
		if (find < input[mid]) //在右边
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << "Output:";

	if (low > high)
		cout << "Not Found" << endl;
	else {

		//找到：寻找下标在二维数组中的位置
		//边界判定法
		//0 ~ MAXLINE - 1 为行与列的填充区域，坐标为下标坐标

		int ubond = 0, dbond = SCALE, lbond = -1, rbond = SCALE;//四边界
		//第一行在完成填充后不能再填充，相当于上边界为0
		int xdir = 1, ydir = 0;//运动方向
		int xpos = 0, ypos = 0;//当前坐标

		for (i = 0; i <= mid - 1; ++i) {//步数等于填入数减一

			if (xdir == 1) {//右移中
				if (xpos + xdir >= rbond) {//到达右边界
					rbond--;
					xdir = 0; ydir = 1;
				}
			}
			else if (xdir == -1) {//左移中
				if (xpos + xdir <= lbond) {
					lbond++;
					xdir = 0; ydir = -1;
				}
			}
			else if (ydir == -1) {//上移中
				if (ypos + ydir <= ubond) {
					ubond++;
					xdir = 1; ydir = 0;
				}
			}
			else {//下移中
				if (ypos + ydir >= dbond) {
					dbond--;
					xdir = -1; ydir = 0;
				}
			}

			//位置前移
			xpos = xpos + xdir; ypos = ypos + ydir;

		}

		cout << ypos << "," << xpos << endl;

	}

	return 0;
}
