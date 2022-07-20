/*
Name: NEHAAL PANDEY
Div: A(A3)
Roll No: 63
PRN no: 0120200245
PROBLEM STATEMENT 1 : Design and implement a program to read, display, insert, update and delete operations on data objects for customer information supply chain 
management system using array (TICKET BOOKING SYSTEM FOR A TRAIN)
*/

#include <iostream>
using namespace std;

//Creating a Class customer
class passenger
{
	//customer class with public variables(Attributes)
	public:
		int pnr_no;
		string passenger_name;
		string booking_status;
		int passenger_age;
		char passenger_gender;
	
		//Methods Declared
		void booking_stat();
		void ticket_details();
};

//
void passenger::booking_stat()
{
	cout<<"\n********BHARATIYA RAILWAYS**********";
	cout<<"\nEnter the PNR number : ";
	cin>>pnr_no;
	cout<<"Enter The Name, gender and age of the passenger : ";
	cin>>passenger_name>>passenger_gender>>passenger_age;
	cout<<"Ticket status : ";
	cin>>booking_status;
}

void passenger::ticket_details()
{
	
	cout<<"\n*******Passenger details********\n";
	cout<<"PNR No: "<<pnr_no<<"\t Passenger Name:"<<passenger_name;
	cout<<"\n Age : "<<passenger_age<<"\tGender : "<<passenger_gender;
	cout<<"\tBooking Status : "<<booking_status;
}


int main()
{
	//Declaring variables and object array
	int i,n,pos,flag=0,choice,loop=0;
	//Instantiating the object array of passenger class
	passenger p[25];
	string delid;
	cout<<"\n***********************TRAIN NO. 11071 KAMAYANI EXPRESS****************************\n";
	//Infinite loop for multiple selection 
	while(loop==0)
	{
		//Menu Driven Program
		cout<<"\n\nPRESS 1 TO ENTER THE PASSENGER DETAILS";
		cout<<"\nPRESS 2 TO CANCEL A TICKET";
		cout<<"\nPRESS 3 TO UPGRADE A TICKET";
		cout<<"\nPRESS 4 TO DISPLAY THE PASSENGER DETAILS";
		cout<<"\nPRESS 5 TO ADD A NEW BOOKING TO THE DATABASE";
		cout<<"\nPRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER";
		cout<<"\nPRESS 7 TO EXIT";
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>choice;
		//Switch Case
		switch(choice)
		{
			case 1:
				//Taking the details of passengers
				cout<<"\nEnter the no. of passengers travelling in SL coach : ";
				cin>>n;
		
				for(i=0;i<n;i++)
				{
					//Calling the method of passenger class
					p[i].booking_stat();	
				}
				break;
			
			case 2:
				//Deleting the Entry of the passenger
				cout<<"\nEnter the passenger name who wants to cancel his ticket : ";
				cin>>delid;
			
				for(i=0;i<n;i++)
				{
					if(p[i].passenger_name==delid)
					{
						flag=1;
						break;
					}		
				}
			
				if(flag==1)
				{	
					for(int j=i;j<n-1;j++)
					{
						//Array is static so need to shift the objects
						p[j]=p[j+1];
					}
					
					cout<<"\nTicket cancelled. \n\n";
					n--;
				}
				else
				{
					cout<<"Not Found";
				}
				break;
		
			case 3:
				//Updating the Entry of the passenger
				cout<<"\nEnter the Passenger Name whose ticket you want to Update : ";
				cin>>delid;
				for(i=0;i<n;i++)
				{
					if(p[i].passenger_name==delid)
					{
						flag=1;
						p[i].booking_stat();
					}
				}
				if(flag==1)
				{
					cout<<"Updated the passenger's ticket!\n";
				}
				else
				{
					cout<<"Not Found\n";	
				}
				break;
					
			case 4:
				//Displaying the details of passengers
				for(i=0;i<n;i++)
				{
					cout<<"\n\n\nPassenger No : "<<i+1;
					p[i].ticket_details();
				}	
				break;
			
			case 5:
				//Insertion of new object in array
				//Incrementing n(Number of objects) for new entry
				n++;
				cout<<"\nEnter the index after which you want to place this ticket : ";
				cin>>pos;
				for(i=n;i>=pos;i--)
				{
					//Array is static so need to shift the objects
					p[i]=p[i-1];
				}
				
				p[pos-1].booking_stat();
				cout<<"\n";
				break;
			
			
		
			case 6:
				//Searching the passenger using binary Search
				cout<<"\nPassenger Name to Search For : \n";
				cin>>delid;
				for(i=0;i<n;i++)
				{
					if(p[i].passenger_name==delid)
					{
						p[i].ticket_details();
					}
				}
				break;
				
			case 7:
			
				cout<<"\nThank You\n";
				loop=1;
				break;
		
		}
	}
}


