//
// Created by patryk on 17.11.2020.
//

#ifndef SEMAPHORES_BUF_H
#define SEMAPHORES_BUF_H

#define N 10

#include <iostream>

class Buffer{
    int size;
    int val;

public:

    Buffer();
    void push();
    void pull();
    void print() const;


};

#endif
