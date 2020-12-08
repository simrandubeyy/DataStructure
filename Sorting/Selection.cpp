#include<iostream>
using namespace std;

int main()
{
  int n,temp;
 
  cout<<"Number of Elements you want to sort"<< endl;
  cin>>n;
  int *arr=new int[n];
  
  cout<<"Elements you want to sort"<< endl;
  //Input
  for(int i=0; i<n; i++)
  {
  	cin>>arr[i];
  }	

  int min;
  //Sorting	
  for(int i=0; i<n-1; i++)
  {
  	
  	//assumed minimum index as 1
  	min=i;
  	
  	for(int j=i+1; j<n; j++)
	  {
	  	if(arr[j]<arr[min])
		  {
		  	//minimum value
		  	min=j;
		  }
	  }
	  
	  //swapping of value
	  int temp;
	  temp=arr[i];
	  arr[i]=arr[min];
	  arr[min]=temp;
	  	  
  }
  
  cout<<"Elements after Sorting"<< endl;
  //Output after Sorting
  for(int i=0; i<n; i++)
  {
  	cout<<arr[i]<<" ";
  }	
		
	return 0;
}
