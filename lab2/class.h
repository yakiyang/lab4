#include<iostream>
#include<string>
#ifndef CLASS_H
#define CLASS_H
using namespace std;
class BMI
{public:
	void set(float ,float);
	void bmi();
	void putname();
	float get_average();
	string get_name(); 
 private:
	float high;
	float weight;
	float average;
	string name;
};
#endif




