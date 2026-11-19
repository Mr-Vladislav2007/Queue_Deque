#include "QueueList.h"
#include <gtest/gtest.h>
#include <string>

// ==========================================
// 1. Базовые тесты (Создание и состояние)
// ==========================================

TEST(QueueListTest, can_create_empty_queue) 
{
    ASSERT_NO_THROW(QueueList<int> q);
}

TEST(QueueListTest, new_queue_is_empty) 
{
    QueueList<int> q;
    EXPECT_TRUE(q.IsEmpty());
    EXPECT_EQ(0, q.size());
}

// ==========================================
// 2. Тесты добавления (Push) и просмотра (Front)
// ==========================================

TEST(QueueListTest, can_push_one_element) 
{
    QueueList<int> q;
    q.Push(10);
    EXPECT_FALSE(q.IsEmpty());
    EXPECT_EQ(1, q.size());
    EXPECT_EQ(10, q.Front());
}

TEST(QueueListTest, queue_follows_fifo_principle) 
{
    QueueList<int> q;
    q.Push(10);
    q.Push(20);
    q.Push(30);

    EXPECT_EQ(3, q.size());
    EXPECT_EQ(10, q.Front());

    q.Pop();
    EXPECT_EQ(20, q.Front());

    q.Pop();
    EXPECT_EQ(30, q.Front());
}

// ==========================================
// 3. Тесты удаления (Pop)
// ==========================================

TEST(QueueListTest, can_pop_element) 
{
    QueueList<int> q;
    q.Push(1);
    q.Pop();
    EXPECT_TRUE(q.IsEmpty());
    EXPECT_EQ(0, q.size());
}

TEST(QueueListTest, pop_on_empty_queue_does_not_crash) 
{
    QueueList<int> q;
    ASSERT_NO_THROW(q.Pop());
    EXPECT_TRUE(q.IsEmpty());
}

// ==========================================
// 4. Тесты исключений (Граничные случаи)
// ==========================================

TEST(QueueListTest, throws_when_getting_front_of_empty_queue) 
{
    QueueList<int> q;
    ASSERT_ANY_THROW(q.Front());
}

// ==========================================
// 5. Тесты копирования и присваивания (Rule of 3)
// ==========================================

TEST(QueueListTest, can_create_copied_queue) 
{
    QueueList<int> q;
    q.Push(1); q.Push(2);
    ASSERT_NO_THROW(QueueList<int> q1(q));
}

TEST(QueueListTest, copied_queue_is_equal_to_source_one) 
{
    QueueList<int> q;
    q.Push(10);
    q.Push(20);

    QueueList<int> q1(q);

    EXPECT_EQ(q.size(), q1.size());
    EXPECT_EQ(q.Front(), q1.Front());
}

TEST(QueueListTest, copied_queue_has_its_own_memory) 
{
    QueueList<int> q;
    q.Push(10); q.Push(20);

    QueueList<int> q1(q);
    q1.Pop();
    q1.Push(30);

    EXPECT_EQ(10, q.Front());
    EXPECT_EQ(2, q.size());

    EXPECT_EQ(20, q1.Front());
    EXPECT_EQ(2, q1.size());
}

TEST(QueueListTest, can_assign_queue_to_itself) 
{
    QueueList<int> q;
    q.Push(1); q.Push(2);

    q = q;

    EXPECT_EQ(2, q.size());
    EXPECT_EQ(1, q.Front());
}

TEST(QueueListTest, can_assign_queues_of_different_size) 
{
    QueueList<int> q;
    QueueList<int> q1;

    q.Push(1); q.Push(2);
    q1.Push(10); q1.Push(20); q1.Push(30);

    q = q1;

    EXPECT_EQ(3, q.size());
    EXPECT_EQ(10, q.Front());
}

// ==========================================
// 6. Тесты с другими типами данных (Шаблонность)
// ==========================================

TEST(QueueListTest, works_with_strings) 
{
    QueueList<std::string> q;
    q.Push("Hello");
    q.Push("World");

    EXPECT_EQ("Hello", q.Front());
    q.Pop();
    EXPECT_EQ("World", q.Front());
}

// ==========================================
// Тестирование класса TForwardList
// ==========================================

TEST(TForwardListTest, can_create_empty_list)
{
    TForwardList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
}


TEST(TForwardListTest, can_create_list_from_array)
{
    int arr[] = { 10, 20, 30 };
    TForwardList<int> list(arr, 3);

    EXPECT_EQ(3, list.Size());
    EXPECT_EQ(10, list.Front());
    EXPECT_EQ(30, list.Back());
}


TEST(TForwardListTest, copied_list_has_its_own_memory)
{
    TForwardList<int> list1;
    list1.Push_Back(1);
    list1.Push_Back(2);

    TForwardList<int> list2 = list1;
    list2.Pop_Front();
    list2.Push_Back(3);

    EXPECT_EQ(2, list1.Size());
    EXPECT_EQ(1, list1.Front());

    EXPECT_EQ(2, list2.Size());
    EXPECT_EQ(2, list2.Front());
}


