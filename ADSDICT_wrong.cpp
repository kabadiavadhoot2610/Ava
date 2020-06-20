#include<iostream>
#include<string.h>
using namespace std;
class node
{
  public:
   char keyword[10];
   char meaning[10];
   node *Llink;
   node *Rlink;
};
class Dictionary
{
public:
node *root;
	Dictionary()
	{
		root=NULL;
	}
void insert();
void attach(node* Node,node* root);
void  display(node* Node);
int comparison(node* Node,char ch[]);
};
void Dictionary::insert()
{
	node *temp,*q;
	char ch;  
	  cout<<"\nDo you want to add keyword to your dictionary . (y/n)\n";
	  cin>>ch;
	
	   while(ch=='y' || ch=='Y')
	   {
	     temp=new node;
	     temp->Rlink=NULL;
	     temp->Llink=NULL;
	 
	      cout<<"\nEnter the keyword you wanna insert\t";
	        cin>>temp->keyword;
	      cout<<"\nNow please insert its meaning \t";
	        cin>>temp->meaning;
	        
	         attach(temp,root);	
	     	  cout<<"\nDo you want to add keyword to your dictionary again. (y/n)\n";
	  	     cin>>ch;
	  	       
	     }
	  
}

void Dictionary::attach(node* temp,node* Nodes)
{	
	//node *temp,*q;
	//temp=Node;
	
	if(root==NULL)
	{
		root=temp;
	}
	 else
	  {   
	  	if(strcmp(temp->keyword,Nodes->keyword)<0)
	  	   {
	  	     if(Nodes->Llink==NULL)
	  	      {
	  	        Nodes->Llink=temp;
	  	        return;
	  	      } 
	  	      else 
	  	      	{
	  	      	  //root=root->Llink; 	      	
	  	    	}
	  	     attach(temp,Nodes->Llink);
	  	   }
	  	else
	  	  if(strcmp(temp->keyword,Nodes->keyword)>0)
	  	      { if(Nodes->Rlink==NULL)
	  	         {
	  	            Nodes->Rlink=temp;
	  	            return;
	  	         }
	  	         else
	  	          {
	  	            //root=root->Rlink;
	  	          }
	  	     	attach(temp,Nodes->Rlink);
	  	      }
	  }
	  
	  
}
void Dictionary::display(node* Node)
{
	//node *temp,*q;
	//temp=Node;
	int count=0;
	if(Node==NULL)
	return;
	
	display(Node->Llink);
	
	cout<<"\nKeyword:: \t"<<Node->keyword;
	cout<<"\tMeaning:: \t"<<Node->meaning;
	display(Node->Rlink);
	


}
int Dictionary::comparison(node* Node,char ch[])
{	int count=1;
	if(strcmp(ch,Node->keyword)==0)
	   return count;

	if(strcmp(ch,Node->keyword)<0)
	  { 
	  count++;
	  comparison(Node->Llink,ch);
	  }else
	    if(strcmp(ch,Node->keyword)>0)
	      {
	      	count++;
	      	comparison(Node->Rlink,ch);
	      }
	      
	   return count;   
}
int main()
{
int cmp=0;
char ch[10];
Dictionary obj;

obj.insert();
cout<<"\nroot\t"<<obj.root->keyword;
obj.display(obj.root);
//cout<<"\n\nThe no of comparisons required are "<<cmp<<"\n";
cout<<"\nEnter the keyword for you want to find comparisons\n";
cin>>ch;
cmp=obj.comparison(obj.root,ch);
cout<<cmp;
}
