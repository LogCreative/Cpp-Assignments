// main.cpp
/*请在以下两个源文件中各添加一个单词，使这两个源文件组成的程序能正常
编译运行。 */
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
