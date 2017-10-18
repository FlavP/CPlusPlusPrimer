/* 
 * File:   smart.cpp
 * Author: flavius
 *
 * Created on October 18, 2017, 9:52 PM
 */

#include <memory>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */

class Report{
private:
    string str;
public:
    Report(const string s) : str(s){cout << "Object created!\n";}
    ~Report(){cout << "Object destroyed!\n";}
    void comment() const {cout << str << "\n"; }
};

int main() {
    {
        auto_ptr<Report> ps (new Report("using auto_ptr"));
        ps->comment();
    }
    {
        shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }
    {
        unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->comment();
    }
    return 0;
}

