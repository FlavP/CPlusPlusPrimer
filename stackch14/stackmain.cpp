/* 
 * File:   stackmain.cpp
 * Author: flavius
 *
 * Created on October 8, 2017, 1:51 PM
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "stack.h"

using namespace std;
const int Num = 10;
/*
 * 

int main() {
    Stack<string> st;
    char ch;
    string po;
    cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
    while(cin >> ch && toupper(ch) !='Q'){
        while(cin.get() != '\n')
            continue;
        if(!isalpha(ch)){
            cout << '\a';
            continue;
        }
        switch(ch){
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if(st.isfull())
                          cout << "stack already full\n";
                      else
                          st.push(po);
                      break;
            case 'P':
            case 'p': if(st.isempty())
                            cout << "Stack already empty\n";
                      else{
                            st.pop(po);
                            cout << "PO #" << po << " popped\n";
                            break;
                      }
        }
        cout << "Please enter A to purchase another order,\n"
                << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
 */

int main (){
    srand(time(0));
    cout << "Please enter stack size: ";
    int stacksize;
    cin >> stacksize;
    Stack<const char *> st(stacksize);
    //in basket
    const char * in[Num] = {
    " 1: Hank Moody", " 2: Phil Pilly",
    " 3: Betty Boop", " 4: Jordan O'Neill",
    " 5: Wolfgang Peterson", " 6: Jurgen Kloop",
    " 7: Bernie Fox", " 8: Juan de Mata",
    " 9: Joy Almond", " 10: Roy Michelle"
    };
    //out basket
    const char * out[Num];
    int processed = 0;
    int nextin = 0;
    while(processed < Num){
        if(st.isempty())
            st.push(in[nextin++]);
        else if(st.isfull())
            st.pop(out[processed++]);
        else if(rand() % 2 && nextin < Num)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    int i;
    for(i = 0; i < Num; i++)
        cout << "Unu" << out[i] << endl;
    cout << "Bye\n";
    return 0;
}
