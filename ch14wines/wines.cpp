#include <iostream>
#include "wines.h"

Wine::Wine(const char* l, int y){
    label = l;
    numofyears = y;
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[]){    
    label = l;
    numofyears = y;
    ArrayInt auxwine = (yr, y);
    ArrayInt auxbot = (bot, y);
    years = auxwine;
    bottles = auxbot;
}

void Wine::show() const{
    int i;
    std::cout << "The wine is: " << label << std::endl;
    std::cout << "And we have: " << bottles[0] << " bottles\n";
}
