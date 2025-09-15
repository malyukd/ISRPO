

#include <iostream>
#include "stringhandler.h"

int main()
{
    char h[100] = "tcp://hh.3:rrrr/kkkkk";
    try {
        StringHandler example(h);
        std::cout << example.protocol << std::endl;
        std::cout << example.isProtocolValid() << std::endl;
        std::cout << example.isIPValid() << std::endl;
    }
    catch (std::exception ex) {
        std::cout << ex.what();
    }
   
}
