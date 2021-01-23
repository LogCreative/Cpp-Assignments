//library .cpp
int x = 10;

static int myfun(int n){
    return n*2;
}
int yourfun(int y){
    return myfun(y);
}
