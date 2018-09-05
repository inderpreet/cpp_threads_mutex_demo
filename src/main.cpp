/**
*   \description Entry Point File
*/

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>

#include "threads1.h"
#include "threads2.h"
#include <mutex1.h>

using namespace std;

int main(void){

    printHello();
    //testStdThreads();
    //testThreads(NUM_THREADS);

    //testMutex1();
    testMutex2();
    return 0;
}