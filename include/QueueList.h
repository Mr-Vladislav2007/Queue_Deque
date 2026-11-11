

#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "List.h"


template<class T>
class QueueList
{
private:
	List<T> list;

public:
	void Push(const T& val);
	void Pop();

	T Front() const;
	T Back() const;
	bool IsEmpty() const;
	size_t size() const;
};


template<class T>
void QueueList<T>::Push(const T& val)
{
	list.PushBack(val);
}


template<class T>
void QueueList<T>::Pop()
{
	if (!list.IsEmpty())
		list.RemoveAt(0);
}


template<class T>
T QueueList<T>::Front() const
{
	return list.Front();
}


template<class T>
T QueueList<T>::Back() const
{
	return list.Back();
}


template<class T>
bool QueueList<T>::IsEmpty() const
{
	return list.IsEmpty();
}


template<class T>
size_t QueueList<T>::size() const
{
	return list.Size();
}



#endif