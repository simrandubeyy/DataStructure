#include<iostream>
using namespace std;

//function to swap the numbers
void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

//Function to peform the wave sort 
void WaveSort(int arr[],int n)
{
	for(int i=1; i<n; i+=2)
	{
		if(arr[i]>arr[i-1])
		{
			swap(arr,i,i-1);
		}
		
		if(arr[i]>arr[i+1] && i<=n-2)
		{
			swap(arr,i,i+1);
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
	
	WaveSort(arr,n);
	
	cout<<"You number after sorting \n";
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
