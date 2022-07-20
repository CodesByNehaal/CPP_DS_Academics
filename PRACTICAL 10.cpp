
//PROBLEM STATEMENT : Design and implement a menu driven program for implementing insertion sort and quick sort for population of a town.

#include <iostream>
using namespace std;	
#define size 5

class sort
{
	public:
	int data[size];
	string city[size];
	void getdata();
	void display();
	void quicksort(int l,int h);
	int partition(int l,int h);
	void insertion_sort();
};

void sort :: getdata()
{
	cout<<"\n\n\n\t\tENTER POPULATION DATA OF CITIES\n\n"<<endl;
	int n=1;
	
	for(int i=0; i<size; i++)
	{
		cout<<"\n\t\tCITY NAME : " ;
		cin>>city[i];
		cout<<"\n\t\tPOPULATION : ";
		cin>>data[i];
		n++;
	}
}
	
void sort :: display()
{
	cout<<"\n\nSorted list of cities according to population "<<endl;
	cout<<"\n\nCITY\t\t\tPOPULATION\n";

	for(int i=0; i<size; i++)
	{		
		cout<<city[i]<<"\t\t\t"<<data[i]<<endl;
	}
}

void sort :: quicksort(int l,int h)
{
	int pos;
	if(l<h)
	{
		pos=partition(l,h);
		quicksort(l,pos-1);
		quicksort(pos+1,h);
	}
}

int sort :: partition(int l,int h)
{
	int i=l;
	int j=h;
	int pivot=data[l];
	
	while(i<j)
	{
		while(data[i]<=pivot)
		{
			i++;
		}
		
		while(data[j]>pivot)
		{
			j--;
		}
		
		if(i<j)
		{
			int temp=data[i];
			string c=city[i];
			data[i]=data[j];
			city[i]=city[j];
			data[j]=temp;
			city[j]=c;
		}
	}
	int t=data[j];
	string c=city[j];
	data[j]=data[l];
	city[j]=city[l];
	data[l]=t;
	city[l]=c;
	return j;
}



void sort :: insertion_sort()
{
	int temp,j;
	string c;
	for(int i=1; i<size; i++)
	{
		temp=data[i];
		c=city[i];
		j=i-1;
		while (j>=0 && data[j]<temp)
		{
			data[j+1]=data[j];
			city[j+1]=city[j];
			j=j-1;
		}
		
		data[j+1]=temp;
		city[j+1]=c;
	
	}
}

int main()
{
	sort population;
	int choice;
	int temp=1,exit_loop=0;
	cout<<"***********************************METROPOLITAN CITY POPULATION RECORD************************************"<<endl;

	do
	{
		cout<<"\n\n\t\t\t\tPRESS 1 TO RECORD THE POPULATION DATA OF METROPOLITAN CITIES OF INDIA"<<endl;
		cout<<"\t\t\t\tPRESS 2 TO SORT IN ASCENDING ORDER USING QUICKSORT METHOD"<<endl;
		cout<<"\t\t\t\tPRESS 3 TO SORT IN DESCENDING ORDER USING INSERTION SORT METHOD"<<endl;
		cout<<"\t\t\t\tPRESS 4 TO EXIT";
		cout<<"\n\nEnter you choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				population.getdata();
				break;
				
			case 2:
				population.quicksort(0,size-1);
				population.display();
				break;
		
			case 3:
				population.insertion_sort();
				population.display();
				break;
			
			case 4:
				exit_loop=1;
				cout<<"\n\nTHANK YOU!";
				break;
		
			default:
				cout<<"Invalid Choice !!!"<<endl;
				break;
		}
		
		if(exit_loop==1)
		{
			break;
		}
		else
		{
			cout<<"\n\nPRESS 1 TO GO TO MAIN-MENU : ";
			cin>>temp;
		}
	}while(temp==1);
	return 0;
}


/*

OUTPUT : 
***********************************METROPOLITAN CITY POPULATION RECORD************************************


                                PRESS 1 TO RECORD THE POPULATION DATA OF METROPOLITAN CITIES OF INDIA
                                PRESS 2 TO SORT IN ASCENDING ORDER USING QUICKSORT METHOD
                                PRESS 3 TO SORT IN DESCENDING ORDER USING INSERTION SORT METHOD
                                PRESS 4 TO EXIT

Enter you choice : 1



                ENTER POPULATION DATA OF CITIES



                CITY NAME : mumbai

                POPULATION : 45876

                CITY NAME : pune

                POPULATION : 12000

                CITY NAME : chennai

                POPULATION : 17643

                CITY NAME : kolkata

                POPULATION : 21534

                CITY NAME : delhi

                POPULATION : 40946


PRESS 1 TO GO TO MAIN-MENU : 1


                                PRESS 1 TO RECORD THE POPULATION DATA OF METROPOLITAN CITIES OF INDIA
                                PRESS 2 TO SORT IN ASCENDING ORDER USING QUICKSORT METHOD
                                PRESS 3 TO SORT IN DESCENDING ORDER USING INSERTION SORT METHOD
                                PRESS 4 TO EXIT

Enter you choice : 2


Sorted list of cities according to population


CITY                    POPULATION
pune                    12000
chennai                 17643
kolkata                 21534
delhi                   40946
mumbai                  45876


PRESS 1 TO GO TO MAIN-MENU : 1


                                PRESS 1 TO RECORD THE POPULATION DATA OF METROPOLITAN CITIES OF INDIA
                                PRESS 2 TO SORT IN ASCENDING ORDER USING QUICKSORT METHOD
                                PRESS 3 TO SORT IN DESCENDING ORDER USING INSERTION SORT METHOD
                                PRESS 4 TO EXIT

Enter you choice : 3


Sorted list of cities according to population


CITY                    POPULATION
mumbai                  45876
delhi                   40946
kolkata                 21534
chennai                 17643
pune                    12000


PRESS 1 TO GO TO MAIN-MENU : 1


                                PRESS 1 TO RECORD THE POPULATION DATA OF METROPOLITAN CITIES OF INDIA
                                PRESS 2 TO SORT IN ASCENDING ORDER USING QUICKSORT METHOD
                                PRESS 3 TO SORT IN DESCENDING ORDER USING INSERTION SORT METHOD
                                PRESS 4 TO EXIT

Enter you choice : 4

THANK YOU!

--------------------------------
Process exited after 43.38 seconds with return value 0
Press any key to continue . . .
*/





//THANK YOU.
