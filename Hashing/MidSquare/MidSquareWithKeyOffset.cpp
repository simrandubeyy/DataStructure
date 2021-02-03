#include<bits/stdc++.h>
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
		cin  >>input;
		arr.push_back(input);
	}
	
	//Checking the MidSquare space in hash table
	for(int i=0; i<n; i++)
	{		
	    //Square of a number 
		int square=arr[i]*arr[i];
		
		//Size of your Square 
		int size;
		
		//Size of the number with this formula
	    size = floor(log10(square) + 1);
	    
	    //int string
	    string square_string = to_string(square);
	    
	    string new_number;
	    int count=0;
	    
	    //copying to new string
	    for(int j=1; j<size-1; j++)
		{
			new_number[count]=square_string[j];
			count++;
		}
		
		//String to Integer
		int new_final = stoi(new_number);
		
		//Applying MidSquare
		if(new_final>9)
		{
			new_final=new_final%10;
		}
			
			if(hash[new_final]==0)
			{
				hash[new_final]=arr[i];
			}
			else
			{
				int key=arr[i];
				int offset=key/10;
				
				int old_Location=new_final;
				
			
				//If collsion Occurs using Key Offset
				while(hash[old_Location]>0)
	     	    {
		    	  new_final=old_Location+offset;
		    	  old_Location=new_final;
		    	  
				  //If Key Offset is Out of memory Apply Modulo
			 	  if(old_Location>9)
		    		{
			 		   	old_Location=old_Location%10;
			 	    }
	    		}
	    		
	    	   if(hash[old_Location]==0)
			   {
			   	hash[old_Location]=arr[i];
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
