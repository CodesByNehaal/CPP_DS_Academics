//NAME ; NEHAAL PANDEY
//ROLL : 63
//BATCH : A3
//PROBLEM STATEMENT : Design and implement a program for survey information of sports using principle of inclusion and exclusion.

#include<iostream>
using namespace std;

int intersection2(int sport1[], int sport2[], int size1, int size2, int choice)   //FUNCTION FOR INTERSECTION OF 2 SETS
{
	int i, j, n, inter_set[20], inter=0;
	for(i=0; i<size1; i++)
	{
		for(j=0; j<size2; j++)
		{
			if(sport1[i]==sport2[j]) //if elements are same add them to intersection
			{
				inter_set[inter]=sport1[i];
				inter++;
			}
		}
	}
	
	if(choice==1)
	{
		cout<<"\nstudents playing both Hockey and Badminton : ";
	}
	else if(choice==2)
	{
		cout<<"\nstudents playing both Hockey and kabaddi : ";
	}
	else if(choice==3)
	{
		cout<<"\nstudents playing both Hockey and cricket : ";
	}
	else if(choice==4)
	{
		cout<<"\nstudents playing both Badminton and Kabaddi : ";
	}
	else if(choice==5)
	{
		cout<<"\nstudents playing both Badminton and Cricket : ";
	}
	else if(choice==6)
	{
		cout<<"\nstudents playing both Kabaddi and Cricket : ";
	}
	cout<<inter<<" {";
	for(i=0; i<inter-1; i++)
	{
		cout<<inter_set[i]<<","; //intersecton elements
	}
	cout<<inter_set[i]<<"}";
	cout<<endl;
	return inter;
}

int intersection3(int sport1[], int sport2[], int sport3[], int size1, int size2, int size3, int choice1)//Intersection of 3 sets
{
	int i, j, k;
	int INTER=0;
	int flag1, flag2;
	int INTER_SET[size1];
	
	for(i=0; i<size1; i++)
	{
		flag1=0, flag2=0;
		for(j=0; j<size2; j++)
		{
			if(sport1[i]==sport2[j])
			{
				flag1=1;
				break;
			}
		}
		for(k=0; k<size3; k++)
		{
			if(sport1[i]==sport3[k])
			{
				flag2=1;
				break;
			}
		}
		if(flag1==1 && flag2==1)
		{
			INTER_SET[INTER]=sport1[i];
			INTER++;
		}
	}
	
	if(choice1==1)
	{
		cout<<"\nstudents playing Hockey, Badminton and Kabaddi : ";
	}
	else if(choice1==2)
	{
		cout<<"\nstudents playing Hockey, Badminton and Cricket : ";
	}
	else if(choice1==3)
	{
		cout<<"\nstudents playing Hockey, Kabaddi and Cricket : ";
	}
	else if(choice1==4)
	{
		cout<<"\nstudents playing Badminton, Kabaddi and Cricket : ";
	}
	cout<<INTER<<" ";
	cout<<"{";
	for(i=0; i<INTER-1; i++)
	{
		cout<<INTER_SET[i]<<","; //intersecton elements
	}
	cout<<INTER_SET[i]<<"}";
	cout<<endl;
	return INTER;
}

int intersection4(int Hockey[],int Badminton[], int Kabaddi[], int Cricket[], int size1, int size2, int size3, int size4) //Intersection of 4 sets
{
	int i, j, c;
	int k=0, p=0, l=0;
	int flag1, flag2, flag3;
	int d[size1];
	for(i=0; i<size1; i++)
	{
		flag1=0, flag2=0, flag3=0;
		for(j=0; j<size2; j++)
		{
			if(Hockey[i]==Badminton[j])
			{
				flag1=1;
				break;
			}
		}
		for(k=0; k<size3; k++)	
		{
			if(Hockey[i]==Kabaddi[k])
			{
				flag2=1;
				break;
			}
		}
		for(l=0; l<size4; l++)
		{
			if(Hockey[i]==Cricket[l])
			{
				flag3=1;
				break;
			}
		}
		if(flag1==1 && flag2==1 && flag3==1)
		{	
			d[p]=Hockey[i];
			p++;
		}
	}	
	
	cout<<"\nstudents playing all the Sports : ";
	cout<<p;
	cout<<" {";
	for(i=0; i<p-1; i++)//intersecton elements
	{
		cout<<d[i]<<",";
	}
	cout<<d[i]<<"}";
	cout<<endl;
	return p;
}

