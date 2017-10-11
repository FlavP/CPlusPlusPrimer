/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queuemain.cpp
 * Author: flavius
 *
 * Created on October 11, 2017, 12:56 PM
 */

#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

/*
 * 
 */
int main() {
    Queue<string> sms(5);
    string temp;
    while(!sms.isfull()){
        cout << "Enter the name. You will be served in the order of arrival\n"
                "name: ";
        getline(cin, temp);
        sms.enqueue(temp);
    }
    cout << "The queue is full. Processing begins1\n";
    while(!sms.isempty()){
        sms.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
    return 0;
}

