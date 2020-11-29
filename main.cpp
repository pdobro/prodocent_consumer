#include <iostream>

#include "syn.h"
Production example;

void runProducerA() {
    example.produceDough();
}
void runProducerC() {
    example.produceMeat();
}
void runProducerB() {
    example.produceCheese();
}
void runProducerD() {
    example.produceCabbage();
}
void runConsumerA() {
    example.consumeCheese();
}
void runConsumerB() {
    example.consumeMeat();
}
void runConsumerC() {
    example.consumeCabbage();
}
int main() {
    pthread_t  producentA, producentB, producentC, producentD, consumerA, consumerB, consumerC;

    pthread_create(&producentA, nullptr, reinterpret_cast<void *(*)(void *)>(runProducerA), nullptr);
    pthread_create(&producentB, nullptr, reinterpret_cast<void *(*)(void *)>(runProducerB), nullptr);
    pthread_create(&producentC, nullptr, reinterpret_cast<void *(*)(void *)>(runProducerC), nullptr);
    pthread_create(&producentD, nullptr, reinterpret_cast<void *(*)(void *)>(runProducerD), nullptr);
    pthread_create(&consumerA, nullptr, reinterpret_cast<void *(*)(void *)>(runConsumerA), nullptr);
    pthread_create(&consumerB, nullptr, reinterpret_cast<void *(*)(void *)>(runConsumerB), nullptr);
    pthread_create(&consumerC, nullptr, reinterpret_cast<void *(*)(void *)>(runConsumerC), nullptr);

    pthread_join(producentA, nullptr);
    pthread_join(producentB, nullptr);
    pthread_join(producentC, nullptr);
    pthread_join(producentD, nullptr);
    pthread_join(consumerA, nullptr);
    pthread_join(consumerB, nullptr);
    pthread_join(consumerC, nullptr);

    return 0;
}
