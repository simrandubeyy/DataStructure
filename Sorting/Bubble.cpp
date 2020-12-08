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

  //Sorting	
  //Number of Passes
  for(int i=0; i<n; i++)
  {
  	//Internal loop for swapping
  	for(int j=0; j<n-i-1; j++)
	  {
	  	//Condition for Swapping
	  	 if(arr[j]>arr[j+1])
		   {
		   	 temp=arr[j];
		   	 arr[j]=arr[j+1];
		   	 arr[j+1]=temp;
		   }
	  }
  }	
  
  cout<<"Elements after Sorting"<< endl;
  //Output after Sorting
  for(int i=0; i<n; i++)
  {
  	cout<<arr[i]<<" ";
  }	
		
	return 0;
}
