#include<iostream>
using namespace std;
int main()
{	int i ,N=22;
	for(i=0;;i++)
	{
		if(N==1)break;
		else if(N>=2)
		{
			if(!(N%2))N=N/2;
			else if(N%2)N=3*N+1;
		}
	cout<<N<<endl;
	}
}

