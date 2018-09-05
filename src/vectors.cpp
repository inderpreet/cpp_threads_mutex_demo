#include <vectors.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// using namespace std;

void testVectors(void){
    std::vector<int> intVec = {1, 2, 4, 3, 5 };

    for(std::vector<int>::iterator i=intVec.begin(); i!=intVec.end(); ++i)
        std::cout<<*i<< '\t';

    std::sort(intVec.begin(), intVec.end());
    std::reverse(intVec.begin(), intVec.end());

    // for(int &s : intVec)
    //     std::cout<< s << "\n";

    for(auto i=intVec.begin(); i!=intVec.end(); ++i)
        std::cout<<*i<<"\t";

    std::cout<<"\nending testVectors\n";
}

