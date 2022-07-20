/*
NAME : NEHAAL PANDEY
PRN : 0120200245
BATCH : A(A3)
ROLL : 63
PROBLEM STATEMENT 8 : Design and implement a menu driven program for linear and circular queue for Train arrival recoerd using array and linked list.
*/


#include<iostream>
#define max 3

using namespace std;

//class Train for public declaration of two variables.
class Train
{
    public:
    	int train_no;
		string train_name;
};

//class for implementing linear array queue.
class Linear_Array_Queue
{
	//instantiating class as arrayof object.
	Train T[max];
	int rear,front;

	public:
		Linear_Array_Queue()  //default constructor for initialising front=rear=-1
		{
			front = -1;
			rear = -1;
		}

//function to check if the queue is empty.
bool isempty()
{
	if(front==-1) //empty condition
	{
		return true;
	}
	else
	{
		return false;
	}
}

//function to check if the queue is full.
bool isfull()
{
	if(rear==(max-1))  //full condition
	{
		return true;
	}
	else
	{
		return false;
	}
}


//function to enter data into the queue. (enqueue)
void enqueue()

{
	//if the rear pointer is at the last element, we cannot add data in the queue even if there is space empty in the initial boxes.
	if(isfull())
	{
    	cout<<"\n\n\tPlease wait for all the scheduled trains to arrive and then update the record.!!"<<endl;
	}	
	else //else, we can enter data into queue by incrementing rear and storing data in rear.
	{
		rear++;
		cout<<"\n\nEnter the Train number and Train name of the next arriving train at the CSMT station : \n";
        cin>>T[rear].train_no>>T[rear].train_name;
		if(front==-1)
		{
			front++;
		}
	}
}

void dequeue()
{
	//we cannot delete an element if the queue is empty.
	if(isempty())
	{
	    cout<<"\n\nNo Train arrivals scheduled for this station!!"<<endl;
	}
	else
	{
		//in linear queue, we simply delete the first data by incrementing front counter and making it point on the second data.
		cout<<"\nThe train with the following details has arrived on the platform.\n\n";
        cout<<"Train No. : "<<T[front].train_no<<"\t\t Train Name : "<<T[front].train_name<<endl;
		if(front==rear)  //single entry queue condition
		{
			front=-1;
			rear=-1;
		}	
		else
		{
			front++;
		}
	}
}

void display()
{
	//to display, we simply traverse from front pointer to rear pointer and keep on printing the data. checking if the queue is empty is mandatory.
	if(isempty())
	{
    	cout<<"\n\nNo Train arrivals!!"<<endl;
	}
	else
	{
		for(int i=front; i<=rear; i++)
		{
			cout<<"train No. "<<T[i].train_no<<"\t\ttrain Name "<<T[i].train_name<<endl;

		}
	}
}
};

//class implementation for circular array queue.
class Circular_Array_Queue
{
	//public declaration for instantiating class as array of objects and ddeclaring two pointers, front and rear.
    public:
    	Train t[5];
    	int a_front,a_rear;
	
	    Circular_Array_Queue() //default constructor for initialising front and rear pointers at -1
	    {
	        a_front=-1;
	        a_rear=-1;
	    }
	    
		//methods declared for outside the class defination
	    bool isEmpty();
	 	bool isFull();
 	   	void ca_enqueue();
 	  	void ca_dequeue();
 	   	void display();
};
//scope resolution for extending class properties to methods
bool Circular_Array_Queue::isEmpty() //checking if the circular queue is empty.
{
    if(a_front==-1 && a_rear==-1) //circular queue empty condition
    {
        return true;
    }
    return false;
}

//checking if the circular queue is full.
bool Circular_Array_Queue:: isFull()
{
    if(a_front==(a_rear+1)%max)//(a_front==0 && a_rear==max-1)||a_front==a_rear+1 //circular queue full condition
    {
        return true;
    }
    return false;
}

