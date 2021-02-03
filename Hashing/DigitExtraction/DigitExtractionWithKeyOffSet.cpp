#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter the Number of Keys you want to Enter \n";
	cin>>n;
	
	vector<long long int> arr;
	vector<long long int> hash (10, 0);
	
	cout<<"Enter the Key \n";
	
	//Taking the Keys 
	for(int i=0; i<n; i++)
	{
		long long int input;
		cin  >>input;
		arr.push_back(input);
	}
	
	int digi1=2;
	int digi2=3;
	int digi3=4;
	
	//Checking the DigitExtraction space in hash table
	for(int i=0; i<n; i++)
	{	
	   	long long int number=arr[i];
	   	string new_number_string = to_string(number);
	   	
	   	string new_number;
		   
		new_number[0]=new_number_string[digi1];
		new_number[1]=new_number_string[digi2];
		new_number[2]=new_number_string[digi3];
		
		long long int new_number_int;
		
		new_number_int = stoi(new_number);
		
		long long int modulo=new_number_int % 10;	
		
		if(hash[modulo]==0)
		{
			hash[modulo]=arr[i];
		}
		else
		{
		    int offset=arr[i]/10;
		    int new_location=modulo+offset;
		    int old_location=new_location;
		    
			while(hash[new_location]>0)
			{
			    new_location=old_location+offset;
			    old_location=new_location;
			    
				while(old_location=new_location>9)
				{
					old_location=old_location%10;
				}
			}
			
			if(hash[new_location]==0)
			{
				hash[new_location]=arr[i];
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
