#include<iostream>      														 //Header files
#include<string>
#include<sstream>      															 //Providing string stream classes   
#define MAX 25       															 //Defining a constant 
using namespace std;  


class Stack            															 //Defining Stack Class
{  
	public:  
		string stack[MAX]; 													 	 //implementing stack using array.
		int top;              													 //declaring top as integer.
		Stack()              	 												 //default constructor to initialise top as -1.
		{  
			top = -1;  
		}  

	    bool isFull()      														//For checking stack is full
		{  
		if(top == MAX-1)               //stack is full if top points at MAX-1
		    return true;  
		else 
	    	return false;  
		} 
		
	    bool isEmpty()     														//For checking stack is empty
		{  
			if(top == -1)                 //stack is empty if top points at -1
				return true;  
			else 
				return false; 
		}
		
	    void push(string element) 														//For pushing item in stack
		{  
			if(isFull()) 
			{//we cannot push an element into a full stack. (overflow)
				cout<<"Stack is full ";  
			}
			
			else
			{//to push an element in stack, we simply increment top by 1 and store the elemen in that index of array.
				top++;  
				stack[top] = element;  
			}  
	    }  

	    string pop()          															//For popping item out of stack
		{  
			if(isEmpty())  
			{//we cannot pop an element out of an empty stack.  (underflow)
				cout<<"Stack is empty";  
			}  
			else
			{//to pop, we simply return the top index element and decrement top pointer by 1.
				string Str_1 = stack[top];  
				top--;  
				return Str_1;  
			} 
    	}
};

class Expression          													//Defining Class Expression
{  
	public:  
		string postfix;                                                     //declaring string variables.
		string infix; 
		Stack Str_1;  
		
	bool isOperator(char x)  												//For checking whether the entered element is operator  
	{  
		if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' )  
		{  
		  return true;  
		}  
		else  
		{  
    	  return false;  
		} 
	}  

	int precedence(string t) 												//For Checking the precedence of operators
	{
	    if(t == "+" || t == "-") 
	      return 1;  
			
		else if( t == "*" || t == "/") 
		  return 2;  
			
		else if(t == "^") 
		  return 3;  
			
		else 
		  return 0;  
	}  
	//declaring the methods of the class.
	void infix_to_postfix();    
	void postfix_to_prefix();
	void postfix_evaluation(); 
};


void Expression::infix_to_postfix()  //For converting infix to postfix
{  
	cout<<"\n\nENTER THE INFIX EXPRESSION : ";  
	cin>>infix; 
	cout<<"\nTHE INFIX EXPRESSION : "<<infix; 
	string postfix;  
	
	for(int i = 0 ; i < infix.length() ; i++)
	{	
		if((infix[i] >= 'a' && infix[i]<='z') || (infix[i] >= 'A' && infix[i] <= 'Z'))             //For checking operands
		   	{
			   	postfix = postfix + infix[i]; 
			}
			
		else if(infix[i] == '(')                //For checking opening parenthesis
		   	{	
			   	Str_1.push("(");  
			}
			
		else if(infix[i] == ')')                //For checking closed parenthesis
		{	
		  	while( Str_1.top!= -1 && Str_1.stack[Str_1.top]!="(")
		   	{
		    	string t = Str_1.stack[Str_1.top];  
		    	Str_1.pop();                             
			  	postfix = postfix + t;  
		   	}  

		   	if(Str_1.stack[Str_1.top] == "(")
		   	{  
		   		string t = Str_1.stack[Str_1.top];  
			  	Str_1.pop();  
		  	} 
		}  
		else
		{  
			while(Str_1.top != -1 && precedence(string(1,infix[i])) <=  precedence(Str_1.stack[Str_1.top]))
			{  
				string t = Str_1.stack[Str_1.top];  
				Str_1.pop();  
				postfix = postfix + t;  
			}  
			Str_1.push(string(1,infix[i]));  
		} 
	}
	while( Str_1.top != -1 )
	{  
    	string t = Str_1.stack[Str_1.top];  
		Str_1.pop();  
		postfix = postfix + t; 
	}  

	cout<<"\nTHE POSTFIX EXPRESSION : "<<postfix<<endl;  
}

