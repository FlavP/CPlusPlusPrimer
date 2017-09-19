/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavius
 *
 * Created on June 21, 2017, 4:41 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

/*
 * 
 */

struct bop {
    
    string fullname;
    string title;
    string bopname;
    int preference;
};

struct donors{
    string name;
    int amount;
};

int main() {
    /*
    char choice;
    string result;
    cout << "Please enter one of the following choices:"<< endl;
    cout << "c), t), p), g)" << endl;
    cin >> choice;
    while(choice != 'c' && choice != 't' && choice != 'p' && choice != 'g' ){
            cout << "Please enter a c, p, t, or g: ";
            cin >> choice;
            }    
    switch(choice){
        case 'c': 
            result = "carnivore";
            break;    
        case 'p':
            result = "pianist";
            break;
        case 't':
            result = "tree";
            break;
        case 'g':
            result = "game";
            break;  
}
    cout << "A maple is a " << result << endl;     
    int structSize = 3;
    bop *bulop = new bop[structSize];
    char cf;
    cout << "a. display by name" << '\t' << "b. display by title" << endl;
    cout << "c. display by bopname" << '\t' << "d. display by preference" << endl;
    cout << "q. quit";
    cf = cin.get();
    bulop[0].fullname = "Ion Ionescu";
    bulop[0].title = "Om al muncii";
    bulop[0].bopname = "Blion Bulion";
    bulop[0].preference = 2;
    bulop[1].fullname = "Nae Caciula";
    bulop[1].title = "Om al muncii fara scula";
    bulop[1].bopname = "Cacaciula";
    bulop[1].preference = 5;    
    bulop[2].fullname = "Willian Branza";
    bulop[2].title = "De-putat";
    bulop[2].bopname = "Telemea pe dinti";
    bulop[2].preference = 10;    
    while (cf != 'q') {
        switch (cf) {
        case 'a':
        for(int i = 0; i < structSize; i++){
            cout << bulop[i].fullname << endl;
            }
        cout << "Enter your choice: " << endl;
        cin >> cf;
        break;
        case 'b':
        for(int i = 0; i < structSize; i++){
            cout << bulop[i].title << endl;
            }
        cout << "Enter your choice: " << endl;
        cin >> cf;
        break;
        case 'c':
        for(int i = 0; i < structSize; i++){
            cout << bulop[i].bopname << endl;
            }
        cout << "Enter your choice: " << endl;
        cin >> cf;
        break;
        case 'd':
        for(int i = 0; i < structSize; i++){
            cout << bulop[i].preference << endl;
            }
        cout << "Enter your choice: " << endl;        
        cin >> cf; 
        break;
        }
    }
    delete bulop;
    /*
    ofstream Filolel;
    ifstream readFile;
    string filename = "file1.txt";
    //Filolel.open(filename);
    //Filolel << "Different this" << endl << "Different that" << endl << "Different other";
    //Filolel.close();
    readFile.open(filename.c_str());
    if(!readFile.is_open()){
        cout << "Could not open file" << filename << endl;
        cout << "Exiting \n";
        exit(EXIT_FAILURE);
    }
    string cucumba, finalstring;
    int count = 0;
    while(readFile >> cucumba){
        ++count;
        finalstring += cucumba;        
    }
    
    if(readFile.eof()){
        cout << "This is the end of file. \n";
    }
    
    else if(readFile.fail()){
        cout << "The program crashed do to data mismatch. \n";
    }
    
    else
        cout << "The program crashed for unknown reasons. \n";
        
    if(count==0){
        cout << "There was no data";
    }
    else{
        cout << "Number of characters is: " << finalstring.size() << endl;
    }
    readFile.close();
    
    int noDonors;
    
    
    cout << "How many donors?" << endl;
    cin >> noDonors;
    cin.clear();
    int donations[noDonors];
    donors *organe = new donors[noDonors];
        for(int i=0; i < noDonors; i++){
        cin.ignore();
        cout << "Enter donor " << i+1 << " name " << endl;
        getline(cin, (organe+i)->name);
        cout << "Enter donor " << i+1 << " donation " << endl;
        cin >> (organe+i)->amount;
    }
    
    ifstream readOne;
    int noDonors;
    string name;
    int donation;
    readOne.open("donations.txt");
    readOne >> noDonors;
    readOne.get();
    donors *organe = new donors[noDonors];
    
    for(int i=0; i < noDonors; i++){
        getline(readOne, (organe + i)->name);
        readOne >> (organe + i)->amount;
        readOne.get();
    } 
    
    for(int j=0; j < noDonors; j++){
        if((organe + j)->amount > 10000){
            donation++;
        }
    }
    cout << donation << " baieti sunt balene" << endl;
    cout << "Restul de " << noDonors - donation << " sunt niste saraci" << endl;
    delete organe;
    readOne.close();
    */
    ofstream outputFile;
    ifstream inputFile;
    int nodonors;
    cout << "How many donors? ";
    cin >> nodonors;
    cin.clear();
    donors * don = new donors[nodonors];
    outputFile.open("donations.txt");
    for(int i = 0; i < nodonors; i++){
       cin.ignore();
       cout << "The name of the donor is: " << endl;
       getline(cin, (don + i)->name);
       cout << "The amount of money donated by " << (don + i)->name << " is: ";
       cin >> (don + i)->amount;
       if(outputFile.is_open())
           outputFile << (don + i)->name << '\t' << (don + i)->amount << endl;
    }
    delete don;
    outputFile.close();
    inputFile.open("donations.txt");
    if(!inputFile.is_open()){
        cout << "Could not open the file" << endl;
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while(inputFile.good()){
    ++count;
    }
    if(inputFile.eof()){
        cout << "End of file reached" << endl;
    }
    else if(inputFile.fail()){
        cout << "Input terminated by data mismatch" << endl;
    }
    else{
        cout << "Input terminated for unknown reason" << endl;
    }
    donors *receive = new donors[count];
    for(int i = 0; i < count; i++){
        inputFile >> (receive + i)->amount;
        getline(inputFile, (receive + i)->name);
        cout << (receive + i)->name << " donated " 
                << (receive + i)->amount << endl;
    }
    delete receive;
    inputFile.close();
    return 0;
}

