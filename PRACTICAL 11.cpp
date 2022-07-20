//NAME : Nehaal Pandey
//roll : 63
//Batch : A3
//Problem Statement : Design and implement a menu driven program for implementing Fibonacci, binary and sentinel searching for 
// 					  student's SGPA of previous semester.


#include <iostream>
using namespace std;


class student
{
	public:
	string name;
	int roll;
	float sgpa;
	
	void display()
	{
		cout<<"Student name : "<<name<<endl;
		cout<<"Student Roll No : "<<roll<<endl;
		cout<<"Student SGPA : "<<sgpa<<endl;
	}
};
	
class search
{
	public:
	student data[25];
	int n;
	void getdata();
	void display();
	int binary(float key);
	int sentinel(string key);
	int fib(int key);
	void sort_sgpa();
	void sort_roll();	
};
	
void search :: getdata()
{
	cout<<"\n\nENTER THE NUMBER OF STUDENTS IN YOUR BATCH : ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"\n\t\tENTER THE NAME OF THE STUDENT : ";
		cin>>data[i].name;
		cout<<"\t\tENTER THE ROLL NUMBER OF THE STUDENT : ";
		cin>>data[i].roll;
		cout<<"\t\tENTER THE SGPA OF THE PERVIOUS SEMESTER OF THE STUDENT : ";
		cin>>data[i].sgpa;
	}
}	
	
void search :: display()
{
	cout<<"NAME \t\tROLL NO.\tSGPA\n";
	for(int i=0; i<n; i++)
	{
		
		cout<<data[i].name<<"\t\t"<<data[i].roll<<"\t\t"<<data[i].sgpa<<endl;
	}
}

void search :: sort_sgpa()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(data[i].sgpa < data[j].sgpa)
			{
				student temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}
}
	
void search :: sort_roll()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(data[i].roll < data[j].roll)
			{
				student temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}
}

int search :: binary(float key)
{
	int l=0;
	int h=n-1;
	int m;
	while(l<=h)
	{
		m= l + (h-l)/2;
		if(data[m].sgpa==key)
		{
			return m;
		}
		else
		{
			if(data[m].sgpa<key)
			{
				l=m+1;
			}
			else
			{
				h=m-1;
			}
		}
	}
	return -1;
}
	
