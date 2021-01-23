// CS154-HW01-Problem 3.cpp

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
	float ab2, bc2, cd2, da2, bd2, ac2;
	float cos_cad2, cos_cbd2;
	int cad_angle, cbd_angle;//1:锐角 0:直角 -1:钝角
	bool sameside;
	float k, b;

	int sign(float x);

	//输入
	cout << "Input:";
	cin >> p1x >> p1y;

	cout << "Input:";
	cin >> p2x >> p2y;

	cout << "Input:";
	cin >> p3x >> p3y;

	cout << "Input:";
	cin >> p4x >> p4y;

	//处理

	ab2 = (p1x - p2x) * (p1x - p2x) + (p1y - p2y) * (p1y - p2y);
	bc2 = (p2x - p3x) * (p2x - p3x) + (p2y - p3y) * (p2y - p3y);
	cd2 = (p3x - p4x) * (p3x - p4x) + (p3y - p4y) * (p3y - p4y);
	da2 = (p4x - p1x) * (p4x - p1x) + (p4y - p1y) * (p4y - p1y);
	bd2 = (p2x - p4x) * (p2x - p4x) + (p2y - p4y) * (p2y - p4y);
	ac2 = (p1x - p3x) * (p1x - p3x) + (p1y - p3y) * (p1y - p3y);

	cos_cad2 = (da2 + ac2 - cd2) * (da2 + ac2 - cd2) / (4 * da2 * ac2);
	cos_cbd2 = (bc2 + bd2 - cd2) * (bc2 + bd2 - cd2) / (4 * bc2 * bd2);

	cout << "Output:";
	if (cos_cad2 == cos_cbd2) {
		//余弦相等

		//计算角的性质
		cad_angle = sign(da2 + ac2 - cd2);
		cbd_angle = sign(bc2 + bd2 - cd2);

		if (cad_angle == 0 && cbd_angle == 0) {
			cout << "Yes" << endl;//两角皆直
		}
		else {

			//算出AB的直线方程
			if (p1x == p2x) {
				//直线方程 x=p1x
				if ((p3x - p1x) * (p4x - p1x) > 0) {
					sameside = true;
				}
				else {
					sameside = false;
				}
			}
			else {
				//直线方程 kx-y+b=0
				k = (float)(p2y - p1y) / (p2x - p1x);
				b = (float)(p1y * p2x - p2y * p1x) / (p2x - p1x);

				if ((k * p3x - p3y + b) * (k * p4x - p4y + b) > 0) {
					sameside = true;
				}
				else {
					sameside = false;
				}
			}


			if (sameside == true) {
				if (cad_angle * cbd_angle) //1代表角的性质相同
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
			else {
				if (cad_angle * cbd_angle==-1)//取反
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}

		}
	}
	else
		cout << "No" << endl;

	return 0;
}

int sign(float x) {
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else
		return -1;
}
