#include <threads2.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <unistd.h>

//using namespace std;

// Timerkeeper thread. Ends after i seconds
void task1(void){
    int i;
    i=4;
    printf("Creating Thread for timer...\n\r");
    while(i!=0){
        i--;
        printf("\n\rTime: %d \n\r", i);    
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void task2(void){
    printf("\n\rCreating Task 2... Sleeping.\n\r");
    sleep(5);
    printf("Task 2 is awake... ending...\n\r");
}

void testStdThreads(void){

    std::thread helper1(task1);
    std::thread helper2(task2);

    // The Join threads...
    helper1.join();
    helper2.join();

    // detach threads...
    // helper1.detach();
    // helper2.detach();

    //printf("\n\nJoined\n\r");
}
