#include<iostream> //Header Files
#include<cstring>
using namespace std;

//declaring a class "parity-checker" for operations of parity check.
class parity_checker 
{
	//declaring variables and methods
	public:
	int i, j=0, counter=0; 
	string str;
	int str_int[100];
	void input(); 
	void even_parity();
	void odd_parity();
};

void parity_checker :: input() //for taking a string from the user.
{
	cout<<"\nENTER THE STRING : ";
	cin>>str;
}

void parity_checker :: even_parity() //for checking even parity
{
	int n=str.length();                      							//storing length of string in a variable "n"
	j=0;																//initialising j=0
	for(i=0; i<n; i++)                     								//traversing through each character of the string.
	{
		int value=int(str[i]);               							//converting the character to its integer equivalnce. i.e. ascii number
		cout<<"ascii of "<<str[i]<<" character : "<<value<<endl;        //displaying the ascii of each character to the user.
		while(value>0) 									
		{//converting ascii value to its binary equivalence and storing it in a new array.
			int p=value%2;
			str_int[j]=p;
			value/=2;
			j++;
		}
	}

	for(i=j-1; i>=0; i--)
	{//counting no. of 1s in the binary code of the whole string.
		cout<<str_int[i];
		
		if(str_int[i]==1)
		{//the counter will keep the count of the 1s present in it.
			counter++;
		}
	}

	if((counter%2)==0)
	{//if there are even no. of 1s, it is even parity.
		cout<<"\nEntered string is EVEN parity.";
	}
	else
	{//else, it is not
		cout<<"\nEntered string is not EVEN parity.";
	}
}

//same like above
void parity_checker :: odd_parity() //Checking ODD parity
{
	int n=str.length();
	j=0;																//initialising j=0
	counter=0;
	for(i=0; i<n; i++)                     //traversing through each character of the string.
	{
		int value=int(str[i]);               //converting the character to its integer equivalnce. i.e. ascii number
		cout<<"ascii of "<<str[i]<<" character : "<<value<<endl;                 //displaying the ascii of each character to the user.
		while(value>0) 									
		{//converting ascii value to its binary equivalence and storing it in a new array.
			int p=value%2;
			str_int[j]=p;
			value/=2;
			j++;
		}
	}
	
	for(i=j-1; i>=0; i--)
	{
		cout<<str_int[i];
		if(str_int[i]==1)
		{
			counter++;
	    }
	}
	
	if((counter%2)!=0)
	{
		cout<<"\nEntered string is ODD parity.";
	}
	else
	{
		cout<<"\nEntered string is not ODD parity.";
	}
}

int main() //Main function
{
	parity_checker parity; //object 'p' of 'parity_checker'
	int choice, end_loop=0;
	
	cout<<"************************************************PARITY CHECKER*****************************************************";
	do
	{
		cout<<"\n\n\t\t\t\tPRESS 1 TO CHECK FOR EVEN PARITY";
		cout<<"\n\t\t\t\tPRESS 2 TO CHECK FOR ODD PARITY";
		cout<<"\n\t\t\t\tPRESS 3 TO EXIT!";
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				parity.input();
				parity.even_parity();
				break;
		
			case 2:
				parity.input();
				parity.odd_parity();
				break;
				
			case 3:
				end_loop = 1;
				break;
			
			default:
				cout<<"ENTER CORRECT OPTION. THANK YOU!";
		}
	}while(end_loop!=1);
}



/*
OUTPUT : 
************************************************PARITY CHECKER*****************************************************

                                PRESS 1 TO CHECK FOR EVEN PARITY
                                PRESS 2 TO CHECK FOR ODD PARITY
                                PRESS 3 TO EXIT!
ENTER YOUR CHOICE : 1

ENTER THE STRING : abc
ascii of a character : 97
ascii of b character : 98
ascii of c character : 99
110001111000101100001
Entered string is EVEN parity.

                                PRESS 1 TO CHECK FOR EVEN PARITY
                                PRESS 2 TO CHECK FOR ODD PARITY
                                PRESS 3 TO EXIT!
ENTER YOUR CHOICE : 2

ENTER THE STRING : abc
ascii of a character : 97
ascii of b character : 98
ascii of c character : 99
110001111000101100001
Entered string is not ODD parity.

                                PRESS 1 TO CHECK FOR EVEN PARITY
                                PRESS 2 TO CHECK FOR ODD PARITY
                                PRESS 3 TO EXIT!
ENTER YOUR CHOICE : 3

--------------------------------
Process exited after 17.07 seconds with return value 0
Press any key to continue . . .
*/
