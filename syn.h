//
// Created by patryk on 17.11.2020.
//

#ifndef SEMAPHORES_SYN_H
#define SEMAPHORES_SYN_H

#define N 10
#include <mutex>
#include <vector>
#include <unistd.h>
#include "sem.h"
#include "buf.h"

class Production {
    Buffer buffer_dough = Buffer();
    Buffer buffer_cheese = Buffer();
    Buffer buffer_meat = Buffer();
    Buffer buffer_cabbage = Buffer();

    Semaphore dough_empty = Semaphore(N);
    Semaphore cheese_empty = Semaphore(N);
    Semaphore meat_empty = Semaphore(N);
    Semaphore cabbage_empty = Semaphore(N);

    Semaphore dough_full = Semaphore(0);
    Semaphore cheese_full = Semaphore(0);
    Semaphore meat_full = Semaphore(0);
    Semaphore cabbage_full = Semaphore(0);

    std::mutex dough_mutex;
    std::mutex cheese_mutex;
    std::mutex meat_mutex;
    std::mutex cabbage_mutex;

    std::mutex cout_mutex;

    pthread_cond_t condConsumerCheese = PTHREAD_COND_INITIALIZER;
    pthread_cond_t condConsumerMeat = PTHREAD_COND_INITIALIZER;
    pthread_cond_t condConsumerCabbage = PTHREAD_COND_INITIALIZER;

    pthread_mutex_t mutexConsumerCheese = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t mutexConsumerMeat = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t mutexConsumerCabbage = PTHREAD_MUTEX_INITIALIZER;

public:
    [[noreturn]] void produceDough();

    [[noreturn]] void produceCheese();

    [[noreturn]] void produceMeat();

    [[noreturn]] void produceCabbage();

    [[noreturn]] void consumeCheese();

    [[noreturn]] void consumeMeat();

    [[noreturn]] void consumeCabbage();



};
#endif
