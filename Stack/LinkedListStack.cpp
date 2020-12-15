#include <iostream>
using namespace std;

//Creating A Struct Node for Different Data Types
struct node
{
	int data;
	node *next;
};

node *top=NULL;

//Function For Pushing the data into Stack
void push()
{
	int item;
	
	cout<<"Enter the number you want to enter in stack \n";
	cin>>item;
	
	node *newnode;
	newnode=new node();
	
	newnode->data=item;
	newnode->next=top;
	
	top=newnode;
	
	cout<<"Number Entered \n";
}

//Function for Poping the data into Stack
void pop()
{
	node *temp=top;
	
	if(top==NULL)
	{
		cout<<"Stack is Empty \n";
	}
	else
	{
		cout<<"Popped up "<<" "<<top->data<<" \n";
		top=temp->next;
		delete temp;
	}
}

//Function for Viewing the top Element		
void peek()
{
	if(top==NULL)
	{
		cout<<"Stack is Empty \n";
	}
	else
	{
		cout<<"The top Element is "<<" "<<top->data<<"\n";
	}
}

//Function to display all the element in stack
void display()
{
  node *temp=top;
  
  if(top==NULL)
  {
  	cout<<"Stack is Empty \n";
  }	
  else
  {
  	cout<<"The Numbers in stack are \n";
  	while(temp!=NULL)
	  {
	  	cout<<temp->data<<" ";
	  	temp=temp->next;
	  }
	  cout<<"\n";
  }
}


int main()
{
	int ch=0;
	
	//Menu Deriven Program
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
	 
	 //Switch case 
	 cin>>ch;
	 switch (ch)
	 {
	 	case 1:
	 		push();
	 		break;
	 	case 2:
	 		pop();
	 		break;
	 	case 3:
	 		peek();
	 		break;
	 	case 4:
	 		display();
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
