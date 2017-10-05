/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include "cds.h"

using namespace std;

Cd::Cd(char* s1, char* s2, int n, double x){
    lenper = strlen(s1) + 1;
    lenlab = strlen(s2) + 1;
    performers = new char[lenper];
    label = new char[label];
    strcpy(performers, s1);
    performers[lenper] = '\0'; 
    strcpy(label, s2);
    label[lenlab] = '\0'; 
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd& d){
    lenper = strlen(d.performers) + 1;
    lenlab = strlen(d.label) + 1;    
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    performers[lenper] = '\0';
    label[lenlab] = '\0';
    selections = d.selections;
    playtime = d.playtime;    
}

void Cd::Report() const{
    cout << "Artist: " << performers << endl;
    cout << "Performing: " << label << endl;
    cout << "Number of selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator =(const Cd& d){
    if(this == d)
        return *this;
    delete [] performers;
    delete [] label;
    lenper = strlen(d.performers) + 1;
    lenlab = strlen(d.label) + 1;   
    performers = new char [lenper];
    label = new char[lenlab];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    performers[lenper] = '\0';
    label[lenlab] = '\0';
    selections = d.selections;
    playtime = d.playtime;       
    return *this;
}

Cd::~Cd(){
    delete [] performers;
    delete [] label;
}

Classic::Classic(char* s1, char* s2, int n, double x, char* s3)
: Cd(s1, s2, n, x){
    lenprim = strlen(s3);
    strcpy(primary, s3);
}

Classic::Classic(const Cd& d, char* s3) : Cd(d){
    lenprim = strlen(s3);    
    primary = new char [lenprim];    
    strcpy(primary, s3);
}

void Classic::Report() const{
    Cd::Report();
    cout << "Primary composition: " << primary << endl;
}

Classic & Classic::operator =(const Classic& cl){
    int i;
    if(this == cl)
        return *this;
    Cd::operator =(cl);
    delete [] primary;
    lenprim = strlen(cl.primary) + 1;    
    primary = new char[lenprim];
    primary[lenprim] = '\0';     
    strcpy(primary, cl.primary);
    return *this;
}