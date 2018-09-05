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
#include <arrays.h>
#include <vectors.h>

using namespace std;

int main(void){

    printHello();

    // Code to test threads
    //testStdThreads();
    //testThreads(NUM_THREADS);

    // Code to test mutex
    //testMutex1();
    //testMutex2();
    
    // Code for std::array
    //testArrays();
    //testArrays2();
    // testArrays3();
    testVectors();

    return 0;
}