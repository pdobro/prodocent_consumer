//
// Created by patryk on 17.11.2020.
//

#include "syn.h"

[[noreturn]] void Production::produceDough() {
    while (true) {
        dough_empty.p();
        dough_mutex.lock();
        buffer_dough.push();
        dough_mutex.unlock();
        dough_full.v();

        if (cheese_full.value() && dough_full.value())
            pthread_cond_signal(&condConsumerCheese);

         if (meat_full.value() && dough_full.value())
            pthread_cond_signal(&condConsumerMeat);

         if (cabbage_full.value() && dough_full.value())
            pthread_cond_signal(&condConsumerCabbage);


        cout_mutex.lock();
        std::cout<<"ciasto: ";
        buffer_dough.print();
        cout_mutex.unlock();

        usleep(300000);
    }
}

[[noreturn]] void Production::produceCheese() {
while (true) {
    cheese_empty.p();
    cheese_mutex.lock();
    buffer_cheese.push();
    cheese_mutex.unlock();
    cheese_full.v();

    if (cheese_full.value() && dough_full.value())
        pthread_cond_signal(&condConsumerCheese);

    cout_mutex.lock();
    std::cout<<"ser: ";
    buffer_cheese.print();
    cout_mutex.unlock();
    usleep(900000);

}
}

[[noreturn]] void Production::produceMeat() {
    while (true) {
        meat_empty.p();
        meat_mutex.lock();
        buffer_meat.push();
        meat_mutex.unlock();
        meat_full.v();

        if (meat_full.value() && dough_full.value())
            pthread_cond_signal(&condConsumerMeat);

        cout_mutex.lock();
        std::cout<<"mieso: ";
        buffer_meat.print();
        cout_mutex.unlock();
        usleep(900000);
    }
    }

[[noreturn]] void Production::produceCabbage() {

    while (true) {
        cabbage_empty.p();
        cabbage_mutex.lock();
        buffer_cabbage.push();
        cabbage_mutex.unlock();
        cabbage_full.v();

        if (cabbage_full.value() && dough_full.value())
            pthread_cond_signal(&condConsumerCabbage);

        cout_mutex.lock();
        std::cout<<"kapusta: ";
        buffer_cabbage.print();
        cout_mutex.unlock();
        usleep(900000);
    }
    }

[[noreturn]] void Production::consumeCheese() {

    while (true) {
        pthread_mutex_lock(&mutexConsumerCheese);
        while (true)
            if (cheese_full.value() && dough_full.value()) {
                dough_full.p();
                cheese_full.p();
                dough_mutex.lock();
                cheese_mutex.lock();

                buffer_dough.pull();
                buffer_cheese.pull();

                cheese_mutex.unlock();
                dough_mutex.unlock();
                cheese_empty.v();
                dough_empty.v();
                break;
            } else {
                pthread_cond_wait(&condConsumerCheese, &mutexConsumerCheese);
            }

        pthread_mutex_unlock(&mutexConsumerCheese);
        cout_mutex.lock();
        std::cout<<"wyprodukowano pierogi z serem\n";
        cout_mutex.unlock();
        usleep(900000);
    }

    }

[[noreturn]] void Production::consumeMeat() {

    while (true) {
        pthread_mutex_lock(&mutexConsumerMeat);
        while (true)
            if (meat_full.value() && dough_full.value()) {
                dough_full.p();
                meat_full.p();
                dough_mutex.lock();
                meat_mutex.lock();

                buffer_dough.pull();
                buffer_meat.pull();

                meat_mutex.unlock();
                dough_mutex.unlock();
                meat_empty.v();
                dough_empty.v();
                break;
            } else {
                pthread_cond_wait(&condConsumerMeat, &mutexConsumerMeat);
            }

        pthread_mutex_unlock(&mutexConsumerMeat);
        cout_mutex.lock();
        std::cout<<"wyprodukowano pierogi z miesem\n";
        cout_mutex.unlock();
        usleep(1000000);
    }
}

[[noreturn]] void Production::consumeCabbage() {

    while (true) {
        pthread_mutex_lock(&mutexConsumerCabbage);
        while (true)
            if (cabbage_full.value() && dough_full.value()) {
                dough_full.p();
                cabbage_full.p();
                dough_mutex.lock();
                cabbage_mutex.lock();

                buffer_dough.pull();
                buffer_cabbage.pull();

                cabbage_mutex.unlock();
                dough_mutex.unlock();
                cabbage_empty.v();
                dough_empty.v();
                break;
            } else {
                pthread_cond_wait(&condConsumerCabbage, &mutexConsumerCabbage);
            }

        pthread_mutex_unlock(&mutexConsumerCabbage);
        cout_mutex.lock();
        std::cout<<"wyprodukowano pierogi z kapusta\n";
        cout_mutex.unlock();
        usleep(1000000);
    }
}