int search :: sentinel(string key)
{
	string last = data[n-1].name;
	data[n-1].name=key;
	int i=0;
	while(data[i].name!=key)
	{
		i++;
	}
	data[n-1].name=last;
	if(i<(n-1) || key==data[n-1].name)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
	
int search :: fib(int key)
{
	int offset=-1;
	int p2=0;
	int p1=1;
	int curr= p2+p1;
	while(curr<n)
	{
		p2=p1;
		p1=curr;
		curr=p2+p1;
	}
	
	int i=0;
	while(curr>1)
	{
		i=min(offset+p2,n-1);
		if(data[i].roll<key)
		{
			curr=p1;
			p1=p2;
			p2=curr-p1;
			offset=i;
		}	
		else if(data[i].roll>key)
		{
			curr=p2;
			p1=p1-p2;
			p2=curr-p1;
		}
		else
		{
			return i;
		}	
	}
	if(p1 && data[offset+1].roll==key)
	{
		return offset+1;
	}
	else
	{
		return -1;
	}
}
	
int main()
{
	cout<<"****************************SEARCH OPERATIONS**********************************";
	search a;
	int choice,index,exit_loop=1,switchcase_end=0;
	float sgpa_key;
	int roll_key;
	string name_key;
	
	cout<<"\n\n<<<<<STUDENT DATA ENTRY>>>>>\n";
	a.getdata();
	cout<<"\n\n<<<<<DATA ENTERED>>>>>\n";
	a.display();
	
	do
	{
		
		cout<<"\n\n<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>>>>>>"<<endl;
		cout<<"\t\t\tPRESS 1 TO SEARCH A STUDENT WITH HIS MARKS VIA BINARY SEARCH\n";
		cout<<"\t\t\tPRESS 2 TO SEARCH A STUDENT WITH HIS NAME VIA SENTINAL SEARCH\n";
		cout<<"\t\t\tPRESS 3 TO SEARCH A STUDENT WITH HIS ROLL NO. VIA FIBONACCI SEARCH\n";
		cout<<"\t\t\tPRESS 4 TO EXIT\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch (choice)
		{
			case 1:
				cout<<"\n\n<<<<<DATA SORTING BASED ON sgpa>>>>>\n";
				a.sort_sgpa();
				a.display();
				cout<<"\n\nENTER THE SGPA OF STUDENT YOU WANT TO SEARCH:"<<endl;
				cin>>sgpa_key;
				index=a.binary(sgpa_key);
				if(index==-1)
				{		
					cout<<"\nStudent Record Not found !!!"<<endl;
				}	
				else
				{
					a.data[index].display();
				}
				break;
		
			case 2:
				cout<<"\n\nENTER THE NAME OF STUDENT YOU WANT TO SEARCH:"<<endl;
				cin>>name_key;
				index=a.sentinel(name_key);
				if(index==-1)
				{
					cout<<"\nStudent Record Not found !!!"<<endl;
				}
				else
				{
					a.data[index].display();
				}
				break;
			
			case 3:
				cout<<"\n\n<<<<<DATA SORTING BASED ON ROLL NO.>>>>>\n";
				a.sort_roll();
				a.display();
				
				cout<<"\n\nENTER THE ROLL NO. OF STUDENT YOU WANT TO SEARCH:"<<endl;
				cin>>roll_key;
				index=a.fib(roll_key);
				if(index==-1)
				{
					cout<<"\nStudent Record Not found !!!"<<endl;
				}
				else
				{
					a.data[index].display();
				}
				break;
			
			case 4:
				switchcase_end = 1;
				cout<<"THANK YOU!";
				break;
				
			default:
				cout<<"Please enter a valid choice!!!";
				break;
		}
		
		if(switchcase_end==1)
		{
			break;
		}
		else
		{
			cout<<"PRESS 1 TO GO TO MAIN MENU : ";
			cin>>exit_loop;
		}
    }while(exit_loop==1);
}


/*

OUTPUT :
****************************SEARCH OPERATIONS**********************************

<<<<<STUDENT DATA ENTRY>>>>>


ENTER THE NUMBER OF STUDENTS IN YOUR BATCH : 5

                ENTER THE NAME OF THE STUDENT : veeraj
                ENTER THE ROLL NUMBER OF THE STUDENT : 65
                ENTER THE SGPA OF THE PERVIOUS SEMESTER OF THE STUDENT : 10

                ENTER THE NAME OF THE STUDENT : nehaal
                ENTER THE ROLL NUMBER OF THE STUDENT : 63
                ENTER THE SGPA OF THE PERVIOUS SEMESTER OF THE STUDENT : 9.57

                ENTER THE NAME OF THE STUDENT : fahmeen
                ENTER THE ROLL NUMBER OF THE STUDENT : 22
                ENTER THE SGPA OF THE PERVIOUS SEMESTER OF THE STUDENT : 9.71

                ENTER THE NAME OF THE STUDENT : jay
                ENTER THE ROLL NUMBER OF THE STUDENT : 45
                ENTER THE SGPA OF THE PERVIOUS SEMESTER OF THE STUDENT : 9.19

                ENTER THE NAME OF THE STUDENT : aditya
                ENTER THE ROLL NUMBER OF THE STUDENT : 124
                ENTER THE SGPA OF THE PERVIOUS SEMESTER OF THE STUDENT : 9.86


<<<<<DATA ENTERED>>>>>
NAME            ROLL NO.        SGPA
veeraj          65              10
nehaal          63              9.57
fahmeen         22              9.71
jay             45              9.19
aditya          124             9.86


<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>>>>>>
                        PRESS 1 TO SEARCH A STUDENT WITH HIS MARKS VIA BINARY SEARCH
                        PRESS 2 TO SEARCH A STUDENT WITH HIS NAME VIA SENTINAL SEARCH
                        PRESS 3 TO SEARCH A STUDENT WITH HIS ROLL NO. VIA FIBONACCI SEARCH
                        PRESS 4 TO EXIT
Enter your choice : 1


<<<<<DATA SORTING BASED ON sgpa>>>>>
NAME            ROLL NO.        SGPA
jay             45              9.19
nehaal          63              9.57
fahmeen         22              9.71
aditya          124             9.86
veeraj          65              10


ENTER THE SGPA OF STUDENT YOU WANT TO SEARCH:
9.19
Student name : jay
Student Roll No : 45
Student SGPA : 9.19
PRESS 1 TO GO TO MAIN MENU : 1


<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>>>>>>
                        PRESS 1 TO SEARCH A STUDENT WITH HIS MARKS VIA BINARY SEARCH
                        PRESS 2 TO SEARCH A STUDENT WITH HIS NAME VIA SENTINAL SEARCH
                        PRESS 3 TO SEARCH A STUDENT WITH HIS ROLL NO. VIA FIBONACCI SEARCH
                        PRESS 4 TO EXIT
Enter your choice : 2


ENTER THE NAME OF STUDENT YOU WANT TO SEARCH:
nehaal
Student name : nehaal
Student Roll No : 63
Student SGPA : 9.57
PRESS 1 TO GO TO MAIN MENU : 1


<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>>>>>>
                        PRESS 1 TO SEARCH A STUDENT WITH HIS MARKS VIA BINARY SEARCH
                        PRESS 2 TO SEARCH A STUDENT WITH HIS NAME VIA SENTINAL SEARCH
                        PRESS 3 TO SEARCH A STUDENT WITH HIS ROLL NO. VIA FIBONACCI SEARCH
                        PRESS 4 TO EXIT
Enter your choice : 3


<<<<<DATA SORTING BASED ON ROLL NO.>>>>>
NAME            ROLL NO.        SGPA
fahmeen         22              9.71
jay             45              9.19
nehaal          63              9.57
veeraj          65              10
aditya          124             9.86


ENTER THE ROLL NO. OF STUDENT YOU WANT TO SEARCH:
22
Student name : fahmeen
Student Roll No : 22
Student SGPA : 9.71
PRESS 1 TO GO TO MAIN MENU : 1


<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>>>>>>
                        PRESS 1 TO SEARCH A STUDENT WITH HIS MARKS VIA BINARY SEARCH
                        PRESS 2 TO SEARCH A STUDENT WITH HIS NAME VIA SENTINAL SEARCH
                        PRESS 3 TO SEARCH A STUDENT WITH HIS ROLL NO. VIA FIBONACCI SEARCH
                        PRESS 4 TO EXIT
Enter your choice : 4
"THANK YOU!"
--------------------------------
Process exited after 75.37 seconds with return value 0
Press any key to continue . . .
*/
