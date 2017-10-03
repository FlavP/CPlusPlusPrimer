/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ch13dma.h
 * Author: flavius
 *
 * Created on October 3, 2017, 3:46 PM
 */

#ifndef CH13DMA_H
#define CH13DMA_H
#include <iostream>

class baseDMA{
private:
    char * label;
    int rating;    
public:
    baseDMA(const char * ch = "null", int r=0);
    baseDMA(const baseDMA & ctrefdma);
    ~baseDMA();
    baseDMA & operator=(const baseDMA & ctbasedmaref);
    friend std::ostream & operator<<(std::ostream & os, 
    const baseDMA & ctbasedmaref);    
};

class lacksDMA : public baseDMA{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * ch = "blank", const char * ch = "null",
            int r = 0);
    lacksDMA(const char * ch, const baseDMA & ctrefdma);
    friend std::ostream & operator<<(std::ostream & os, 
    const lacksDMA & ctrefdma);    
};

class hasDMA : public baseDMA{
public:
    char *ch;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & ctrefdma);
    hasDMA(const hasDMA & objrefdma);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & cthasdmaref);
    friend std::ostream & operator<<(std::ostream & os, 
    const hasDMA & cthasdmaref);
};

#endif /* CH13DMA_H */

