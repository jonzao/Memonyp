//
// Created by jon on 2020/11/16.
//


#include <iostream>
#include <string>
#include "Allocator.h"


class Foo{
public:
    long L;
    std::string str;
    static allocator myAllloc;

public:
    Foo(long l):L(l){}
    static void * operator new (std::size_t size){ return myAllloc.allocate(size);}
    static void operator delete (void* p,std::size_t size){return myAllloc.deallocate(p,size);}

};

allocator Foo::myAllloc;



int main(){

    Foo *p=new Foo(1L);
    delete p;
    return 0;
}
