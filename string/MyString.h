#pragma once

class MyString {
    private:
        char *str;
        int length;

        //copying re-alloc
        void cpyAlloc(int sz);
    public:
        MyString(const char *str = "");
        MyString(const MyString &ref);
        ~MyString();

        bool operator== (const MyString &ref) const;
        bool operator!= (const MyString &ref) const;

        int getLength() const;
        void show() const;
        void showDebug() const;
        void append(const MyString &str);
        void addChar(char ch);
        char getChar(int idx) const;
        int compare (const MyString &str) const;
        void toUpper();
        void toLower();
        void insertCharAt(char ch, int idx);
        void insertStrAt(const MyString &str, int idx);
};
