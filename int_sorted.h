//
// Created by Johannes Joujo on 2022-11-19.
//

#ifndef UNTITLED1_INT_SORTED_H
#define UNTITLED1_INT_SORTED_H
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <memory>
#include "int_buffer.h"

class int_sorted {
public:
    int_sorted(const int* source , size_t size);
    size_t size() const;
    void insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted& merge_with) const;

    int_sorted sort(const int* begin , const int *end);
    bool test_if();

private:
    int_buffer buff;
};


#endif //UNTITLED1_INT_SORTED_H
