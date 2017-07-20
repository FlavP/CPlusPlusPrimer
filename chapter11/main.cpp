

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "complex0.h"
#include "vector.h"
#include "timer.h"

using namespace std;

/*
 * 
 */
int main() {/*
    Timer planning;
    Timer coding(2, 40);
    Timer fixing(5, 55);
    Timer total;
    Timer impredict;
    cout << "planning time = ";
    cout << planning;
    cout << endl;
    cout << "coding time = ";
    cout << coding;
    cout << endl;
    total = coding + fixing;
    cout << "coding + fixing = ";
    cout << total;
    cout << endl;
    
    Timer morefixing(3, 28);
    cout << "more fixing time = ";
    cout << morefixing;
    cout << endl;
    total = morefixing.operator +(total);
    cout << "new total = ";
    cout << total;
    cout << endl;
    total = total * 1.5;
    cout << "even newer total = ";
    cout << total << endl;
    impredict = 4.5 * coding;
    cout << impredict;
    cout << endl;

    using VECTOR::Vector;
    ofstream os;
    srand(time(0));   // seed random number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    os.open("distance.txt", std::ofstream::out);
    cout << "Enter distance to target (q to quit): ";
    while (cin >> target){
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;
        os << "Target Distance: " << target << ", Step Size: " << dstep;
        while (result.get_mag() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::Pol);
            os << steps << ": " << step;
            result = result + step;
            steps++;
        }    
        
        os << "After " << steps << " steps, the subject has the following location:\n";
        os << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
                << result.get_mag()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    os.close();
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n')
        continue;
    */
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c){
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c = " << a + c << '\n';
        cout << "a - c = " << a - c << '\n';
        cout << "a * c = " << a * c << '\n';
        cout << "-2 * c = " << -2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }   
    cout << "Done!\n";
    return 0;
}

