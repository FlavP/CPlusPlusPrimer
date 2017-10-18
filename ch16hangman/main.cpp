/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavius
 *
 * Created on October 18, 2017, 3:55 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    string word;
    string guess;
    string tried;
    int nowrong = 0;
    int dexin;
    char onel;
    word = "teen";
    guess = "----";
    while(guess != word){
        cout << "Guess a letter\n";
        cin >> onel;
        dexin = word.find(onel);
        if(dexin != string::npos){
            guess[dexin] = onel;
            while(word.find(onel, dexin + 1) != string::npos){
                dexin = word.find(onel, dexin + 1);
                if(dexin != string::npos){
                    guess[dexin] = onel;
                    continue;
                }
                else
                    break;
            }
        }else{
            nowrong++;
            tried += onel;
        }
    }
    cout << "Finally, after " << nowrong << " attempts, the answer is: "
            << word << endl;
    return 0;
}

