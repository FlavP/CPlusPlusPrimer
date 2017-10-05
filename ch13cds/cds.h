/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cds.h
 * Author: flavius
 *
 * Created on October 5, 2017, 12:50 PM
 */

#ifndef CDS_H
#define CDS_H

class Cd{
private:
    char * performers;
    char * label;
    int selections; // number of selections
    double playtime; // playing time in minutes
    int lenper;
    int lenlab;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const; // reports all CD data
    virtual Cd & operator=(const Cd & d);
};

class Classic : public Cd{
private:
    char * primary;
    int lenprim;
public:
    Classic(char *s1, char *s2, int n, double x,  char *s3) : Cd(s1, s2, n, x){}
    Classic(const Cd & d, char *s3) : Cd(d){}
    Classic();
    virtual void Report() const;
    virtual Classic & operator=(const Classic & cl);
};

#endif /* CDS_H */

