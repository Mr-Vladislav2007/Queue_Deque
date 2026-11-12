

#ifndef T_FORWARD_LIST_
#define T_FORWARD_LIST_

#include <iostream>

using namespace std;


template<class T>
class TForwardList
{
	class Node
	{
		T value;
		Node* next;

	public:
		Node(T tmp) : value(tmp), next(nullptr);
	};


	Node* first;
	Node* last;
	size_t size;

public:
	TForwardList();
	~TForwardList();

	void Push_Back(const T& val);
	void Push_Front(const T& val);

	void Push(int ind, const T& val);
	void Pop(int ind);

	T Front() const;
	T Back() const;
	bool IsEmpty() const;
	size_t Size() const;


	friend ostream& operator<<(ostream& os, const TForwardList<T>& list)
	{
		Node<T>* tmp = list.first;
		os << "[";
		while (tmp != nullptr)
		{
			os << tmp->value;
			if (tmp->next != nullptr)
				os << ", ";
			tmp = tmp->next;
		}

		os << "]";
		return os;
	}
};


template<class T>
TForwardList<T>::TForwardList() : first(nullptr), last(nullptr), size(0) {}


template<class T>
TForwardList<T>::~TForwardList()
{
	Node* tmp = first;
	while (tmp != nullptr)
	{
		Node* tmp2 = tmp->next;
		delete[] tmp;
		tmp = tmp2;
	}
}


template<class T>
void TForwardList<T>::Push_Back(const T& val)
{
	Node<T>* tmp = new Node<T>(val);
	if (first == nullptr)
		first = last = tmp;
	else
	{
		last->next = tmp;
		last = tmp;
	}

	++size;
}


template<class T>
void TForwardList<T>::Push_Front(const T& val)
{
	Node<T>* tmp = new Node<T>(val);
	tmp->next = first;
	first = tmp;
	if (last == nullptr)
		last = tmp;

	++size;
}


template<class T>
void TForwardList<T>::Push(int ind, const T& val)
{
	if (ind < 0 || ind > (int)size)
		return;
	if (ind == 0)
	{
		Push_Front(val);
		return;
	}
	if (ind = (int)size)
	{
		Push_Back(val);
		return;
	}

	Node<T>* tmp = first;
	for (int i = 0; i < ind - 1; i++)
		tmp = tmp->next;

	Node<T>* tmp2 = new Node<T>(val);
	tmp2->next = tmp->next;
	tmp->next = tmp2;
	++size;
}


template<class T>
void TForwardList<T>::Pop(int idx)
{
	if (ind < 0 || ind >(int)size)
		return;

	Node<T>* tmp = first;

	if (ind == 0)
	{
		first = first->next;
		delete[] tmp;
		if (first == nullptr)
			last = nullptr;

		--size;
		return;
	}

	for (int i = 0; i < ind - 1; i++)
		tmp = tmp->next;

	Node<T>* tmp2 = tmp->next;
	tmp->next = tmp2->next;

	if (tmp2 == last)
		last = tmp;

	delete[] tmp2;
	--size;
}


template<class T>
T TForwardList<T>::Front() const
{
	if (first != nullptr)
		return first->value;
}


template<class T>
T TForwardList<T>::Back() const
{
	if (last != nullptr)
		return last->value;
}


template<class T>
bool TForwardList<T>::IsEmpty() const
{
	return size == 0;
}


template<class T>
size_t TForwardList<T>::Size() const
{
	return size;
}


#endif