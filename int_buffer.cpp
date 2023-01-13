//
// Created by Johannes Joujo on 2022-11-19.
//

#include "int_buffer.h"
// konstruktor som skapar array.
int_buffer::int_buffer(size_t size): first(new int [size]), last(first+size){

}

//paramatrisera cons resurs skapare garanterar att det finns plats
int_buffer::int_buffer(const int* source , size_t size): int_buffer(size){
    std::copy(source,source+size,first);
}
//copy cons
int_buffer::int_buffer(const int_buffer& rhs): int_buffer(rhs.first,rhs.size()){

}
//move cons
int_buffer::int_buffer(int_buffer&& rhs):first(nullptr), last(nullptr)
{
    std::swap(first,rhs.first);
    std::swap(last,rhs.last);
}
//copy assigne cons
int_buffer & int_buffer::operator=(const int_buffer&rhs){
    int_buffer temp(rhs);
    std::swap(first,temp.first);
    std::swap(last,temp.last);
    return *this;
}
//move assign cons
int_buffer & int_buffer::operator=(int_buffer&& rhs){
    std::swap(first,rhs.first);
    std::swap(last,rhs.last);
    return *this;
}

int& int_buffer::operator[](size_t index){
    return first[index];
}

const int& int_buffer::operator[](size_t index) const{
    return first[index];
}

size_t int_buffer::size() const{
    return (last-first);
}

int* int_buffer::begin(){
    return first;
}

const int* int_buffer::begin() const{
    return first;
}

int* int_buffer::end(){
    return last;
}
const int* int_buffer::end() const{
    return last;
}
//destruktor
int_buffer::~int_buffer(){
    delete [] first;
}
