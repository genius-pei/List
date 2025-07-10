#pragma once
#include<iostream>
#include<list>
using namespace std;
namespace yiming
{
	template<class T>
	struct list_node//当不考虑用访问限定符做限制，所有成员公有的情况下，可以使用struct
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
	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{

		}
		T& operator*()
		{
			return _node->_data;
		}
		list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		bool operator!=(const list_iterator<T>& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
		typedef list_node<T> Node;
		
	public:
		typedef list_iterator<T> iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			
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

	private:
		Node* _head;
	};
}
