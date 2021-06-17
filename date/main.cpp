#include <iostream>
#include <cassert>
#include "Date.h"

void testIsLeapYear(const Date &date, bool expected);
void testAdd(Date &source, int days, const Date &expected);
void testDiff(Date &source, const Date &comparison, int expected);

int main() {
    testIsLeapYear(Date(1, 1, 0), true);
    testIsLeapYear(Date(1, 1, 420), true);
    testIsLeapYear(Date(1, 1, 1000), false);
    testIsLeapYear(Date(1, 1, 2001), false);

    Date *testDate = new Date();
    testAdd(*testDate, 366, Date(1, 1, 2001));
    testAdd(*testDate, 1, Date(2, 1, 2001));
    testAdd(*testDate, 30, Date(1, 2, 2001));
    delete(testDate);

    Date *testDiffDate = new Date(1, 1, 2020);
    testDiff(*testDiffDate, Date(1, 1, 2019), 365);
    testDiff(*testDiffDate, Date(1, 2, 2020), 31);
    testDiff(*testDiffDate, Date(2, 1, 2020), 1);
    delete(testDiffDate);
}

void testIsLeapYear(const Date &date, bool expected) {
    assert(date.isLeapYear() == expected);
}

void testAdd(Date &source, int days, const Date &expected) {
    source.add(days);
    assert(source == expected);
}

void testDiff(Date &source, const Date &comparison, int expected) {
    assert(source.diff(comparison) == expected);
}