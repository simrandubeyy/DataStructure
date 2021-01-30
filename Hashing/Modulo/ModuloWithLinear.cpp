#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter the Number of Keys you want to Enter \n";
	cin>>n;
	
	vector<int> arr;
	vector<int> hash (10, 0);
	
	cout<<"Enter the Key \n";
	
	for(int i=0; i<n; i++)
	{
		int input;
		cin>>input;
		arr.push_back(input);
	}
	
	for(int i=0; i<n; i++)
	{
		int key=arr[i];
		int modulo=key%10;
		
		if(hash[modulo]==0)
		{
			hash[modulo]=key;
		}
		
		else
		{
			while(hash[modulo]>0)
	     	{
			  modulo+=1;
			  
			  if(modulo>9)
		    	{
			    	modulo=modulo%10;
			    }
	    	}
			
			if((hash[modulo])==0)
			{
				hash[modulo]=key;
			}		
		}
	}
	
	cout<<"Hash Table Value \n"
	
	for(int i=0; i<10; i++)
	{
		cout<<hash[i]<<" ";
	}
	
	return 0;
}
