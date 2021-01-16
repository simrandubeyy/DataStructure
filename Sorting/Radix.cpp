#include<iostream>
using namespace std;

//Function for calling Counting Sort
int CountingSort(int arr[],int size,int div)
{
	int output[size];
	int count[10]={0};
	
	for(int i=0; i<size; i++)
	{
		count[(arr[i]/div)%10]++;
	}
	
	for(int i=1; i<10; i++)
	{
		count[i]=count[i]+count[i-1];
	}
	
	for(int i=size-1; i>=0; i--)
	{
		output[count[(arr[i]/div)%10]-1]=arr[i];
		count[(arr[i]/div)%10]--;
	}
	
	for(int i=0; i<size; i++)
	{
		arr[i]=output[i];
	}
}

//Function to get maximum element from array
int GetMax(int arr[],int size)
{
	int max=0;
	for(int i=0; i<size; i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	
	return max;
}

//Function for Radix sort 
void RadixSort(int arr[],int size)
{
	int m=GetMax(arr,size);
	
	for(int div=1; m/div>0; div*=10)
	{
		CountingSort(arr,size,div);
    }
}


int main()
{
	int size;
	cout<<"Enter the Size of the array \n";
	cin>>size;
	
	int arr[size];
	cout<<"Enter "<<size<<" integer in any array \n";
	
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Array before Sorting \n";
	
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	RadixSort(arr, size);
	
	cout<<"After Sorting \n";
 
    for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}	
	
	return 0;
}
