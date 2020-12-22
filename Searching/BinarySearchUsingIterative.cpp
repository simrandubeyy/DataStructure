//Binary Search using iterrative approach 
#include<iostream>
using namespace std;

 
int BinarySearch(int arr[],int l,int r, int data)
{
  if(r>=l)
  {
  	int mid=l+(r-1)/2;
   
   if(arr[mid]==data)
   {
   	 return mid;
   }
   
   if(arr[mid]>data)
   {
   	r=mid-1;
   }
   
   if(arr[mid]<data)
   {
   	l=mid+1;
   }
  }

   return -1;
}

int main()
{
	int n;
	
	cout<<"How many numbers do you want to enter \n";
	cin>>n;
	
	cout<<"Enter the Elements in a sorted format \n";
	
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	int data;
	cout<<"Which number do you want to search \n";
	cin>>data;
	
	int result=BinarySearch(arr,0,n-1,data);
	
	(result == -1) ? cout << "Element is not present in array \n"
                   : cout << "Element is present at " << result<<" index \n";
	
	return 0;
}
