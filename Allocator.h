//
// Created by jon on 2020/11/16.
//

#ifndef MYC_ALLOCATOR_H
#define MYC_ALLOCATOR_H
#include <iostream>
#include <stdlib.h>

/**
 *creation memonyPool
 */
class allocator{

private:
    struct all{
        struct all* next;
   };
public:
    void * allocate(std::size_t);
    void deallocate(void *,std::size_t);


private:
    all * freeStroe= nullptr;
    const int CHUNK=10;
};

void* allocator::allocate(std::size_t size) {
    all *p;
    if(!freeStroe){
        std::size_t chunk=CHUNK*size;
        freeStroe=p=(all*)malloc(chunk);
        for(int i=0;i<(CHUNK-1);++i){
            p->next=(all*)((char*)p+size);
            p=p->next;

        }
        p->next= nullptr;
    }
    p=freeStroe;
    freeStroe=freeStroe->next;
    return p;

}

void allocator::deallocate(void * p, std::size_t) {
    ((all*)p)->next=freeStroe;
    freeStroe=(all*)p;
}





#endif //MYC_ALLOCATOR_H