void Expression::postfix_to_prefix()   //For conversion of postfix to prefix
{  
	cout<<"\nENTER THE POSTFIX EXPRESSION : ";  
	cin>>postfix;  
	cout<<"\nTHE POSTFIX EXPRESSION : ";

	for (int i = 0;i<postfix.length();i++) 
	{  
		if(isOperator(postfix[i]))    //For checking operator
		{  
			string op1 = Str_1.pop();  
			string op2 = Str_1.pop();
			string exp = postfix[i] + op2 + op1; 
			Str_1.push(exp);  
		}  
			
		else  
		{  
			Str_1.push(string(1,postfix[i]));  
		} 
	}  

	string prefix = Str_1.pop();  
	cout<<"\nPREFIX EXPRESSION : "<<prefix<<endl;  
}

void Expression::postfix_evaluation()  //Evaluation of postfix expression
{ 
    string postfix;  

	cout<<"\nENTER THE POSTFIX EXPRESSION : ";  
	cin>>postfix;

	for(int i=0;i<postfix.length();i++)
	{  
		if(isOperator(postfix[i]))
		{  
			int ans;  
			int t2,t1;  
			
			string t_2 = Str_1.pop();  
			string t_1 = Str_1.pop();  
			stringstream change_2(t_2);  //changing the datatype of element of expression
			stringstream change_1(t_1);  
			change_2>>t2;  
			change_1>>t1;  
		

			if(postfix[i]=='+') 
          		ans = t1+t2;  
		
			else if(postfix[i]=='-') 
			  	ans = t1-t2;  
		
			else if(postfix[i]=='/') 
			  	ans = t1/t2;  
		
			else if (postfix[i]=='*') 
	    	  	ans = t1*t2;  
		
			else if(postfix[i]=='^') 
			  	ans = t1^t2;  
		
			ostringstream ans_1;  
        	ans_1<<ans;  
			string ans__1 = ans_1.str();  
			Str_1.push(ans__1);
	   } 

		else  if(isdigit(postfix[i]))
		{  	
			Str_1.push(string(1,postfix[i]));  
		} 
	}  
	string result = Str_1.pop();  
	cout<<"\nEVALUATED VALUE OF POSTFIX EXPRESSION : "<<result<<endl;  
}
	
int main()  
{  
	Expression exp;  
	int choice;
	int exit=0;
	cout<<"\t\t\t\t****************STACK APPLICATION*****************"<<endl;	
	while(exit!=-1)
	{
		cout<<"\n\t\t\t\tPRESS 1 TO CONVERT INFIX EXPRESSION TO POSTFIX";
		cout<<"\n\t\t\t\tPRESS 2 TO CONVERT POSTFIX EXPRESSION TO PREFIX";  
		cout<<"\n\t\t\t\tPRESS 3 TO EVALUATE A POSTFIX EXPRESSION";
		cout<<"\n\nENTER YOUR CHOICE : ";  
		cin>>choice;  
	
		switch(choice)  
		{
			case 1:  
			{  
				cout<<"\n\n<<<<<<<<<<INFIX TO POSTFIX CONVERSION>>>>>>>>>>";
				exp.infix_to_postfix();  
				break;  
			}  
	
			case 2: 
			{  
				cout<<"\n\n<<<<<<<<<<POSTFIX TO PREFIX CONVERSION>>>>>>>>>>";
				exp.postfix_to_prefix();  
				break;  
			}  
	
			case 3:  
			{
				cout<<"\n\n<<<<<<<<<<POSTFIX EVALUATION>>>>>>>>>>";
				exp.postfix_evaluation();  
				break;  
			} 
		}
	
		cout<<"\n\n\n\t\t\t\tPRESS -1 TO EXIT OR 1 TO GO MAIN MENU : ";
		cin>>exit;
	}
	return 0;
}


/*
OUTPUT : 

*/
