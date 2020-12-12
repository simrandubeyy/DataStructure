#include <iostream>
using namespace std;

class Stack
{
	public:
		int top=-1;
		int n=6; 
	    int arr[6];
		
    void push()
    {
	int x;
	
	cout<<"Enter the Number you want to push in stack \n";
	cin>>x;
	
	if(top==n-1)
	{
		cout<<"OverFlow \n";
	}
	else
	{
		top++;
		arr[top]=x;
	}
    }

    
    void pop()
	{
		if(top==-1)
		{
			cout<<"UnderFlow \n";
		}
		else
		{
			cout<<"Number"<<" "<<arr[top]<<" "<<"Poped \n";
			top--;
		}
	}
	
	void peek()
	{
		if(top==-1)
		{
			cout<<"Stack is Empty \n";
		}
		else
		{
			cout<<"Peek Element"<<arr[top]<<" \n";
		}
	}

    void display()
	{
		if(top==-1)
		{
			cout<<"Stack is Empty \n";
		}
		else
		{
			for(int i=top; i>=0; i--)
			{
				cout<<arr[i]<<" ";
			}
		}
		cout<<"\n";
	}
		
};



int main()
{
	Stack s;
	int ch=0;
	
	
	while(ch!=5)
	{
	 cout<<"*****************************************************************************\n";	
	 cout<<"Main Menu \n";
	 cout<<"*****************************************************************************\n \n \n";
	 
	 cout<<"1.Push in Stack \n";
	 cout<<"2.Pop in Stack \n";
	 cout<<"3.View Top \n";
	 cout<<"4.Display \n";
	 cout<<"5.Exit \n";
	 
	 cin>>ch;
	 switch (ch)
	 {
	 	case 1:
	 		s.push();
	 		break;
	 	case 2:
	 		s.pop();
	 		break;
	 	case 3:
	 		s.peek();
	 		break;
	 	case 4:
	 		s.display();
	 		break;
	 	case 5:
	 		exit(0);
	 		break;
	 	default:
	 		cout<<"Please Enter a Valid Choice \n";
	 }		
	}
	
	return 0;
}
