//NAME : NEHAAL PANDEY
//BATCH : A(A3)
//ROLL : 63
//PROBLEM STATEMENT 14 : Design and develop a program using linear recurrence relations for various loan schemes of a bank

#include<iostream>
using namespace std;
string name; //Declaring the Global variables
int time;
float amt;
float rate;
class Loan //Creating the Class Loan
{
	public:
	 //Defining Member Functions
	void input();
	void output();
	void home();
	void education();
	void gold();
	void car();
	void rateinfo();
	void amtcalc();
};
void Loan::input()
{
	cout<<"\n\t\tEnter Your name : ";
	cin>>name;
	cout<<"\n\t\tEnter the loan amount : ";
	cin>>amt;
	cout<<"\n\t\tEnter the time duration(yrs) : ";
	cin>>time;
}

void Loan::home()
{
	rate=6;
}

void Loan::education()
{
	rate=9;
}

void Loan::gold()
{
	rate=1;
}
	
void Loan::car()
{
	rate=10;
}

void Loan::output()
{
	//cout<<"\nYOUR LOAN DETAILS "<<endl;
	cout<<"\n\t\t\tName : "<<name;
	cout<<"\n\t\t\tLoan amount :" <<amt;
	cout<<"\n\t\t\tTime Duration : "<<time<<"yrs";	
	cout<<"\n\t\t\tInterest rate : "<<rate<<"%";
}

void Loan::rateinfo()
{
	cout<<"\nINTEREST RATE OF DIFFERENT LOANS\n"<<endl;
	cout<<"\t\t***********************"<<endl;
	cout<<"\t\t*  HOME LOAN-11%      *"<<endl;
	cout<<"\t\t*  EDUCATION LOAN-10% *"<<endl;
	cout<<"\t\t*  GOLD LOAN-15%      *"<<endl;
	cout<<"\t\t*  CAR LOAN-12%       *"<<endl;
	cout<<"\t\t***********************\n"<<endl;
}

void Loan::amtcalc()
{
	cout<<"\n\n\t\tLOAN AMOUNT CALCULATOR "<<endl;
	cout<<"\n\t\tEnter the Principle Amount : ";
	cin>>amt;	
	cout<<"\n\t\tEnter the Interest Rate : ";
	cin>>rate;
	cout<<"\n\t\tEnter the time Duration(yrs) : ";
	cin>>time;
}

float finalamt(int t,int amt,float rt) 															//Creating a Recursive Function
{
	if(t<=0)
	{
		return amt ;
	}
	else
		return (1+(rt/100))*finalamt(t-1,amt,rt) ;
}

