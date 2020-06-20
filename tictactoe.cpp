#include<iostream>
#include<stdlib.h>	
using namespace std;
char matrix[3][3]={'_','_','_','_','_','_','_','_','_'};
char player='x';
void Draw()
{	cout<<"TIC TAC TOE v1.O\n\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<matrix[i][j]<<" ";	
		}	
		cout<<"\n";
		//cout<<"\t\t\t";	
	}
}
void input()
{
	int a;
cout<<"\n Enter the no for marking\n";
cin>>a;
	if(a==1)
	{
		if(matrix[0][0]!='x' && matrix[0][0]!='o')
		matrix[0][0]=player;
	}
	else 
	if(a==2)
	{
		if(matrix[0][1]!='x' && matrix[0][1]!='0')
		matrix[0][1]=player;
	}
	else 
	if(a==3)
	{
		if(matrix[0][2]!='x' && matrix[0][2]!='0')
		matrix[0][2]=player;
	}	
	else 
	if(a==4)
	{
		if(matrix[1][0]!='x' && matrix[1][0]!='0')
		matrix[1][0]=player;
	}
	else 
	if(a==5)
	{
		if(matrix[1][1]!='x' && matrix[1][1]!='0')
		matrix[1][1]=player;
	}
	else 
	if(a==6)	
	{
	if(matrix[1][2]!='x' && matrix[1][2]!='0')
	matrix[1][2]=player;
	}
	else
	 if(a==7)
	{
		if(matrix[2][0]!='x' && matrix[2][0]!='0')
		matrix[2][0]=player;
	}else
	
	 if(a==8)
	{
		if(matrix[2][1]!='x' && matrix[2][1]!='0')
		matrix[2][1]=player;
	}	
	else 
	if(a==9)
	{
		if(matrix[2][2]!='x' && matrix[2][2]!='0')
		matrix[2][2]=player;
	}
}
void Toggleplayer()
{
	if(player=='x')
	player='o';
	else if(player=='o')
	player='x';
	
}
char win()
{
	if(matrix[0][0]=='x' && matrix[0][1]=='x' && matrix[0][2]=='x')
	return 'x';
 	else 
	if(matrix[1][0]=='x' && matrix[1][1]=='x' && matrix[1][2]=='x')
	return 'x';
	else
	 if(matrix[2][0]=='x' && matrix[2][1]=='x' && matrix[2][2]=='x')
	return 'x';
	else
	 if(matrix[0][0]=='x' && matrix[1][0]=='x' && matrix[2][0]=='x')
	return 'x';
	else
	if(matrix[0][1]=='x' && matrix[1][1]=='x' && matrix[2][1]=='x')
	return 'x';
	else
	if(matrix[0][2]=='x' && matrix[1][2]=='x' && matrix[2][2]=='x')
	return 'x';
	else
	if(matrix[0][0]=='x' && matrix[1][1]=='x' && matrix[2][2]=='x')
	return 'x';
	else	
	if(matrix[0][2]=='x' && matrix[1][1]=='x' && matrix[2][0]=='x')
	return 'x';

	//second player
	
	
	if(matrix[0][0]=='o' && matrix[0][1]=='o' && matrix[0][2]=='o')
	return 'o';
 	else 
	if(matrix[1][0]=='o' && matrix[1][1]=='o' && matrix[1][2]=='o')
	return 'o';
	else
	 if(matrix[2][0]=='o' && matrix[2][1]=='o' && matrix[2][2]=='o')
	return 'o';
	else
	 if(matrix[0][0]=='o' && matrix[1][0]=='o' && matrix[2][0]=='o')
	return 'o';
	else
	if(matrix[0][1]=='o' && matrix[1][1]=='o' && matrix[2][1]=='o')
	return 'o';
	else
	if(matrix[0][2]=='o' && matrix[1][2]=='o' && matrix[2][2]=='o')
	return 'o';
	else
	if(matrix[0][0]=='o' && matrix[1][1]=='o' && matrix[2][2]=='o')
	return 'o';
	else	
	if(matrix[0][2]=='o' && matrix[1][1]=='o' && matrix[2][0]=='o')
	return 'o';

	return '/';
}
int main()
{
int i,j,count=0;
Draw();
while(1)
{	
	input();
	count=0;
	for(i=0;i<3;i++)
	{	
		for(j=0;j<3;j++)
		{
			if(matrix[i][j]=='_')
			{
			count++;
			}
		}
	
	}
	
	Draw();
	if(win()=='x')
	{
	cout<<"X wins !!\n";
	break;
	}
	else if(win()=='o')
	{
	cout<<"O wins !!\n";
	break;	
	}	
	Toggleplayer();
	if(count==0)
	{	cout<<"\nMatch drawn\n";
		exit(1);	
	}

}
system("pause");
return 0;
}
