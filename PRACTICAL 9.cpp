//NAME : NEHAAL PANDEY
//ROLL : 63
//BATCH : A(A3)
//PROBLEM STATEMENT 9 : Design and implement a program for double ended queue and its operations for a shopping Mall.


#include <iostream>
using namespace std;
#define MAX 3
class shopping_mall
{
	public:
		string item;
		int price;
		int quantity;
		int cost;
		shopping_mall()
		{
			item = "";
			price = 0;
			quantity = 0;
		}
		void get_data();
		void show_data();
};


void shopping_mall :: get_data()
{
	cout<<"Enter the item name : ";
	cin>>item;
	cout<<"Enter the quantity : ";
	cin>>quantity;
	cout<<"Enter the price of 1 unit : RS. ";
	cin>>price;
	cost = quantity*price;
}

void shopping_mall :: show_data()
{
	cout<<item<<"\t\t\t"<<quantity<<"\t\t\tRS. "<<price<<"\t\t\t"<<cost<<"\n";
}

class deque
{
	public:
	shopping_mall data[MAX];
	int front, rear;
	deque()
	{
		front = -1;
		rear = -1;
	}

	int is_empty();
	int is_full();
	void insert_front();
	void insert_rear();
	void delete_front();
	void delete_rear();
	void get_front();
	void get_rear();
	void display_data();
	
};

int deque :: is_empty()
{
	if(front == -1 && rear == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int deque :: is_full()
{
	if((front == 0 && rear == (MAX-1)) || front == (rear+1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void deque :: insert_front()
{
	if(is_full())
	{
		cout<<"cart is full"<<endl;
	}
	else
	{
		shopping_mall m1;
		m1.get_data();
		if(is_empty())
		{
			front = 0;
			rear = 0;
		}
		else if(front == 0)
		{
			front = MAX-1;
		}
		else
		{
			front = front-1;
		}
		data[front] = m1;
	}
}

void deque :: insert_rear()
{
	if(is_full())
	{
		cout<<"cart is full"<<endl;
	}
	else
	{
		shopping_mall m2;
		m2.get_data();
		if(is_empty())
		{
			front = 0;
			rear = 0;
		}
		else if(rear == (MAX-1))
		{
			rear = 0;
		}
		else
		{
			rear = rear+1;
		}
		data[rear] = m2;
	}
}

void deque :: delete_front()
{
	if(is_empty())
	{
		cout<<"cart is empty"<<endl;
	}
	else
	{
		shopping_mall a = data[front];
		if(front == rear)

		{
			front = -1;
			rear = -1;
		}
		else if(front == (MAX-1))
		{
			front = 0;
		}
		else
		{
			front = front+1;
		}
		cout<<a.item<<" is deleted successfully"<<endl;
	}
}
	
void deque :: delete_rear()
{
	if(is_empty())
	{
		cout<<"cart is empty"<<endl;
	}
	else
	{
		shopping_mall a = data[rear];
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if(rear == 0)
		{
		rear = MAX-1;
		}
		else
		{
		rear = rear-1;
		}
		cout<<a.item<<" is deleted successfully"<<endl;
	}
}

void deque :: get_front()
{
	if(is_empty())
	{
		cout<<"cart is empty"<<endl;
	}
	else
	{
		data[front].show_data();
	}
}

void deque :: get_rear()
{
	if(is_empty())
	{	
		cout<<"cart is empty"<<endl;
	}
	else
	{
		data[rear].show_data();
	}	
}

void deque :: display_data()
{
	cout<<"ITEM NAME \t\tITEM QUANTITY \t\tITEM PRICE \t\tTOTAL COST\n";
	if(is_empty())
	{
		cout<<"cart is empty"<<endl;
	}
	else
	{
		if(front <= rear)
		{
			for(int i=front; i<=rear; i++)
			{
				data[i].show_data();
			}
		}
		else
		{
			for(int i=front; i<=MAX-1; i++)
			{
				data[i].show_data();
			}
			for(int i=0; i<=rear; i++)
			{
				data[i].show_data();
			}
		}
	}
}

int main()
{
	int temp=1;
	int choice;

	deque a1;
	shopping_mall s1;
	cout<<"*****************************************WELCOME TO MR SHOPPING COMPLEX*************************************"<<endl;
	cout<<"\n\nNOTE : ADD/DELETE ITEMS TO THE LIST FROM BOTH THE ENDS TO ENSURE 100% SCANNING OF ITEMS.";


	while(temp==1)
	{
		cout<<"\n\n\t\t\t\tPress 1 to Insert an item from front";
		cout<<"\n\t\t\t\tPress 2 to Insert an item from rear ";
		cout<<"\n\t\t\t\tPress 3 to delete the item at front";
		cout<<"\n\t\t\t\tPress 4 to delete the item at rear ";
		cout<<"\n\t\t\t\tPress 5 to get the first item in the cart";
		cout<<"\n\t\t\t\tPress 6 to get the last item in the cart";
		cout<<"\n\t\t\t\tPress 7 to Display the cart";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				a1.insert_front();
				break;
			case 2:
				a1.insert_rear();
				break;
			case 3:
				a1.delete_front();
				break;
			case 4:
				a1.delete_rear();
				break;
				
			case 5:
				cout<<"\n\n\t\tTHE FIRST ITEM IN THE CART IS : \n";
				a1.get_front();
				break;
			
			case 6:
				cout<<"\n\n\t\tTHE LAST ITEM IN THE CART IS : \n";
				a1.get_rear();
				break;
		
			case 7:
				a1.display_data();
				break;
		
			default:
				cout<<"Invalid choice"<<endl;
				break;
		}
		cout<<"\n\n\n\t\tPRESS 1 TO CONTINUE : ";
		cin>>temp;
	}
return 0;
}


/*
OUTPUT :
*****************************************WELCOME TO MR SHOPPING COMPLEX*************************************


NOTE : ADD/DELETE ITEMS TO THE LIST FROM BOTH THE ENDS TO ENSURE 100% SCANNING OF ITEMS.

                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 1
Enter the item name : APPLE
Enter the quantity : 6
Enter the price of 1 unit : RS. 12



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 2
Enter the item name : BANANA
Enter the quantity : 12
Enter the price of 1 unit : RS. 3



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 1
Enter the item name : MANGO
Enter the quantity : 5
Enter the price of 1 unit : RS. 38



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 2
cart is full



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 5


                THE FIRST ITEM IN THE CART IS :
MANGO                   5                       RS. 38                  190



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 7
ITEM NAME               ITEM QUANTITY           ITEM PRICE              TOTAL COST
MANGO                   5                       RS. 38                  190
APPLE                   6                       RS. 12                  72
BANANA                  12                      RS. 3                   36



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 4
BANANA is deleted successfully



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 6


                THE LAST ITEM IN THE CART IS :
APPLE                   6                       RS. 12                  72



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 3
MANGO is deleted successfully



                PRESS 1 TO CONTINUE : 1


                                Press 1 to Insert an item from front
                                Press 2 to Insert an item from rear
                                Press 3 to delete the item at front
                                Press 4 to delete the item at rear
                                Press 5 to get the first item in the cart
                                Press 6 to get the last item in the cart
                                Press 7 to Display the cart
Enter your choice : 7
ITEM NAME               ITEM QUANTITY           ITEM PRICE              TOTAL COST
APPLE                   6                       RS. 12                  72



                PRESS 1 TO CONTINUE : 0

--------------------------------
Process exited after 63.81 seconds with return value 0
Press any key to continue . . .
*/
//THANK YOU.
