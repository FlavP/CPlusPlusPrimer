/* 
 * File:   smart.cpp
 * Author: flavius
 *
 * Created on October 18, 2017, 9:52 PM
 */

#include <memory>
#include <iostream>
#include <string>

using namespace std;

/*
 * 


class Report{
private:
    string str;
public:
    Report(const string s) : str(s){cout << "Object created!\n";}
    ~Report(){cout << "Object destroyed!\n";}
    void comment() const {cout << str << "\n"; }
};

int main() {
    {
        auto_ptr<Report> ps (new Report("using auto_ptr"));
        ps->comment();
    }
    {
        shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }
    {
        unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->comment();
    }
    return 0;
}

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review {
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
bool operator<(const Review & t1, const Review & t2);
bool worseThan(const Review & t1, const Review & t2);
void ShowReview(const Review & rr);

/*
int main(){
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if(num > 0){
        cout << "You've entered the following:\n";
        for_each(books.begin(), books.end(), ShowReview);
        vector<Review>::iterator pr;
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        vector <Review> oldlist(books); // copy constructor
        if(num > 3){
            //remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasure:\n";
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            //insert one item
            books.insert(books.begin(), oldlist.begin() + 1, 
                    oldlist.begin() + 2);
            cout << "After insertions: \n";
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout << "Swapping: \n";
        for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr); 
    }
    else
        cout << "You did not enter anything\n";
    return 0;
}
*/
using namespace std;
int main(){
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(temp); 
    if(books.size() > 0){
        cout << "You enetered the following: \n";
        for_each(books.begin(), books.end(), ShowReview);
        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        
        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
        
        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries\n";
    return 0;
}

bool operator<(const Review  &r1, const Review &r2){
    if(r1.title < r2.title)
        return true;
    else if(r1.title ==  r2.title && r1.rating < r2.rating)
        return true;
    else return false;
}

bool worseThan(const Review  &r1, const Review &r2){
    if(r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr){
    std::cout << "Enter book title, quit to quit: ";
    std::getline(std::cin, rr.title);
    if(rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin)
        return false;
    // get rid of the rest of input line
    while(std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr){
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}