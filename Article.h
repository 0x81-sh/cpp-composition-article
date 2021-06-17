#pragma once
#include "string/MyString.h"
#include "date/Date.h"

class Article {
    private:
        static int instanceCount;

        const int id;
        int type;
        MyString label;
        Date inStockSince;
        double price;
    public:
        static const int HARDWARE = 0;
        static const int SOFTWARE = 1;
        static int getInst();

        Article(int id = 0, int type = HARDWARE, const MyString &label = "???", const Date &inStockSince = {}, double price = 0.0); //id has default property to prevent default constructor
        Article(int id, int type, const MyString &label, int d = 1, int m = 1, int y = 2000, double price = 0.0);
        ~Article();
        int getId() const;
        int getType() const;
        void setType(int type);
        const MyString &getLabel() const;
        void setLabel(const MyString &label);
        const Date &getInStockSince() const;
        void setInStockSince(const Date &inStockSince);
        double getPrice() const;
        void setPrice(double price);
};

