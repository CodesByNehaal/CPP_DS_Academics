/* 
Name: Nehaal Pandey
Roll No: 63
PRN No: 0120200245
Division: A
Batch: A3
PRACTICAL 2: Design and implement a program for sparse matrix operations of addition, multiplication and transpose of sparse matrix for 
climate prediction data stored in 2D array.


*/

//Including all the Header Files for Matrix
#include<iostream>
#include<math.h>
using namespace std;

//Declaring Class for Matrix Operations
class S_matrix
{
private:
    int temp;//While Transpose and Sort
    int len = 0;//As a counter
    int a[20][3];//for Storing Sparse Matrix

public:
    //Constructor Initialising the Values
    S_matrix(int row, int col, int no_val = 0)
    {
        a[0][0] = row;
        a[0][1] = col;
        a[0][2] = no_val;
        len +=1;
    }

    void input_matrix(int r, int c, int v)
    {
        if(r>a[0][0] || c>a[0][1] )
        {
            cout<<"Wrong Entry\n";
        }
        else
        {
        a[len][0] = r;
        a[len][1] = c;
        a[len][2] = v;
        len +=1;
        }
    }

    void display()
    {
        //cout<<"\t\tThe Entered Sparse Matrix is\n";
        cout<<"\t\tRow\t\tCol\t\tValue\n";
        for(int i=0 ; i<len; i++)
        {
            cout<<"\t\t"<<a[i][0]<<"\t\t"<<a[i][1]<<"\t\t"<<a[i][2]<<endl;
        }
    }

    //Transpose of the matrix
    S_matrix transpose()
    {
        S_matrix t(a[0][0],a[0][1],a[0][2]);
        t.a[0][0] = a[0][0];
        t.a[0][1] = a[0][1];
        t.a[0][2] = a[0][2];
        t.len = len;
        for (int i= 0;i<len;i++)
        {
            t.a[i][0] = a[i][1];
            t.a[i][1] = a[i][0];
            t.a[i][2] = a[i][2];
        }
        return t;
    }



    void add_matrix(S_matrix b)
    {
        int apos=1;
        int bpos=1;
        S_matrix result(a[0][0],a[0][1],0);

        if(a[0][0]!=b.a[0][0] || a[0][1]!=b.a[0][1])
        {
            cout<<"Matrices Cannot be added";
        }
            else
            {
                while(apos<=len && bpos<=b.len)
                {
                    if(a[apos][0]>b.a[bpos][0] ||(a[apos][0]==b.a[bpos][0] && a[apos][1]>b.a[bpos][1]))
                    {
                        result.input_matrix(b.a[bpos][0],b.a[bpos][1],b.a[bpos][2]);
                        bpos++;
                    }
                    else if(a[apos][0]<b.a[bpos][0] || (a[apos][0]==b.a[bpos][0] && a[apos][1]<b.a[bpos][1]))
                    {
                        result.input_matrix(a[apos][0],a[apos][1],a[apos][2]);
                        apos++;
                    }
                    else
                    {
                        int sum=a[apos][2]+b.a[bpos][2];
                        if(sum!=0)
                        result.input_matrix(a[apos][0],a[apos][1],sum);
                        apos++;
                        bpos++;
                    }
                }


            }
            result.a[0][2]=result.len-1;
            cout<<"The Multiplication of Matrices are\n"<<endl;
            result.display();
    }



    void matrix_multiplication(S_matrix t)
    {
            int sum,t1,t2, t3=1;

         S_matrix result(a[0][0],t.a[0][1],0);

    for(int i=0;i<a[0][0];i++)
    {
        for(int j=0;j<t.a[0][1];j++)
        {
            sum = 0;
            t1 = 1;
            t2 = 1;
            int flag1 = 0;
            int flag2 = 0;
            while(t1<=a[0][2])
            {
                if(a[t1][0] == i)
                {
                    flag1 = 1;
                    break;
                }
                t1++;
            }

            while(t2<=t.a[0][2])
            {
                if(t.a[t2][0] == j)
                {
                    flag2 = 1;
                    break;
                }
                t2++;
            }
            if(flag1 == 1 && flag2 == 1)
            {
                while(a[t1][0]==i && t.a[t2][0]==j)
                {
                    if(a[t1][1] == t.a[t2][1])
                    {
                        sum = sum + a[t1][2] * t.a[t2][2];
                        t1++;
                        t2++;
                    }
                    else if(a[t1][1]< t.a[t2][1])
                    {
                        t1++;
                    }
                    else
                    {
                        t2++;
                    }
                }
                if(sum>0)
                {
                    result.input_matrix(a[t3][0],t.a[t3][1],sum);
                    t3++;
                }
            }
        }
    }
     result.a[0][2] = t3-1;
     cout<<"\t\t The Multiplication of Matrix is "<<endl;
     result.display();
}



};