//function to add element in the circular queue.
void Circular_Array_Queue::ca_enqueue() 
{
    if(!isFull())
    {
        if(isEmpty())
        {
            a_front=0;//a_front++ i.e -1+1=0
        }
        a_rear=(a_rear+1)%max;
        cout<<"\n\nEnter the Train number and Train name of the next arriving train at the CSMT station : \n";
        cin>>t[a_rear].train_no>>t[a_rear].train_name;
        return;
    }
    cout<<"\n\n\tNo empty platform for other train arrivals!!"<<endl;
}

//function to delete an element in the circular queue
void Circular_Array_Queue::ca_dequeue()
{

    if(!isEmpty())
    {
    	cout<<"\nThe train with the following details has arrived on the platform.\n\n";
        cout<<"Train No. : "<<t[a_front].train_no<<"\t\t Train Name : "<<t[a_front].train_name<<endl;
        if(a_front==a_rear)
        {
            a_front=-1;
            a_rear=-1;
        }
        else
        {
            a_front=(a_front+1)%max;   
        }
        return;
    }
    cout<<"\n\nNo Train arrivals scheduled for this station!!"<<endl;
}

//function to display the elements fromthe circular queue.
void Circular_Array_Queue::display()
{
    int i;
    if(!isEmpty())
    {
        if(a_front<=a_rear)
        {
            for(i=a_front;i<=a_rear;i++)
            {
                cout<<"train No. "<<t[i].train_no<<"\t\ttrain Name "<<t[i].train_name<<endl;
            }
        }
        else
        {
            for(i=a_front;i<max;i++)
            {
                cout<<"train No. "<<t[i].train_no<<"\t\ttrain Name "<<t[i].train_name<<endl;
            }
            for(i=0;i<=a_rear;i++)
            {
                cout<<"train No. "<<t[i].train_no <<"\t\ttrain Name "<<t[i].train_name<<endl;
            }
        }
        return;
    }
    cout<<"\n\nNo Train arrivals!!"<<endl;
    
}

//class node for linked list implementation
class node
{
    public:
    	int train_no;
		string Name;
    	node *next;
    	node()
    	{
    	    next=NULL;
    	}
};

class Linear_LL_Queue
{
	node *front,*rear;
	public:
		Linear_LL_Queue()
		{
			front=NULL;
			rear=NULL;
		}
	
