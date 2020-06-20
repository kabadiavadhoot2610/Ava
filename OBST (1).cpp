#include<iostream>
#define MAX 20
using namespace std;
class OBTree
{
	public:
		int w[20][10],c[20][10],r[20][10],i,j,k,n,m;
		char idnt[10][10];
		//int P_index,Q_index;
		float q[MAX],p[MAX],SearchCost;
		OBTree()
		{
			//P_index=0;
			//Q_index=0;
			SearchCost=0.0;
		}
		
	
		void accept()
		{
			cout<<"enter the no, of identifiers";
			cin>>n;
			cout<<"enter identifiers";
			for(i=1;i<=n;i++)
				cin>>idnt[i];
			idnt[0][0]='0';
			cout<<"enter success propability for identifiers";
			for(i=1;i<=n;i++)
				cin>>p[i];
			cout<<"enter failure propability for identifiers";
			for(i=0;i<=n;i++)
				cin>>q[i];
			for(i=0;i<=n;i++)
			{
				    w[i][i]=q[i];
	     			c[i][i]=r[i][i]=0;
	    		}
	   		for(m=1;m<=n;m++)
	    		{
	     			for(i=0;i<=n-m;i++)
	      			{
	      				j=i+m;
	      				k=find(i,j);
	      				w[i][j]=w[i][j-1]+p[j]+q[j];
	      				r[i][j]=k;
	      				c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
	      			}
	    		}
		}

		int find(int i,int j)
		{
			int min=3000,m,l;
			for(m=i+1;m<=j;m++)
				if(min > c[i][m-1]+c[m][j])
				{
					min=c[i][m-1]+c[m][j];
					l=m;
				}
			return l;
		}

		void print()
		{
			int oo;
			for(int mm=0; mm<=n; mm++)
			{
				for(int nn=0; nn<=n-mm; nn++)
	    			{
	      				oo = mm+nn;
	      				cout<<"w"<<nn<<oo<<" = "<<w[nn][oo]<<"     ";
      				
					if(w[nn][oo]<10)
			   			cout<<"  ";
	      				else if(w[nn][oo]<100) 
					   	cout<<" ";
				}
				cout<<endl;
    				for(int nn=0; nn<=n-mm; nn++)
    				{
      					oo = mm+nn;
      					cout<<"c"<<nn<<oo<<" = "<<c[nn][oo]<<"     ";
      					if(c[nn][oo]<10)
   						cout<<"  ";
      					else if(c[nn][oo]<100) 
   						cout<<" ";
    				}
    				cout<<endl;
    				for(int nn=0; nn<=n-mm; nn++)
    				{
      					oo = mm+nn;
      					cout<<"r"<<nn<<oo<<" = "<<r[nn][oo]<<"     ";
      					if(r[nn][oo]<10)
   						cout<<"  ";
      					else if(r[nn][oo]<100) 
   						cout<<" ";
    				}
    				cout<<endl<<endl;
				
				
   			}
   			cout<<"\n\tMinimum cost of the optimum binary tree is: "<<c[0][n];
   			cout<<endl<<endl;



}
};

int main()
{
	OBTree OBT;
	OBT.accept();
	OBT.print();
	return 0;
}


