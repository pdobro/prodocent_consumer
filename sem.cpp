//
// Created by patryk on 17.11.2020.
//
#include"sem.h"

Semaphore::Semaphore(int beg) {
    if (sem_init(&semaphore, 0 , beg))
        throw ;
}

//Semaphore::~Semaphore() {sem_destroy(&semaphore);}

void Semaphore::p(){
    if (sem_wait(&semaphore))
        throw "wait e";
}

void Semaphore::v() {
    if(sem_post(&semaphore))
        throw "signal e";
}

int Semaphore::value() {
    int val;
    sem_getvalue(&semaphore,&val);
    return val;
}

