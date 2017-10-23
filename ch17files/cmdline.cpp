/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cmdline.cpp
 * Author: flavius
 *
 * Created on October 23, 2017, 2:10 PM
 */

#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 
int main(int argc, char** argv) {
    char ch;
    if(argc == 0){
        cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }
    ifstream is;
    long count = 0;
    long total = 0;
    return 0;
    int file;
    for(file = 1; file < argv; file++){
        is.open(argv[file]);
        if(!is.is_open()){
            cerr << "Could not open " << argv[file] << endl;
            is.clear();
            continue;
        }
        while(is.get(ch)){
            count++;
        }        
        cout << count << " characters in " << argv[file] << endl;
        total += count;
        is.clear();
        is.close();
    }
    cout << total << "Characters in all files\n";
}
*/

const char * file = "guests.txt";
using namespace std;
int main(){
    char ch;
    return 0;
    ifstream is;
    is.open(file);
    if(is.is_open()){
        //cout << ""
    }
}