TEST(TForwardListTest, can_assign_list_to_itself)
{
    TForwardList<int> list;
    list.Push_Back(5);

    list = list;

    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(5, list.Front());
}


TEST(TForwardListTest, can_push_front)
{
    TForwardList<int> list;
    list.Push_Front(20);
    list.Push_Front(10);

    EXPECT_EQ(2, list.Size());
    EXPECT_EQ(10, list.Front());
    EXPECT_EQ(20, list.Back());
}


TEST(TForwardListTest, can_push_back)
{
    TForwardList<int> list;
    list.Push_Back(10);
    list.Push_Back(20);

    EXPECT_EQ(2, list.Size());
    EXPECT_EQ(10, list.Front());
    EXPECT_EQ(20, list.Back());
}


TEST(TForwardListTest, can_pop_front)
{
    TForwardList<int> list;
    list.Push_Back(20);
    list.Push_Back(10);

    list.Pop_Front();

    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(10, list.Front());
}


TEST(TForwardListTest, can_pop_back)
{
    TForwardList<int> list;
    list.Push_Back(20);
    list.Push_Back(10);

    list.Pop_Back();

    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(20, list.Back());
}


TEST(TForwardListTest, pop_back_single_element_makes_list_empty)
{
    TForwardList<int> list;
    list.Push_Back(10);

    list.Pop_Back();

    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
}

TEST(TForwardListTest, pop_on_empty_does_not_crash)
{
    TForwardList<int> list;
    ASSERT_NO_THROW(list.Pop_Front());
    ASSERT_NO_THROW(list.Pop_Back());
    EXPECT_TRUE(list.IsEmpty());
}


TEST(TForwardListTest, can_insert_at_beginning_and_end)
{
    TForwardList<int> list;
    list.Push_Back(20);

    list.InsertAt(0, 10);
    list.InsertAt(2, 30);

    EXPECT_EQ(3, list.Size());
    EXPECT_EQ(10, list.Front());
    EXPECT_EQ(30, list.Back());
}


TEST(TForwardListTest, can_insert_middle)
{
    TForwardList<int> list;
    list.Push_Back(10);
    list.Push_Back(30);

    list.InsertAt(1, 20);

    EXPECT_EQ(3, list.Size());
    EXPECT_EQ(10, list[0]);
    EXPECT_EQ(20, list[1]);
    EXPECT_EQ(30, list[2]);
}


TEST(TForwardListTest, insert_at_invalid_index_does_nothing)
{
    TForwardList<int> list;
    list.Push_Back(10);

    list.InsertAt(-1, 5);
    list.InsertAt(5, 5);

    EXPECT_EQ(1, list.Size());
}


TEST(TForwardListTest, can_remove_at_middle)
{
    TForwardList<int> list;
    list.Push_Back(10);
    list.Push_Back(20);
    list.Push_Back(30);

    list.RemoveAt(1);
    
    EXPECT_EQ(2, list.Size());
    EXPECT_EQ(10, list[0]);
    EXPECT_EQ(30, list[1]);
}


TEST(TForwardListTest, can_remove_at_beginning_and_end)
{
    TForwardList<int> list;
    list.Push_Back(10);
    list.Push_Back(20);
    list.Push_Back(30);

    list.RemoveAt(0);
    list.RemoveAt(1);

    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(20, list.Front());
    EXPECT_EQ(20, list.Back());
}


TEST(TForwardListTest, remove_at_invalid_index_does_nothing)
{
    TForwardList<int> list;
    list.Push_Back(10);

    list.RemoveAt(-1);
    list.RemoveAt(5);

    EXPECT_EQ(1, list.Size());
}


TEST(TForwardListTest, can_clear_list)
{
    TForwardList<int> list;
    list.Push_Back(1);
    list.Push_Back(2);

    list.Clear();

    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
}


TEST(TForwardListTest, can_access_element_by_index)
{
    TForwardList<int> list;
    list.Push_Back(10);
    list.Push_Back(20);
    list.Push_Back(30);

    EXPECT_EQ(10, list[0]);
    EXPECT_EQ(20, list[1]);
    EXPECT_EQ(30, list[2]);

    list[1] = 99;
    EXPECT_EQ(99, list[1]);
}


TEST(TForwardListTest, throws_when_accessing_invalid_index)
{
    TForwardList<int> list;
    list.Push_Back(10);

    ASSERT_ANY_THROW(list[-1]);
    ASSERT_ANY_THROW(list[5]);
}


TEST(TForwardListTest, throws_when_getting_front_or_back_of_empty_list)
{
    TForwardList<int> list;

    ASSERT_ANY_THROW(list.Front());
    ASSERT_ANY_THROW(list.Back());
}