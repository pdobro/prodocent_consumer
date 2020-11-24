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
void runCosnumerA() {
    example.consumeCheese();
}
void runConsumerB() {
    example.consumeMeat();
}
void runCosnumerC() {
    example.consumeCabbage();
}
int main() {
    pthread_t  producentA, producentB, producentC, producentD, cosumerA, consumerB, consumerC;

    pthread_create(&producentA, NULL, reinterpret_cast<void *(*)(void *)>(runProducerA), NULL);
    pthread_create(&producentB, NULL, reinterpret_cast<void *(*)(void *)>(runProducerB), NULL);
    pthread_create(&producentC, NULL, reinterpret_cast<void *(*)(void *)>(runProducerC), NULL);
    pthread_create(&producentD, NULL, reinterpret_cast<void *(*)(void *)>(runProducerD), NULL);
    pthread_create(&cosumerA, NULL, reinterpret_cast<void *(*)(void *)>(runCosnumerA), NULL);
    pthread_create(&consumerB, NULL, reinterpret_cast<void *(*)(void *)>(runConsumerB), NULL);
    pthread_create(&consumerC, NULL, reinterpret_cast<void *(*)(void *)>(runCosnumerC), NULL);

    pthread_join(producentA, NULL);
    pthread_join(producentB, NULL);
    pthread_join(producentC, NULL);
    pthread_join(producentD, NULL);
    pthread_join(cosumerA, NULL);
    pthread_join(consumerB, NULL);
    pthread_join(consumerC, NULL);

    return 0;
}
