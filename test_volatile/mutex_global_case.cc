#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>

/*
 * Compile command: g++ -std=c++17 -pthread -O2 <filename> SUCCESS?
 * Thread_1 use mutex on global var
 * in thread2 lock mutex and change var;
 */

std::mutex m;
std::condition_variable cv;

bool flag = false;

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
    std::lock_guard<std::mutex> lock(m);
    value->update();
    flag = true;
    std::cout << "in thread2: " << flag << std::endl;
    cv.notify_one();
    return;
}

void thread1_func(std::promise<int> &obj){
    flag = false;
    struct Type* value = new Type(3);
    std::cout << "In thread1 b4 lock: " << flag << std::endl;
    std::thread thread_2(thread2_func, value);
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, [](){ return flag; });
    std::cout << "In thread1 after lock: " << value->data << std::endl;
    lock.unlock();
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