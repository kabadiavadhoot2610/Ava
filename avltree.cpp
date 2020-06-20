#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
using namespace std;
struct tnode
{
	string key, mean;
	tnode *L,*R;
};
class avl_tree
{
private:
	tnode *root;
public:
	avl_tree()
	{
		root=NULL;
	}
	void create();
	void display();
	void inorder(tnode*);
	tnode *insert(tnode*,string,string);
	tnode *LL(tnode*);
	tnode *RR(tnode*);
	tnode *LR(tnode*);
	tnode *RL(tnode*);
	int height(tnode*);
	int max(int,int);
	void search();
	void update();
};
tnode *avl_tree :: LL(tnode *parent)
{
	tnode *temp;
	temp=parent->L;
	parent->L=temp->R;
	temp->R=parent;
	return temp;
}
tnode *avl_tree :: RR(tnode *parent)
{
	tnode *temp;
	temp=parent->R;
	parent->R=temp->L;
	temp->L=parent;
	return temp;
}
tnode *avl_tree :: LR(tnode *parent)
{
	parent->L=RR(parent->L);
	parent=LL(parent);
	return parent;
}
tnode *avl_tree :: RL(tnode *parent)
{
	parent->R=LL(parent->R);
	parent=RR(parent);
	return parent;
}
int avl_tree :: max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;

}
int avl_tree :: height(tnode *temp)
{
	if(temp==NULL)
		return -1;
	if(temp->L==NULL && temp->R==NULL)
		return 0;
	return(1+max(height(temp->L),height(temp->R)));
}
void avl_tree :: display()
{
	inorder(root);
}
void avl_tree :: inorder(tnode *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->L);
		cout<<"\n"<<temp->key<<"\t"<<temp->mean<<"\n";
		inorder(temp->R);
	}
}
void avl_tree :: create()
{
	fstream f1;
	char data[30],key[10],mean[15];
	int i,j;
	f1.open("dict12.txt",ios::in);
	while(f1)
	{
		f1.getline(data,30);
		if(f1)
		{
			for(i=0;data[i]!=':';i++)
				key[i]=data[i];
			key[i]='\0';
				i++;
			for(j=0;data[i]!='\0';i++,j++)
				mean[j]=data[i];
			mean[j]='\0';
			root=insert(root,key,mean);
		}

	}
}
tnode *avl_tree :: insert(tnode *temp,string keyv, string meanv)
{

	if(temp==NULL)
	{
		temp=new tnode;
		temp->key=keyv;
		temp->mean=meanv;
		temp->L=temp->R=NULL;

	}
	else
	{
		if(keyv < temp->key)
		{
			temp->L=insert(temp->L,keyv,meanv);
			if(height(temp->L)-height(temp->R)==2)
			{
				if(keyv < temp->L->key)
					temp=LL(temp);
				else
					temp=LR(temp);
			}
		}
		else
		{
			temp->R=insert(temp->R,keyv,meanv);
            if(height(temp->L)-height(temp->R)==-2)
			{
				if(keyv > temp->R->key)
					temp=RR(temp);
				else
					temp=RL(temp);
			}

		}
	}
	return temp;
}

void avl_tree::search()

{

char key1[10];

cout<<"\nEnter The Word You Want To Search: ";
cin>>key1;
tnode *temp;
temp=root;
int flag,count;
flag=count=0;

while(temp!=NULL)
{
count++;


if(temp->key == key1)
{
    cout<<"\nData found after"<<count<<"comparisons!!!";
    flag=1;
    break;
}
else
{

    if(temp->key < key1)
          temp=temp->R;
    else
       temp=temp->L;

}
}
if(flag==0)
    cout<<"\nData not found!!!";
}

void avl_tree::update()
{
    tnode *p;
    char key1[30];
    p=root;
    cout<<"Enter the keyword to be updated:";
    cin>>key1;
    int flag,count;
    flag=count=0;

    while(p!=NULL)
    {

        count++;
        if(p->key==key1)
        {
            cout<<"Enter the updated meaning";
        cin>>p->mean;
        flag=1;
        break;
        }
        else
        {
            if(p->key<key1)
                 p=p->R;
            else
                p=p->L;

        }
    }
    if(flag==0)
         cout<<"Data not found";
    display();

}

int main()
{
	avl_tree t;
        tnode *temp;
	t.create();
	t.display();
	t.search();
	t.update();
        t.display();
	return 0;
}


