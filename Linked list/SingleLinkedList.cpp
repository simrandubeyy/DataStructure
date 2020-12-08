#include <iostream>
using namespace std;

//Created A Structure that can have different Data Types 
struct node
{
	int data;
	node *next;
};

//Created a Class
class Single
{
	//Assigned Public, Default is private.
	public:
		node *head;
	
	//Function to add the element in the start of the linked List.	
	void insert_at_begin()
	{
		node *ptr=new node();
		int item;
		
		if(ptr==NULL)
		{
			cout<<"OVERFLOW \n";
		}
		else
		{
			cout<<"Enter the Number you want to insert \n";
			cin>>item;
			ptr->data=item;
			ptr->next=head;
			head=ptr;
			cout<<"Number Inserted \n";
		}
	}
	
	
    //Function to add the element in the last of the linked List.	
	void insert_at_last()
	{
		node *ptr,*temp;
		temp=new node();
		int item;
		ptr=head;
		
		if(ptr==NULL)
		{
			cout<<"OVERFLOW \n";
		}
		else
		{
			cout<<"Enter The number you want to Insert \n";
			cin>>item;
			temp->data=item;
			temp->next=NULL;
			
			while(ptr->next!=NULL)
			{
				ptr = ptr->next;
			}
			ptr->next=temp;
			cout<<"Inserted your Number \n";		
		}		
	}
	
	
	//Function to add the element in the position given by the user in the linked List.	
	void random_insert()
	{
		node *ptr,*ptr2;
		ptr=head;
		ptr2=new node();
		int pos,item;
		
		cout<<"Enter the Postion \n";
		cin>>pos;
		
		cout<<"Enter the Number \n";
		cin>>item;	
		
		ptr2->data=item;
		ptr2->next=NULL;
		if(ptr==NULL)
		{
			cout<<"OVERFLOW \n";
		}
		else
		{		
		pos--;
		while(pos!=1)
		{
			ptr=ptr->next;
			pos--;
		}	
		ptr2->next=ptr->next;
		ptr->next=ptr2;
		cout<<"Value Inserted \n";
	   }
	}
	
	
	//Function to Delete the element in the start of the linked List i.e First Element.	
	void delete_at_begin()
	{
		node *ptr,*temp;
		if(head==NULL)
		{
			cout<<"List is alreagy empty \n";
		}
		else
		{
			temp=head;
			head=temp->next;
            delete temp;
            temp=NULL;
            cout<<"Deleted the first Data \n";
		}		
	}
	
	//Function to delete the element in the end of the linked List.	
	void delete_at_last()
	{
		if(head==NULL)
		{
			cout<<"List is Already Empty \n";
		}
		else if(head->next==NULL)
		{
			delete head;
			head=NULL;
			cout<<"Deleted the only element from the list \n";		
		}
		else
		{
			node *temp=head;
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next=NULL;
			cout<<"Deleted \n";
		}	
	}
	
	//Function to delete the element in the user defined position of the linked List.	
	void rendom_delete()
	{
		 node *current,*previous;
		 *current=*head;
		 *previous=*head;
		 int position;
		 
		 cout<<"Enter the Number you want to Enter \n";
		 cin>>position;
		 
		 if(head==NULL)
		 {
		 	cout<<"List is already empty \n";
		 }
		 else if(position==1)
		 {
		 	head=current->next;
		 	delete current;
		 	current = NULL;
		 }
		 else
		 {
		 	while(position != 1)
			 {
			 	previous = current;
			 	current = current->next;
			 	position--;
			 }
			 previous->next=current->next;
			 delete current;
			 current = NULL;
			 cout<<"Deleted \n";
		 }
	}
	
	//Print the Linked List
	void display()
	{
		node *ptr;
		if(head==NULL)
		{
			cout<<"Linked List is Empty \n";
		}
		else
		{
			ptr=head;
			cout<<"Data are \n";
			while(ptr!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}

		}		
	}
	
	//Delete the whole Linked List
	void delete_whole_list()
	{
		node *temp;
		temp=head;
	  if(head==NULL)
	  {
	  	cout<<"Deleted \n";
	  }
	  else
	  {
	    while(temp!=NULL)
	   {
	  	temp=temp->next;
	  	delete head;
	  	head=temp;
	   }
	  }	
	}
	
	
	//Count Number of Elements i.e Data in the linked list
	void count()
	{
		int count=0;
		node *temp;
		temp=head;
		if(head==NULL)
		{
			cout<<"Linked list is Empty \n";
		}
		else
		{
			while(temp->next!=NULL)
			{
				count++;
				temp=temp->next;
			}
		}
		cout<<"Total Number of Elements present is "<<count<<"\n";		
	}
	
	//Function to Reverse the Linked List
	void reverse_linked_list()
	{
		node *prev, *front;
		prev=NULL;
		front=NULL;
		
		while(head!=NULL)
		{
			front=head->next;
			head->next=prev;
			prev=head;
			head=front;
		}
		head=prev;
		cout<<"Updated \n";
	}
};


int main()
{
	int choice=0;
	Single s;
	while(choice!=9)
	{
		//Menue
		cout<<"\n\n*********Main Menu*********\n";  
        cout<<"\nChoose one option from the following list ...\n";  
        cout<<"\n===============================================\n"; 
		
		cout<<"\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Display\n8.Delete Whole List\n9.Count Number of Elements\n10.Reverse the Linked List\n11.Exit\n";  
        cout<<"\nEnter your choice?\n";         
       
        cin>>choice;
        
        //Switch case to select the option
        switch(choice)  
        {  
            case 1:  
            s.insert_at_begin();      
            break;  
            case 2:  
            s.insert_at_last();         
            break;  
            case 3:  
            s.random_insert();     
            break;  
            case 4:  
            s.delete_at_begin();       
            break;  
            case 5:  
            s.delete_at_last();       
            break;  
            case 6:  
            s.rendom_delete();         
            break;  
            case 7:  
            s.display();       
            break;  
            case 8:  
            s.delete_whole_list();       
            break;  
            case 9:
            s.count();
            break;
            case 10:
            s.reverse_linked_list();
            break;
            case 11:
            exit(0);  
            break;  
            default:  
            cout<<"Please enter valid choice.. \n";  
        }  
	}	
	return 0;
}
