#include<iostream>
#define SPACE 10
using namespace std;

//TreeNode Class
class TreeNode
{
  public:
    int value;
	TreeNode *left;
	TreeNode *right;
	
	//Default Constructor
	TreeNode()
	{
		value = 0;
		left = NULL;
		right = NULL;
	}
	
	//Parametrized Constuctor
	TreeNode(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}		
};

class BST
{
  public:
  	TreeNode *root;
  	
  	BST()
	{
		root=NULL;
	}
  	
  	
  	//if tree is empty then root==Null
  	bool isEmpty()
	{
		if(root==NULL)
		   return true;
		
		else
		   return false;
	}
	
	void insertNode(TreeNode *new_node)
	{
		if(root==NULL)
		{
			root = new_node;
			cout<<"Value Inserted as root node!"<<endl;
		}
		else
		{
			TreeNode *temp=root;
			
			while(temp!=NULL)
			{
				//Checks Duplicates
				if(new_node->value==temp->value)
				{
				  cout<<"Value Already Exit, Insert Another Value!"<<endl;
				  return;	
				}
				else if((new_node->value < temp->value) && (temp->left==NULL))
				{
					temp->left=new_node;
					cout<<"Value inserted to the left"<<endl;
					break;
				}
				else if(new_node->value < temp->value)
				{
					temp = temp->left;
				}
				else if((new_node->value > temp->value) && (temp->right==NULL))
				{
					temp->right=new_node;
					cout<<"Value inserted to thr right"<<endl;
					break;
				}
				else
				{
					temp = temp->right;
				}	
			}
		}	
	}
	
	void print2D(TreeNode *r,int space)
	{
		if(r == NULL) //Base Case
		    return;
		space +=SPACE; //Increase Distance between Levels
		print2D(r->right,space); //Process Right Child First
		cout<<endl;
		
		for(int i=SPACE; i<space; i++) //Print current node after space count
		    cout<<" ";
		cout<<r->value<<"\n";
		print2D(r->left,space); // process left child
	}
	
	void printPreorder(TreeNode* r)
	{
		if(r==NULL)
		   return; 
		//first print data of node
		cout<<r->value<<" ";
		//then recur on left subtree
		printPreorder(r->left);
		printPreorder(r->right);
	}
	
	void printInorder(TreeNode *r)
	{
		if(r==NULL)
		   return;
		printInorder(r->left);
		cout<<r->value<<" ";
		printInorder(r->right);
	}
	
	void printPostorder(TreeNode *r)
	{
		if(r==NULL)
		   return;
		printPostorder(r->left);
		printPostorder(r->right);
		cout<<r->value<<" ";
	}
	
	TreeNode* iterativeSearch(int val)
	{
		if(root==NULL)
		   return root;
		else
		{
			TreeNode *temp=root;
			while(temp!=NULL)
			{
				if(val==temp->value)
				   return temp;
				else if(val<temp->value)
				   temp=temp->left;
				else
				   temp=temp->right;
			}
		}
		return NULL;
	}
	
	int height(TreeNode *r)
	{
		if(r==NULL)
		   return -1;
		else
		{
			int lheight=height(r->left);
			int rheight=height(r->right);
			if(lheight > rheight)
			   return lheight+1;
			else
			   return rheight+1;
		}
	}
	
	void printLevelOrderBFS(TreeNode *r)
	{
		int h=height(r);
		
		for(int i=0; i<=h; i++)
		{
			printGivenLevel(r,i);
		}
	}
	
	void printGivenLevel(TreeNode *r,int level)
	{
		if(r==NULL)
		   return;
		else if(level == 0)
		   cout<<(r->value)<<" ";
		else
		   printGivenLevel(r->left,level-1);
		   printGivenLevel(r->right,level-1);
	}
	
	TreeNode *minValueNode(TreeNode *node)
	{
		TreeNode *current =  node;
		while(current->left!=NULL)
		{
			current = current->left;
		}
		return current;
	}
	
