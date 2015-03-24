#include<iostream>
#include<string>
#include"class.h"
using namespace std;

void BMI::set(float a ,float b){high=a/100;weight=b;}
void BMI::bmi(){average= weight/(high*high);}
void BMI::putname()
{
	if(average<15)name="Very severly underweight";
	if(average>15&&average<16)name="Severly underweight";
	if(average>16&&average<18.5)name="Underweight";
	if(average>18.5&&average<25)name="Normal";
	if(average>25&&average<30)name="Overage";
	if(average>30&&average<35)name="Obese Class 1 (Moderately obese)";
	if(average>35&&average<40)name="Obese Class 2 (Moderately obese)";
	if(average>=40)name="Obese Class 3 (Moderately obese)";
}
float BMI::get_average(){return average;}
string BMI::get_name(){return name;}

