#include<iostream>
using namespace std; 

int imin,i,j;
float temp;
void selection_sort(float a[],int size);
int main()
{float a[20];
int size;
cout<<"\n Enter size of array";
cin>>size;

	
	for(int i=0;i<size;i++)
	{
	cout<<"\n Enter the element ";
	cin>>a[i];
	cout<<"the element is : "<<a[i];	
	}
 selection_sort(a,size);
	cout<<"\n\n THE SORTED ELEMENTS ARE\n";
	for(i=0;i<size;i++)
	{
	cout<<"\t"<<a[i];	
	}
return 0;
}
void selection_sort(float a[],int size)
{
for(i=0;i<size-1;i++)
{
	imin=i;
	for(j=i+1;j<size;j++)
	{
		if(a[j]<a[imin])
		imin=j;
	}
	temp=a[i];
	a[i]=a[imin];
	a[imin]=temp;
}
}
