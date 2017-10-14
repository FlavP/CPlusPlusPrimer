/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ch15tv.h
 * Author: flavius
 *
 * Created on October 10, 2017, 12:47 PM
 */
#include <iostream>
#ifndef CH15TV_H
#define CH15TV_H

class Tv;

class Remote{
public:
    enum {On, Off};
    enum {MinVol, MaxVol = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};
    enum {NORMAL, INTERACTIVE};    
private:
    int mode;
    int isint;
public:
    friend Tv;
    Remote(int m = TV) : mode(m) {}
    bool volup(Tv & t);
    bool voldown(Tv & t);
    void onoff(Tv & t);
    void channup(Tv & t);
    void chandown(Tv & t);
    void set_mode(Tv & t);
    void set_intput(Tv & t);
    void see_mode(Tv & t);
    void set_chan(Tv & t, int c);
    void set_int(){isint = (isint == NORMAL) ? INTERACTIVE : NORMAL;}
};


class Tv
{
public:
    friend Remote;
    enum {On, Off};
    enum {MinVol, MaxVol = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};
    friend void Remote::set_chan(Tv & t, int c);
    Tv(int s = Off, int mc = 125) : state(s), volume(5),
    maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On) ? Off : On;}
    bool ison() {return state == On;}
    bool volup();
    bool voldown();
    bool channup();
    bool chandown();
    void change_int(Remote & r);
    void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;}
    void set_input() {input = (input == TV) ? DVD : TV;}
    void settings() const;
private:
    int state;
    int volume;
    int maxchannel;
    int mode;
    int input;
    int channel;
};

inline bool Remote::volup(Tv & t){return t.volup();}
inline bool voldown(Tv & t){return t.voldown();}
inline void onoff(Tv & t){t.onoff();}
inline void channup(Tv & t){t.channup();}
inline void chandown(Tv & t){t.chandown();}
inline void set_mode(Tv & t){t.set_mode();}
inline void set_intput(Tv & t){t.set_input();}
#endif /* CH15TV_H */

