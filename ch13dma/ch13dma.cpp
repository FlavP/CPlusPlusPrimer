/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstring>
#include "ch13dma.h"

baseDMA::baseDMA(const char* ch, int r){
    int len = std::strlen(ch);
    label = new char[len + 1];
    std::strcpy(label, ch);
    rating = r;
}

baseDMA::baseDMA(const baseDMA& ctrefdma){
    int len = std::strlen(ctrefdma.label);
    label = new char[len + 1];
    std::strcpy(label, ctrefdma.label);
    rating = ctrefdma.rating;
}

baseDMA::~baseDMA(){
    delete [] label;
}

baseDMA & baseDMA::operator =(const baseDMA& ctbasedmaref){
    if(this == &ctbasedmaref)
        return *this;
    delete [] label;
    label = new char[std::strlen(ctbasedmaref.label) + 1];
    std::strcpy(label, ctbasedmaref.label);
    rating = ctbasedmaref.rating;
    return *this;
}