#include<iostream>
using namespace std;
int fib(int n, int a = 0, int b = 1) {
    if(n==0)return a;
    if(n==1)return b;
    return fib(n-1,b,a+b);
}

int main()
{
	int x=66;
	cout<<"factoiral of x = "<<fib(40)<<endl;
	return 0;
}
