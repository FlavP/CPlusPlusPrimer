/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   starting.cpp
 * Author: flavius
 *
 * Created on October 24, 2017, 2:47 PM
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <ostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

/*
 * 
 /

const int LIM = 20;

int main(){
    char ch[LIM];
    char cts;
    cout << "Enter characters:\n";
    cin.get(ch, LIM, '$');
    cin.get(cts);
    cout << ch << endl;
    cout << "And the last character is: " << cts << endl;
    
    return 0;
}



int main(){
    const char * filename;
    ofstream outfile; 
    char ch;
    filename = "lgi.txt";
    outfile.open(filename);
    if(!outfile.is_open()){
        cout << "Could not open the file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Gimme output: ";
    while(cin.get(ch)){
        if(outfile.eof())
            break;
        outfile << ch;    
    }
    outfile.close();    
    char input;
    ifstream infile;
    infile.open(filename);
    cout << "\nWe are reading the file now: \n";
    if(infile.is_open()){
        while(infile.get(input))
                cout << input;
    }
    return 0;
}


const int LIM = 10;

int main(){
    char filecopy[LIM];
    char filepaste[LIM];
    char ch;
    ifstream infile;
    cout << "Enter the name of the file you want to copy from: ";
    cin >> filecopy;
    infile.open(filecopy);
    if(!infile.is_open()){
        cerr << "Could not open the file: " << filecopy << endl;
        exit(EXIT_FAILURE);
    }
    ofstream outfile;
    cout << "Enter the name of the file you want to copy into: ";
    cin >> filepaste;
    outfile.open(filepaste);
    if(!outfile.is_open()){
        cerr << "Could not open the file: " << filepaste << endl;
        exit(EXIT_FAILURE);
    }
    while(infile.get(ch))
        outfile << ch;
    infile.close();
    outfile.close();
    cout << "\nLet's see what we did\n";
    infile.open(filepaste);
    if(!infile.is_open()){
        cerr << "Could not open the file: " << filepaste << endl;
        exit(EXIT_FAILURE);
    }   
    while(infile.get(ch))
        cout << ch;
    return 0;
}
 
 

const int LIM = 80;

int main(){
    const char *copyone = "file1.txt";
    const char *copytwo = "file2.txt";
    const char *pasteone = "out.txt";
    string line1, line2;
    char ch;
    char ch1[LIM], ch2[LIM];
    ifstream inone;
    ifstream intwo;
    inone.open(copyone);
    intwo.open(copytwo);
    if(!inone.is_open() || !intwo.is_open()){
        cerr << "Could not open input files\n";
        exit(EXIT_FAILURE);
    }
    ofstream outfile;
    outfile.open(pasteone);
    if(!outfile.is_open()){
        cerr << "Could not open output file\n";
        exit(EXIT_FAILURE);   
    }
    do{        
        inone.get(ch1, LIM, '\n');
        intwo.get(ch2, LIM, '\n');
        outfile << ch1 << '\t' << ch2;
        outfile << endl;
    }while(inone.get(ch) && intwo.get(ch));
    inone.close();
    intwo.close();
    outfile.close();
    return 0;
}
 */

int main(){
    string mats[] = {"unu", "doi", "trei", "patru"};
    string pats[] = {"cinci", "patru", "trei", "sase"};    
    int sizes1, sizes2;
    sizes1 = sizeof(mats)/sizeof(mats[0]);
    sizes2 = sizeof(pats)/sizeof(pats[0]);
    set<string> matsie(mats, mats + sizes1);
    set<string> patsie(pats, pats + sizes2);
    set<string> matandpat;
    
    fstream matsfile, patsfile, matsandpats;
    
    matsfile.open("mats.dat", ios_base::out | ios_base::binary);
    if(!matsfile.is_open()){
        cerr << "Could not open mats file\n";
        exit(EXIT_FAILURE);
    }
    ostream_iterator<string> outmat(matsfile);
    copy(matsie.begin(), matsie.end(), outmat);
    
    patsfile.open("pats.dat", ios_base::out | ios_base::binary);
    if(!patsfile.is_open()){
        cerr << "Could not open pats file\n";
        exit(EXIT_FAILURE);
    }    
    ostream_iterator<string> outpat(patsfile);
    ostream_iterator<string> outandout(matsandpats);
    copy(patsie.begin(), patsie.end(), outpat);
    set_union(matsie.begin(), matsie.end(), patsie.begin(), patsie.end(),
            insert_iterator<set<string> >(matandpat, matandpat.begin()));
    matsandpats.open("matandpat.dat", ios_base::out | ios_base::binary);
    if(!matsandpats.is_open()){
        cerr << "Could not open the combined file\n";
        exit(EXIT_FAILURE);
    }    
    copy(matandpat.begin(), matandpat.end(), outandout);
    matsfile.close();
    patsfile.close();
    matsandpats.close();
    return 0;
}