#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
namespace yiming
{
	void test01()
	{
		yiming::list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
	}
}
int main()
{
	yiming::test01();
	return 0;
}