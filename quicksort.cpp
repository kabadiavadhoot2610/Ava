#include<iostream>
using namespace std;
int partition(int a[],int low,int high)
{
	int pivot,i,j;
	pivot=a[low];
	i=low;
	j=high;j++;i--;
	do{
	do{i++;}while(a[i]<=pivot);
	do{j--;}while(a[j]>pivot);
	if(i<j)
	{
	swap(a[i],a[j]);
	}

	}while(i<j);
	swap(a[j],a[low]);
	return j;
}
void quicksort(int a[],int low,int high)
{	int partitionindex;
	if(low<high)
	{
	partitionindex=partition(a,low,high);
	quicksort(a,low,partitionindex-1);
	quicksort(a,partitionindex+1,high);
	}

}
int main()
{
int n,i;
cout<<"\nEnter the no of elements \n";
cin>>n;
int arr[n];	
	for(i=0;i<n;i++)
	{
	cout<<"Enter no:  ";
	cin>>arr[i];	
	}
//arr[i]=INT32_MAX;
	quicksort(arr,0,n-1);
	cout<<"\nAfter sorting\n";
	for(i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i];	
	}
return 0;
}
