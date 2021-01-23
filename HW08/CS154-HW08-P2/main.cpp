// main.cpp
#include <iostream>
using namespace std;
int myfun(int);
int yourfun(int);

int main(){
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: ";
    cout << myfun(n) << endl;
return 0;
}

int myfun(int n){
    extern int x;
    return yourfun(n+x);
}
