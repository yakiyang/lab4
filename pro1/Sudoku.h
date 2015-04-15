#include<iostream>
using namespace std;
class Sudoku
{
public:
	static const int size_su = 144;
	static const int size_r = 12;
	static const int size_c = 12;
	static const int size_b = 9;
	void GiveQuestion();
	void ReadIn();
	void Solve();
	void Init();
	void check1();
	void check2(int);
	void check3(int ,int ,int* ,int);
	void check4(int*);
	int check5(int ,int*);
	int check6(int ,int ,int* ,int ,int*);
	bool cellpossiblenum[size_su][9];
	int st_r[size_su] ;                                // 列位置的起點
	int st_c[size_su] ;                                // 行位置的起點
	int st_b[size_su] ;                                // 九宮格位置的起點
	int add_r[size_r] ;                           // 列位置的加值
	int add_c[size_c] ;                                   // 行位置的加值
	int add_b[size_b] ;
	int T;
	int t;
private:
	int map[size_su];	
};





