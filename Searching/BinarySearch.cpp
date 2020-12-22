//Key Differences Between Linear Search and Binary Search. 
//Linear search is iterative in nature and uses sequential approach. 
//On the other hand, Binary search implements divide and conquer approach. 
//The time complexity of linear search is O(N) while binary search has O(log2N).

//Binary Search is Divide And Conqure Techniquie 


//**************************************************************************************

//Binary Search Recursive

#include<iostream>
using namespace std;

//Function Called Recursively till the element is found. 
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
   	return(arr,l,mid-1,data);
   }
   
   if(arr[mid]<data)
   {
   	return(arr,mid+1,r,data);
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
	
	int result=BinarySearch(arr,0,n,data);
	
	(result == -1) ? cout << "Element is not present in array \n"
                   : cout << "Element is present at " << result<<" position \n";
	
	return 0;
}