int union3(int sport1[], int sport2[], int sport3[],int sport4[], int size1, int size2, int size3,int size4)
{
	int Result;
	//Priciple of inclusion and exclusion using formula for union
	Result=size1+size2+size3+size4
	-intersection2(sport1,sport2,size1,size2,1)
	-intersection2(sport1,sport3,size1,size3,2)
	-intersection2(sport1,sport4,size1,size4,3)
	-intersection2(sport2,sport3,size2,size3,4)
	-intersection2(sport2,sport4,size2,size4,5)
	-intersection2(sport3,sport4,size3,size4,6)
	+intersection3(sport1,sport2,sport3,size1,size2,size3,1)
	+intersection3(sport1,sport2,sport4,size1,size2,size4,2)
	+intersection3(sport1,sport3,sport4,size1,size3,size4,3)
	+intersection3(sport2,sport3,sport4,size2,size3,size4,4)
	-intersection4(sport1,sport2,sport3,sport4,size1,size2,size3,size4);
	return Result;
}
int main()
{
	int Hockey[10],Badminton[10],Kabaddi[10],Cricket[10];
	int i;
	int size1;
	cout<<"\t******************************************SURVEY INFORMATION OF SPORTS*********************************************";
	cout<<"\n\nENTER THE NO. OF STUDENTS PLAYING HOCKEY : ";
	cin>>size1;
	for(i=0; i<size1; i++)
	{
		cout<<"\n\t\t\t\tROLL NO. OF STUDENT PLAYING HOCKEY : ";
		cin>>Hockey[i];
	}
	
	int size2;
	cout<<"\n\nENTER THE NO. OF STUDENTS PLAYING BADMINTON : ";
	cin>>size2;
	for(i=0; i<size2; i++)
	{
		cout<<"\n\t\t\t\tROLL NO. OF STUDENT PLAYING BADMINTON : ";
		cin>>Badminton[i];
	}
	
	int size3;
	cout<<"\n\nENTER THE NO. OF STUDENTS PLAYING KABADDI : ";
	cin>>size3;
	for(i=0; i<size3; i++)
	{
		cout<<"\n\t\t\t\tROLL NO. OF STUDENT PLAYING KABADDI : ";
		cin>>Kabaddi[i];
	}
	
	int size4;
	cout<<"\nENTER THE NO. OF STUDENTS PLAYING CRICKET : ";
	cin>>size4;
	for(i=0; i<size4; i++)
	{
		cout<<"\n\t\t\t\tROLL NO. OF STUDENT PLAYING CRICKET : ";
		cin>>Cricket[i];
	}
	
	cout<<endl;
	
	int Result=union3(Hockey,Badminton,Kabaddi,Cricket,size1,size2,size3,size4); //CALL UNION FUNCTION
	cout<<endl<<Result<<" student(s) playing atleast one of the sport.";
	return 0;
}

/*
OUTPUT :

        ******************************************SURVEY INFORMATION OF SPORTS*********************************************

ENTER THE NO. OF STUDENTS PLAYING HOCKEY : 3

                                ROLL NO. OF STUDENT PLAYING HOCKEY : 101

                                ROLL NO. OF STUDENT PLAYING HOCKEY : 102

                                ROLL NO. OF STUDENT PLAYING HOCKEY : 103


ENTER THE NO. OF STUDENTS PLAYING BADMINTON : 3

                                ROLL NO. OF STUDENT PLAYING BADMINTON : 102

                                ROLL NO. OF STUDENT PLAYING BADMINTON : 103

                                ROLL NO. OF STUDENT PLAYING BADMINTON : 104


ENTER THE NO. OF STUDENTS PLAYING KABADDI : 2

                                ROLL NO. OF STUDENT PLAYING KABADDI : 103

                                ROLL NO. OF STUDENT PLAYING KABADDI : 102

ENTER THE NO. OF STUDENTS PLAYING CRICKET : 4

                                ROLL NO. OF STUDENT PLAYING CRICKET : 101

                                ROLL NO. OF STUDENT PLAYING CRICKET : 102

                                ROLL NO. OF STUDENT PLAYING CRICKET : 103

                                ROLL NO. OF STUDENT PLAYING CRICKET : 104


students playing both Hockey and Badminton : 2 {102,103}

students playing both Hockey and kabaddi : 2 {102,103}

students playing both Hockey and cricket : 3 {101,102,103}

students playing both Badminton and Kabaddi : 2 {102,103}

students playing both Badminton and Cricket : 3 {102,103,104}

students playing both Kabaddi and Cricket : 2 {103,102}

students playing Hockey, Badminton and Kabaddi : 2 {102,103}

students playing Hockey, Badminton and Cricket : 2 {102,103}

students playing Hockey, Kabaddi and Cricket : 2 {102,103}

students playing Badminton, Kabaddi and Cricket : 2 {102,103}

students playing all the Sports : 2 {102,103}

4 student(s) playing atleast one of the sport.
--------------------------------
Process exited after 18.88 seconds with return value 0
Press any key to continue . . .

*/
