/**
*   \Description Program to test Mutexes
*/
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <threads1.h>
#include <cstdlib>
#include <unistd.h>


void *PrintHello(void *threadid){
    long tid;
    tid = (long)threadid;
    printf("Hello From Thread: %ld\n", tid);
    pthread_exit(NULL);
}

void *wait(void *t){
    long tid;
    tid = (long)t;

    sleep(3);
    printf("Sleeping with thread\n\rExiting id: %ld\n\r", tid);
    pthread_exit(NULL);
}

void testThreads(long num_threads){
    pthread_t threads[num_threads*2];
    pthread_attr_t attr;
    void *status;
    int rc;
    long i;

    // joinable threads
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


    for(i=0; i<num_threads; i++){
        printf("main() : Creating Threads: %ld\n", i);
        // pthread_create(thread_id, attributes, start_routine, argument_to_routine)
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
        if(rc){
            printf("Error creating Thread %d\n", rc);
            exit(-1);
        }

        rc = pthread_create(&threads[i+num_threads], &attr, wait, (void *)i);
        if(rc){
            printf("Error creating Thread %d\n", rc);
            exit(-1);
        }
    }


    pthread_attr_destroy(&attr);
    for (i=0; i<num_threads; i++){
        // Join Threads
        rc = pthread_join(threads[i+num_threads], &status);
        if(rc){
            printf("Unable to Join: %d\n\r", rc);
            exit(-1);
        }
        printf("Joining thread : %ld\n\r", i);
    }
    pthread_exit(NULL);

}

void printHello(void){
    printf("Testing Threads...\n\r\n\r");
}
