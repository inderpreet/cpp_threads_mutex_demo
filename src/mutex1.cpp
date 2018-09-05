#include <mutex1.h>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <map>


// using namespace std;
int counter;

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;
std::mutex cntr;

// Uses a mutex lock to increment a global variable
void safeIncrement(int t){
    int i;
    i=5;
    while(i!=0){
        if(cntr.try_lock() == true){
            counter++;
            std::cout<<counter<<"\n\r";
            i--;
            cntr.unlock();
        } else {
            std::cout<<"lock failed\n\r";
        }
        std::this_thread::sleep_for(std::chrono::seconds(t));
    }
}

// creates two threads and then lets them increment them at different intervals.
void testMutex2(void){
    std::cout<<"Testing Mutex 2 - Locks should fail sometimes. Each thread will increment 5 times"<<"\n\r";

    std::thread t1(safeIncrement, 1);
    std::thread t2(safeIncrement, 1);
    t1.join();
    t2.join();

    std::cout<<"final count :"<<counter<<"\n\r";
}

void save_page(const std::string &url){
    std::string result = "fake Content";

    // lock_guard guard is a better way of using mutexes
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    g_pages[url] = result;
}

void testMutex1(void){
    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");
    t1.join();
    t2.join();

    for(const auto &pair : g_pages){
        std::cout<<pair.first << " => " << pair.second << "\n\r";
    }
}

