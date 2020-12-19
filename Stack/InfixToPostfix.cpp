#include<iostream>
#include<stack>
using namespace std;

/* **********Rules for Infix to Postfix*******************
Scan Expression from Left to Right
Print OPERANDs as the arrive
If OPERATOR arrives & Stack is empty, push this operator onto the stack
IF incoming OPERATOR has HIGHER precedence than the TOP of the Stack, push it on stack
IF incoming OPERATOR has LOWER precedence than the TOP of the Stack, then POP and print the TOP. Then test the incoming operator against the NEW TOP of stack.
IF incoming OPERATOR has EQUAL precedence with TOP of Stack, use ASSOCIATIVITY Rules.
For ASSOCIATIVITY of LEFT to RIGHT –
POP and print the TOP of stack, then push the incoming OPERATOR
For ASSOCIATIVITY of RIGHT to LEFT –
PUSH incoming OPERATOR on stack.
At the end of Expression, POP & print all  OPERATORS from the stack
IF incoming SYMBOL is ‘(‘ PUSH it onto Stack.
IF incoming SYMBOL is ‘)’ POP the stack and print OPERATORs till ‘(‘ is found. POP that ‘(‘
IF TOP of stack is ‘(‘ PUSH OPERATOR on Stack*/


//Function to check the operator given by the user
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

//function to check the Precedence of the operators
int Precedence(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='*' || c=='/')
	{
		return 2;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

//function to Covert Infix to Postfix
string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	
	for(int i=0; i<infix.length(); i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((!s.empty()) && (s.top()!='('))
			{
				postfix+=s.top();
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
				if(Precedence(infix[i]) > Precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else if((Precedence(infix[i]) == Precedence(s.top())) && (infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty()) && (Precedence(infix[i]) <= Precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
		
	return postfix;
}

int main()
{
	string postfix,infix;
	cout<<"Enter the Infixfix Expression : ";
	cin>>infix;
	
	stack <char> s;
	postfix=InfixToPostfix(s,infix);
    cout<<endl<<"Postfix Expression After Conversion is : "<<postfix;
	
	return 0;
}
