#include<iostream>
using namespace std;
int get_max(int a[],int n)
{
	int max,i;
	max=a[0];
	for(i=0;i<n;i++)
	if(a[i]>max)
	max=a[i];
return max;

}
void countsort(int a[],int n,int exp)
{
	int output[n],count[10]={0},i;
	for(i=0;i<n;i++)
	{
	  count[(a[i]/exp)%10]++;			
	}

	for(i=1;i<10;i++)
	{
	  count[i]+=count[i-1];	
	}
		
	for(i=n-1;i>=0;i--)
	{
	  output[count[(a[i]/exp)%10]-1]=a[i];
	  count[(a[i]/exp)%10]--;		
	}
		
	for(i=0;i<n;i++)
	{
	a[i]=output[i];	
	}		
}
void radixsort(int a[],int n)
{
int m,exp;
m=get_max(a,n);
for(exp=1;(m/exp)>0;exp*=10)
countsort(a,n,exp);
}
int main()
{
int n,i;
cout<<"\nEnter the no of element of array \n";
cin>>n;
int arr[n];
for(i=0;i<n;i++)
{
cout<<"\nEnter element:  ";
cin>>arr[i];
}
radixsort(arr,n);
cout<<"\nAfter sorting\n";
for(i=0;i<n;i++)
{
cout<<"\t"<<arr[i];
}
return 0;
}
