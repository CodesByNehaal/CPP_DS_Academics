#include<iostream>
#include <cstring>
using namespace std;


char temp[100];
int count;

void combination(char *str,int r,int index)
{
	for(int i=0; i<strlen(str); i++)
	{
		temp[index]=str[i];
		if(index==r-1)
		{
			cout<<"\n"<<temp;
			count++;
		}
		else
		{
			combination(str,r,index+1);
		}
	}
}

int main()
{
	char str[10];
	cout<<"Enter the string : ";
	cin>>str;
	for(int i=1; i<=strlen(str); i++)
	{
		combination(str,i,0);
	}
	cout<<"\n\n\n\t\t\tTOTAL NO. OF POSSIBLE COMBINATIONS IS : "<<count<<"\n\n\n";
}

/*
OUTPUT : 
Enter the string : pop

p
o
p
pp
po
pp
op
oo
op
pp
po
pp
ppp
ppo
ppp
pop
poo
pop
ppp
ppo
ppp
opp
opo
opp
oop
ooo
oop
opp
opo
opp
ppp
ppo
ppp
pop
poo
pop
ppp
ppo
ppp


                        TOTAL NO. OF POSSIBLE COMBINATIONS IS : 39



--------------------------------
Process exited after 2.74 seconds with return value 0
Press any key to continue . . .
*/
