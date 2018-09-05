# Experiments with threads

This respository contains experiements with the pthreads.

## Description

Before I forget what I did, here is the low down.

threads1.cpp - This file is a simple demo of pthreads. Technically this is what I am familiar with since this is runs on C and embedded devices such as the TI CC3200 and other arm controllers.

threads2.cpp - This file contains a demo app with CPP threads. I added the flags to the make file so that it would compile without hiccups.

mutex1.cpp - This file contains a demo of mutexs and locks. There is one example I got from the internet which uses the lock_guard guard which means it automatically unlocks the mutex once the block ends. The other uses lock unlock which I wrote as a test and is typical in an embedded environment.

arrays.cpp - This file experiments with std::array<type, length> name ; fixed size arrays

## Commands

make clean - cleans

make - Compiles

make run - runs the binary

## Authors
- Inderpreet Singh

## License
GPLv2 - Copy it at your own risk and attribute the original author always.