/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstring>
#include <c++/4.8/iosfwd>
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

std::ostream & operator<<(std::ostream & os, const baseDMA & bsdma){
    os << "Label: " << bsdma.label << "\n";
    os << "Rating: " << bsdma.rating << "\n";
    return os;
}

lacksDMA::lacksDMA(const char* ch, const char* l, int r) : baseDMA(l, r){
    std::strncpy(color, ch, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* ch, const baseDMA& ctrefdma) : baseDMA(ctrefdma){
    std::strncpy(color, ch, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & lcks){
    os << (const baseDMA &) lcks; //slick type casting
    os << "Color: " << lcks.color << std::endl;
    return os;
}
 
hasDMA::hasDMA(const char* s, const char* l, int r) : baseDMA(l, r){
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& basedma) : baseDMA(basedma){
    style = new char[std::strlen[s] + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hasdma) : baseDMA(hasdma){
    style = new char[std::strlen(hasdma.style) + 1];
    std::strcpy(style, hasdma.style);
}

hasDMA::~hasDMA(){
    delete [] style;
}

hasDMA & hasDMA::operator =(const hasDMA& hadma){
    if(this == hadma)
        return *this;
    baseDMA::operator =(hadma);
    delete [] style;
    style = new char[std::strlen(hadma.style) + 1]
    std::strcpy(style, hadma.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hasdma){
    os << (const baseDMA &) hasdma;
    os << "Style: " << hasdma.style << std::endl;
    return os;
}