/*
OUTPUT : 


***********************TRAIN NO. 11071 KAMAYANI EXPRESS****************************


PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 1

Enter the no. of passengers travelling in SL coach : 5

********BHARATIYA RAILWAYS**********
Enter the PNR number : 12345
Enter The Name, gender and age of the passenger : NEHAAL M 19
Ticket status : CNF//S1/9

********BHARATIYA RAILWAYS**********
Enter the PNR number : 12345
Enter The Name, gender and age of the passenger : FAHMEEN F 18
Ticket status : CNF//S1//10

********BHARATIYA RAILWAYS**********
Enter the PNR number : 67890
Enter The Name, gender and age of the passenger : VEERAJ M 19
Ticket status : WL1

********BHARATIYA RAILWAYS**********
Enter the PNR number : 67890
Enter The Name, gender and age of the passenger : ADITYA M 19
Ticket status : WL2

********BHARATIYA RAILWAYS**********
Enter the PNR number : 67890
Enter The Name, gender and age of the passenger : SHRUTI F 18
Ticket status : WL3


PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 4



Passenger No : 1
*******Passenger details********
PNR No: 12345    Passenger Name:NEHAAL
 Age : 19       Gender : M      Booking Status : CNF//S1/9


Passenger No : 2
*******Passenger details********
PNR No: 12345    Passenger Name:FAHMEEN
 Age : 18       Gender : F      Booking Status : CNF//S1//10


Passenger No : 3
*******Passenger details********
PNR No: 67890    Passenger Name:VEERAJ
 Age : 19       Gender : M      Booking Status : WL1


Passenger No : 4
*******Passenger details********
PNR No: 67890    Passenger Name:ADITYA
 Age : 19       Gender : M      Booking Status : WL2


Passenger No : 5
*******Passenger details********
PNR No: 67890    Passenger Name:SHRUTI
 Age : 18       Gender : F      Booking Status : WL3

PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 2

Enter the passenger name who wants to cancel his ticket : FAHMEEN

Ticket cancelled.



PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 2

Enter the passenger name who wants to cancel his ticket : SHRUTI

Ticket cancelled.



PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 3

Enter the Passenger Name whose ticket you want to Update : VEERAJ

********BHARATIYA RAILWAYS**********
Enter the PNR number : 67890
Enter The Name, gender and age of the passenger : VEERAJ F 19
Ticket status : CNF//S1/10
Updated the passenger's ticket!


PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 5

Enter the index after which you want to place this ticket : 4

********BHARATIYA RAILWAYS**********
Enter the PNR number : 45678
Enter The Name, gender and age of the passenger : RITWIK M 18
Ticket status : WL1



PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 6

Passenger Name to Search For :
ADITYA

*******Passenger details********
PNR No: 67890    Passenger Name:ADITYA
 Age : 19       Gender : M      Booking Status : WL2

PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 4



Passenger No : 1
*******Passenger details********
PNR No: 12345    Passenger Name:NEHAAL
 Age : 19       Gender : M      Booking Status : CNF//S1/9


Passenger No : 2
*******Passenger details********
PNR No: 67890    Passenger Name:VEERAJ
 Age : 19       Gender : F      Booking Status : CNF//S1/10


Passenger No : 3
*******Passenger details********
PNR No: 67890    Passenger Name:ADITYA
 Age : 19       Gender : M      Booking Status : WL2


Passenger No : 4
*******Passenger details********
PNR No: 45678    Passenger Name:RITWIK
 Age : 18       Gender : M      Booking Status : WL1

PRESS 1 TO ENTER THE PASSENGER DETAILS
PRESS 2 TO CANCEL A TICKET
PRESS 3 TO UPGRADE A TICKET
PRESS 4 TO DISPLAY THE PASSENGER DETAILS
PRESS 5 TO ADD A NEW BOOKING TO THE DATABASE
PRESS 6 TO SEARCH THE TICKET DETAILS OF A PASSENGER
PRESS 7 TO EXIT
ENTER YOUR CHOICE : 7

Thank You

--------------------------------
Process exited after 301 seconds with return value 0
Press any key to continue . . .
*/
