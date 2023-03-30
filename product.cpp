// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

/* Function to print product array
for a given array arr[] of size n */
void productArray(int arr[], int n)
{
	int temp=1;
	int product[n];
	fill(product,product+n,1);
for(int index=0;index<n;index++) {
	product[index] *=temp;
	temp *=arr[index];
}
temp=1;
for(int index=n-1;index>=0;index--)
{
	product[index] *=temp;
	temp*=arr[index];
}
for(int index=0;index<n;index++) {
	cout<<product[index]<<' ';
}

}
/* Driver code*/
int main()
{
	int arr[] = { 10, 3, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The product array is: \n";
	productArray(arr, n);
}

// This is code is contributed by rathbhupendra

