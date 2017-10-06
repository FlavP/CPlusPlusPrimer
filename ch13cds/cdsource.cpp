/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cstring>
#include "cds.h"

using namespace std;

Cd::Cd(const char* s1, const char* s2, int n, double x){
    lenper = strlen(s1) + 1;
    lenlab = strlen(s2) + 1;
    performers = new char[lenper];
    label = new char[lenlab];
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
    if(this == &d)
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
/*
Cd::Cd(){
    int len = 4;
    lenper = 0;
    lenlab = 0;
    performers = new char[len];
    label = new char[len];
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}
*/
Cd::~Cd(){
    delete [] performers;
    delete [] label;
}

Classic::Classic(const char* s1, const char* s2, const char* s3 , int n, double x)
: Cd(s2, s3, n, x){
    lenprim = strlen(s1);
    primary = new char[lenprim];
    strcpy(primary, s1);
}

Classic::Classic(const char* s1, const Cd & d) : Cd(d){
    lenprim = strlen(s1);    
    primary = new char [lenprim];    
    strcpy(primary, s1);
}

Classic::Classic(const Classic& cl) : Cd(cl){
    lenprim = strlen(cl.primary);    
    primary = new char [lenprim];    
    strcpy(primary, cl.primary);
}
/*
Classic::Classic(){
    int len = 4;
    lenprim = 0;
    primary = new char[len];
    primary[0] = '\0';
}
*/
void Classic::Report() const{
    cout << "Report" << endl;
    Cd::Report();
    cout << "Primary composition: " << primary << endl;
}

Classic & Classic::operator =(const Classic& cl){
    int i;
    if(this == &cl)
        return *this;
    Cd::operator =(cl);
    delete [] primary;
    lenprim = strlen(cl.primary) + 1;    
    primary = new char[lenprim];
    primary[lenprim] = '\0';     
    strcpy(primary, cl.primary);
    return *this;
}

Classic::~Classic(){
    delete [] primary;
}