	TreeNode *deleteNode(TreeNode *r, int v)
	{
		if(r==NULL)
		  return NULL;
		else if(v < r->value)
		{
			r->left = deleteNode(r->left,v);
		}
		else if(v > r->value)
		{
			r->right = deleteNode(r->right,v);
		}
		else
		{
			if(r->left==NULL)
			{
				TreeNode *temp=r->right;
				delete r;
				return temp;
			}
			else if(r->right==NULL)
			{
				TreeNode *temp=r->left;
				delete r;
				return temp;
			}
			else
			{
				TreeNode *temp = minValueNode(r->right);
				r->value = temp->value;
				r->right = deleteNode(r->right,temp->value);
			}
		}
		return r;
	}
};


int main()
{
	int option,val,search,deletee;
	BST obj;
	do
	{
	 cout<<"What operations do want to perform?"
	 <<"Select Option number. Enter 0 to exit."<< endl;
	 
	 cout<<"1. Insert Node"<<endl;
	 cout<<"2. Search Node"<<endl;
	 cout<<"3. Delete Node"<<endl;
	 cout<<"4. Print BST values"<<endl;
	 cout<<"5. Clear Screen"<<endl;
	 cout<<"6. Print Pre Order"<<endl;
	 cout<<"7. Print In Order"<<endl;
	 cout<<"8. Print Post Order"<<endl;
	 cout<<"9. Height of the tree"<<endl;
	 cout<<"10. Level Order BST"<<endl;
	 cout<<"0. Exit Program"<<endl;
	 
	 cin>>option;
	 
	 //Create new node 
	 TreeNode *new_node = new TreeNode();
	 
	 switch(option)
	 {
	 	case 0:
	 	   break;
	 	   
	 	case 1:
	 		cout<<"Insert"<<endl;
	 		cout<<"Enter the value of tree node to enter in bst"<<endl;
	 		cin>>val;
	 		new_node->value = val;
	 		obj.insertNode(new_node);
	 		cout<<endl;
	 		break;
	 		
	 	case 2:
	 		cout<<"Search"<<endl;
	 		cout<<"Enter the value you want to search? "<<endl;
	 		cin>>search;
	 		if(obj.iterativeSearch(search))
	 		   cout<<"The value you are looking for is Present "<<endl;
	 		else
	 		   cout<<"The value you are looking for is not Present "<<endl;
	 		break;
	 		
	 	case 3:
	 		cout<<"Delete"<<endl;
	 		cout<<"Enter the value you want to delete" <<endl;
	 		cin>>deletee;
	 		new_node = obj.iterativeSearch(deletee);
	 		
	 		if(new_node!=NULL)
			 {
			 	obj.deleteNode(obj.root,deletee);
			 	cout<<"Value Deleted"<<endl;
			 }
			 else
			 {
                cout<<"Value not found"<<endl;
			 }
	 		break;
	 		
	 	case 4:
	 		cout<<"Print and Traverse"<<endl;
	 		obj.print2D(obj.root,5);
	 		break;
	 		
	 	case 5:
	 		cout<<"clr scr"<<endl;
	 		system("cls");
	 		break;
	 		
	 	case 6:
	 		obj.printPreorder(obj.root);
	 		cout<<endl;
	 		break;
	 		
	 	case 7:
	 		obj.printInorder(obj.root);
	 		cout<<endl;
	 		break;
	 		
	 	case 8:
	 		obj.printPostorder(obj.root);
	 		cout<<endl;
	 		break;
	 		
	 	case 9:
	 		cout<<obj.height(obj.root);
	 		cout<<endl;
	 		break;
	 		
	 	case 10:
	 		obj.printLevelOrderBFS(obj.root);
	 		cout<<endl;
	 		break;
	 		
	 	default:
	 		cout<<"Enter the right value"<<endl;
			
	 }
	}
	while(option!=0);
	
	
	
	return 0;
}
