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

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

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


const char * file = "guests.txt";
using namespace std;
int main(){
    char ch;
    ifstream fis;
    fis.open(file);
    if(fis.is_open()){
        cout << "Here are the contents of the file "
                << file << endl;
        while(fis.get(ch))
            cout << ch;
        fis.close();
    }
    //add new names
    ofstream fout(file, ios::out | ios::app);
    if(!fout.is_open()){
        cerr << "Could not open the file " << file << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Enter name of guest (blank to quit):\n";
    string name;
    while(getline(cin, name) && name.size() > 0)
        fout << name << endl;
    fout.close();
    //show new file
    fis.clear();
    fis.open(file);
    if(fis.is_open()){
        cout << "New content: " << endl;
        while(fis.get(ch))
            cout << ch;
        fis.close();
    }
    return 0;
}

inline void cutline(){while(std::cin.get() != '\n') continue;}

struct planet{
    char name[20];
    long population;
    double g;
};

const char * file = "planets.dat";

int main(){
    using namespace std;
    planet pl;
    cout << fixed << right;
    ifstream fin;
    fin.open(file, 
    ios_base::in | ios_base::binary);
    if(fin.is_open()){
        cout << "Here are the current input of the file:\n";
        while(fin.read( (char *) &pl, sizeof(pl))){
            cout << setw(20) << pl.name << ' '
                    << setprecision(0) << setw(12) << pl.population << ' '
                    << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    ofstream fout;
    fout.open(file, 
    ios_base::out | ios_base::app | ios_base::binary);
    if(!fout.is_open()){
        cout << "There was an error opening" << file << endl;
        exit(EXIT_FAILURE);
    }
    while(pl.name[0] != '\0'){
        cutline();
        cout << "Enter planet population: ";
        cin >> pl.population;
        cout << "Enter planet g force: ";
        cin >> pl.g;
        cutline();
        fout.write((char *) & pl, sizeof pl);
        cout << "Enter planet name (blank to quit)\n";
        cin.get(pl.name, 20);
    }
    fout.close();
    fin.clear();
    fin.open(file, ios_base::in | ios_base::binary);
    if(fin.is_open()){
        cout << "Here are the new contents:\n";
        while(fin.read((char *) &pl, sizeof(pl))){
            cout << setw(20) << pl.name << ' '
                    << setprecision(0) << setw(12) << pl.population << ' '
                    << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    return 0;
}
*/
//planets.dat has to exist and have recordings in it for the next part
const int LIM = 20;
struct planet{
    char name[LIM];
    long population;
    double g;
};
using namespace std;
const char * file = "planets.dat";
inline void clearline(){while(cin.get() != '\n') continue;}

int main(){
    planet pl;
    cout << fixed;
    fstream finout;
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
    int ct = 0;
    if(finout.is_open()){
        finout.seekg(0);
        cout << "Current contents of " << file << " are:\n";
        while(finout.read((char *) &pl, sizeof pl))
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                    << setprecision(0) << setw(12) << pl.population
                    << setprecision(2) << setw(6) << pl.g << endl;
    if(finout.eof()){
        finout.clear();
    }else{
        cerr << "Error in reading " << file << endl;
        exit(EXIT_FAILURE);
        }
    } else {
        cerr << "Could not open " << file << endl;
        exit(EXIT_FAILURE);
    }
    //change a record
    cout << "Enter a record number you want to edit: ";
    long rec;
    cin >> rec;
    clearline();
    if(rec < 0 || rec >= ct){
        cerr << "Invalid record number -- exit\n";
        exit(EXIT_FAILURE);
    }
    streampos place = rec * sizeof pl;
    finout.seekg(place);
    if(finout.fail()){
        cerr << "Error in attempted seek\n";
        exit(EXIT_FAILURE);
    }
    finout.read((char *) &pl, sizeof pl);
    cout << "You selected:\n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
                    << setprecision(0) << setw(12) << pl.population
                    << setprecision(2) << setw(6) << pl.g << endl;
    if(finout.eof())
        finout.clear();
    cout << "Enter planet name: ";
    cin.get(pl.name, LIM);
    cout << "\nEnter planet population: ";
    cin >> pl.population;
    cout << "\nEnter planet gforce: ";
    cin >> pl.g;
    finout.seekp(place);
    finout.write((char *) &pl, sizeof pl) << flush;
    if(finout.fail()){
        cerr << "Error in attempted writing to file\n";
        exit(EXIT_FAILURE);
    }
    // show revised file
    ct = 0;
    finout.seekg(0);
    cout << "Here is the revised file:\n";
    while(finout.read((char *) &pl, sizeof pl))
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                    << setprecision(0) << setw(12) << pl.population
                    << setprecision(2) << setw(6) << pl.g << endl;
    finout.close();
    return 0;
}