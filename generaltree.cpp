#include<iostream>
using namespace std;
class node 
{
public:
	char name[20];
	node *Llink,*Rlink;
};
class GT
{
public:
	node *root;

	GT()
	{	
	root=NULL;
	}

void insert_lchildren();
void insert_rchildren();
void print();

};
void GT::insert_lchildren()
{
	node *temp,*current,*p,*q;
	char choice;	
	p=root;
	do{
		temp=new node;
		temp->Llink=NULL;
		temp->Rlink=NULL;
		cout<<"\nEnter the name \n";
		cin>>temp->name;
		
	if(root==NULL)
	   {
		root=temp;	
	   }
	else
	  { p=root;	
	     while(p->Llink!=NULL)
		{
			p=p->Llink;
		}
		    p->Llink=temp;		
	  }
		cout<<"\nEnter the choice y/n\n";
		cin>>choice;
	  }while(choice=='y' || choice=='Y');
}
void GT::insert_rchildren()
{
	node *temp,*current,*p,*q,*prev;
	char choice1,choice2;
	current=root->Llink;
	       prev=root;
	while(current!=NULL)
	{ q=current;
	        
		cout<<"\n***************"<<current->name<<"*************************";	
	



	/*do{
			//
			//cin>>choice1;
			  // if(choice1=='y'|| choice1=='Y')
	 		     {
				temp=new node;
				temp->Llink=NULL;
				temp->Rlink=NULL;
				cout<<"\nEnter the name \n";
				cin>>temp->name;
		
		    if(q->Rlink==NULL)
			{
			   q->Rlink=temp;
			   q=temp;	
			}	
		}
		cout<<"want to add r-child";
		cin>>choice2;
		}while(choice2=='y' || choice2=='Y');
*/
		cout<<"\nwant to add r-child\n";
		cin>>choice2;
			while(choice2=='y' || choice2=='Y')
			 {
			
				temp=new node;
				temp->Llink=NULL;
				temp->Rlink=NULL;
				cout<<"\nEnter the name \n";
				cin>>temp->name;
		
			    if(q->Rlink==NULL)
				{
				   q->Rlink=temp;
				   q=temp;
				   q->Llink=prev;	
				}	
				cin>>choice2;
			}

	cout<<"\n*********************************************************************";
		current=current->Llink;
		prev=prev->Llink;		
	}	
}
void GT::print()
{
        node *temp,*current,*p,*q,*prev;
       temp=root;
       	int i=0,j=0,k=0;
	cout<<"\n *******"<<temp->name<<"*********"<<endl;
	temp=temp->Llink;
	while(temp!=NULL)
	 {
		cout<<++i<<"."<<temp->name<<endl;
		node *temp1=temp->Llink;
		j=0;
		 while(temp1!=NULL)
		  {cout<<"\t";
		   cout<<i<<"."<<++j<<"."<<temp1->name<<endl;
		   node *temp2=temp1->Llink;
		   k=0;
		    while(temp2!=NULL)
		      {
		      cout<<"\t";
		      	cout<<i<<"."<<j<<"."<<++k<<"."<<temp2->name<<endl;
		      	temp2=temp2->Rlink;
		      }
		      temp1=temp1->Rlink;	
		  } 
	    temp=temp->Rlink;
	 }
    
}
int main()
{
	GT obj;
	obj.insert_lchildren();
	obj.insert_rchildren();
	obj.print();
	return 0;
}
