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
	
	//Taking the Keys 
	for(int i=0; i<n; i++)
	{
		int input;
		cin>>input;
		arr.push_back(input);
	}
	
	//Checking the modulo space in hash table
	for(int i=0; i<n; i++)
	{
		int key=arr[i];
		int modulo=key%10;
		
		if(hash[modulo]==0)
		{
			hash[modulo]=key;
		}
		//If full use Key Offset Probing
		else
		{
			int offset=key/10;
			int old_Location=modulo;
			
			while(hash[modulo]>0)
	     	{
		      modulo=old_Location+offset;
		      old_Location=modulo;
		      
			  //If Keyoffset is Out of memory Apply Modulo
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
	
	cout<<"Hash Table Value \n";
	
	for(int i=0; i<10; i++)
	{
		cout<<hash[i]<<" ";
	}
	
	return 0;
}
