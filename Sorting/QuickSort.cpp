#include<iostream>
using namespace std;

//Function to Swap the Numbers
void swap(int arr[],int i, int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

//Function to set the pivot i.e for sorted place of array
int Partision(int arr[], int l, int r)
{
	int pivot=arr[r];
	int i=l-1;
	
	for(int j=l; j<r; j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr,i,j);
		}
	}
	
	swap(arr,i+1,r);
	return i+1;
	
}

//Calling QuickSort function recursively to peform the sorting
QuickSort(int arr[], int l, int r)
{
  if(l<r)
  {
  	int pi=Partision(arr,l,r);
  	QuickSort(arr,pi+1,r);
  	QuickSort(arr,l,pi-1);
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
	
	QuickSort(arr,0,n-1);
	
	cout<<"You number after sorting \n";
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
