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