//Initialisation of Main Function
int main()
{
	Loan l; //Creating Object Of Class Loan
	int choice,loop_end=0;
	cout<<"\n********************************************PANDEYJI BANK***********************************************"<<endl;
	while(loop_end!=-1)
	{
		cout<<"\n\t\t\t<<<<<<<<<<<<<<<WELCOME TO LOAN SECTION>>>>>>>>>>>>>>>>>\n\n";
		cout<<"\n\t\t\t\tPRESS 1 TO DISPLAY THE CURRENT INTEREST RATE FOR DIFFERENT LOANS AT OUR BANK";
		cout<<"\n\t\t\t\tPRESS 2 TO EXPLORE HOME LOAN";
		cout<<"\n\t\t\t\tPRESS 3 TO EXPLORE EDUCATION LOAN";
		cout<<"\n\t\t\t\tPRESS 4 TO EXPLORE GOLD LOAN";
		cout<<"\n\t\t\t\tPRESS 5 TO EXPLORE CAR LOAN";
		cout<<"\n\t\t\t\tPRESS 6 TO CALCULATE A CUSTOMISED LOAN"<<endl;
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>choice;
	
		switch(choice) //Using Switch Cases
		{
			case 1:
				l.rateinfo();
				break;
				
			case 2:
				l.input();
				l.home();
				cout<<"\n\t\t\tYOUR HOME LOAN DETAILS\n\n";
				l.output();
				cout<<"\n\t\t\tYou pay RS. "<<finalamt(time,amt,rate)<<" in "<<time<<" years.";  //calling the recursive function
				break;
			
			case 3:
				l.input();
				l.education();
				cout<<"\n\t\t\tYOUR EDUCATION LOAN DETAILS";
				l.output();
				cout<<"\n\t\t\tYou pay RS. "<<finalamt(time,amt,rate)<<" in "<<time<<" years.";   //calling the recursive function
				break;
		
			case 4:	
				l.input();
				l.gold();
				cout<<"\n\t\t\tYOUR GOLD LOAN DETAILS";
				l.output();
				cout<<"\n\t\t\tYou pay RS. "<<finalamt(time,amt,rate)<<" in "<<time<<" years.";   //calling the recursive function
				break;
		
			case 5:
				l.input();
				l.car();
				cout<<"\n\t\t\tYOUR CAR LOAN DETAILS";
				l.output();
				cout<<"\n\t\t\tYou pay RS. "<<finalamt(time,amt,rate)<<" in "<<time<<" years.";   //calling the recursive function
				break;
		
			case 6:
				l.amtcalc();	
				cout<<"\n\t\t\tYou pay RS. "<<finalamt(time,amt,rate)<<" in "<<time<<" years.";   //calling the recursive function
				break;
			
			default:
				cout<<"\n!!!!!Enter valid option!!!!"<<endl;
		}
		cout<<"\n\n\t\tPRESS -1 TO EXIT OR 1 TO GO BACK TO MAIN MENU : ";
		cin>>loop_end;
	}
	cout<<"\n**********************************thank you. visit again*****************************************"<<endl;
}

