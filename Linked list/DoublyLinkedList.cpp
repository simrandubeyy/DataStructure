#include <iostream>
using namespace std;

//Created A Structure that can have different Data Types 
struct node
{
	node *prev;
	int data;
	node *next;
};

	//Creating A Empty Node
	node *AddToEmpty(node *head, int data)
	{
		node *temp=new node();
		temp->prev=NULL;
		temp->data=data;
		temp->next=NULL;
		head=temp;
		return head;
	}	

   //Adding at the Start
   node *AddAtBeg(node *head,int data)
   {
   	node *temp=new node();
   	temp->prev=NULL;
   	temp->data=data;
   	temp->next=NULL;
   	temp->next=head;
   	head->prev=temp;
   	head=temp;
   	return head;
   }
   
   //Add At the End Of the Linked List
   node *AddAtEnd(node *head, int data)
   {
   	node *tp,*temp;
   	temp=new node();
   	temp->prev=NULL;
   	temp->data=data;
   	temp->next=NULL;
   	
   	tp=head;
   	while(tp->next!=NULL)
	   {
	   	tp=tp->next;
	   }
	   
	   tp->next=temp;
	   temp->prev=tp;
	   return head;	
   }
  
  //Add at Particluar Position After in the Linked List
   node *AddAtPosAfter(node *head,int data,int position)
   {
   	node *newP=NULL;
   	node *temp=head;
   	node *temp2=NULL;
   	newP=AddToEmpty(newP,data);
   	
   	while(position !=1)
	   {
	   	 temp=temp->next;
	   	 position--;
	   }
	   
	   if(temp->next==NULL)
	   {
	   	temp->next=newP;
	   	newP->prev=temp;
	   }
	   else{
	   
	   temp2=temp->next;
	   temp2->prev=newP;
	   temp->next=newP;
	   newP->next=temp2;
	   newP->prev=temp;
   }
   return head;
   } 
   
   //Add At the Particular Position Brfore in the Linked List
   node *AddAtPosBefore(node *head, int data, int position)
   {

   	node *newP=NULL;
   	node *temp=head;
   	node *temp2=NULL;
   	newP=AddToEmpty(newP,data);
   	
   	while(position !=2)
	   {
	   	 temp=temp->next;
	   	 position--;
	   }
	   
	   if(position==1)
	   {
	   	head=AddAtBeg(head, data);
	   }
	   else
	   {
	   
	   temp2=temp->next;
	   temp2->prev=newP;
	   temp->next=newP;
	   newP->next=temp2;
	   newP->prev=temp;
	   return head;
       } 
   }  
   
   //Create Entire Linked List 
   node *CreateEntireList(node *head)
   {
   	int data,n,i;
   	cout<<"Enter the number of Nodes : \n";
   	cin>>n;
   	
   	if(n==0)
	   {
	   	return head;
	   }
	   
	   cout<<"Enter the element of node 1 : \n";
	   cin>>data;
	   head=AddToEmpty(head,data);
	   
	   for(int i=1; i<n; i++)
	   {
	   	cout<<"Enter the Element for the Node "<<i+1<<" : \n";
	   	cin>>data;
	   	head=AddAtEnd(head,data);
	   }
	   return head;
   }
   
   //Delete At the Start of The Linked List 
   node *DelAtFirst(node *head)
   {
   	 head=head->next;
   	 delete head->prev;
   	 head->prev=NULL;
   }
   
   //Delete At the Last Of the Linked List
   node *DelAtLast(node *head)
   {
   	 node *temp,*temp2;
   	 temp=head;
   	 
   	 while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp2=temp->prev;
		temp2->next=NULL;
		delete temp;
		
		return head;
   }
   
   //Delete at the Position given 
   node *DelAtPos(node *head, int position)
   {
   	node *temp,*temp2;
   	temp=head;
   	temp2=NULL;
   	
   	if(position==1)
	   {
	   	head=DelAtFirst(head);
	   	return head;
	   }
	   
   	while(position > 1)
	   {
	   	temp=temp->next;
	   	position--;
	   }
	   
	   if(temp->next==NULL)
	   {
	   	head=DelAtLast(head);
	   }
	   else
	   {
	   	temp2=temp->prev;
	   	temp2->next=temp->prev;
	   	temp2->next=temp->next;
	   	temp->prev->prev=temp2;
	   	delete temp;
	   	temp=NULL;   	
	   }
	   return head;
   }
   
   
   
int main()
{
	node *head=NULL;
	node *ptr;
	head=AddToEmpty(head,45);     
	head=AddAtBeg(head,65);
	head=AddAtEnd(head,99);
	head=AddAtPosAfter(head,32,2);
	head=AddAtPosBefore(head,23,3);
        head=CreateEntireList(head);
	head=DelAtFirst(head);
	head=DelAtLast(head);
	head=DelAtPos(head,3);
	
	//Print The Linked List
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	
	return 0;
}
