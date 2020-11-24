//
// Created by patryk on 17.11.2020.
//

#ifndef SEMAPHORES_SEM_H
#define SEMAPHORES_SEM_H

#include <semaphore.h>

class Semaphore{

    sem_t semaphore;

    public:

    Semaphore(int beg);
    //~Semaphore();
    void p();
    void v();
    int value();
};

#endif
