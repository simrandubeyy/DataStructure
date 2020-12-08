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
  for(int i=0; i<n; i++)
  {
  	int current=arr[i];
  	int j=i-1;
  	
  	while(j>=0 && arr[j]>current)
	  {
	  	arr[j+1]=arr[j];
	  	j--;
	  }
	  arr[j+1]=current;	
  }
  
  cout<<"Elements after Sorting"<< endl;
  //Output after Sorting
  for(int i=0; i<n; i++)
  {
  	cout<<arr[i]<<" ";
  }	
		
	return 0;
}
