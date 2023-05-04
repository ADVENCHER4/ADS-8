// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr), last(nullptr) {}

void Train::addCage(bool light) {
    Cage* tmp = new Cage;
    tmp->light = light;
    if (!first && !last) {
        first = tmp;
        last = tmp;
        last->next = first;
        last->prev = first;
    } else {
        last->next = tmp;
        last->next->prev = last;
        last = last->next;
        last->next = first;
        first->prev = last;
    }
}

int Train::getLength() {
    int count = 0, countBack = 0;
    Cage* cur = first;
    cur->light = true;
    countOp++;
    count++;
    cur = cur->next;
    while (cur) {
        if (cur->light) {
            cur->light = false;
            countBack = 0;
            while (countBack != count) {
                countBack++;
                countOp++;
                cur = cur->prev;
            }
            if (!cur->light) {
                return count;
            } else {
                count = 1;
                countOp++;
                cur = cur->next;
            }
        } else {
            count++;
            countOp++;
            cur = cur->next;
        }
    }
    return 0;
}

int Train::getOpCount() {
    return countOp;
}
