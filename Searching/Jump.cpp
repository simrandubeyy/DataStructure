#include <bits/stdc++.h>
using namespace std;

//Function of Jump Search
int Jump(int arr[],int x,int n)
{
	int step=sqrt(n);
	int prev=0;
	
	while(arr[min(step,n)-1]<x)
	{
		prev=step;
		step+=sqrt(n);
		
		if(prev>=n)
		{
			return -1;
		}
	}
	
	while(arr[prev]<x)
	{
		prev++;
	}
	
	if(arr[prev]==x)
	{
		return prev;
	}
	
	return -1;
}
int main()
{
	//Array should be sorted
	int arr[] = {0,1,2,3,4,8,13,21,34,55,89,117,435,567,789,899};
	int n=16;
	int x=899;
	
	int index=Jump(arr,x,n);
	
	cout<<"Index at which number "<<x<<" is present "<< index;
	
	return 0;
}
