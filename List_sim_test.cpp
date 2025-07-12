#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
namespace yiming
{
	template<class T>
	void print(const list<T>&lt)//���ʵ��ָ������ݲ����޸õ����ܶ�it���в�����
	{
		typename list<T>::const_iterator it = lt.begin();//��ģ��δʵ����������ȥ��ģ�����Һ���Ķ���,typename���߱����������Ͷ��Ǿ�̬��Ա����
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test01()
	{
		yiming::list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int>::iterator it = lt.begin();
		lt.insert(it, 10);
		lt.push_back(6);
		lt.push_front(3);
		print(lt);
		yiming::list<int> lt2(lt);
		print(lt2);
		yiming::list<int> lt3={ 1,2,3,4,5 };
		print(lt3);
		
	}
}
int main()
{
	yiming::test01();
	return 0;
}