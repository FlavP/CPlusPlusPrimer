/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sales.h"

using std::cout;
using std::string;

Sales::bad_index::bad_index(int smh, const std::string& s) : 
std::logic_error(s), bi(smh){}

Sales::Sales(int yy){
    year = yy;
    int i;
    for(i = 0; i < MONTHS; i++)
        gr[i] = 0;
}

Sales::Sales(int yy, const double* gruob, int n){
    year = yy;
    int lim = (n < MONTHS) ? n : MONTHS;
    int i;
    for(i = 0; i < n; ++i)
        gr[i] = gruob[i];
    for( ; i < MONTHS; ++i)
        gr[i] = 0;
}

double Sales::operator [](int i) const{
    if(i <= 0 || i > MONTHS)
        throw bad_index(i);
    return gr[i];
}

double & Sales::operator [](int i){
    if(i <= 0 || i > MONTHS)
        throw bad_index(i);
    return gr[i];
}

LabeledSales::nbad_index::nbad_index(const std::string & lbl, int smh,
                    const std::string & s) : Sales::bad_index(smh, s){
    label = lbl;
}

LabeledSales::LabeledSales(const std::string& str, int yy){
    label = str;
}

LabeledSales::LabeledSales(const std::string& lbl, int yy, 
        const double* gr, int n){
    label = lbl;
}

double LabeledSales::operator [](int i) const{
    if(i <= 0 || i > MONTHS)
        throw nbad_index(return_label(), i);
    return Sales::operator [](i);
}

double & LabeledSales::operator [](int i){
    if(i <= 0 || i > MONTHS)
        throw nbad_index(return_label(), i);
    return Sales::operator [](i);
}
