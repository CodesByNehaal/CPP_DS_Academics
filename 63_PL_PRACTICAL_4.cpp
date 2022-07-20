/*
NAME : NEHAAL PANDEY
BATCH : A(A3)
ROLL NO. : 63
PRN : 0120200245
PRACTICAL 4 : Design and develop program for polynomial addition, multiplication operations for disease information using circular linked list.


*/

//including the required library 
#include<iostream>
using namespace std;

class node //creating a class named node 
{
	public: 
	int coeff;
	int exp;
	node *next;
	node() //creating a constructor.
	{
		next = NULL;
	}
};

class poly //creating a class named poly to do operations for polynomial.
{
	
	node *head;
	public:
	poly()
	{
		head = NULL;
	}
	void create();
	void display();
	void sorted_insert(node *temp);
	void addition(poly p1, poly p2);
	void multiplication(poly p1, poly p2);
};

//creating a polynomial by taking the coefficient and the exponent by the user. 
void poly :: create()
{
	int ch;
	node *temp;
	do
	{
		temp = new node();
		cout<<"\n\n\tEnter the coefficient : ";
		cin>>temp->coeff;
		cout<<"\n\tEnter the exponent : ";
		cin>>temp->exp;
		temp->next = temp;
		sorted_insert(temp);
		cout<<"\n\n\tPress 1 to add more term or any other key to exit...";
		cin>>ch;
	}while(ch==1);	
}

//sorting the polynomial based on its exponent value.
void poly:: sorted_insert(node *temp)
{
	if(head == NULL)
    {
    	head = temp;
		return;
    }
	node *p, *prev;
	if (head->exp<temp->exp)
	{
		p = head;
		while(p->next!=head )
		{
			p=p->next;
		}
		p->next = temp;
		temp->next= head;
		head = temp;
		return;
	}
	p=head;
	while(1)
	{	
		if(p->exp==temp->exp)
		{
			p->coeff=p->coeff+temp->coeff;
			delete(temp);
			break;
		}
        else if(p->exp<temp->exp || p->next==head)
	    {
		    if(p->exp<temp->exp)
	    	{
    			prev->next=temp;
	    		temp->next=p;
		    	break;
	        }
            else 
            {
            	temp->next=p->next;
	        	p->next=temp;
	            break;
            }
        }
        else
	    {
    		prev = p;
	    	p = p->next;
	    }
    }
}

//function to add two polynomials
void poly::addition(poly p1, poly p2)
{
	if(p1.head==NULL && p2.head==NULL)
	{
		return;
	}
	node *p, *temp;
	p=p1.head;
	do
	{
		temp = new node;
	    temp->coeff=p->coeff;
        temp->exp=p->exp;
        temp->next=temp;
        sorted_insert(temp);
        p=p->next;
    }while(p!=p1.head);
    
	p=p2.head;
    do
	{
	   temp = new node;
	   temp->coeff=p->coeff;
	   temp->exp=p->exp;
	   temp->next=temp;
	   sorted_insert(temp);
	   p=p->next;
	}while(p!=p2.head);
}

//function to multiply two polynomials.
void poly:: multiplication(poly p1, poly p2)
{
	if(p1.head==NULL && p2.head==NULL)
	{
		return;
	}
	node *t1, *t2, *temp;
    t1=p1.head;
	do
	{
		t2=p2.head;
		do
		{
			temp=new node();
			temp->coeff=t1->coeff*t2->coeff;
			temp->exp=t1->exp+t2->exp;
			temp->next=temp;
			sorted_insert(temp);
			t2=t2->next;
		}while(t2!=p2.head);
	    t1=t1->next;
	}while(t1!=p1.head);
}

//function to display a polynomial.
void poly::display()
{
	node *p;
	if(head==NULL)
	{
		cout<<"Polynomial is Empty";
	}
    else
    {
    	p=head;
        while(p->next!=head)
		{
			cout<<" "<<p->coeff<<"X^"<<p->exp<<" +";
			p = p->next;
		}
		cout<<" "<<p->coeff<<"X^"<<p->exp<<" = 0";
	}
}

