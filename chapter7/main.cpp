/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavius
 *
 * Created on June 27, 2017, 11:32 AM

int create_prop(int casoi[], int n);
void show_prop(const int casoi[], int n);
void modify_prop(int casoi[], int n, int r);

int main() {
    const int homes = 5;
    int modif;
    int casoi[homes];
    int casute = create_prop(casoi, homes);
    show_prop(casoi, casute);
    if(casute > 0){
        cout << "Care este rata de modificare? " << endl;
        while(!(cin >> modif)){
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input, Please enter a number:";
        }
        modify_prop(casoi, casute, modif);
    }
    cout << "Done" << endl;
    
    show_prop(casoi, casute);
    return 0;
}

int create_prop(int casoi[], int n){
        int i, temp;
        for(i = 0; i < n; i++){            
            cout << "Value of real estate: " << i+1 << endl;
            cin >> temp;
            if(!cin){ //bad input
                cin.clear();
                while(cin.get() != '\n'){
                    continue;
                }
                cout << "Bad input; Terminate";
                break;
            }
            else if(temp < 0){
                break;
            }
            casoi[i] = temp;
    }
        return i;
}

void show_prop(const int casoi[], int n){
        int i;
        for(i = 0; i < n; i++){
            cout << "Value of real estate: " << i+1 << 
                    " is: " << casoi[i] << endl;            
    }
}

void modify_prop(int casoi[], int n, int r){
        int i;
        for(i = 0; i < n; i++){
            casoi[i] *= r;
            cout << "The new value of real estate: " << i+1 << 
                    " is: " << casoi[i] * r << endl;            
    }
}


int funcoff(const char *c, char d);
int main(){
    char mm[15] = "catacapleasca";
    char *kwoy = "ukulele";
    char cc = 'c';
    char ll = 'l';
    unsigned int numof_c, numof_l;
    numof_c = funcoff(mm, cc);
    numof_l = funcoff(kwoy, ll);
    cout << "Number of: " << cc << " in " << mm << " is " << numof_c <<endl;
    cout << "Number of: " << ll << " in " << kwoy << " is " << numof_l <<endl;
    return 0;
}

int funcoff(const char *c, char d){
    unsigned int count = 0;
    while(*c){
        if(*c == d){
            count++;
        }
        c++;
    }
    return count;
}

char * build_string(char c, int d);

int main(){
    char c;
    int d;
    cout << "Give us a character: " << endl;
    cin >> c;
    cout << "Repeat how many times: " << endl;
    cin >> d;
    char *gigel = build_string(c, d);
    cout << "Here is the string: " << gigel << endl;
    delete gigel;
    return 0;
}

char * build_string(char c, int d){
    char *ret = new char[d+1];
    ret[d] = '\0';
    while(d-- > 0){
        ret[d] = c;
    }
    return ret;
}

using namespace std;

struct rect{
    double x;
    double y;
};

struct polar{
    double distance;
    double angle;
};

void rect_to_polar(const rect *one, polar *two);
void show_polar(const polar *two);

int main(){
    rect one;
    polar two;
    cout << "Give coordonates " << endl;
    while(cin >> one.x >> one.y){
        rect_to_polar(&one, &two);
        show_polar(&two);
    }
    return 0;
}

void rect_to_polar(const rect *one, polar *two){    
    two->distance = sqrt(one->x * one->x + one->y * one->y);
    two->angle = atan2(one->y, one->y);
}

void show_polar(const polar * two){
    const double coef = 57.29577951;
    cout << "The distance is: " << two->distance << endl;
    cout << "The angle is: " << two->angle << endl;
}

const int SIZE = 4;

void display(const string st[], int n);

int main(){
    string alist[SIZE];
    cout << "Enter " << SIZE << " bullshit names: " << endl;
    for(int i=0; i < SIZE; i++){
        cout << i + 1 << ": ";
        getline(cin, alist[i]);
        }
    cout << "The list: \n";
    display(alist, SIZE);
    
    return 0;
}

