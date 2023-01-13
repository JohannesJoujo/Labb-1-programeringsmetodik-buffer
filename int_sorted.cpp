//
// Created by Johannes Joujo on 2022-11-19.
//

#include "int_sorted.h"

int_sorted::int_sorted(const int* source , size_t size): buff(source,size)
{
    if(size>1){
        buff=sort(buff.begin(),buff.end()).buff;
    }
}

size_t int_sorted::size() const{
    return buff.size();
}

void int_sorted::insert(int value){
    int_sorted sortera(&value,1);
    this->buff= merge(sortera).buff;
    //int_sorted temp(merge(sortera));
    //buff=temp.buff;
}
const int* int_sorted::begin() const{
    return buff.begin();
}

const int* int_sorted::end() const{
    return buff.end();
}

int_sorted int_sorted::merge(const int_sorted &merge_with) const {

    int_buffer temp(buff.size()+merge_with.size());
    const int* bufp=buff.begin();
    const int* merp=merge_with.begin();
    int pos=0;

    while(bufp!= buff.end() && merp!= merge_with.end()){
        if(*bufp<*merp){
            temp[pos]=*bufp;
            bufp++;
            pos++;
        }
        else{
            temp[pos]=*merp;
            merp++;
            pos++;
        }
    }
    while(bufp!=buff.end()){
        temp[pos]=*bufp;
        bufp++;
        pos++;
    }
    while(merp!=merge_with.end()){
        temp[pos]=*merp;
        merp++;
        pos++;
    }

    int_sorted hej(nullptr,0);
    hej.buff=temp;
    return hej;
}

int_sorted int_sorted::sort(const int* begin , const int *end){
    if (begin == end) return {nullptr, 0};
    if (begin == end - 1) return {begin, 1};
    const ptrdiff_t half = (end - begin) / 2; // pointer diff type
    const int *mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}


bool int_sorted::test_if(){
    int *bufp=buff.begin();
    int a;
    int b;
    a=*bufp;

    while(bufp!=buff.end()){
        bufp++;
        b=*bufp;
        if(a>b){
            std::cerr<<"Not sorted! ";
            return false;
        }
        else {
            a = b;
            //bufp++;
            //b = *bufp;
        }
    }
    std::cerr<<"Sorted! \n";
    return true;
}

