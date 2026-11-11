

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>


template <class T>
class Queue
{
private:
	T* pMem;
	int max_size;
	int start;
	int finish;
	int size;

public:
	Queue(int n);
	~Queue();

	void Push(const T& val);
	void Pop();

	T Top();
	bool IsEmpty() const;
	bool IsFull() const;
};



template<class T>
Queue<T>::Queue(int n) : max_size(n), start(-1), finish(-1), size(0)
{
	pMem = new T[max_size];
}


template<class T>
Queue<T>::~Queue()
{
	delete[] pMem;
}


template<class T>
void Queue<T>::Push(const T& val)
{
	if (!IsFull())
	{
		finish = (finish + 1) % max_size;
		pMem[finish] = val;
		if (start == -1)
		{
			start = finish;
		}

		++size;
	}
}


template<class T>
void Queue<T>::Pop()
{
	if (!IsEmpty())
	{
		if (start == finish)
		{
			start = -1;
			finish = -1;
		}
		else
			start = (start + 1) % max_size;
		--size;
	}
}


template<class T>
T Queue<T>::Top()
{
	if (!IsEmpty())
	{
		return pMem[start];
	}
}


template<class T>
bool Queue<T>::IsEmpty() const
{
	return size == 0;
}

template<class T>
bool Queue<T>::IsFull() const
{
	return size == max_size;
}


#endif