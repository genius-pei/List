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
void test02()
{
	list<int> l1(10, 1);
	l1.push_back(6);
	l1.push_front(6);
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;

	l1.resize(8, 3);
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;

}
void test03()
{
	srand(time(0));
	const int N = 100000;
	list <int> lt1;
	vector<int> v;
	for (int i = 0;i < N;++i)
	{
		auto e = rand() + i;
		lt1.push_back(e);
		v.push_back(e);
	}
	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	lt1.sort();
	int end2 = clock();
	printf("vector sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);


}
void test04()
{
	list<double> lt1 = { 1,2,3,4,5 };
	auto it = find(lt1.begin(), lt1.end(), 3);
	lt1.splice(lt1.begin(), lt1, it,next(it,2));
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	int main();
	
}