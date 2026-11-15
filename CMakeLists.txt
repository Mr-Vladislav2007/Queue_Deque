cmake_minimum_required(VERSION 3.10)
project(Queue_Deque LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB queue ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(QueueApp ${queue})

target_include_directories(QueueApp PRIVATE include)

enable_testing()
include(FetchContent)

# Скачиваем стабильную версию GTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE  # <--- ДОБАВИТЬ ВОТ ЭТУ СТРОКУ
)

# Для Windows: предотвращаем конфликт библиотек CRT
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Собираем файлы тестов
file(GLOB test_sources ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)

# Создаем отдельный исполняемый файл для тестов
add_executable(QueueTests ${test_sources})

# Линкуем GTest и подключаем папку include (где лежат QueueList.h и TForwardList.h)
target_link_libraries(QueueTests PRIVATE GTest::gtest_main)
target_include_directories(QueueTests PRIVATE include)

# Автоматическая регистрация тестов в CTest
include(GoogleTest)
gtest_discover_tests(QueueTests)