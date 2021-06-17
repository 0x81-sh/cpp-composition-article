#include "MyString.h"
#include <cstring>
#include <iostream>

void MyString::cpyAlloc(int sz) {
    sz++; //for \0

    char *old = str;
    str = new char[sz];

    strcpy(str, old);
    delete[] old;
}

MyString::MyString(const char *str) {
    this->length = strlen(str);

    this->str = new char[this->length + 1];
    strcpy(this->str, str);
}

MyString::MyString(const MyString &ref) {
    this->length = ref.length;

    this->str = new char[this->length + 1];
    strcpy(this->str, ref.str);
}

MyString::~MyString() {
    delete[] str;
}

bool MyString::operator==(const MyString &ref) const {
    return strcmp(str, ref.str) == 0;
}

bool MyString::operator!=(const MyString &ref) const {
    return strcmp(str, ref.str) != 0;
}

int MyString::getLength() const {
    return length;
}

void MyString::show() const {
    for (int i = 0; i < length; i++) {
        std::cout << str[i];
    }
}

void MyString::showDebug() const {
    for (int i = 0; i < length; i++) {
        std::cout << (int) str[i] << "<" << str[i] << ">" <<  ";";
    }

    //stdio breaks if \0 is outputted, therefore this workaround is needed
    if (str[length] != '\0') {
        std::cout << (int) str[length] << "<" << str[length] << ">";
    } else {
        std::cout << "\\0";
    }
}

void MyString::append(const MyString &str) {
    this->length += strlen(str.str);
    cpyAlloc(this->length);
    strcat(this->str, str.str);
}

void MyString::addChar(char ch) {
    length++;
    cpyAlloc(length);
    str[length - 1] = ch;
    str[length] = '\0';
}

char MyString::getChar(int idx) const {
    return str[idx];
}

int MyString::compare(const MyString &str) const {
    return strcmp(this->str, str.str);
}

void MyString::toUpper() {
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
}

void MyString::toLower() {
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

void MyString::insertCharAt(char ch, int idx) {
    length++;
    cpyAlloc(length);

    memmove(str + idx + 1, str + idx, length - idx); //strncpy does not have defined behaviour for overlapping source and destination, therefore memmove has to be used
    str[idx] = ch;
}

void MyString::insertStrAt(const MyString &str, int idx) {
    cpyAlloc(str.length + length);

    memmove(this->str + idx + str.length, this->str + idx, this->length - idx); //strncpy does not have defined behaviour for overlapping source and destination, therefore memmove has to be used
    memcpy(this->str + idx, str.str, str.length); //use memcpy to avoid copying \0 into the middle of the string

    this->length += str.length;
    //manually add \0 in the correct position
    this->str[this->length] = '\0';
}

