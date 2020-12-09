#include<iostream>
using namespace std;

//Function for Count Sorting
void CountSort(int arr[],int n)
{
	//Finding the Maximum Element
	int k=arr[0];
	
	for(int i=0; i<n; i++)
	{
		k=max(k,arr[i]);
	}
	
	//Creating the count array Dynamic allocation is not allowed in C++
	int count[10]={0};
	
	//Count array of the counting number
	for(int i=0; i<n; i++)
	{
		count[arr[i]]++;
	}
	
	//Adding the number of Count in the Count array
	for(int i=1; i<=k; i++)
	{
		count[i]+=count[i-1];
	}
	
	//Output array that will store the array in sorted format
	int output[n];
	
	for(int i=n-1; i>=0; i--)
	{
		output[--count[arr[i]]]=arr[i];
	}
	
	//Storing the sorted form in orginal array
	for(int i=0; i<n; i++)
	{
		arr[i]=output[i];
	}	
}


int main()
{
	
	int arr[] = {4, 2, 2, 8, 3, 3, 1};
	int n=7;
	CountSort(arr,n);
	
	cout<<"You number after sorting \n";
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
