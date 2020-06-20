#include <iostream>
 
using namespace std;
 
void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;cout<<"\ni="<<i;cout<<"\t"<<high;
	k = 0;
	j = mid + 1;cout<<"\tj="<<j;
 
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
		while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	
	}
 
		while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	
	}
 
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
		cout<<"\t"<<temp[i-low];
	}
}
 
void MergeSort(int *a, int low, int high)
{
	int mid,i,j;
	if (low < high)
	{
		mid=(low+high)/2;
		//for(i=low;i<=mid;i++)
		//{cout<<"\t"<<a[i];}cout<<"\n";
		cout<<"\t1.low="<<low<<"\tmid="<<mid<<"\thigh="<<high<<"\n";
		MergeSort(a, low, mid);
		//cout<<"\n\n";
		//for(j=mid+1;j<=high;j++)
		//{cout<<"\t"<<a[j];}
		cout<<"\n\t2.low="<<mid<<"\tmid="<<mid<<"\thigh="<<high<<"\n";
		MergeSort(a, mid+1, high);
 		Merge(a, low, high, mid);
	}
}
 
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	MergeSort(arr, 0, n-1);
 
	cout<<"\n\n\n\n\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"\t"<<arr[i];
 
	return 0;
}
