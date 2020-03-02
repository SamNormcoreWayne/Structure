#include <iostream>
#include <thread>
#include <future>
#include <atomic>

/*
 * Compile command: g++ -std=c++17 -pthread -O2 <filename> SUCCESS?
 * Thread_1 poll thread2
 * in thread2 change global var flag to true;
 */

std::atomic<bool> flag = false;

struct Type
{
    int data = 0;
    void update()
    {
        std::cout << "Hey! I am Type::update()" << std::endl;
        this->data += 1;
    }
    Type(int a) : data(a)
    {}
};

void thread2_func(struct Type* value){
    value->update();
    flag = true;
    std::cout << "in thread2: " << flag << std::endl;
    return;
}

void thread1_func(std::promise<int> &obj){
    flag = false;
    struct Type* value = new Type(3);
    std::cout << "In thread1 b4 while: " << flag << std::endl;
    std::thread thread_2(thread2_func, value);
    while(true)
    {
        if (flag == true)
        {
            std::cout << "In while: " << value->data << std::endl;
            break;
        }
    }
    thread_2.join();
    if (nullptr != value)
    {
        delete value;
    }
    obj.set_value(0);
    return;
}

int main(int argc, char*argv[])
{
    std::promise<int> obj;
    std::future<int> futureObj = obj.get_future();
    std::thread thread_1(thread1_func, std::ref(obj));
    thread_1.join();
    return 0;
}   