int main()
{
    int r,c,v;
    int val;
    int choice = 0;
    int exit_code = 1;

                    cout<<"Enter Number of Rows in Matrix: ";
                    cin>>r;
                    cout<<"Enter Number of Columns in Matrix: ";
                    cin>>c;
                    cout<<"Enter Number of Non_Zero Value: ";
                    cin>>v;
                    S_matrix s(r,c,v);
                    cout<<"Enter the Matrix Data\n";
                    for(int i=0;i<v;i++)
                        {
                            cout<<"Enter Row Value"<<endl;
                            cin>>r;
                            cout<<"Enter Column Value"<<endl;
                            cin>>c;
                            cout<<"Enter Number of Non_zero Value"<<endl;
                            cin>>val;
                            s.input_matrix(r,c,val);
                        }

                    cout<<"The Entered  Matrix with Temperature Data is \n\n";
                    s.display();
                    //Second Matrix
                    cout<<"Enter Number of Rows in Matrix: ";
                    cin>>r;
                    cout<<"Enter Number of Columns in Matrix: ";
                    cin>>c;
                    cout<<"Enter Number of Non_Zero Value: ";
                    cin>>v;
                    S_matrix t(r,c,v);
                    cout<<"Enter the Matrix Data\n";
                    for(int i=0;i<v;i++)
                        {
                            cout<<"Enter Row Value"<<endl;
                            cin>>r;
                            cout<<"Enter Column Value"<<endl;
                            cin>>c;
                            cout<<"Enter Number of Non_zero Value"<<endl;
                            cin>>val;
                            t.input_matrix(r,c,val);
                        }
                        cout<<"The Entered  Matrix with Temperature Data is\n";
                        t.display();
    do
    {
    	cout<<"Enter 1 for Addition\nEnter 2 for Multiplication\nEnter 3 for Transpose\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {

                s.add_matrix(t);
        }
        break;
        case 2:
            {

                s.matrix_multiplication(t);
            }
            break;
        case 3:
            {
                cout<<"The Transpose of First Matrix is \n"<<endl;
                s=s.transpose();
                s.display();

                cout<<"The Transpose of Second Matrix is"<<endl;
                t=t.transpose();
                t.display();
            }
        }
        cout<<"Enter -1 to Exit or 1 to Continue\n";
        cin>>exit_code;
    }while(exit_code!=-1);

    return 0;
}

/*
Output

Enter Number of Rows in Matrix: 4
Enter Number of Columns in Matrix: 4
Enter Number of Non_Zero Value: 4
Enter the Matrix Data
Enter Row Value
1
Enter Column Value
2
Enter Number of Non_zero Value
10
Enter Row Value
1
Enter Column Value
3
Enter Number of Non_zero Value
12
Enter Row Value
2
Enter Column Value
1
Enter Number of Non_zero Value
1
Enter Row Value
2
Enter Column Value
3
Enter Number of Non_zero Value
2
The Entered  Matrix with Temperature Data is
                Row             Col             Value
                4               4               4
                1               2               10
                1               3               12
                2               1               1
                2               3               2
Enter Number of Rows in Matrix: 4
Enter Number of Columns in Matrix: 4
Enter Number of Non_Zero Value: 4
Enter the Matrix Data
Enter Row Value
1
Enter Column Value
1
Enter Number of Non_zero Value
2
Enter Row Value
1
Enter Column Value
2
Enter Number of Non_zero Value
5
Enter Row Value
2
Enter Column Value
2
Enter Number of Non_zero Value
1
Enter Row Value
3
Enter Column Value
1
Enter Number of Non_zero Value
8
The Entered  Matrix with Temperature Data is
                Row             Col             Value
                4               4               4
                1               1               2
                1               2               5
                2               2               1
                3               1               8
Enter 1 for Addition
Enter 2 for Multiplication
Enter 3 for Transpose
2
                 The Multiplication of Matrix is
                Row         Col         Val
                1           1           96
                1           2           10
                2           1           18
                2           2           5
Enter -1 to Exit or 1 to Continue
1
Enter 1 for Addition
Enter 2 for Multiplication
Enter 3 for Transpose
1
                Row             Col             Value
                4               4               8
                1               1               2
                1               2               15
                1               3               12
                2               1               1
                2               2               1
                2               3               2
                0               0               0
Enter -1 to Exit or 1 to Continue
1
Enter 1 for Addition
Enter 2 for Multiplication
Enter 3 for Transpose
3
The Transpose of First Matrix is

                Row             Col             Value
                4               4               4
                2               1               10
                3               1               12
                1               2               1
                3               2               2
The Transpose of Second Matrix is
                Row             Col             Value
                4               4               4
                1               1               2
                2               1               5
                2               2               1
                1               3               8
Enter -1 to Exit or 1 to Continue
*/
