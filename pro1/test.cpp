#include<iostream>
#include<cstdlib>
using namespace std;
	
int sudoku[81] ;                                // 數獨題目陣列
int st_r[81] ;                                // 列位置的起點
int st_c[81] ;                                // 行位置的起點
int st_b[81] ;                                // 九宮格位置的起點
int add_r[9] ;                                   // 列位置的加值
int add_c[9] ;                                   // 行位置的加值
int add_b[9] ;                                   // 九宮格位置的加值
		
int Init() 
{// 參數設定
	int i ;
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
int check1(int sp, int start, int *addnum)
{// 檢查指定的行、列、九宮格有沒有相同的數
	int test= 0, i, sp1  ;
	for(i=0; i<9; i++) 
       	{
	      sp1= start+ addnum[i] ;
	      if(sp!=sp1 && sudoku[sp]==sudoku[sp1]) test++ ;
	}
	return(test) ;
}
int check(int sp) 
{// 檢查同行、列、九宮格有沒有相同的數
	int test= 0 ;
	if(!test) test= check1(sp, st_r[sp], add_r) ;   // 檢查同列有沒有相同的數字
	if(!test) test= check1(sp, st_c[sp], add_c) ;   // 檢查同行有沒有相同的數字
	if(!test) test= check1(sp, st_b[sp], add_b) ;   // 檢查同九宮格有沒有相同的數字
	return(test) ;
}
int Sudoku() 
{
	int sp=0;                    // 取得第一個空白的位置開始填入數字	
 	srand(time(NULL)); 
	do
        {
		sudoku[sp]=rand()%9+1 ;
            	if(check(sp)==0)
		{
			cout<<sudoku[sp]<<" ";
	      		if(sp%9==8) cout<<"\n";
			sp++;
		}
	} while(sp>=0 && sp<81) ;
}
int main()
{
	int j ,i ;
	for(i=0;i<81;i++)sudoku[i]=0;
	cout<<"------------------\n";
	Init() ;                                     // 參數設定
	Sudoku() ;                                   // 題目設定
	//PrintSudoku(sudoku) ;                        // 印出
	cout<<"------------------\n";
}
    
