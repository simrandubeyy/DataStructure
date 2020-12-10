#include<iostream>
using namespace std;

void swap(int arr[],int a, int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

void DnfSort(int arr[], int n)
{
	int low=0;
	int mid=0;
	int high=n-1;
	
	while(mid<=high)
	{
	 if(arr[mid]==0)
	 {
	 	swap(arr,mid,low);
		mid++;
		low++;
	 }
	 else if(arr[mid]==1)
	 {
	 	mid++;
	 }
	 else
	 {
	 	swap(arr,mid,high);
	 	high--;
	 } 	
	}
}


int main()
{
	
	int n;
	cout<<"How many numbers you want to sort \n";
	cin>>n;
	
	int arr[n];
	cout<<"Enter the elments you want to sort \n";
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	DnfSort(arr,n);
	
	cout<<"You number after sorting \n";
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
