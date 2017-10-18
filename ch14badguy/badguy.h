/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   badguy.h
 * Author: flavius
 *
 * Created on October 18, 2017, 11:09 AM
 */

#ifndef BADGUY_H
#define BADGUY_H

#include <string>

class Person{
private:
    std::string fullname;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    explicit Person() : fullname("No name"){}
    explicit Person(const std::string & s) : fullname(s){}
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;    
};

class Gunslinger : virtual public Person{
private:
    int notches;
protected:
    void Data() const;
    void Get();
public:
    Gunslinger() : Person(), notches(0){}
    Gunslinger(const std::string & s, int n = 0) : Person(s), notches(n){}
    Gunslinger(const Person & p, int n = 0) : Person(p), notches(n){}
    double Draw() const;
    void Set();
    void Show() const;
};


class PokerPlayer : virtual public Person{
protected:
    void Data() const;
    void Get();
public:
    PokerPlayer() : Person(){}
    explicit PokerPlayer(const std::string & s) : Person(s){}
    explicit PokerPlayer(const Person & p) : Person(p){}
    int Draw() const;
    void Set();
    void Show() const;
};

class BadDude : public Gunslinger, PokerPlayer{
protected:
    void Data() const;
    void Get();
public:
    BadDude(){}
    BadDude(const std::string & s, int n = 0) : Person(s), PokerPlayer(s),
    Gunslinger(s, n){}
    BadDude(const Person & p, int n = 0) : Person(p), PokerPlayer(p),
    Gunslinger(p, n){}
    BadDude(const PokerPlayer & p, int n = 0) : Person(p), PokerPlayer(p),
    Gunslinger(p, n){}
    BadDude(const Gunslinger & g) : Person(g), PokerPlayer(g), Gunslinger(g){}
    double Gdraw();
    int Cdraw();
    void Set();
    void Show() const;
};

#endif /* BADGUY_H */

