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
    int lenlab;
    int lenper;
public:
    Cd(const char * s1 = "No name",const char * s2 = "No album", 
            int n = 0, double x = 0.0);
    Cd(const Cd & d);
//    Cd();
    virtual ~Cd();
    virtual void Report() const; // reports all CD data
    Cd & operator=(const Cd & d);
};

class Classic : public Cd{
private:
    char * primary;
    int lenprim;
public:
    Classic(const char* s1 = "No name", const char* s2 = "No album", 
            const char* s3 = "No primary" , int n = 0, double x = 0.0);
    Classic(const char* s1, const Cd & d);
    Classic(const Classic & cl);
   // Classic();
    ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & cl);
};

#endif /* CDS_H */

