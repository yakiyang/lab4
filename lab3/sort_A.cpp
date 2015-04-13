#include<vector>
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int i;
	ifstream in("file.in" ,ios::in);
 	int size;
	in>>size;
 	int init_array[size];
	for(i=0;i<size;i++)
		in>>init_array[i];
	vector<int> v(size);
 	int insert, moveItem;

 	cout << "Unsorted array:\n";
 	for(int i=0; i<size; ++i)
 	{
 		v.at(i) = init_array[i];
 		cout << setw(4) << v.at(i);
 	}
 	cout << endl;
 	for(int next=1;next<size;++next)
 	{
 		insert = v.at(next);
 		moveItem = next;
 		while((moveItem>0) &&(v.at(moveItem-1) > insert))
 		{
 			v.at(moveItem) = v.at(moveItem-1);
 			--moveItem;
 		}
 		v.at(moveItem) = insert;
 		for(int i=0; i<size; ++i)
 		cout << setw(4) << v.at(i);
 		cout << endl;
 	}
	int sum=0;
	for(i=size-1;i>=(size-5);i--)
		sum=sum+v.at(i);
	cout<<sum<<endl;
	return 0;
}

