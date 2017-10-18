/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "badguy.h"

Person::~Person(){}

void Person::Data() const{
    std::cout << "The fullname is: " << fullname << std::endl;
}

void Person::Get(){
    std::getline(std::cin, fullname);
}

void Gunslinger::Data() const{
    std::cout << "Can fire: " << notches << " bullets\n";
}

void Gunslinger::Set(){
    std::cout << "Gunslinger's name: ";
    Person::Get();
    std::cout << std::endl;
    std::cout << "How many bullets can he fire? ";
    Get();
}

void Gunslinger::Get(){
    std::cin >> notches;
}

double Gunslinger::Draw() const{
    std::srand(time(NULL));
    double draw = std::rand() % 1 + 0.15;
    Person::Data();
    std::cout << " drew the gun in: " << draw << " seconds\n";
    return draw;
}

void Gunslinger::Show() const{
    std::cout << "Category gunslinger\n";
    Person::Data();
    Data();
}

void PokerPlayer::Set(){
    std::cout << "Poker player's name: ";
    Get();
}

void PokerPlayer::Get(){
    Person::Get();
}

void PokerPlayer::Data() const{
    Person::Data();
}

int PokerPlayer::Draw() const{
    std::srand(time(NULL));
    int draw = std::rand() % 52 + 1;
    Person::Data();
    std::cout << " drew the " << draw 
            << "-th card in the deck\n";
    return draw;
}

void PokerPlayer::Show() const{
    std::cout << "Category Poker Player\n";
    Data();
}

void BadDude::Data() const{
    Gunslinger::Data();
}

void BadDude::Get(){
    Gunslinger::Get();
}

double BadDude::Gdraw(){
    Gunslinger::Draw();
}

int BadDude::Cdraw(){
    PokerPlayer::Draw();
}

void BadDude::Set(){
    Get();
}

void BadDude::Show() const{
    std::cout << "Category Bad Dude\n";
    BadDude::Data();
}