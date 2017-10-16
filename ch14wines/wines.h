/* 
 * File:   wines.h
 * Author: flavius
 *
 * Created on October 15, 2017, 8:30 PM
 */

#ifndef WINES_H
#define	WINES_H
#include <iostream>
#include <string>
#include <valarray>

typedef std::valarray<int> ArrayInt;


class Wine{
private:
    std::string label;
    int numofyears;
public:
    ArrayInt years;
    ArrayInt bottles;
//    class Pair{
//    typedef Pair<ArrayInt, ArrayInt> PairArray;
//    private:
//        PairArray botandyrs;
//    public:
//        Pair(int y, const int yr[], const int bot[]);
//        void sharewis(PairArray);
//    };
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y = 1);
    ~Wine(){}
    void show() const;
};


#endif	/* WINES_H */

