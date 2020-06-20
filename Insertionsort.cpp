#include<iostream>
using namespace std;
int i,n,j,hole,a[20],value;
void get_elements(void);
void insertion_sort(int a[],int n);
void put_elements(void);
int main()
{

get_elements();
insertion_sort(a,n);
put_elements();
return 0;
}
void get_elements()
{
cout<<"\n Enter the no of elements to be inserted ";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\n Enter the element:\t";
cin>>a[i];
}
}
void insertion_sort(int a[],int n)
{
   for(i=1;i<n;i++)
  {
	hole=i;
	value=a[i];
	while(hole>0 && a[hole-1]>value)
 	{
         a[hole]=a[hole-1];
	hole--;                    
	}
	a[hole]=value;
  }
}
void put_elements()
{
	cout<<"\n After sorting the elemnts are: ";
	for(i=0;i<n;i++)
	{
	cout<<a[i]<<"\t";		
	}
	cout<<"\n";
}
