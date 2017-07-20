/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   move.h
 * Author: flavius
 *
 * Created on July 7, 2017, 2:07 PM
 */

#ifndef MOVE_H
#define MOVE_H

class Move{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmove();
    Move add(const Move & m) const;
    void reset(double a = 0, double b = 0 );
};

#endif /* MOVE_H */

