#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"class.h"
using namespace std;

int main()
{
	float high ,weight ,a;
	string n;
	BMI b;
	ifstream inFile("file.in" ,ios::in);
	ofstream outFile("file.out" ,ios::out);
	if(!inFile)
	{
		cerr<<"Fail Opening"<<endl;
		exit(1);
	}
	if(!outFile)
	{
		cerr<<"Fail Opening"<<endl;
		exit(1);
	}
	while(inFile>>high>>weight)
	{
		b.set(high ,weight);
		b.bmi();
		b.putname();
		a=b.get_average();
		n=b.get_name();
		outFile<<a<<"\t"<<n<<"\n"<<endl;
	}
	return 0;
}

	
