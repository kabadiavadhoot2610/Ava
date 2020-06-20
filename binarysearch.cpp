#include<iostream>
using namespace std;
int mid,w;
int mid_element(int n)
	{mid=(((0)+(n))/2);
	//cout<<"mid fn"<<mid;
	return mid;}
int mid_element1(int q,int w)
{
	mid=(((q+1)+(w))/2);
	//cout<<"mid fn1  "<<mid;
	return mid;
}
class search_techniques
{
int a[20],i,j,k,n;
public:
search_techniques(int a)
{
n=a;
}
void get_no();
void linear_search();
void binary_search();

};
void search_techniques::get_no()
{
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter the elements of array ";
		cin>>a[i];	
	}

}
void search_techniques::linear_search()
{
	int key;
	for(i=0;i<n;i++)
	{
	cout<<"\n The array elements are :";
	cout<<" "<<a[i];	
	}
	cout<<"\n Enter the no to search from array \n";
	cin>>key;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
		cout<<"\n The element is found at "<<i<<" index using Linear search\n";
		break;		
		}	
	}
}
void search_techniques::binary_search()
{
	int mid,key,p,u,q,z,e=0;
	int mid_element(int n);
	int mid_element1(int q,int w);
	for(i=0;i<n;i++)
	{
	cout<<"\n The array elements are :";
	cout<<" "<<a[i];	
	}
	cout<<"\n Enter the no to search from array \n";
	cin>>key;
	//finding mid
	
	 
	mid=(((0)+(n-1))/2);
	
	do{
	e=0;

	//cout<<"\t mid "<<a[mid]<<"\t i "<<mid;
	if(a[mid]==key)
	{
	cout<<"\n The element is found at "<<mid<<" index using Binary search\n";e=1;		
	}else
	if(key<a[mid])
	{
		p=mid;
		mid=mid_element(p);
		//cout<<p<<mid<<n<<"\t"<<u;
		if(a[mid]==key)
		{
		cout<<"\n The element is found at "<<mid<<" index using Binary search\n";
		e=1;	
		}
	}else
	
	if(key>a[mid])
	{
		q=mid;
		//cout<<"  mid  "<<mid;
		w=n-1;
		mid=mid_element1(q,w);
		if(a[mid]==key)
		{
		cout<<"\n The element is found at "<<mid<<" index using Binary search \n";		
		e=1;
		}	
	}

	}while(e<1);
}
int main()
{
int m;
cout<<"\n Enter the size of array : \n";
cin>>m;
search_techniques obj(m);
int t;
cout<<"\n 1.Linear search \n2.Binary search\n";
cin>>t;
switch(t)
{
case 1:
	{obj.get_no();
	obj.linear_search();
	}
	break;
case 2:
	{
	obj.get_no();
	obj.binary_search();
	}
}
return 0;
}
