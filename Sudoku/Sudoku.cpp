#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;
void Sudoku::GiveQuestion()
{//隨機出題
	int i ,j=0 ,k ,s ,s1 ,s2 ,ss1[12] ,ss2[12];
	//排列方式:s交換數字:s1,s2數字位置:ss1,ss2
	srand(time(NULL));
	s=rand()%5;//選擇排列方式
	ifstream in("file.in" ,ios::in);//數獨原版檔
	ofstream out("file.out" ,ios::out);//數獨隨機版檔
	if(s==0)//排列方式
		for(i=0;i<size_su;i++)//相同
			in>>map[i];
	if(s==1)
		for(i=143;i>=0;i--)//相反
			in>>map[i];
	if(s==2)
		for(i=0;i<12;i++)//左到右上到下
			for(j=i;j<size_su;j=j+12)
				in>>map[j];
	if(s==3)
		for(i=11;i>=0;i--)//上到下右到左
			for(j=i;j<size_su;j=j+12)
				in>>map[j];
	if(s==4)
		for(i=11;i<size_su;i=i+12)//右到左上到下
			for(j=i;j>=(i-11);j--)
				in>>map[j];
	for(k=0;k<4;k++)
	{//交換數字
		for(i=0;i<12;i++)
			ss1[i]=-1;
		for(i=0;i<12;i++)
			ss2[i]=-1;
		s1=rand()%9+1;//隨機選擇交換數字
		do
		{
			s2=rand()%9+1;//隨機選擇交換數字
		}while(s1==s2);//數字相同則再選一次
		j=0;
		for(i=0;i<size_su;i++)
		{
			if(map[i]==s1)//存取數字位置
			{
				ss1[j]=i;
				j++;
			}
		}
		j=0;
		for(i=0;i<size_su;i++)
		{
			if(map[i]==s2)//存取數字位置
			{
				ss2[j]=i;
				j++;
			}
		}
		for(i=0;i<12;i++)
			if(ss1[i]!=(-1))
				map[ss1[i]]=s2;//交換數字
		for(i=0;i<12;i++)
			if(ss2[i]!=(-1))
				map[ss2[i]]=s1;//交換數字
	}
	for(i=0;i<size_su;i++)
	{//存檔
		out<<map[i]<<"\t";
		if(i%12==11)out<<"\n";
	}

}
void Sudoku::ReadIn()
{//讀檔
	int i;
	ifstream in("file.out" ,ios::in);
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
			cellpossiblenum[i][j]=true;//測試每格可能答案    
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
	//每格可能答案數量:n 可能答案數字:m 是否繼續遞迴:k 遞迴次數:t
	t++;
	for(i=0; i<size_su; i++)//重新確認每格可能答案 
		if(map[i]==0)
	      		check2(i);
	for(i=0;i<size_su;i++)
	{
		n=0;
		if(map[i]==0)//空格為零之位置
		{
			for(j=0;j<9;j++)//可能答案
				if(cellpossiblenum[i][j]==true)
			 	{
					n++;//可能答案數量
					m=j+1;//可能答案數字
				}
			if(n==1)//可能答案數量唯一
			{
				map[i]=m;//填入答案
				break;
			}
		}
	}
	if(i==size_su)//盤面0位置每格可能答案無唯一解或無解
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
						k++;//可能答案數量
						m=j+1;
					}
				}
				if(k==0)T=0;//可能答案數量為零:無解
				else if(k>1)//可能答案數量大於一:多重解
				{
					T=T*k;//多重解數
					map[i]=m;
				}
				break;
			}
		}
		if(i==size_su)
		{
			if(T>1)T=2;//多重解T為二		
			cout<<T<<endl;
		}
	}
	if(k>0)check1();//盤面上0位置每格可能答案至少有一個唯一解則繼續遞迴
}
void Sudoku::Solve()
{
	int i ,j=0;
	T=1;
	t=0;//遞迴次數
	Init();
	check1();
	if(T==1)//唯一解則印出
	{
		for(i=0;i<size_su;i++)
		{
			cout<<map[i]<<"\t";
			if(i%12==11)cout<<endl;
		}
	}
	cout<<endl;
}
