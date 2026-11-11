#include <iostream>
#include <string>

#include "QueueList.h"
#include "Queue.h"
#include "Deque.h"

using namespace std;

int main() 
{
    // =========================================================
    // 1. ТЕСТ ОЧЕРЕДИ НА СПИСКЕ (QueueList FIFO)
    // =========================================================
    cout << "--- 1. QueueList (Linked List) ---\n";
    QueueList<string> qList;

    qList.Push("First");
    qList.Push("Second");
    qList.Push("Third");

    cout << "Front: " << qList.Front() << "\n"; // Первый
    cout << "Size:  " << qList.size() << "\n";

    qList.Pop();
    cout << "After Pop -> Front: " << qList.Front() << "\n"; // Второй
    cout << "Size: " << qList.size() << "\n\n";


    // =========================================================
    // 2. ТЕСТ КОЛЬЦЕВОЙ ОЧЕРЕДИ НА МАССИВЕ (Queue)
    // =========================================================
    cout << "--- 2. Array Queue (Circular) ---\n";
    Queue<int> qArr(3); // Вместимость 3

    qArr.Push(10);
    qArr.Push(20);
    qArr.Push(30);
    cout << "Is Full? " << boolalpha << qArr.IsFull() << "\n"; // true

    qArr.Push(40); // Проигнорируется, так как нет места
    cout << "Top (first element): " << qArr.Top() << "\n"; // 10

    qArr.Pop(); // Убрали 10
    qArr.Pop(); // Убрали 20
    qArr.Push(40); // Встает на место 10 (кольцевой эффект)
    qArr.Push(50); // Встает на место 20

    cout << "Top after shifts: " << qArr.Top() << "\n"; // 30
    cout << "Is Full? " << qArr.IsFull() << "\n\n";


    // =========================================================
    // 3. ТЕСТ ДЕКА НА МАССИВЕ (Deque)
    // =========================================================
    cout << "--- 3. Array Deque ---\n";
    Deque<char> deque(10);

    // Добавляем в середину, затем расширяем в обе стороны
    deque.Push_Back('M');   // Middle
    deque.Push_Front('L');  // Left
    deque.Push_Back('N');   // Next (Right)
    deque.Push_Front('K');  // K

    cout << "Deque Front: " << deque.Front() << "\n"; // K
    cout << "Deque Back:  " << deque.Back() << "\n";  // N

    // Удаляем с обоих концов
    deque.Pop_Front(); // Убрали K
    deque.Pop_Back();  // Убрали N

    cout << "After pops -> Front: " << deque.Front()
        << ", Back: " << deque.Back() << "\n"; // L, M

    cout << "\n=== QUEUE TESTS FINISHED ===\n";
    return 0;
}