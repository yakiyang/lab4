#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;
void Sudoku::GiveQuestion()
{
	int i ,j=0 ,k ,s ,s1 ,s2 ,ss1[12] ,ss2[12];
	srand(time(NULL));
	s=rand()%5;
	ifstream in("file.in" ,ios::in);
	ofstream out("file.out" ,ios::out);
	if(s==0)
		for(i=0;i<size_su;i++)
			in>>map[i];
	if(s==1)
		for(i=143;i>=0;i--)
			in>>map[i];
	if(s==2)
		for(i=0;i<12;i++)
			for(j=i;j<size_su;j=j+12)
				in>>map[j];
	if(s==3)
		for(i=11;i>=0;i--)
			for(j=i;j<size_su;j=j+12)
				in>>map[j];
	if(s==4)
		for(i=11;i<size_su;i=i+12)
			for(j=i;j>=(i-11);j--)
				in>>map[j];
	for(k=0;k<4;k++)
	{
		for(i=0;i<12;i++)
			ss1[i]=-1;
		for(i=0;i<12;i++)
			ss2[i]=-1;
		s1=rand()%9+1;
		do
		{
			s2=rand()%9+1;
		}while(s1==s2);
		j=0;
		for(i=0;i<size_su;i++)
		{
			if(map[i]==s1)
			{
				ss1[j]=i;
				j++;
			}
		}
		j=0;
		for(i=0;i<size_su;i++)
		{
			if(map[i]==s2)
			{
				ss2[j]=i;
				j++;
			}
		}
		for(i=0;i<12;i++)
			if(ss1[i]!=(-1))
				map[ss1[i]]=s2;
		for(i=0;i<12;i++)
			if(ss2[i]!=(-1))
				map[ss2[i]]=s1;
	}
	for(i=0;i<size_su;i++)
	{
		out<<map[i]<<"\t";
		if(i%12==11)out<<"\n";
	}

}
void Sudoku::ReadIn()
{
	int i;
	ifstream in("file.in" ,ios::in);
	for(i=0;i<size_su;++i)
		in>>map[i];
}
void Sudoku::Init() 
{// 參數設定
	int i ,j;
	for(i=0; i<size_su; i++) 
	{
	      st_r[i]= i/12* 12 ;                       // 列位置的起點
	      st_c[i]= i% 12 ;                         // 行位置的起點
	      st_b[i]= ((i/12)/3)*36+ ((i%12)/3)*3 ;    // 九宮格位置的起點
	}
	for(i=0; i<12; i++) 
	{
	      add_r[i]= i ;                              // 列位置的加值
	      add_c[i]= i*12 ;                            // 行位置的加值
	}
	for(i=0;i<size_b;i++) 
	      add_b[i]= (i/3)*12+ (i%3) ;                 // 九宮格位置的加值
	for(i=0;i<size_su;i++)
		for(j=0;j<9;j++)
			cellpossiblenum[i][j]=true;
}
void Sudoku::check3(int s, int start ,int *add ,int size)
{// 檢查指定的行、列、九宮格有沒有相同的數
	int i ,sp;
	for(i=0; i<size; i++) 
       	{
		sp= start +add[i];
		if(map[sp]!=0&&map[sp]!=-1)
			cellpossiblenum[s][map[sp]-1]=false;      	
	}
}
void Sudoku::check2(int s) 
{// 檢查同行、列、九宮格有沒有相同的數
	check3(s, st_r[s] ,add_r ,size_r) ;   // 檢查同列有沒有相同的數字
	check3(s, st_c[s] ,add_c ,size_c) ;   // 檢查同行有沒有相同的數字
	check3(s, st_b[s] ,add_b ,size_b) ;   // 檢查同九宮格有沒有相同的數字	
}
void Sudoku::check1()
{
	int i ,j ,n ,m ,k=1;
	t++;
	for(i=0; i<size_su; i++) 
		if(map[i]==0)
	      		check2(i);
	for(i=0;i<size_su;i++)
	{
		n=0;
		if(map[i]==0)
		{
			for(j=0;j<9;j++)
				if(cellpossiblenum[i][j]==true)
			 	{
					n++;
					m=j+1;
				}
			if(n==1)
			{
				map[i]=m;
				break;
			}
		}
	}
	if(i==size_su)
	{
		k=0;
                for(i=0;i<size_su;i++)
		{
			if(map[i]==0)
			{
				for(j=0;j<9;j++)
				{
					if(cellpossiblenum[i][j]==true)
					{
						k++;
						m=j+1;
					}
				}
				if(k==0)T=0;
				else if(k>1)
				{
					T=T*k;
					map[i]=m;
				}
				break;
			}
		}
		if(i==size_su)
		{
			if(T>1)T=2;		cout<<T<<endl;
		}
	}
	if(k>0)check1();
}
void Sudoku::Solve()
{
	int i ,j=0;
	T=1;
	t=0;
	Init();
	check1();
	if(T==2)
	{
		for(i=0;i<size_su;i++)
		{
			cout<<map[i]<<"\t";
			if(i%12==11)cout<<endl;
		}
	}
	cout<<endl;
}