void display(const string st[], int n){
    for(int i=0; i < n; i++){
        cout << i + 1 << ": " << st[i] <<endl;
    }
}

const int Seasons = 4;
const array<string, Seasons> colec = {"Primavara", "Vara", "Toamna", "Iarna"};
void putvalues(array<double, Seasons> *modif_pointer);
void readvalues(const array<double, Seasons> take_values);

int main(){
    array<double, Seasons> dob_of_array;
    putvalues(&dob_of_array);
    readvalues(dob_of_array);
    return 0;
}

void putvalues(array<double, Seasons> *modif_pointer){
    for(int i=0; i < Seasons; i++){
        cout << "Enter " << colec[i] << " numbers " << endl;
        cin >> (*modif_pointer)[i];
    }
}

void readvalues(const array<double, Seasons> take_values){
    double tot = 0.0;
    for(int i=0; i < Seasons; i++){
        cout << "The number for the month of " << colec[i] << " is " <<
                take_values[i] << endl;
        tot += take_values[i];
    }
}



void howmany(int n);

int main(){
    howmany(4);
    return 0;
}

void howmany(int n){
    cout << "Counting down " << n << endl;
    if(n > 0){
        howmany(n-1);
    }
    cout << n << " is n now" << endl;
}
 */

#include <iostream>
#include <cstring>

