/*
NAME : NEHAAL PANDEY
PRN : 0120200245
ROLL : 63
DIV : A(A3)
PROBLEM STATEMENT 5 : Design and implement a program for sorting two given lists and merging these two sorted lists of marks scored for 
technical skill examination of recruitment cell using doubly linked list.
*/

#include <iostream>
using namespace std;

//declaring a class name node with two pointers. next and prev
class node
{
    public:
    int marks;
    int roll_no;
    node *next, *prev;
};

//declaring a class name marks with methods for creating, displaying, sorting and merging a doubly linked list.
class marks
{
    public:
    node *head;
    int len;
    marks()
    {
        head = NULL;
        len = 0;
    }
    void create();
    void display();
    void sort();
    void merge(marks CS, marks IT);
    void qualified();
};

//creating a doubly linked list
void marks::create()
{
    node *temp, *ptr;
    int flag;
    //a do-while loop until the user wants to enter data into the list.
    do
    {
        temp = new node;
        cout<<"\n\nEnter Student's roll number : ";
        cin>>temp->roll_no;
        cout<<"Enter Student's marks out of 10 : ";
        cin>>temp->marks;
        temp->prev = NULL;
        temp->next = NULL;
        len++;
        
        //if the list is empty, i.e. the head==null, we make temp as the head of the list. 
        if (head == NULL)
        {
            head = temp;
        }
        else
        {//else, we traverse till the end of the list and attach the temp at last. we also update the prev pointer of the temp.
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout<<"\n\n\t\tPRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : ";
        cin>>flag;
    }while(flag == 1);
}

void marks::display()
{//To display, we simply traverse the list while displaying the details of every node.
    node *ptr;
    ptr = head;
    
    cout<<"\n\n\t\tRoll no.\t\t\tMarks\n";
    while (ptr != NULL)
    {
        cout<<"\t\t"<<ptr->roll_no<<"\t\t\t\t"<<ptr->marks <<endl;
        ptr = ptr->next;
    }
}

//Sorting the list in descending order of marks.
void marks::sort()
{
    node *q,*p,*ptr1,*ptr2,*temp;
    p=head;
    while(p->next!=NULL)
    {
        q=head;
        while(q->next!=NULL)
        {
            if(q->marks<q->next->marks)
            {
                ptr1=q;
                ptr2=q->next;
                temp=ptr2->next;
                if(ptr1->prev!=NULL)
                {
                    ptr1->prev->next=ptr2;
                }
                else
                {
                    head=ptr2;
                }
                ptr2->next=ptr1;
                ptr2->prev=ptr1->prev;
                ptr1->next=temp;
                ptr1->prev=ptr2;
                if(temp!=NULL)
                {
                    temp->prev=ptr1;
                }
                q=ptr2;
            }
            q=q->next;
        }
        p=p->next; 
    }
}

//merging two linked list sent as parameters.
void marks::merge(marks CS,marks IT)
{
    node *p = CS.head;
    node *q = IT.head;
    node *r = NULL;
    if(head==q)
	{
        head = p;
    }
    if(head==p)
	
	{
        head = q;
    }
    if(p!=NULL && q!=NULL)
	{
        if(p->marks<q->marks)
		{
            r=p;
            p=p->next;
        }
		else
		{
            r = q;
            q = q->next;
        }
        head = r;
    }
    while(p!=NULL && q!=NULL)
	{
        if(p->marks>=q->marks)
		{
            r->next = p;
            p->prev = r;
            r = p;
            p = p->next;
        }
		else
		{
            r->next = q;
            q->prev = r;
            r = q;
            q = q->next;
        }
    }
    if(p==NULL)
	{
        r->next = q;
        q->prev = r;
    }
    if(q==NULL)
	{
        r->next = p;
        p->prev = r;
    }
}

void marks::qualified()
{
	cout<<"THE FOLLOWING TOP 5 STUDENTS FROM CS/IT ARE QUALIFIED FOR ROUND 2 OF TECHNICAL SKILL EXAMINATION : ";
	node *ptr;
    ptr = head;
    
    cout<<"\n\n\t\tRoll no.\t\t\tMarks\n";
    int i = 0;
    while (i!=5)
    {
        cout<<"\t\t"<<ptr->roll_no<<"\t\t\t\t"<<ptr->marks <<endl;
        ptr = ptr->next;
        i++;
    }
	
}


int main()
{
    marks CS,IT,ALL;
    int tag;
    int choice;
    cout<<"\n************************************WELCOME TO RECRUITMENT CELL******************************************" << endl;
    cout<<"\n*************************TECHNICAL SKILLS MARKSHEET USING DOUBLY LINKED LIST*****************************" << endl;

    do
    {
        cout<<"\n\n\t\tPress 1 to Create List of CS students who gave the technical skills exam"<<endl;
        cout<<"\t\tPress 2 to Create List of IT students who gave the technical skills exam"<<endl;
        cout<<"\t\tPress 3 to Display the list of CS students"<<endl;
        cout<<"\t\tPress 4 to Display the list of IT students"<<endl;
        cout<<"\t\tPress 5 to Sort the list of CS students based on their marks"<<endl;
        cout<<"\t\tPress 6 to Sort the list of IT students based on their marks"<<endl;
        cout<<"\t\tPress 7 to Merge both the student lists in order of their marks"<<endl;
        cout<<"\t\tPress 8 to generate the list of CS/IT students selected for round 2";
		  
        cout<<"\n\nEnter your Choice : ";
        cin>>choice;
        switch (choice)
        {
        	case 1:
        	    CS.create();
        	    break;
        	case 2:
        	    IT.create();
        	    break;
        	case 3:
        		cout<<"\nSTUDENT'S DATA COLLECTED SO FAR : "<<endl;
        	    CS.display();
        	    break;
        	case 4:
        	    cout<<"\nSTUDENT'S DATA COLLECTED SO FAR : "<<endl;
        	    IT.display();
        	    break;
        	case 5:
        	    CS.sort();
       		    CS.display();
            	break;
            case 6:
            	IT.sort();
           	    IT.display();
        		break;
			case 7:
            	ALL.merge(CS,IT);
            	ALL.display();
            	break;  
				
			case 8:
				ALL.qualified();
				break;
				
        	default:
            	cout << " Invalid Choice !!! " << endl;
            	break;
        }
        cout<<"\n\n\t\tEnter -1 To Exit the system : ";
        cin>>tag;
    }while (tag != -1);
    
    
    return 0;
}



/*

OUTPUT:

************************************WELCOME TO RECRUITMENT CELL******************************************
*************************TECHNICAL SKILLS MARKSHEET USING DOUBLY LINKED LIST*****************************


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 1


Enter Student's roll number : 101
Enter Student's marks out of 10 : 7


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 102
Enter Student's marks out of 10 : 9


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 103
Enter Student's marks out of 10 : 10


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 104
Enter Student's marks out of 10 : 6


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 105
Enter Student's marks out of 10 : 8


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 106
Enter Student's marks out of 10 : 8


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 107
Enter Student's marks out of 10 : 10


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 108
Enter Student's marks out of 10 : 7


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 109
Enter Student's marks out of 10 : 5


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 110
Enter Student's marks out of 10 : 7


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 0


                Enter -1 To Exit the system : 1


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 2


Enter Student's roll number : 401
Enter Student's marks out of 10 : 8


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 402
Enter Student's marks out of 10 : 4


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 403
Enter Student's marks out of 10 : 6


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 404
Enter Student's marks out of 10 : 2


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 405
Enter Student's marks out of 10 : 9


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 406
Enter Student's marks out of 10 : 10


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 407
Enter Student's marks out of 10 : 9


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 408
Enter Student's marks out of 10 : 6


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 409
Enter Student's marks out of 10 : 10


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 1


Enter Student's roll number : 410
Enter Student's marks out of 10 : 9


                PRESS 1 TO ENTER DETAILS OF ONE MORE STUDENT : 0


                Enter -1 To Exit the system : 1


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 3

STUDENT'S DATA COLLECTED SO FAR :


                Roll no.                        Marks
                101                             7
                102                             9
                103                             10
                104                             6
                105                             8
                106                             8
                107                             10
                108                             7
                109                             5
                110                             7


                Enter -1 To Exit the system : 1


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 4

STUDENT'S DATA COLLECTED SO FAR :


                Roll no.                        Marks
                401                             8
                402                             4
                403                             6
                404                             2
                405                             9
                406                             10
                407                             9
                408                             6
                409                             10
                410                             9


                Enter -1 To Exit the system : 1


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 5


                Roll no.                        Marks
                103                             10
                107                             10
                102                             9
                105                             8
                106                             8
                101                             7
                108                             7
                110                             7
                104                             6
                109                             5


                Enter -1 To Exit the system : 1


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 6


                Roll no.                        Marks
                406                             10
                409                             10
                405                             9
                407                             9
                410                             9
                401                             8
                403                             6
                408                             6
                402                             4
                404                             2


                Enter -1 To Exit the system : 1


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 7


                Roll no.                        Marks
                406                             10
                103                             10
                107                             10
                409                             10
                102                             9
                405                             9
                407                             9
                410                             9
                105                             8
                106                             8
                401                             8
                101                             7
                108                             7
                110                             7
                104                             6
                403                             6
                408                             6
                109                             5
                402                             4
                404                             2


                Enter -1 To Exit the system : 1


                Press 1 to Create List of CS students who gave the technical skills exam
                Press 2 to Create List of IT students who gave the technical skills exam
                Press 3 to Display the list of CS students
                Press 4 to Display the list of IT students
                Press 5 to Sort the list of CS students based on their marks
                Press 6 to Sort the list of IT students based on their marks
                Press 7 to Merge both the student lists in order of their marks
                Press 8 to generate the list of CS/IT students selected for round 2

Enter your Choice : 8
THE FOLLOWING TOP 5 STUDENTS FROM CS/IT ARE QUALIFIED FOR ROUND 2 OF TECHNICAL SKILL EXAMINATION :

                Roll no.                        Marks
                406                             10
                103                             10
                107                             10
                409                             10
                102                             9


                Enter -1 To Exit the system : -1

--------------------------------
Process exited after 126.7 seconds with return value 0
Press any key to continue . . .

*/


