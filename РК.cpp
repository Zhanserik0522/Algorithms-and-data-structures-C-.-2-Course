#include<iostream>
#include<cmath>
using namespace std;

class Date {
    int day;
    int month;
    int year;

    int DAYS_IN_MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string MONTHS[12] = {"January", "Februart" ,"March" , " Aipril" ,"May" , "June" ," July" ," August" ," September" ," Octomber" ," November" ," December"}; // complete

public:
    Date(int day, int month, int year) {
        if (month >= 1 && month <= 12) {
            this->month = month;
            isValid;
        }
        for (int i = month; i < 1; i++) {
            if (day >= DAYS_IN_MONTHS[month] && day <= DAYS_IN_MONTHS[month]) {
                this->day = day;
                isValid;
            }
        }
        this->year = year;
    }

  
    int getday() {
        return day;
    }
    int getmonth() {
        return month;
    }
    int getyear() {
        return year;
    }
    void setday(int day) {
        this->day = day;
    }
    void setmonth(int month) {
        this->month = month;
    }
    void setyear(int year) {
        this->year = year;
    }


    friend ostream operator << (ostream& out, Date& date) {
        if (date.day = 1) {
            out << date.day << "st " << date.month << " " << date.year << endl;
        }
        if (date.day = 2) {
            out << date.day << "nd " << date.month << " " << date.year << endl;
        }
        if (date.day = 3) {
            out << date.day << "rd " << date.month << " " << date.year << endl;
        }
        else {
            out << date.day << "rd " << date.month << " " << date.year << endl;
        }
    }
    // Overload increment and decrement operators

    void operator ++ (int) {
        day += 1;
    }

    void operator -- (int) {
        day -= 1;
    }

    bool isLeapYear() {
        if (year % 4 == 0 && year % 100 == 0 || year % 400 == 0) {
            return false;
        }
        return true;
    }

    bool isValid() {
        for (int i = month; i < 1; i++) {
            if (day > DAYS_IN_MONTHS[month] && day < DAYS_IN_MONTHS[month]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Date date(1, 1, 2019);
    Date date1(29, 2, 2019);    // Incorrect date

    cout << date << endl;       // 1st January, 2019

    date--;

    cout << date << endl;       // 31th December, 2018

    date++;
    date++;

    cout << date << endl;       // 2nd January, 2019
    return 0;
}