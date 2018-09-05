#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
 
void testArrays3(void){
    std::array<int, 5> myList = {1,2,3,4,5};

    for(int &s : myList)
        std::cout<< s <<"\n";

}

void testArrays2(void){
    std::array<std::string, 10> mylist = {  "hello",
                                            "world",
                                            "test",
                                            "string",
                                            "new",
                                            "old",
                                            "seven",
                                            "eight",
                                            "nine",
                                            "ten"
                                            };
    std::sort(mylist.begin(), mylist.end());

    for(std::string &s: mylist)
        std::cout<< s << "\n\r";

    std::cout<<"No of elements :"<< mylist.size()<<"\n"<<mylist.at(9)<<"\n";

    std::cout<<"\n\n\n";
    for(auto i=mylist.begin() ; i!=mylist.end(); ++i)
        std::cout<<*i<<"\t";
    std::cout<<"\n\n";
}

void testArrays(void){

    // construction uses aggregate initialization
    std::array<int, 3> a1{ {1, 2, 3} }; // double-braces required in C++11 (not in C++14)
    std::array<int, 3> a2 = {1, 2, 3};  // never required after =
    std::array<std::string, 2> a3 = { std::string("abcd"), "b" };
 
    // container operations are supported
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));
 
    std::cout << '\n';
 
    // ranged for loop is supported
    for(const auto& s: a3)
        std::cout << s << ' '<<"\n\r";
}
