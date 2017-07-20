/*
#include <iostream>
#include "libs.h"

void other(void);
void another(void);

int main(){
    using debts::Debt;
    
    using debts::showDebt;
    
    Debt golf = {{"Johnny", "Ciomagovici"}, 120.0};
    showDebt(golf);
    other();
    another();
    return 0;
}

void other(void){
    using std::cout;
    using std::endl;
    using namespace debts;
    int i=0;
    Person db = {"Wehave","Cookies"};
    showPerson(db);
    cout << endl;
    Debt debters[3];
    for(i=0; i < 3; i++){
        getDebt(debters[i]);
    }
    for(i=0; i< 3; i++){
        showDebt(debters[i]);
    }
    cout << "Total debt: $" << sumDebts(debters, 3) << endl;
}

void another(void){
    using person::Person;
    Person collector = {"Mo", "Lawnshark"};
    person::showPerson(collector);
    std::cout << std::endl;
}
*/