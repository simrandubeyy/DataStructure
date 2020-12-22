#include<iostream>
using namespace std;

int main()
{
	int n,data;
	
	cout<<"How many numbers you want to enter \n";
	cin>>n;
	
	int arr[n];
	
	cout<<"Enter "<<n<<" numbers \n";
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Enter the number you want to search \n";
	cin>>data;
	
	bool flag=false;
	int i;
	
	for(i=0; i<n; i++)
	{
		if(arr[i]==data)
		{
			flag=true;
			cout<<"Number is present at index "<<i<< endl;
			break;
		}
	}
 
    if(flag==false)
	{
		cout<<"Number is not present \n";
	}
    
	return 0;
}
