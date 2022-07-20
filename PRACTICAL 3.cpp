/*
NAME : NEHAAL ANIL PANDEY
BATCH : A(A3)
ROLL NO. : 63
PRN NO. : 0120200245
Practical 3 : Design and develop program for insertion, up-dating, searching, sorting, listing and deletion operations using singly linked list 
for placement information system
*/


#include <iostream>
using namespace std;

class node
{
	public:
		int roll_no,prn;
		float sgpa1,sgpa2,cgpa;
		node *next;
		node()
		{
			next =NULL;
		}
};

class A3_batch
{
	node *head;
	public:
		A3_batch()
		{
			head = NULL;
		}
		void input();
		void output();
		void append();
		void insert_beg();
		void insert_after();
		void search();
		void update();
		void del();
		void sort();

};

void A3_batch :: input()
{
	node *temp, *p;
	int ch;
	do
	{
		temp = new node();
		cout<<"\n\nENTER THE ROLL NO. : ";
		cin>>temp->roll_no;
		cout<<"ENTER THE PRN OF THE STUDENT : ";
		cin>>temp->prn;
		cout<<"ENTER THE SGPA OF SEM1 AND SEM 2 : ";
		cin>>temp->sgpa1>>temp->sgpa2;
		temp->cgpa = (temp->sgpa1 + temp->sgpa2)/2.0;
		
		if(head==NULL)
		{
			head = temp;
		}
		else
		{
			p = head;
			while(p->next!=0)
			{
				p = p->next;
			}
			p->next=temp;
		}
		cout<<"PRESS 1 TO ADD MORE STUDENT : ";
		cin>>ch;
	}while(ch==1);
}

void A3_batch::append()
{
	node *temp;
	temp = new node();
	cout<<"ENTER THE ROLL NO. TO BE APPENDED AT THE LAST : ";
	cin>>temp->roll_no;
	cout<<"ENTER THE PRN OF THE STUDENT : ";
	cin>>temp->prn;
	cout<<"ENTER THE SGPA OF SEM1 AND SEM 2 : ";
	cin>>temp->sgpa1>>temp->sgpa2;
	temp->cgpa = (temp->sgpa1 + temp->sgpa2)/2.0;


	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		node *p;
		p = head;
			while(p->next!=0)
			{
				p = p->next;
			}
			p->next=temp;
	}
}

