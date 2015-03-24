BMI:BMI.o class.o 
	g++ -o BMI BMI.o class.o
BMI.o:BMI.cpp class.h
	g++ -c BMI.cpp
class.o:class.cpp class.h
	g++ -c class.cpp
clean:
	rm BMI*.o class*.o

