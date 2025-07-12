#pragma once
#include<iostream>
#include<list>
using namespace std;
namespace yiming
{
	template<class T>
	struct list_node//���������÷����޶��������ƣ����г�Ա���е�����£�����ʹ��struct
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{

		}
	};
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{

		}
		~list_iterator()//����������Ҫ��������������
		{

		}
	    Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
	    Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
				_node = _node->_prev;
			return tmp;
		}
		bool operator==(const Self& it)const
		{
			return _node == it._node;
		}
		bool operator!=(const Self& it)const
		{
			return _node != it._node;
		}
	};
	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	Node* _node;
	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{

	//	}
	//	~list_const_iterator()//����������Ҫ��������������
	//	{

	//	}
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	list_const_iterator<T>& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	list_const_iterator<T>& operator++(int)
	//	{
	//		list_const_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	list_const_iterator<T>& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//	list_const_iterator<T>& operator--(int)
	//	{
	//		list_const_iterator<T> tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}
	//	bool operator==(const list_const_iterator<T>& it)const
	//	{
	//		return _node == it._node;
	//	}
	//	bool operator!=(const list_const_iterator<T>& it)const
	//	{
	//		return _node != it._node;
	//	}
	//};
	//
	template<class T>
	class list
	{
		typedef list_node<T> Node;
		
	public:
		typedef list_iterator<T,T&,T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const 
		{
			return const_iterator(_head);
		}
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			
		}
		~list()
		{
			iterator it = begin();
			while (it != end())
			{
				it= erase(it);
			}
			delete _head;
			_head = nullptr;
		}
		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;  // ����ԭʼǰ���ڵ�
			Node* newnode = new Node(val);

			// �����½ڵ�����
			newnode->_prev = prev;    // �� ��ָ��ԭʼǰ��
			newnode->_next = cur;     // �� ָ��ǰ�ڵ�

			// �������ڽڵ�
			prev->_next = newnode;    // ԭʼǰ�����½ڵ�
			cur->_prev = newnode;     // ��ǰ�ڵ���½ڵ�
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			cur->_next = next;
			cur->_prev = prev;
			delete cur;
			return iterator(next);
		}
	private:
		Node* _head;
	};
}
