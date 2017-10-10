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

#ifndef CH15TV_H
#define CH15TV_H

class Remote{
private:
    int mode;
public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv & t){return t.volup();}
    bool voldown(Tv & t){return t.voldown();}
    void onoff(Tv & t){t.onoff();}
    void channup(Tv & t){t.channup();}
    void chandown(Tv & t){t.chandown();}
    void set_mode(Tv & t){t.set_mode();}
    void set_intput(Tv & t){t.set_input();}
    void set_chan(Tv & t, int c);
};


class Tv
{
public:
    enum {On, Off};
    enum {MinVol, MaxVol = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};
    friend void Remote::set_chan(Tv & t, int c){t.channel = c;}
    Tv(int s = Off, int mc = 125) : state(s), volume(5),
    maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On) ? Off : On;}
    bool ison() {return state == On;}
    bool volup();
    bool voldown();
    bool channup();
    bool chandown();
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


#endif /* CH15TV_H */

