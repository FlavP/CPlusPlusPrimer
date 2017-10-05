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
    return 
    int i;
    for(i = 0; i < strlen(performers); i++)
        performers[i] = '';
    performers[strlen(d.performers)] = '\0';
    for(i = 0; i < strlen(label); i++)
        label[i] = '';
    label[strlen(d.label)] = '\0'; 
    strcpy(performers, d.performers);
    strcpy(label, d.label);
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
    strcpy(primary, s3);
}

Classic::Classic(const Cd& d, char* s3) : Cd(d){
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
    for(i = 0; i < strlen(primary); i++)
        primary[i] = '';
    primary[strlen(cl.primary)] = '\0';     
    strcpy(primary, cl.primary);
    return *this;
}