void A3_batch::insert_beg()
{
	node *temp;
	temp = new node();
	cout<<"ENTER THE ROLL NO. YOU WISH TO INSERT IN THE BEGINNING : ";
	cin>>temp->roll_no;
	cout<<"ENTER THE PRN OF THE STUDENT : ";
	cin>>temp->prn;
	cout<<"ENTER THE SGPA OF SEM1 AND SEM 2 : ";
	cin>>temp->sgpa1>>temp->sgpa2;
	temp->cgpa = (temp->sgpa1 + temp->sgpa2)/2.0;

	if(head==NULL)
	{
		head = temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}

void A3_batch::insert_after()
{
	node *temp, *p;
	int flag=0, x;
	
	cout<<"\n Enter the Roll Number after which you want to insert: ";
	cin>>x;
	
	if(head==NULL)
	{
		cout<<"\n List is empty";
		return;
	}
	
	temp = new node();
	
	cout<<"\n Enter the Roll Number to be Insert: ";
	cin>>temp->roll_no;
	cout<<"ENTER THE PRN OF THE STUDENT : ";
	cin>>temp->prn;
	cout<<"ENTER THE SGPA OF SEM1 AND SEM 2 : ";
	cin>>temp->sgpa1>>temp->sgpa2;
	temp->cgpa = (temp->sgpa1 + temp->sgpa2)/2.0;

	
	p=head;
	while(p!=NULL)
	{
		if(p->roll_no==x)
		{
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==1)
	{
		temp->next = p->next;
		p->next = temp;
	}
	else
	{
		cout<<"\n Element not found!!! ";
	}
}

void A3_batch::search()       
{
	node *temp, *p;
	int flag=0, x;

	cout<<"\nEnter the Roll Number you are searching for: ";
	cin>>x;
	
	if(head==NULL)
	{
		cout<<"\n List is empty";
		return;
	}
	
	p=head;
	while(p!=NULL)
	{
		if(p->roll_no==x)
		{
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==1)
	{
		cout<<"\n Roll Number's records are present!!!";
		cout<<"\nROLL NO. : "<<p->roll_no;
		cout<<"\nPRN : "<<p->prn;
		cout<<"\nSEM 1 SGPA : "<<p->sgpa1;
		cout<<"\nSEM 2 SGPA : "<<p->sgpa2;
		cout<<"\nCGPA : "<<p->cgpa;
	}
	else
	{
		cout<<"\nRoll Number's records not found!!!";
	}
}

void A3_batch::update()                                       
{
	int flag=0,x; 
	
	cout<<"\nENter the roll no whose details you want to update : ";
	cin>>x;
	
	if(head==NULL)
	{
		cout<<"\nList id empty ";
		return;
	}
	node *p, *prev;
	p=head;
	while(p!=NULL)
	{
		if(p->roll_no==x)
		{
			flag=1;
			cout<<"\nEnter the updated PRN of roll no "<<p->roll_no<<" : ";
			cin>>p->prn;
			cout<<"\nEnter the updated SGPA of sem1 and sem2 of roll no "<<p->roll_no<<" : ";
			cin>>p->sgpa1>>p->sgpa2;
			p->cgpa = (p->sgpa1 + p->sgpa2)/2.0;
			break;
		}
		p=p->next;
	}
	if(flag==0)
	{
		cout<<"\n Roll no. not found.";
	}
	else
	{
		cout<<" Updated successfully!!!";
	}

}

void A3_batch::del()
{
	node *p;
    float x=9.2;
    
    if(head==NULL)
    {
        cout<<"List is empty\n";
    }
    p=head;
    while(p->next!=NULL)
    {
    	if(head->cgpa<=x)
    	{
    		head = head->next;
		}
		else if(p->next->cgpa<=x && p->next!=NULL)
		{
			p->next=p->next->next;
		}
		else
		{
			 p=p->next;
		}
    }
}


void A3_batch::sort()
{
	node *p,*q,*temp;
	int swapped=0;
	temp = new node();
	q=head;
	while(q->next!=NULL)
	{
		p=head;
		swapped=0;
		while(p->next!=NULL)
		{
			if(p->cgpa<p->next->cgpa)
			{
				temp->cgpa=p->cgpa;
				p->cgpa=p->next->cgpa;
				p->next->cgpa=temp->cgpa;
				temp->prn=p->prn;
				p->prn=p->next->prn;
				p->next->prn=temp->prn;
				temp->roll_no=p->roll_no;
				p->roll_no=p->next->roll_no;
				p->next->roll_no=temp->roll_no;
				temp->sgpa1=p->sgpa1;
				p->sgpa1=p->next->sgpa1;
				p->next->sgpa1=temp->sgpa1;
				temp->sgpa2=p->sgpa2;
			  	p->sgpa2=p->next->sgpa2;
			  	p->next->sgpa2=temp->sgpa2;
				swapped=1;	
			}
			p=p->next;
		}
		if(swapped=0)
		{
			break;
		}
		else
		{
			q=q->next;
		}
	}
}

void A3_batch::output()
{
	node *p;
	if(head==NULL)
	{
		cout<<"LINKED LIST EMPTY";
	}
	else
	{
		cout<<"\nroll no\t PRN\t\t SEM 1 SGPA\t\tSEM 2 SGPA\t\t\t CGPA\n";
		p = head;
		while(p!=NULL)
		{
			cout<<p->roll_no<<"\t"<<p->prn<<"\t\t"<<p->sgpa1<<"\t\t\t"<<p->sgpa2<<"\t\t\t  "<<p->cgpa<<"\n";
			p = p->next;
		}
	}
}

int main()
{
	A3_batch A3;
	int choice,choice1,choice2;
	cout<<"\t\t\t**********INTERNSHIP PLACEMENT FOR SY BTECH STUDENTS**********";
	cout<<"\n\n\t\t\t\tCRITERIA : cummulative GPA above 9.2 in FY BTECH!!!";
	
	cout<<"\n\n\n\t\t\tENTER BELOW THE DETAILS OF THE STUDENTS APPLYING FOR THE INTERNSHIP\n";
	A3.input();
	cout<<"\n\n\n\t\t\tFOLLOWING STUDENTS HAVE SHOWN INTEREST FOR THE INTERNSHIP PROGRAM\n";
	A3.output();
	cout<<"\n\n\t\tDOES THE LIST CONTAINS LIST OF ALL THE STUDENTS OR HAVE WE MISSED OUT ON SOMEONE?\n";
	cout<<"\nPRESS 1 TO INSERT A STUDENT AT THE END OF THE LIST";
	cout<<"\nPRESS 2 TO INSERT A STUDENT AT THE BEGINNING OF THE LIST";
	cout<<"\nPRESS 3 TO INSERT A STUDENT AT THE POSITION OF YOUR CHOICE";
	cout<<"\nPRESS 4 IF THE LIST CONTAINS DETAILS OF ALL THE INTERESTED STUDENTS\n";
	cout<<"\n\t\tENTER YOUR CHOICE : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
			A3.append();
			break;
		
		case 2:
			A3.insert_beg();
			break;
			
		case 3:
			A3.insert_after();
			break;
		
		case 4:
			cout<<"LIST UPDATION SUCCESSFUL";
			break;
		
		default:
			cout<<"\nENTER A VALID CHOICE. THANK YOU!!!";
	}
	
	cout<<"\n\n\t\tTHE LIST NOW HAS THE DETAILS OF ALL THE STUDENTS!";
	
	cout<<"\n\n\t\tPRESS 1 TO UPDATE THE DETAILS OF A STUDENT OR 0 TO MOVE AHEAD : \n";
	cin>>choice1;
	if(choice1==1)
	{
		A3.update();
	}
	
	cout<<"\n\n\t\tTHE UPDATED LIST IS DISPLAYED BELOW \n\n";
	A3.output();
	
	cout<<"\n\n\t\tPRESS 1 TO SEARCH THE DETAILS OF A STUDENT OR 0 TO MOVE AHEAD : ";
	cin>>choice2;
	if(choice2==1)
	{
		A3.search();
	}

	cout<<"\n\n\t\tLET'S REMOVE THE DETAILS OF THE STUDENTS WHOSE CGPA IS BELOW 9.2\n";
	A3.del();
	A3.output();
	
	cout<<"\n\\n\t\tWE WILL NOW SORT THE STUDENTS BASED ON THEIR CGPA AND THE TOP 3 WILL BE QUALIFIED FOR THE INTERVIEW ROUND!";
	A3.sort();
	A3.output();
	cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!";
	
	
	
	return 0;
}


/*
OUTPUT : 

                        **********INTERNSHIP PLACEMENT FOR SY BTECH STUDENTS**********

                                CRITERIA : cummulative GPA above 9.2 in FY BTECH!!!


                        ENTER BELOW THE DETAILS OF THE STUDENTS APPLYING FOR THE INTERNSHIP


ENTER THE ROLL NO. : 101
ENTER THE PRN OF THE STUDENT : 120200201
ENTER THE SGPA OF SEM1 AND SEM 2 : 9.8 9.6
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 102
ENTER THE PRN OF THE STUDENT : 120200202
ENTER THE SGPA OF SEM1 AND SEM 2 : 9.4 9.4
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 103
ENTER THE PRN OF THE STUDENT : 120200203
ENTER THE SGPA OF SEM1 AND SEM 2 : 8.6 8.7
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 104
ENTER THE PRN OF THE STUDENT : 120200204
ENTER THE SGPA OF SEM1 AND SEM 2 : 7.8 9.0
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 105
ENTER THE PRN OF THE STUDENT : 120200205
ENTER THE SGPA OF SEM1 AND SEM 2 : 10 10
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 106
ENTER THE PRN OF THE STUDENT : 120200206
ENTER THE SGPA OF SEM1 AND SEM 2 : 8.9 9.7
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 107
ENTER THE PRN OF THE STUDENT : 120200207
ENTER THE SGPA OF SEM1 AND SEM 2 : 8.8 8.9
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 108
ENTER THE PRN OF THE STUDENT : 120200208
ENTER THE SGPA OF SEM1 AND SEM 2 : 7.8 8.1
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 109
ENTER THE PRN OF THE STUDENT : 120200209
ENTER THE SGPA OF SEM1 AND SEM 2 : 9.8 9.6
PRESS 1 TO ADD MORE STUDENT : 1


ENTER THE ROLL NO. : 110
ENTER THE PRN OF THE STUDENT : 120200210
ENTER THE SGPA OF SEM1 AND SEM 2 : 10 9.95
PRESS 1 TO ADD MORE STUDENT : 0



                        FOLLOWING STUDENTS HAVE SHOWN INTEREST FOR THE INTERNSHIP PROGRAM

roll no  PRN             SEM 1 SGPA             SEM 2 SGPA                       CGPA
101     120200201               9.8                     9.6                       9.7
102     120200202               9.4                     9.4                       9.4
103     120200203               8.6                     8.7                       8.65
104     120200204               7.8                     9                         8.4
105     120200205               10                      10                        10
106     120200206               8.9                     9.7                       9.3
107     120200207               8.8                     8.9                       8.85
108     120200208               7.8                     8.1                       7.95
109     120200209               9.8                     9.6                       9.7
110     120200210               10                      9.95                      9.975


                DOES THE LIST CONTAINS LIST OF ALL THE STUDENTS OR HAVE WE MISSED OUT ON SOMEONE?

PRESS 1 TO INSERT A STUDENT AT THE END OF THE LIST
PRESS 2 TO INSERT A STUDENT AT THE BEGINNING OF THE LIST
PRESS 3 TO INSERT A STUDENT AT THE POSITION OF YOUR CHOICE
PRESS 4 IF THE LIST CONTAINS DETAILS OF ALL THE INTERESTED STUDENTS

                ENTER YOUR CHOICE : 2
ENTER THE ROLL NO. YOU WISH TO INSERT IN THE BEGINNING : 100
ENTER THE PRN OF THE STUDENT : 120200200
ENTER THE SGPA OF SEM1 AND SEM 2 : 9.9 9.9


                THE LIST NOW HAS THE DETAILS OF ALL THE STUDENTS!

                PRESS 1 TO UPDATE THE DETAILS OF A STUDENT OR 0 TO MOVE AHEAD :
1

ENter the roll no whose details you want to update : 109

Enter the updated PRN of roll no 109 : 120200209

Enter the updated SGPA of sem1 and sem2 of roll no 109 : 9.7 9.7
 Updated successfully!!!

                THE UPDATED LIST IS DISPLAYED BELOW


roll no  PRN             SEM 1 SGPA             SEM 2 SGPA                       CGPA
100     120200200               9.9                     9.9                       9.9
101     120200201               9.8                     9.6                       9.7
102     120200202               9.4                     9.4                       9.4
103     120200203               8.6                     8.7                       8.65
104     120200204               7.8                     9                         8.4
105     120200205               10                      10                        10
106     120200206               8.9                     9.7                       9.3
107     120200207               8.8                     8.9                       8.85
108     120200208               7.8                     8.1                       7.95
109     120200209               9.7                     9.7                       9.7
110     120200210               10                      9.95                      9.975


                PRESS 1 TO SEARCH THE DETAILS OF A STUDENT OR 0 TO MOVE AHEAD : 1

Enter the Roll Number you are searching for: 105

 Roll Number's records are present!!!
ROLL NO. : 105
PRN : 120200205
SEM 1 SGPA : 10
SEM 2 SGPA : 10
CGPA : 10

                LET'S REMOVE THE DETAILS OF THE STUDENTS WHOSE CGPA IS BELOW 9.2

roll no  PRN             SEM 1 SGPA             SEM 2 SGPA                       CGPA
100     120200200               9.9                     9.9                       9.9
101     120200201               9.8                     9.6                       9.7
102     120200202               9.4                     9.4                       9.4
105     120200205               10                      10                        10
106     120200206               8.9                     9.7                       9.3
109     120200209               9.7                     9.7                       9.7
110     120200210               10                      9.95                      9.975

\n              WE WILL NOW SORT THE STUDENTS BASED ON THEIR CGPA AND THE TOP 3 WILL BE QUALIFIED FOR THE INTERVIEW ROUND!
roll no  PRN             SEM 1 SGPA             SEM 2 SGPA                       CGPA
105     120200205               10                      10                        10
110     120200210               10                      9.95                      9.975
100     120200200               9.9                     9.9                       9.9
101     120200201               9.8                     9.6                       9.7
109     120200209               9.7                     9.7                       9.7
102     120200202               9.4                     9.4                       9.4
106     120200206               8.9                     9.7                       9.3





                                                THANK YOU!
--------------------------------
Process exited after 210.4 seconds with return value 0
Press any key to continue . . .
*/ 
