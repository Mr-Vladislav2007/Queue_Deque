

#ifndef T_FORWARD_LIST_
#define T_FORWARD_LIST_

#include <iostream>
#include <stdexcept>

using namespace std;


template<class T>
class TForwardList											
{
	struct Node												// вспомогательная структура для списка (ячейка)
	{
		T value;											// значение ячейки
		Node* next;											// указатель на следующую ячейку

		Node(const T& val, Node* nxt = nullptr) : value(val), next(nxt) {}
	};


	Node* first;											// указатель на первый элемент списка
	Node* last;												// указатель на последний элемент списка
	int size;												// размер списка

public:
	TForwardList();											// конструктор по умолчанию
	TForwardList(const T* arr, int n);						// конструктор из динамического массива
	TForwardList(const TForwardList<T>& other);				// конструктор копирования
	TForwardList& operator=(const TForwardList<T>& other);	// оператор присваивания
	~TForwardList();										// деструктор

	void Push_Front(const T& val);							// добавление в начало
	void Push_Back(const T& val);							// добавление в конец
						
	void Pop_Front();										// удаление из начала
	void Pop_Back();										// удаление с конца

	void InsertAt(int index, const T& val);					// добавление на позицию index
	void RemoveAt(int index);								// удаление с позиции index

	void Clear();											// очистка списка

	T& operator[](int index);								// возвращение элемента на позиции index
	T Front() const;										// возвращение первого элемента
	T Back() const;											// возвращение последнего элемента
	bool IsEmpty() const;									// проверка списка на пустоту
	int Size() const;										// текущий размер списка


	friend ostream& operator<<(ostream& os, const TForwardList<T>& list)
	{
		Node* tmp = list.first;
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
TForwardList<T>::TForwardList(const T* arr, int n) : first(nullptr), last(nullptr), size(0)
{
	for (int i = n - 1; i >= 0; --i)
	{
		Node* NewElem = new Node(arr[i], nullptr);
		Node* tmp = first;

		if (tmp != nullptr)
		{
			first = NewElem;
			NewElem->next = tmp;
		}
		else
		{
			first = NewElem;
			last = NewElem;
		}
		++size;
	}
}


template<class T>
TForwardList<T>::TForwardList(const TForwardList<T>& other) : first(nullptr), last(nullptr), size(other.size)
{
	Node* tmp = other.first;
	if (tmp != nullptr)
	{
		Node* NewElem = new Node(tmp->value, nullptr);
		first = NewElem;
		Node* NewList = first;

		for (tmp = tmp->next; tmp != nullptr; tmp = tmp->next)
		{
			NewElem = new Node(tmp->value, nullptr);
			NewList->next = NewElem;
			NewList = NewElem;
		}
		last = NewElem;
	}
}


template<class T>
TForwardList<T>& TForwardList<T>::operator=(const TForwardList<T>& other)
{
	if (this == &other)
		return *this;

	Clear();

	Node* tmp = other.first;
	size = other.size;

	if (tmp != nullptr)
	{
		Node* NewElem = new Node(tmp->value, nullptr);
		first = NewElem;
		Node* NewList = first;

		for (tmp = tmp->next; tmp != nullptr; tmp = tmp->next)
		{
			NewElem = new Node(tmp->value, nullptr);
			NewList->next = NewElem;
			NewList = NewElem;
		}
		last = NewElem;
	}

	return *this;
}


template<class T>
TForwardList<T>::~TForwardList()
{
	Clear();
}


template<class T>
void TForwardList<T>::Push_Back(const T& val)						// добавление в конец
{
	Node* New = new Node(val, nullptr);
	if (last == nullptr)
		first = last = New;
	else
	{
		last->next = New;
		last = New;
	}

	++size;
}


template<class T>
void TForwardList<T>::Push_Front(const T& val)						// добавление в начало
{
	Node* New = new Node(val, first);
	first = New;
	if (last == nullptr)
		last = New;

	++size;
}


template<class T>
void TForwardList<T>::Pop_Front()									// удаление из начала
{
	if (first == nullptr)
		return;

	Node* tmp = first;
	first = first->next;
	delete tmp;

	if (first == nullptr)
		last = nullptr;

	--size;
}


template<class T>
void TForwardList<T>::Pop_Back()									// удаление с конца
{
	if (first == nullptr)
		return;

	if (first == last)
	{
		delete first;
		first = nullptr;
		last = nullptr;
		--size;
		return;
	}

	Node* tmp = first;
	for (int i = 0; i < size - 2; i++)
		tmp = tmp->next;

	delete last;
	last = tmp;
	last->next = nullptr;
	--size;
}


template<class T>
void TForwardList<T>::InsertAt(int index, const T& val)				// добавление на позицию index
{
	if (index < 0 || index > size)
		return;
	if (index == 0)
	{
		Push_Front(val);
		return;
	}
	if (index == size)
	{
		Push_Back(val);
		return;
	}

	Node* tmp = first;
	for (int i = 0; i < index - 1; i++)
		tmp = tmp->next;

	Node* NewElem = new Node(val, tmp->next);
	tmp->next = NewElem;
	++size;
}


template<class T>
void TForwardList<T>::RemoveAt(int index)							// удаление с позиции index
{
	if (index < 0 || index >= size)
		return;

	if (index == 0)
	{
		Pop_Front();
		return;
	}

	if (index == size - 1)
	{
		Pop_Back();
		return;
	}

	Node* tmp = first;

	for (int i = 0; i < index - 1; i++)
		tmp = tmp->next;

	Node* toDelete = tmp->next;
	tmp->next = toDelete->next;

	delete toDelete;
	--size;
}


template<class T>
void TForwardList<T>::Clear()										// очистка списка
{
	Node* next_elem = first;
	Node* tmp;

	while (next_elem != nullptr)
	{
		tmp = next_elem->next;
		delete next_elem;
		next_elem = tmp;
	}

	first = nullptr;
	last = nullptr;
	size = 0;
}


template<class T>
T& TForwardList<T>::operator[](int index)							// возвращение элемента на позиции index
{
	if (index >= 0 && index < size)
	{
		Node* tmp = first;
		for (int i = 0; i < index; i++)
			tmp = tmp->next;

		return tmp->value;
	}
	throw std::out_of_range("Index out of range");
}


template<class T>
T TForwardList<T>::Front() const
{
	if (first != nullptr)
		return first->value;
	throw std::underflow_error("List is empty");
}


template<class T>
T TForwardList<T>::Back() const
{
	if (last != nullptr)
		return last->value;
	throw std::underflow_error("List is empty");
}


template<class T>
bool TForwardList<T>::IsEmpty() const
{
	return size == 0;
}


template<class T>
int TForwardList<T>::Size() const
{
	return size;
}


#endif