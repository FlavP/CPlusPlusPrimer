/* 
 * File:   inpexc.cpp
 * Author: flavius
 *
 * Created on October 22, 2017, 5:59 PM
 */

#include <exception>
#include <iostream>

using namespace std;

/*
 * 
 
int main() {
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";
    int sum = 0;
    int input;
    try{
        while(cin >> input){
            sum += input;
        }
    }catch(ios_base::failure & fv){
        cout << fv.what() << endl;
        cout << "Wahaaaa\n";
    }
    cout << "Last value for input: " << input << endl;
    cout << "Last value for sum: " << sum << endl;

    return 0;
}
 */

int main(){
    const int Limit = 255;
    char input[Limit];
    cout << "Enter a string for getline processing:\n";
    cin.getline(input, Limit, '#');
    cout << "Here is the output:\n";
    cout << input << "\nDone\n";
    
    char ch;
    cin.get(ch);
    cout << "The input character is: " << ch << endl;
    if(ch != '\n'){
        cin.ignore(Limit, '\n'); //discard the rest of the line
    }
    cout << "Enter a string for get() processing:\n";
    cin.get(input, Limit, '#');
    cout << "This is the second input:\n";
    cout << input << endl;
    
    cin.get(ch);
    cout << "The next input character is: " << ch << endl;
    return 0;
}

