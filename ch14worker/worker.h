/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   worker.h
 * Author: flavius
 *
 * Created on October 16, 2017, 2:32 PM
 */

#ifndef WORKER_H
#define WORKER_H

#include <string>

class Worker{
private:
    std::string fullname;
    long id;
private:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("No one"), id(0L){}
    Worker(const std::string & s, long n) : fullname(s), id(n){}
    virtual ~Worker() = 0; // virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0){}
    Waiter(const std::string & s, long n, int p = 0) : 
    Worker(s, n), panache(p){}
    Worker(const Worker & wk, int p = 0) :
    Worker(wk), panache(p){}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker{
protected:
    enum {other, alto, contrabalto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other) : 
    Worker(s, n) , voice(v) {}
    Singer(const Worker & wk, int v = other) : 
    Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

//multiple inheritance
class SingingWaiter : public Singer, public Waiter{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other) : 
    Worker(s, n), Waiter(s, n, p), Singer(s, n, v){}
    SingingWaiter(const Worker & wk, int p = 0, int v = other) :
    Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter & wt, int v = 0) : 
    Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer & sg, int p = 0) : 
    Worker(sg), Waiter(sg, p), Singer(sg) {}    
};
#endif /* WORKER_H */

