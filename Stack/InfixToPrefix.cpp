#include<bits/stdc++.h>
using namespace std;

//Isoperator 
bool isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}	
}

//Will check the precedence
int Precedence(char c)
{
	if(c=='+' || c=='-')
	{
		return 1;
	}
	else if(c=='*' || c== '/')
	{
		return 2;
	}
	else if(c=='^')
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

//Function to Convert Infix to Postfix
string Infix_To_Prefix(stack<char> s,string infix)
{
	string prefix;
	//Renerse first
	reverse(infix.begin(),infix.end());
	
	//Reverse the ( )  sign
	for(int i=0; i<infix.length(); i++)
	{
		if(infix[i]=='(')
		{
			infix[i]=')';
		}
		else if(infix[i]==')')
		{
			infix[i]='(';
		}
	}
	//Output
	for(int i=0; i<infix.length(); i++)
	{
		if((infix[i]>='a' && infix[i]<='z') ||  (infix[i]>='A' && infix[i]<='Z'))
		{
			prefix+=infix[i];	
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((!s.empty()) && (s.top()!='('))
			{
				prefix+=s.top();
				s.pop();
			}
			
			if(s.top()=='(')
			{
				s.pop();
			}
			
		}
		else if(isOperator(infix[i]))
		{
		   if(s.empty())
		   {
		   	s.push(infix[i]);
		   }
		   else
		   {
		   	if(Precedence(infix[i])>Precedence(s.top()))
			{
			   	s.push(infix[i]);
			}
			else if((Precedence(infix[i])==Precedence(s.top()))  && infix[i]=='^')
			{
				while(((Precedence(infix[i])==Precedence(s.top()))  && infix[i]=='^'))
				{
					prefix+=s.top();
					s.pop();
				}
				s.push(infix[i]);
			}
			else if(Precedence(infix[i])==Precedence(s.top()))
			{
				s.push(infix[i]);
			}
			else if(Precedence(infix[i])<Precedence(s.top()))
			{
				while((!s.empty()) && (Precedence(infix[i])<Precedence(s.top())))
				{
					prefix+=s.top();
					s.pop();
				}
				s.push(infix[i]);
			}
		   }	
		}
	}
	
	while(!s.empty())
	{
		prefix+=s.top();
		s.pop();
	}
	
	//Reverse Again 	
	reverse(prefix.begin(),prefix.end());
	return prefix;
}

int main()
{
	string infix;
	cout<<"Enter the Infix String : ";
	cin>>infix;
	
	stack<char> stack;
	
	string prefix=Infix_To_Prefix(stack,infix);
	
	cout<<"Prefix is : "<<prefix;
	
	return 0;
}
