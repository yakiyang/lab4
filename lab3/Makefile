Sort_a:sort_A.cpp
	g++ -o Sort_a sort_A.cpp
Sort_b:sort_B.o clock_B.o
	g++ -o Sort_b sort_B.o clock_B.o
sort_B.o:sort_B.cpp clock_B.h
	g++ -c sort_B.cpp
clock_B.o:clock_B.cpp clock_B.h
	g++ -c clock_B.cpp
clean:
	rm sort_B *.o
	rm clock_B *.o
