#include<iostream>
using namespace std;
class OBST
{
	
	int weight[15][15],cost[15][15], root[15][15]; 
	char identifiers[10][10];
	float q[15],p[15],searchcost;

	public:
	OBST()
	  {
	  	searchcost=0;
	  }
		//int i,j,k;
	void accept();
	void print(int n);
	int find(int i,int j);
};
void OBST::accept()
{   int n,i,j,l,k,m;
		cout<<"\nHow many entries do you want  \t";
		cin>>n;
	
	  for(j=1;j<=n;j++)
	   {
	     cout<<"\n1.Enter the idendifiers of "<<j<<" th position: \t";
	   	       cin>>identifiers[j];
	   	  cout<<"\n2.Probability of success of"<<j<<" th element: \t";
	   	     cin>>p[j];
	   }
	   for(i=0;i<=n;i++)
	    {
	    		cout<<"\nProbability of failure of "<<i<<":\t";
	   	  	  cin>>q[i];
	   }
	    
	    	   	
	   for(i=0;i<=n;i++)
	    {
	    	weight[i][i]=q[i];
	    	cost[i][i]=root[i][i]=0;
	    }
	   for(i=0;i<n;i++)
	   	{
	   		cost[i][i+1]=weight[i][i+1]=q[i]+q[i+1]+p[i+1];
	   		root[i][i+1]=i+1;
	   		
	   	
	   	}
	  	for(m=2;m<=n;m++)	
	   	 { 
	   	    for(i=0;i<=n-m;i++)
	   	        {		
	   	        	j=i+m;
	   	        	
	   	                weight[i][j]=weight[i][j-1]+p[j]+q[j];
	   	                k=find(i,j);	
	   	                cost[i][j]=cost[i][k-1]+cost[k][j]+weight[i][j];
	   	                root[i][j]=k;  
	   	        }
	   	 	
	   	 }
	   	 
	
	   	 
	   	 print(n);
	 
}

int OBST::find(int a,int b)
{	int k;
	int min1=1000,l;      
	
	           for(k=a+1;k<=b;k++)
	   	      {
	   	        if(min1>cost[a][k-1]+cost[k][b])
	   	            {
	   	              min1=cost[a][k-1]+cost[k][b];
	   	              l=k;
	   	            }
	   	      }
		return l;
}
void OBST::print(int n)
{	int i,j,k;
       for(i=0;i<=n;i++)
        {   
            
            for( j=0;j<=n-i;j++)
             {
             k=i+j;
             cout<<"weight"<<j<<k<<"  "<<weight[j][k]<<"\t";
            

             }
            cout<<"\n";
            for(j=0;j<=n-i;j++)
             {
             k=i+j;
              cout<<"cost"<<j<<k<<"    "<<cost[j][k]<<"\t";
             
             }
            cout<<"\n";
	     for(j=0;j<=n-i;j++)
             { 
             k=i+j;
               cout<<"root"<<j<<k<<"    "<<root[j][k]<<"\t";
             
             }
             cout<<"\n\n";            
        }
        
        cout<<"\n\tMinimum cost of the optimum binary tree is: "<<cost[0][n]<<"\n";

} 
int main()
{
OBST obj;
obj.accept();
//obj.print();
return 0;
}
