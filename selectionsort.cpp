#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
int i,j,min,temp;
for(int i=0;i<n-1;i++)
{
min=i;
for(int j=i+1;j<n;j++)
{
if(arr[j]<arr[min])
{
min=j;
}
}
temp=arr[i];
arr[i]=arr[min];
arr[min]=temp;
}
}
int main()
{
int n,arr[n];
cout<<"Enter tne value of n:";
cin>>n;
cout<<"Enter the value in array:";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
selection_sort(arr, n);
cout << "Sorted array: ";
for (int i = 0; i < n; i++)
{
cout << arr[i] << " ";
}
return 0;
}
