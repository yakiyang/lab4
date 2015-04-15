Sudoku:main.o Sudoku.o 
	g++ -o Sudoku main.o Sudoku.o
Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
main.o:Sudoku.cpp Sudoku.h
	g++ -c main.cpp
clear:
	rm Sudoku.o main.o
