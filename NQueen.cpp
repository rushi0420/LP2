#include<iostream>
#include<stdlib.h>
using namespace std;
int place(int r,int c);
int NQueen(int r,int c);
int print(int n);
int x[20],count;
int NQueen(int r,int n)
{
int i,c;
for(c=1;c<=n;c++)
{
if(place(r,c))
{
x[r]=c;
if(r==n)
{
print(n);
}
else
{
NQueen(r+1,n);
}
}
}
}

int print(int n)
{
int i,j;
cout<<"\n\n Solution "<<++count<<"\n\n";
for(i=1;i<=n;i++)
{

cout<<"\t"<<i;
}
for(i=1;i<=n;i++)
{
cout<<"\n"<<i;
for(j=1;j<=n;j++)
{
if(x[i]==j)
cout<<"\t Q";
else
cout<<"\t-";

}
} return 0;
}
int place(int r,int c)
{
int j;
for(j=1;j<=r-1;j++)
{
if(x[j]==c)
{
return 0;
}
else
{
if(abs(x[j]-c)==abs(j-r))
{
return 0;
}
}
}
return 1;
}
int main()
{
int n;
cout<<"\n*****NQueen solution****\n";
cout<<"\n Enter the no.of Queen:\n";
cin>>n;
NQueen(1,n);
return 0;
}
