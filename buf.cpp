//
// Created by patryk on 17.11.2020.
//

#include "buf.h"

Buffer::Buffer() {
    val = 0;
    size = N;
}

void Buffer::print() const {

    for (int i = 0; i < N; i++){
        if (i < val)
            std::cout<<'X';
        else
            std::cout<<'O';
    }
    std::cout<<"  "<<"r: "<<val<<"\n";
    //std::cout<<"\n";

}

void Buffer::push() {
    val++;
    if (val > N)
        std::cout<<"\nbufor przepełiony!";

}

void Buffer::pull() {
    val--;
    if (val < 0)
        std::cout<<"\ndostęp do pustego bufora!";
}

