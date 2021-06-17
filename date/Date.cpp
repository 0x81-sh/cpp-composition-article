#include "Date.h"
#include <iostream>
#include <iomanip>

#define ZERO_YEAR 2000

using namespace std;
const string monthList[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

bool Date::isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

bool Date::dateIsValid(int d, int m, int y) {
    return (0 < d && d <= monthDays(m, y) && 0 < m && m <= 12);
}

Date::Date(int day, int month, int year) {
    this->year = year;
    if (!dateIsValid(day, month, year)) {
        this->month = 1;
        this->day = 1;
    } else {
        this->day = day;
        this->month = month;
    }
}

void Date::setDate(int day, int month, int year) {
    if (!dateIsValid(day, month, year)) {
        cerr << "Can not set date to invalid value." << endl;
        return;
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::setDate(const Date &date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

bool Date::isLeapYear() const {
    return isLeapYear(this->year);
}

void Date::show(int type) const {
    switch (type) {
        default:
        case SHORT:
            cout << right << setw(2) << setfill('0') << this->day << "." << setw(2) << setfill('0') << this->month << "." << this->year << endl;
            break;
        case MEDIUM:
            cout << right << setw(2) << setfill('0') << this->day << ". " << monthList[this->month - 1].substr(0, 3) << ". " << this->year << endl;
            break;
        case FULL:
            cout << right << setw(2) << setfill('0') << this->day << ". " << monthList[this->month - 1] << " " << this->year << endl;
            break;
    }
}

int Date::yearDays(int y) {
    return 365 + isLeapYear(y);
}

int Date::monthDays(int m, int y) {
    return m == 2 ? 28 + isLeapYear(y) : 30 + !(((m - 1) % 7) % 2);
}

int Date::toDay(const Date &date) {
    int m = date.month;
    int d = date.day - 1;
    int y = date.year;

    while (--m > 0) {
        d += monthDays(m, y);
    }
    while (m < 0) {
        d -= monthDays(m++, y);
    }
    while (y > ZERO_YEAR) {
        d += yearDays(y-- - 1);
    }
    while (y < ZERO_YEAR) {
        d -= yearDays(y++);
    }
    return d;
}

Date* Date::toDate(int d) {
    bool n = d < 0;
    int m = 1 + n * 11;
    int y = ZERO_YEAR - n;

    while (d >= yearDays(y)) {
        d -= yearDays(y++);
    }
    while (d >= monthDays(m, y)) {
        d -= monthDays(m++, y);
    }

    ++d;
    while (d <= -yearDays(y)) {
        d += yearDays(y--);
    }
    while (d <= -monthDays(m, y)) {
        d += monthDays(m--, y);
    }

    d += n * monthDays(m, y);
    return new Date(d, m, y);
}

void Date::add(int days) {
    int d = toDay(*this) + days;

    Date *res = toDate(d);
    this->setDate(*res);
    delete res;
}

int Date::diff(const Date &date) const {
    return abs(toDay(*this) - toDay(date));
}

bool Date::operator== (const Date &b) const {
    return b.day == this->day &&
           b.month == this->month &&
           b.year == this->year;
}

//-------------- getters

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}
