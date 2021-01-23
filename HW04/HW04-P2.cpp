//CS154-HW04-P2.cpp

#include <iostream>

using namespace std;

template <class T>
int SpaceCounter(T &input) {
	
	if (*(&(input)-1) == 0 || *(&(input)-1) == 1)	input = *(&(input)-1) + 1;
	else input = 0;
	return sizeof(T) * (input + 1);

}

int main() {

	int a[3];
	double b[3];

	cout << SpaceCounter(a[0]);
	cout << SpaceCounter(a[1]);
	cout << SpaceCounter(a[2]);
	cout << SpaceCounter(b[0]);
	cout << SpaceCounter(b[1]);
	cout << SpaceCounter(b[2]);

}