using namespace std;
/*
void ruler(char art[], int min, int max, int levels);

int main(){
    int artsize = 88;
    int level = 8;
    int min, max;
    char art[artsize];
    for(int i = 0; i < artsize - 2; i++){
        art[i] = ' ';
    }
    art[artsize - 1] = '\0';
    min = 0;
    max = artsize - 2;
    art[min] = art[max] = '|';
    cout << art << endl;
    for(int j = 0; j < level; j++){
        ruler(art, min, max, j);
        cout << art << endl;    
        for(int k=0; k < artsize - 2; k++){
            art[k] = ' ';
        }
    }
    return 1;
}

void ruler(char art[], int min, int max, int level){
    if(level == 0)
        return;
    int mid = (min + max)/2;
    art[mid] = '|';
    ruler(art, min, mid, level - 1);
    ruler(art, mid, max, level - 1);
    
}
 

void setelem(int arr[], int n, int gig);

int main(){
    const int n = 10;
    int arr[n];
    const int tic = 4;
    setelem(arr, n, tic);
    for(int i=0; i < n; i++){
        cout << "Elementul " << i + 1 << " are valoarea " << arr[i] << endl;
    }
    return 0;
}

void setelem(int arr[], int n, int gig){
    for(int i = 0; i < n; i++){
        arr[i] = gig;
    }
}


double trouble(const double arr[], int n);

int main(){
    const int n = 5;
    double max;
    double arr[] = {345.28, 792.37, 793.01, 793.02, 543.2};
    max = trouble(arr, n);
    cout << "The maximum is: " << max << endl;
    return 0;
}

double trouble(const double arr[], int n){
    double max;
    for(int i = 0;i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}


int replace(char * str, char c1, char c2);

int main(){
    char * tr = "traiasca ma-ta";
    char c1, c2;
    int deori = 0;
    cout << "Ce caracter vreti sa fie inlocuit? " << endl;
    cin >> c1;
    cout << "Cu ce caracter doriti sa se faca inlocuirea? " << endl;
    cin >> c2;
    deori = replace(tr, c1, c2);
    cout << "S-a intamplat de " << deori << " ori" << endl;
    return 0;
}

int replace(char *str, char c1, char c2){
    int counter = 0;
    while(*str){
        if(*str == c1){
            *str = c2;
            counter++;
        }
        str++;
    }
    return counter;
}

struct applicant {
    char name[30];
    int credit_ratings[3];
};

//void show_applicant(applicant gigel);

void show_applicant(applicant *gigel);
void f1(applicant *a);
const char * f2(const applicant * a1, const applicant *a2);

int main(){
    typedef void (*p_f1)(applicant *);
    p_f1 p1 = f1;
    typedef const char *(*p_f2)(const applicant *, const applicant *);
    p_f2 p2 = f2;
    p_f1 ap1[5];
    p_f2 (*ap2)[10];
    applicant *t = new applicant;
    string s = "Ion";
    strcpy(t->name, s.c_str());
    //strncpy(t.name, s.c_str(), sizeof(t.name));
    t->credit_ratings[0] = 1;
    t->credit_ratings[2] = 0;
    t->credit_ratings[1] = 2;

    show_applicant(t);
    return 0;
}


//void show_applicant(applicant gigel){
//    cout << "Applicant name: " << gigel.name << endl;
//    for(int i=0; i < 3; i++){
//        cout << gigel.credit_ratings[i] << endl;
//    }
//}

void show_applicant(applicant *gigel){
    cout << "Applicant name: " << gigel->name << endl;
    for(int i=0; i < 3; i++){
        cout << gigel->credit_ratings[i] << endl;
    }
}



double harmonic(double x, double y);

int main(){
    double x, y, answ;
    do{
    cout << "Please give me two numbers " << endl;
    cin >> x >> y;
    answ = harmonic(x, y);
    cout << "The harmonic average is: " << answ << endl;
    }while(x !=0 && y !=0);
}

double harmonic(double x, double y){
    return 2*x*y/(x + y);
}
 

int create_arr(float arr[], int n);
void display_arr(const float arr[], int n);
float avg(const float arr[], int n);

int main(){
    const int size = 10;
    int act_size;
    float iot[size];
    act_size = create_arr(iot, size);
    display_arr(iot, act_size);
    float aver = avg(iot, act_size);
    cout << "The average is: " << aver << endl;
    return 0;
}

int create_arr(float arr[], int n){
    int i;
    for(i=0; i < n; i++){
        cout << "Element " << i+1 << " is: " << endl;
        if(!(cin >> arr[i]))
            break;
    }
    return i;
}


void display_arr(const float arr[], int n){
    for(int i=0; i < n; i++){
        cout << "Element " << i+1 << " is: " << arr[i] << endl;
    }
}

float avg(const float arr[], int n){
    float tot = 0;
    for(int i=0; i < n; i++){
        tot += arr[i];
    }
    return tot/n;
}

struct box{
    char maker[40];
    float height;
    float width;
    float weight;
    float volume;
};

void display_box(box cutie);

void volume(box *cutie);

int main(){
    box cutiuta;
    float vol;
    cout << "Make: " << endl;
    cin.getline(cutiuta.maker, 40);
    cout << "Height: " << endl;
    cin >> cutiuta.height;
    cout << "Width: " << endl;
    cin >> cutiuta.width;
    cout << "Weight: " << endl;
    cin >> cutiuta.weight;
    box *pointbox;
    pointbox = &cutiuta; // Vezi aici ba!
    volume(pointbox);
    cout << pointbox->height << " " << pointbox->volume << endl;
    display_box(cutiuta);
    return 0;
}

void display_box(box cutie){
    cout << "Make: " << cutie.maker << endl;
    cout << "Height: " << cutie.height << endl;
    cout << "Width: " << cutie.width << endl;
    cout << "Weight: " << cutie.weight << endl;
    cout << "Volume: " << cutie.volume << endl;
}

void volume(box *cutie){
    cutie->volume = cutie->height * cutie->weight * cutie->width;
}



long double factorial(int num);

int main(){
    int num;
    double fac;
    fac = factorial(3);
    cout << "Factorial is: " << fac << endl;
    return 0;
}

long double factorial(int num){
    if(num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}


int fill_array(double arr[], int n);

void show_array(const double arr[], int n);

void reverse_array(double arr[], int n);

int main(){
    int maxSize = 10;
    int actSize;
    double arr[maxSize];
    actSize = fill_array(arr, maxSize);
    show_array(arr, actSize);
    reverse_array(arr, actSize);
    show_array(arr, actSize);
    return 0;
}

int fill_array(double arr[], int n){
    int i = 0;
    cout << "Element " << i + 1 << " is: " << endl;
    while(i < n){
        if(!(cin >> arr[i]))
            break;
        else{
            i++;
            cout << "Element " << i + 1 << " is: " << endl;
        }
    }
    return i;
}

void show_array(const double arr[], int n){
    for(int i=0; i < n; i++){
        cout << "Element " << i+1 << " is: " << arr[i] << endl;
    }
}

void reverse_array(double arr[], int n){
    double temp;
    for(int i=0; i < n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-i-1] = temp;
    }
}


double * fill_array(double arr[], int n);

void show_array(const double arr[], double * pn);

void reverse_array(double arr[], double * pn);

int main(){
    int maxSize = 10;
    double * pn;
    double arr[maxSize];
    pn = fill_array(arr, maxSize);
    show_array(arr, pn);
    reverse_array(arr, pn);
    show_array(arr, pn);
    return 0;
}

double * fill_array(double arr[], int n){
    int i = 0;
    cout << "Element " << i + 1 << " is: " << endl;
    while(i < n){
        if(!(cin >> arr[i]))
            break;
        else{
            i++;
            cout << "Element " << i + 1 << " is: " << endl;
        }
    }
    return arr + i;
}

void show_array(const double arr[], double * pn){
    while(arr < pn){
        cout << "Element " << arr << " is: " << *arr << endl;
        arr++;
    }
}

void reverse_array(double arr[], double * pn){
    double temp;
    int i = 0;
    double *start;
    start = arr + i;
    double *end;
    end = pn - i - 1;
    double *half;
    half = arr + int(sizeof(pn)/2);
    cout << *half << endl;
    while(start <= start + half){
        temp = *start;       
        *start = *end;
        *end = temp;        
        start = arr + i;
        end = pn - i - 1;
        i++;
    }
}



const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(const student stud);
void display2(const student *stud);
void display3(const student pa[], int n);

int main(){
    cout << "enter class size: ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n'){
        continue;
    }
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for(int i = 0; i < entered; i++){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done";
    return 0;
    return 0;
}

int getinfo(student pa[], int n){
    int i;
    for(i=0; i < n; i++){
        cout << "Student " << i+1 << " fullname is: " << endl;
        cin.get(pa[i].fullname, SLEN);
        if(0 == strlen(pa[i].fullname))
            break;  
        else{
        while(cin.get() != '\n')
            continue;
        cout << "Student " << i+1 << " hobby is: " << endl;
        cin.get(pa[i].hobby, SLEN);
        cout << "Student " << i+1 << " ooplevel is: " << endl;       
        cin >> pa[i].ooplevel;
        cin.get();
        }
        }
    return i;
}

void display1(const student stud){
    cout << "Student fullname is: " << stud.fullname << endl;
    cout << "Student hobby is: " << stud.hobby << endl;
    cout << "Student ooplevel is: " << stud.ooplevel << endl;     
}

void display2(const student *stud){
    cout << "Student fullname is: " << stud->fullname << endl;
    cout << "Student hobby is: " << stud->hobby << endl;
    cout << "Student ooplevel is: " << stud->ooplevel << endl;     
}

void display3(const student pa[], int n){
    for(int i=0; i < n; i++){
        cout << "Student fullname is: " << pa[i].fullname << endl;
        cout << "Student hobby is: " << pa[i].hobby << endl;
        cout << "Student ooplevel is: " << pa[i].ooplevel << endl;
    }
}
*/

double add(double x, double y);
double subtract(double x, double y);
double mult(double x, double y);
double calculate(double x, double y, double (double, double));

int main(){
    double a, b;
    double result;
    cout << "Please enter two numbers" << endl;
    while(cin >> a >> b){
        result = calculate(a, b, add);
        cout << "Rezultatul este: " << result << endl;
        cout << "Please another two numbers " << endl;
    }
    return 0;
}

double add(double x, double y){
    return x + y;
}

double calculate(double x, double y, double p(double, double)){
    return (*p)(x, y);
}
