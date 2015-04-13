 #include <vector>
 #include <algorithm>
 #include <iostream>
 #include <cstdlib>
 #include "clock_B.h"
 using namespace std;
 void insertion_sort(vector<int> & v)
 {
 	int insert, moveItem;
 	for(int next=1;next<v.size();++next)
 	{
 		insert = v.at(next);
		moveItem = next;
		while((moveItem>0) &&(v.at(moveItem-1) > insert))
 		{
			v.at(moveItem) = v.at(moveItem-1);
 			--moveItem;
 		}
 		v.at(moveItem) = insert;
   	}
}
int main()
{
 	Clock clk;
 	const int size1 = 1000;
 	const int size2 = 10000;
 	const int size3 = 100000;
 	const int size4 = 1000000;
 	vector<int> v1(size1),v2;
 	srandom(time(NULL));
 	for(int i=0; i<size1; ++i)
 		v1.at(i) = random();
 	v2 = v1; clk.start();
 	sort(v1.begin(), v1.end());
 	cout<<"size="<<size1<<endl;
	cout << "sort(): " <<
	clk.getElapsedTime() << " seconds\n";
 	cout << "v1/v2 are "<<((v1==v2)?"the same.\n":"different.\n");
 	clk.start();
 	insertion_sort(v2);
 	cout << "insertion_sort(): " <<clk.getElapsedTime() << " seconds\n";
 	cout << "v1/v2 are "<<((v1==v2)?"the same.\n":"different.\n");
 	cout<<endl;
	vector<int> v3(size2),v4;
 	for(int i=0; i<size2; ++i)
 		v3.at(i) = random();
 	v4 = v3; clk.start();
 	sort(v3.begin(), v3.end());
 	cout<<"size="<<size2<<endl;
 	cout << "sort(): " <<
	clk.getElapsedTime() << " seconds\n";
 	cout << "v1/v2 are "<<((v3==v4)?"the same.\n":"different.\n");
 	clk.start();
 	insertion_sort(v4);
 	cout << "insertion_sort(): " <<clk.getElapsedTime() << " seconds\n";
 	cout<<endl;
	vector<int> v5(size3),v6;
 	for(int i=0; i<size3; ++i)
 		v5.at(i) = random();
 	v6 = v5; clk.start();
 	sort(v5.begin(), v5.end());
 	cout<<"size="<<size3<<endl;
 	cout << "sort(): " <<
	clk.getElapsedTime() << " seconds\n";
 	cout << "v1/v2 are "<<((v5==v6)?"the same.\n":"different.\n");
 	clk.start();
 	insertion_sort(v6);
 	cout << "insertion_sort(): " <<clk.getElapsedTime() << " seconds\n";
 	cout<<endl;
	vector<int> v7(size4),v8;
 	for(int i=0; i<size4; ++i)
 		v7.at(i) = random();
 	v8 = v7; clk.start();
 	sort(v7.begin(), v7.end());
 	cout<<"size="<<size4<<endl;
 	cout << "sort(): " <<
	clk.getElapsedTime() << " seconds\n";
 	cout << "v1/v2 are "<<((v7==v8)?"the same.\n":"different.\n");
 	clk.start();
 	insertion_sort(v8);
 	cout << "insertion_sort(): " <<clk.getElapsedTime() << " seconds\n";
 	return 0;
 }
