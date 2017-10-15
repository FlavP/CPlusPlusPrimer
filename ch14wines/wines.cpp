#include <iostream>
#include "wines.h"

Wine::Wine(const char* l, int y){
    label = l;
    numofyears = y;
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[]){    
    label = l;
    numofyears = y;
    int i;
//    years = (yr, y);
//    bottles = (bot, y);
}

void Wine::show() const{
    int i;
    std::cout << "The wine is: " << label << std::endl;
//    std::cout << "And we have: " << bottles << " bottles\n";
}
