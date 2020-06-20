#include<iostream>
#include<string.h>
using namespace std;
class phonebook
{
	public:
		char name[10];
		long number;

};
class Directory                                              
{
	public:
		phonebook obj[25];
	 
	  Directory()
	  {
	  	for(int i=0;i<25;i++)
	  	  {
	  	  	strcpy(obj[i].name,"NULL");
	  	  	obj[i].number=0;
	  	  }
	  }
	  
void create_phonebook(int temp,char arr[],long no);	  
void display();
void Delete(char name2[],int hash_index_d);
};
void Directory::create_phonebook(int temp,char arr[],long no)
{ int index=temp;
	if(strcmp(obj[temp].name,"NULL")==0)
	  { //cout<<"AVADHOOT";
	    obj[temp].number=no;
	    strcpy(obj[temp].name,arr);
	  }else
	    { 
	    do{
			if(strcmp(obj[temp].name,"NULL")==0) 
		   		{ 
		 			//cout<<"AVADHOOT";
	    			obj[temp].number=no;
	    			strcpy(obj[temp].name,arr);
	    			break;
	  			}
	  			temp=(temp+1)%25;
	  			}
		   while(index!=temp);	    
	    }

}
void Directory::display()
{
	for(int i=0;i<25;i++)
	  {	
	  	if(obj[i].number!=-1)
	  	{
	  	  cout<<"\nName : \t"<<obj[i].name;
	  	  cout<<"\tNumber: \t"<<obj[i].number;
	  	}
	  }
}
void Directory::Delete(char name2[],int hash_index_d)
{	while(1)
       {
	 strcmp(obj[hash_index_d].name,name2);
	  {
	 	strcpy(obj[hash_index_d].name,"NULL");
	 	obj[hash_index_d].number=-1;
	 	break;
	  } 
	  hash_index_d++;
	}

}
int main()
{
	int no,hash_index,entries,hash_index_d,choice;
	long number1;
	char name1[10],name2[10],ch;
		cout<<"\nHow many entries you wanna make\t";
		  cin>>entries;
	 
	 Directory obj1;
		ch='y';
		while(ch=='y' || ch=='Y')
		  {		
		     cout<<"\nEnter the choice to perform the action\n1.create directory\n2.display\n3.delete a contact \t";
		     	cin>>choice;
		   
		   switch(choice)
		     {
		       case 1:
		       for(int j=0;j<entries;j++)
		  	{
		       	 cout<<"\nEnter the name of person\t";
	 		  cin>>name1; 
			cout<<"\nEnter the number\t";
			  cin>>number1;
	 
	 		hash_index=name1[0];
	 		hash_index=hash_index%25;
	 
			obj1.create_phonebook(hash_index,name1,number1);
			
		      }	 break;        
	              case 2:
	              	   obj1.display();
	              	   break;
	 	      case 3: 	      	
	 		cout<<"\nEnter the name of person that oyu want to delete from Directory \t";
	 		cin>>name2;
	 
	 		hash_index_d=name2[0];
	         	hash_index_d=hash_index_d%25;
	  		
	  		obj1.Delete(name2,hash_index_d);
	  		break;
	  	     
	  	       default:
	  	     	break;
	  	     }
	  	   
	  	     cout<<"\nDo you want to perform action again\n";
	  	     cin>>ch;
	  	    } 
	 
	 
}
