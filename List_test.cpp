#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
using namespace std;
void test01()
{
	list<int> lt1;
	list<int> lt2(10, 1);
	vector<int> v1 = { 1,2,3,4,5,6 };
	list<int> lt3 (v1.begin(), v1.end());
	for (auto e : lt3)
	{
		cout << e<<" ";
	}
	cout << endl;
}
int main()
{
	test01();
	int main();
	
}