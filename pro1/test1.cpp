#include<iostream>
#include<cstdlib>
#define N 70
using namespace std;
	
int sudoku[81] ;                                // 數獨題目陣列
int list[81][9];
int st_r[81] ;                                // 列位置的起點
int st_c[81] ;                                // 行位置的起點
int st_b[81] ;                                // 九宮格位置的起點
int add_r[9] ;                                   // 列位置的加值
int add_c[9] ;                                   // 行位置的加值
int add_b[9] ;                                   // 九宮格位置的加值
		
int Init() 
{// 參數設定
	int i ,j ;
	for(i=0; i<81; i++) 
	{
	      st_r[i]= i/9* 9 ;                       // 列位置的起點
	      st_c[i]= i% 9 ;                         // 行位置的起點
	      st_b[i]= ((i/9)/3)*27+ ((i%9)/3)*3 ;    // 九宮格位置的起點
	}
	for(i=0; i<9; i++) 
	{
	      add_r[i]= i ;                              // 列位置的加值
	      add_c[i]= i*9 ;                            // 行位置的加值
	      add_b[i]= (i/3)*9+ (i%3) ;                 // 九宮格位置的加值
	}
	for(i=0;i<81;i++)
		for(j=0;j<9;j++)
			list[i][j]=true;	
}
	
int PrintSudoku(int *prn)
{// 印出數獨題目
	int i ;
	for(i=0; i<81; i++) 
	{
	      cout<<prn[i];
	      if(i%9==8) cout<<"\n";
	}
}
int Test1(int sp, int start, int *addnum ,int num)
{// 檢查指定的行、列、九宮格有沒有相同的數
	int test=0,i ,j ,sp1 ,num1 ;
	for(i=0; i<9; i++) 
       	{
		test=0;
	      	sp1= start+ addnum[i] ;
		for(j=0;j<9;j++)
		{
			if(sp1==sp)break;
			else if(list[sp1][j]==true)
			{
				num1==j;
				test++;
			}
		}
		if(sp!=sp1&&test==1&&num==num1)
			return 1;
		if(num==sudoku[sp1])
			return 1;
	}
	return 0;
}
int Test(int sp ,int num) 
{// 檢查同行、列、九宮格有沒有相同的數
	int test= 0 ;
	if(!test) test= Test1(sp, st_r[sp], add_r ,num) ;   // 檢查同列有沒有相同的數字
	if(!test) test= Test1(sp, st_c[sp], add_c ,num) ;   // 檢查同行有沒有相同的數字
	if(!test) test= Test1(sp, st_b[sp], add_b ,num) ; // 檢查同九宮格有沒有相同的數字
	return(test) ;
}
void Correct(int sp ,int start ,int *addnum ,int num)
{
	int i ,sp1;
	for(i=0;i<9;i++)
	{
		sp1=start+addnum[i];
		list[sp1][num]=false;
	}
}
void Correct_list(int sp ,int num) 
{// 檢查同行、列、九宮格有沒有相同的數
	Correct(sp, st_r[sp], add_r ,num) ;   // 檢查同列有沒有相同的數字
	Correct(sp, st_c[sp], add_c ,num) ;   // 檢查同行有沒有相同的數字
	Correct(sp, st_b[sp], add_b ,num) ; // 檢查同九宮格有沒有相同的數字
}
int Sudoku() 
{
	int i ,sp ,num;                    // 取得第一個空白的位置開始填入數字	
 	srand(time(NULL)); 
	for(i=0;i<N;i++)
        {
		sp=rand()%81;
		num=rand()%9+1;
            	if(!Test(sp ,num))
		{	
			sudoku[sp]=num;
			Correct_list(sp ,num);
		}
	}
	for(i=0;i<81;i++)
	{
		cout<<sudoku[i]<<" ";
		if(i%9==8)cout<<"\n";
	}
}
int main()
{
	int i ;
	for(i=0;i<81;i++)sudoku[i]=0;
	cout<<"------------------\n";
	Init() ;                                     // 參數設定
	Sudoku() ;                                   // 題目設定
	//PrintSudoku(sudoku) ;                        // 印出
	cout<<"------------------\n";
}
    
