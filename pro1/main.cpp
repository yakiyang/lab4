#include<iostream>
#include"Sudoku.h"
using namespace std;
int main()
{
	Sudoku t;
	t.GiveQuestion();
	t.ReadIn();
	t.Solve();
	return 0;
}