	bool isempty()
	{
		if(front==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void enqueue()
	{
		node *temp;
		temp= new node;
		cout<<"\nEnter the Train number and Train name of the next arriving train at the CSMT station : \n";
 	    cin>>temp -> train_no>>temp -> Name;	
		temp->next=NULL;
	
		if(isempty())
		{
			front=temp;
			rear= temp;
		}
		else
		{
			rear->next=temp;
			rear=rear->next;
		}
	}


	void dequeue()
	{
		if(isempty())
		{
		    cout<<"\n\nNo Train arrivals !!"<<endl;
		}	
		else	
		{
			cout<<"\nThe train with the following details has arrived on the platform.\n\n";
			cout<<"train No. : "<<front -> train_no<<"\t\ttrain Name : "<<front -> Name<<endl;
			node *t= front;
			if(front==rear)
			{
				front=NULL;
				rear=NULL;
			}
			else
			{
				front=front->next;
				delete t;
			}
		}
	}

	void display()
	{
		if(isempty())
		{
 		   	cout<<"\n\nNo Train arrivals scheduled for this Station!!"<<endl;	
		}
		else
		{
			node *t;
			t=front;
			while(t!=NULL)
			{
				cout<<"Train No. "<<t -> train_no<<"\tTrain Name "<<t -> Name<<endl;   
				t=t->next;
			}
		}
	}
};

class Circular_LL_Queue
{
    public:

    node *front,*rear;
    Circular_LL_Queue()
    {
        front=NULL;
        rear=front;
    }

    bool isEmpty();
    void cll_enqueue();
    void cll_dequeue();
    void Display();
};

bool Circular_LL_Queue::isEmpty()
{
    if(front==NULL && rear==NULL)
    {
        return true;
    }
    return false;
}

void Circular_LL_Queue::cll_enqueue()
{
    node *temp;
    temp=new node;
    cout<<"\nEnter the Train number and Train name of the next arriving train at the CSMT station : \n";
    cin>>temp -> train_no>>temp -> Name;
    temp->next=temp;
    if(isEmpty())
    {
        front=temp;
        rear=front;
        temp -> next = front;
    }
    else
    {
        rear -> next = temp;
        temp -> next = front;
        rear = rear -> next;
    }
}

void Circular_LL_Queue::cll_dequeue()
{
    if(!isEmpty())
    {
        node *temp;
        temp=front;
        cout<<"\nThe train with the following details has arrived on the platform.\n\n";
        cout<<"\ntrain No. : "<<front -> train_no<<"\t\ttrain Name : "<<front -> Name<<endl;
        if(front==rear)
        {
            front=NULL;
            rear=front;
            return;
        }
        front=front -> next;
        rear -> next=front;
        delete temp;
        return;
    }
    
    cout<<"\n\nNo Train arrivals !!"<<endl;

}

void Circular_LL_Queue::Display()
{
    if(!isEmpty())
    {
        node *p;
        p=front;
        do
        {
            cout<<"Train No. "<<p -> train_no<<" Name "<<p -> Name<<endl;   
            p=p -> next;
        }while(p!=front);
        return;
    }
    cout<<"\n\nNo Train arrivals scheduled for this Station!!"<<endl;
}


int main()
{
    Circular_Array_Queue p1;
    Circular_LL_Queue p2;
    Linear_Array_Queue p3;
    Linear_LL_Queue p4;
    int temp1,temp2,temp3,temp4;
    int choice,ch1,ch2,ch3,ch4,again=0;
    
	cout<<"***********************************************TRAIN ARRIVAL RECORD****************************************************";
    do
    {
        cout<<"\n\n\t\t\t\tPRESS 1 TO USE CIRCULAR QUEUE USING ARRAY"<<endl;
		cout<<"\t\t\t\tPRESS 2 TO USE CIRCULAR QUEUE USING LINKED LIST"<<endl;
        cout<<"\t\t\t\tPRESS 3 TO USE LINEAR QUEUE USING ARRAY"<<endl;
		cout<<"\t\t\t\tPRESS 4 TO USE LINEAR QUEUE USING LINKED LIST\n"<<endl;
        cout<<"Enter your choice of data structure to keep the record of the train arrivals : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            	do
            	{
				   cout<<"\n\n\t\t\tPress 1 to record train arrivals"<<endl;
				   cout<<"\t\t\tPress 2 to record departure of the scheduled train arrivals"<<endl;
				   cout<<"\t\t\tPress 3 to display the record"<<endl;
                   cout<<"Enter your choice for operations : ";
                   cin>>ch1;

                   switch(ch1)
                   {
                       case 1:
                            p1.ca_enqueue();
                            break;
                       
                       case 2:
                            p1.ca_dequeue();
                        	break;

                       case 3:
							p1.display();
							break;

                        default:
							cout<<"\nPlease enter valid choice!!"<<endl;
                            break;
                            
                   }
                   cout<<"\n\nPRESS 1 TO PLAY WITH THE LIST : ";
                   cin>>temp1;
				}while(temp1==1);
                   break;

            case 2:
				do
				{
				   	cout<<"\n\n\t\t\tPress 1 to record train arrivals"<<endl;
				   	cout<<"\t\t\tPress 2 to record departure of the scheduled train arrivals"<<endl;
				   	cout<<"\t\t\tPress 3 to display the record"<<endl;
                   	cout<<"Enter your choice for operations : ";                   
                   	cin>>ch2;

                   	switch(ch2)
                   	{
                    	case 1:
                            p2.cll_enqueue();
                            break;
                       
                       	case 2:
                        	p2.cll_dequeue();
                        	break;

                       	case 3:
                            p2.Display();
                            break;

                        default:
						cout<<"\nPlease enter valid choice!!"<<endl;
                   	    break;
                   }
                   cout<<"Press 1 to play with the record : ";
                   cin>>temp2;
				}while(temp2==1);
            
			case 3:
				do
				{
				   	cout<<"\n\n\t\t\tPress 1 to record train arrivals"<<endl;
				   	cout<<"\t\t\tPress 2 to record departure of the scheduled train arrivals"<<endl;
				   	cout<<"\t\t\tPress 3 to display the record"<<endl;
                   	cout<<"Enter your choice for operations : ";                   
                   	cin>>ch3;

                   	switch(ch3)
                   	{
                    	case 1:
                            p3.enqueue();
                            break;
                       
                       	case 2:
                        	p3.dequeue();
                        	break;

                       	case 3:
                            p3.display();
                            break;

                        default:
						cout<<"\nPlease enter valid choice!!"<<endl;
                   	    break;
                   }
                   cout<<"Press 1 to play with the record : ";
                   cin>>temp3;
				}while(temp3==1);
            
            case 4:
				do
				{
				   	cout<<"\n\n\t\t\tPress 1 to record train arrivals"<<endl;
				   	cout<<"\t\t\tPress 2 to record departure of the scheduled train arrivals"<<endl;
				   	cout<<"\t\t\tPress 3 to display the record"<<endl;
                   	cout<<"Enter your choice for operations : ";                   
                   	cin>>ch4;

                   	switch(ch4)
                   	{
                    	case 1:
                            p4.enqueue();
                            break;
                       
                       	case 2:
                        	p4.dequeue();
                        	break;

                       	case 3:
                            p4.display();
                            break;

                        default:
						cout<<"Please enter valid choice!!"<<endl;
                   	    break;
                   }
                   cout<<"Press 1 to play with the record : ";
                   cin>>temp4;
				}while(temp4==1);
            
				
			default:
				cout<<"\nPlease enter valid choice!!"<<endl;
                break;
        }
        cout<<"Enter 1 to try with different format of queue : ";
        cin>>again;
    }while(again==1);

    return 0;
}


/*
OUTPUT : (ONLY FOR 1 COMPLETE IMPLEMENTATIOIN.)

***********************************************TRAIN ARRIVAL RECORD****************************************************

                                PRESS 1 TO USE CIRCULAR QUEUE USING ARRAY
                                PRESS 2 TO USE CIRCULAR QUEUE USING LINKED LIST
                                PRESS 3 TO USE LINEAR QUEUE USING ARRAY
                                PRESS 4 TO USE LINEAR QUEUE USING LINKED LIST

Enter your choice of data structure to keep the record of the train arrivals : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 1


Enter the Train number and Train name of the next arriving train at the CSMT station :
11071
kamayaniexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 1


Enter the Train number and Train name of the next arriving train at the CSMT station :
22221
rajdhaniexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 1


Enter the Train number and Train name of the next arriving train at the CSMT station :
12068
lttbsbexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 3
train No. 11071         train Name kamayaniexp
train No. 22221         train Name rajdhaniexp
train No. 12068         train Name lttbsbexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 1


        No empty platform for other train arrivals!!


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 2

The train with the following details has arrived on the platform.

Train No. : 11071                Train Name : kamayaniexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 1


Enter the Train number and Train name of the next arriving train at the CSMT station :
12063
chennaiexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 3
train No. 22221         train Name rajdhaniexp
train No. 12068         train Name lttbsbexp
train No. 12063         train Name chennaiexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 2

The train with the following details has arrived on the platform.

Train No. : 22221                Train Name : rajdhaniexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 2

The train with the following details has arrived on the platform.

Train No. : 12068                Train Name : lttbsbexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 2

The train with the following details has arrived on the platform.

Train No. : 12063                Train Name : chennaiexp


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 3


No Train arrivals!!


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 2


No Train arrivals scheduled for this station!!


PRESS 1 TO PLAY WITH THE LIST : 1


                        Press 1 to record train arrivals
                        Press 2 to record departure of the scheduled train arrivals
                        Press 3 to display the record
Enter your choice for operations : 3


No Train arrivals!!


PRESS 1 TO PLAY WITH THE LIST : 0
Enter 1 to try with different format of queue : 0

--------------------------------
Process exited after 76.79 seconds with return value 0
Press any key to continue . . .
*/

//THANK YOU.