int main()
{
	cout<<"**********************************DISEASE RATE CALCULATIONS**********************************************\n\n\n";
	poly DR_2019, DR_2020, DR_1920, GR_2019, GR_2020, sum1, sum2, MR_2019, MR_2020;
	
	cout<<"\nEnter the bacteria growth rate equation for Pune for 2019 : \n";
	GR_2019.create();
	cout<<"\n\n\nThe Equation is :\n";
	GR_2019.display();
	cout<<"\n\n\nEnter the bacteria growth rate equation for pune for 2020 : \n";
	GR_2020.create();
	cout<<"\n\n\nThe Equation is :\n";
	GR_2020.display();
	
	cout<<"\n\nEnter the bacteria Mutation rate equation for Pune for 2019 : \n";
	MR_2019.create();
	cout<<"\n\n\nThe Equation is :\n";
	MR_2019.display();
	cout<<"\n\n\nEnter the bacteria Mutation rate equation for pune for 2020 : \n";
	MR_2020.create();
	cout<<"\n\n\nThe Equation is :\n";
	MR_2020.display();
	
	
	int choice;
	cout<<"\n\nPRESS 1 TO GET THE DISEASE SPREAD RATE FOR PUNE FOR 2019";
	cout<<"\nPRESS 2 TO GET THE DISEASE SPREAD RATE FOR PUNE FOR 2020";
	cout<<"\nPRESS 3 TO GET THE DISEASE SPREAD RATE FOR PUNE FOR 2019-20";
	cout<<"\n\n\tENTER YOUR CHOICE : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: 
			DR_2019.multiplication(GR_2019,MR_2019);
			cout<<"\n\nMultiplying Growth rate with Mutation Rate of the bacteria for the year 2019 : ";
			cout<<"\n\tthe disease spread rate is :";
			DR_2019.display();
			break;
		
		case 2:
			DR_2020.multiplication(GR_2020,MR_2020);
			cout<<"\n\nMultiplying Growth rate with Mutation Rate of the bacteria for the year 2020 : ";
			cout<<"\n\tthe disease spread rate is :";
			DR_2020.display();
			break;
			
		case 3:
			cout<<"\n\nAdding the Growth rate of the bacteria of year 2019 and 2020 : \n";
			sum1.addition(GR_2019,GR_2020);	
			sum1.display();
			
			cout<<"\n\nAdding the Mutation rate of the bacteria of year 2019 and 2020 : \n";
			sum2.addition(MR_2019,MR_2020);
			sum2.display();
			
			cout<<"\n\nMultiplying them to get the disease rate equation for the combined year of 2019 and 2020 : \n\n";
			DR_1920.multiplication(sum1,sum2);
			DR_1920.display();
			break;
	}
	return 0;
}

/*

OUTPUT : 

**********************************DISEASE RATE CALCULATIONS**********************************************



Enter the bacteria growth rate equation for Pune for 2019 :


        Enter the coefficient : 3

        Enter the exponent : 2


        Press 1 to add more term or any other key to exit...1


        Enter the coefficient : 5

        Enter the exponent : 1


        Press 1 to add more term or any other key to exit...0



The Equation is :
 3X^2 + 5X^1 = 0


Enter the bacteria growth rate equation for pune for 2020 :


        Enter the coefficient : 6

        Enter the exponent : 3


        Press 1 to add more term or any other key to exit...1


        Enter the coefficient : 4

        Enter the exponent : 2


        Press 1 to add more term or any other key to exit...1


        Enter the coefficient : 2

        Enter the exponent : 1


        Press 1 to add more term or any other key to exit...0



The Equation is :
 6X^3 + 4X^2 + 2X^1 = 0

Enter the bacteria Mutation rate equation for Pune for 2019 :


        Enter the coefficient : 9

        Enter the exponent : 2


        Press 1 to add more term or any other key to exit...1


        Enter the coefficient : 6

        Enter the exponent : 1


        Press 1 to add more term or any other key to exit...0



The Equation is :
 9X^2 + 6X^1 = 0


Enter the bacteria Mutation rate equation for pune for 2020 :


        Enter the coefficient : 3

        Enter the exponent : 3


        Press 1 to add more term or any other key to exit...1


        Enter the coefficient : 2

        Enter the exponent : 2


        Press 1 to add more term or any other key to exit...1


        Enter the coefficient : 3

        Enter the exponent : 2


        Press 1 to add more term or any other key to exit...1


        Enter the coefficient : 2

        Enter the exponent : 1


        Press 1 to add more term or any other key to exit...0



The Equation is :
 3X^3 + 5X^2 + 2X^1 = 0

PRESS 1 TO GET THE DISEASE SPREAD RATE FOR PUNE FOR 2019
PRESS 2 TO GET THE DISEASE SPREAD RATE FOR PUNE FOR 2020
PRESS 3 TO GET THE DISEASE SPREAD RATE FOR PUNE FOR 2019-20

        ENTER YOUR CHOICE : 3


Adding the Growth rate of the bacteria of year 2019 and 2020 :
 6X^3 + 7X^2 + 7X^1 = 0

Adding the Mutation rate of the bacteria of year 2019 and 2020 :
 3X^3 + 14X^2 + 8X^1 = 0

Multiplying them to get the disease rate equation for the combined year of 2019 and 2020 :

 18X^6 + 105X^5 + 167X^4 + 154X^3 + 56X^2 = 0
--------------------------------
Process exited after 64.92 seconds with return value 0
Press any key to continue . . .

*/