/*
OUTPUT : 


********************************************PANDEYJI BANK***********************************************

                        <<<<<<<<<<<<<<<WELCOME TO LOAN SECTION>>>>>>>>>>>>>>>>>


                                PRESS 1 TO DISPLAY THE CURRENT INTEREST RATE FOR DIFFERENT LOANS AT OUR BANK
                                PRESS 2 TO EXPLORE HOME LOAN
                                PRESS 3 TO EXPLORE EDUCATION LOAN
                                PRESS 4 TO EXPLORE GOLD LOAN
                                PRESS 5 TO EXPLORE CAR LOAN
                                PRESS 6 TO CALCULATE A CUSTOMISED LOAN

ENTER YOUR CHOICE : 1

INTEREST RATE OF DIFFERENT LOANS

                ***********************
                *  HOME LOAN-11%      *
                *  EDUCATION LOAN-10% *
                *  GOLD LOAN-15%      *
                *  CAR LOAN-12%       *
                ***********************



                PRESS -1 TO EXIT OR 1 TO GO BACK TO MAIN MENU : 1

                        <<<<<<<<<<<<<<<WELCOME TO LOAN SECTION>>>>>>>>>>>>>>>>>


                                PRESS 1 TO DISPLAY THE CURRENT INTEREST RATE FOR DIFFERENT LOANS AT OUR BANK
                                PRESS 2 TO EXPLORE HOME LOAN
                                PRESS 3 TO EXPLORE EDUCATION LOAN
                                PRESS 4 TO EXPLORE GOLD LOAN
                                PRESS 5 TO EXPLORE CAR LOAN
                                PRESS 6 TO CALCULATE A CUSTOMISED LOAN

ENTER YOUR CHOICE : 2

                Enter Your name : abc

                Enter the loan amount : 10000

                Enter the time duration(yrs) : 5

                        YOUR HOME LOAN DETAILS


                        Name : abc
                        Loan amount :10000
                        Time Duration : 5yrs
                        Interest rate : 6%
                        You pay RS. 13382.3 in 5 years.

                PRESS -1 TO EXIT OR 1 TO GO BACK TO MAIN MENU : 1

                        <<<<<<<<<<<<<<<WELCOME TO LOAN SECTION>>>>>>>>>>>>>>>>>


                                PRESS 1 TO DISPLAY THE CURRENT INTEREST RATE FOR DIFFERENT LOANS AT OUR BANK
                                PRESS 2 TO EXPLORE HOME LOAN
                                PRESS 3 TO EXPLORE EDUCATION LOAN
                                PRESS 4 TO EXPLORE GOLD LOAN
                                PRESS 5 TO EXPLORE CAR LOAN
                                PRESS 6 TO CALCULATE A CUSTOMISED LOAN

ENTER YOUR CHOICE : 3

                Enter Your name : def

                Enter the loan amount : 12000

                Enter the time duration(yrs) : 5

                        YOUR EDUCATION LOAN DETAILS
                        Name : def
                        Loan amount :12000
                        Time Duration : 5yrs
                        Interest rate : 9%
                        You pay RS. 18463.5 in 5 years.

                PRESS -1 TO EXIT OR 1 TO GO BACK TO MAIN MENU : 1

                        <<<<<<<<<<<<<<<WELCOME TO LOAN SECTION>>>>>>>>>>>>>>>>>


                                PRESS 1 TO DISPLAY THE CURRENT INTEREST RATE FOR DIFFERENT LOANS AT OUR BANK
                                PRESS 2 TO EXPLORE HOME LOAN
                                PRESS 3 TO EXPLORE EDUCATION LOAN
                                PRESS 4 TO EXPLORE GOLD LOAN
                                PRESS 5 TO EXPLORE CAR LOAN
                                PRESS 6 TO CALCULATE A CUSTOMISED LOAN

ENTER YOUR CHOICE : 4

                Enter Your name : pqr

                Enter the loan amount : 25000

                Enter the time duration(yrs) : 5

                        YOUR GOLD LOAN DETAILS
                        Name : pqr
                        Loan amount :25000
                        Time Duration : 5yrs
                        Interest rate : 1%
                        You pay RS. 26275.2 in 5 years.

                PRESS -1 TO EXIT OR 1 TO GO BACK TO MAIN MENU : 1

                        <<<<<<<<<<<<<<<WELCOME TO LOAN SECTION>>>>>>>>>>>>>>>>>


                                PRESS 1 TO DISPLAY THE CURRENT INTEREST RATE FOR DIFFERENT LOANS AT OUR BANK
                                PRESS 2 TO EXPLORE HOME LOAN
                                PRESS 3 TO EXPLORE EDUCATION LOAN
                                PRESS 4 TO EXPLORE GOLD LOAN
                                PRESS 5 TO EXPLORE CAR LOAN
                                PRESS 6 TO CALCULATE A CUSTOMISED LOAN

ENTER YOUR CHOICE : 5

                Enter Your name : xyz

                Enter the loan amount : 80000

                Enter the time duration(yrs) : 8

                        YOUR CAR LOAN DETAILS
                        Name : xyz
                        Loan amount :80000
                        Time Duration : 8yrs
                        Interest rate : 10%
                        You pay RS. 171487 in 8 years.

                PRESS -1 TO EXIT OR 1 TO GO BACK TO MAIN MENU : 1

                        <<<<<<<<<<<<<<<WELCOME TO LOAN SECTION>>>>>>>>>>>>>>>>>


                                PRESS 1 TO DISPLAY THE CURRENT INTEREST RATE FOR DIFFERENT LOANS AT OUR BANK
                                PRESS 2 TO EXPLORE HOME LOAN
                                PRESS 3 TO EXPLORE EDUCATION LOAN
                                PRESS 4 TO EXPLORE GOLD LOAN
                                PRESS 5 TO EXPLORE CAR LOAN
                                PRESS 6 TO CALCULATE A CUSTOMISED LOAN

ENTER YOUR CHOICE : 6


                LOAN AMOUNT CALCULATOR

                Enter the Principle Amount : 2000

                Enter the Interest Rate : 3

                Enter the time Duration(yrs) : 1

                        You pay RS. 2060 in 1 years.

                PRESS -1 TO EXIT OR 1 TO GO BACK TO MAIN MENU : -1

**********************************thank you. visit again*****************************************

--------------------------------
Process exited after 89.36 seconds with return value 0
Press any key to continue . . .*/
