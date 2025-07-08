#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
void test01()
{
	list<int> lt1;
	list<int> lt2(10, 1);
	vector<int> v1 = { 1,2,3,4,5,6 };
	list<int> lt3 (v1.begin(), v1.end());
	list<int>lt4 = { 1,2,4,4,6,3 };
	int a[] = { 1,2,3,4 };
	list<int>lt5(lt2.begin(),lt2.end());
	for (auto e : lt3)
	{
		cout << e<<" ";
	}
	cout << endl;
	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : lt5)
	{
		cout << e << " ";
	}
	cout << endl;
	lt4.sort();
	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int>::iterator it5 = lt5.begin();
	while (it5 != lt5.end())
	{
		cout << *it5 << " ";
		++it5;
	}
	cout << endl;
}
int main()
{
	test01();
	int main();
	
}