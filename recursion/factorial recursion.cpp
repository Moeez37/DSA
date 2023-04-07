#include<iostream>
using namespace std;
int factorial(int x)
{
	if(x==0)
	{
		return 1;
	}
	if(x<0)return -1;
	
unsigned int k=x*factorial(x-1);
return k;
}
int main()
{
	int x=66;
	cout<<"factoiral of x is"<<factorial(-20)<<endl;
	return 0;
}
