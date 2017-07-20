#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc){
    std::strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g){
    std::cout << "Enter the name of the golfer ";
    std::cin.get(g.fullname, 40);
    std::cout << "Enter the handicap ";
    std::cin >> g.handicap;
    if(std::strlen(g.fullname) == 0)
        return 0;
    return 1;
}

void handicap(golf & g, int hc){
    g.handicap = hc;
}

void showgolf(const golf &g){
    std::cout << "Golfer name: " << g.fullname << std::endl;
    std::cout << "Golfer handicap: " << g.handicap << std::endl;
}