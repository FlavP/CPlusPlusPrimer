/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sales.h
 * Author: flavius
 *
 * Created on October 13, 2017, 11:56 AM
 */

#ifndef SALES_H
#define SALES_H

#include <stdexcept>
#include <string>

class Sales{
public:
    enum{MONTHS=12};
    class bad_index : public std::logic_error{
    private:
        int bi;
    public:
        explicit bad_index(int smh, 
                const std::string & s = "Sales have a bad index number\n");
        int return_bad_index() const {return bi;}
        virtual ~bad_index() throw(){}
    };
    Sales(int yy = 0);
    Sales(int yy, const double * gr, int n);
    virtual ~Sales();
    int ret_year(){return year;}
    virtual double operator[](int i) const;
    virtual double & operator[](int i);
private:
    double gr[MONTHS];
    int year;
};

class LabeledSales : public Sales{
public:
    class nbad_index : public bad_index{
        private:
            std::string label;
        public:
            nbad_index(const std::string & lbl, int smh,
                    const std::string & s = "Labeled sales have a bad index\n");
            const std::string & ret_label(){return label;}
            virtual ~nbad_index() throw();
    };
    explicit LabeledSales(const std::string & str = "none", int yy = 0);
    LabeledSales(const std::string & lbl, int yy, const double * gr, int n);
    virtual ~LabeledSales();
    const std::string & return_label(){return label;}
    virtual double operator[](int i) const;
    virtual double & operator[](int i);
private:
    std::string label;
};
#endif /* SALES_H */

