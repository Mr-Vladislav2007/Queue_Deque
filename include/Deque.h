

#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>

template<class T>
class Deque
{
private:
	T* pMem;
	int max_size;
	int start;
	int finish;
	int size;

public:
	Deque(int n);
	~Deque();

	void Push_Front(const T& val);
	void Push_Back(const T& val);

	void Pop_Front();
	void Pop_Back();

	T Front() const;
	T Back() const;
	bool IsEmpty() const;
};


template<class T>
Deque<T>::Deque(int n) : max_size(n), size(0)
{
	pMem = new T[max_size];
	start = max_size / 2;
	finish = max_size / 2;
}


template<class T>
Deque<T>::~Deque()
{
	delete[] pMem;
}


template<class T>
void Deque<T>::Push_Front(const T& val)
{
	if (start > 0)
	{
		--start;
		pMem[start] = val;
		++size;
	}
}


template<class T>
void Deque<T>::Push_Back(const T& val)
{
	if (finish < max_size - 1)
	{
		++finish;
		pMem[finish] = val;
		++size;
	}
}


template<class T>
void Deque<T>::Pop_Front()
{
	if (!IsEmpty())
	{
		++start;
		--size;
	}
}


template<class T>
void Deque<T>::Pop_Back()
{
	if (!IsEmpty())
	{
		--finish;
		--size;
	}
}


template<class T>
T Deque<T>::Front() const
{
	if (!IsEmpty())
		return pMem[start];
}


template<class T>
T Deque<T>::Back() const
{
	if (!IsEmpty())
		return pMem[finish];
}


template<class T>
bool Deque<T>::IsEmpty() const
{
	return size == 0;
}



#endif