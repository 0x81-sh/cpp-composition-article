#include "Article.h"

int Article::instanceCount = 0;

Article::Article(int id, int type, const MyString &label, const Date &inStockSince, double price)
    : id(id), type(type), label(label), inStockSince(inStockSince), price(price) {
    Article::instanceCount++;
}

Article::Article(int id, int type, const MyString &label, int d, int m, int y, double price)
    : id(id), type(type), label(label), inStockSince(d, m, y), price(price) {
    Article::instanceCount++;
}

Article::~Article() {
    Article::instanceCount--;
};

int Article::getInst() {
    return Article::instanceCount;
}

int Article::getId() const {
    return id;
}

int Article::getType() const {
    return type;
}

void Article::setType(int type) {
    this->type = type;
}

const MyString &Article::getLabel() const {
    return label;
}

void Article::setLabel(const MyString &label) {
    this->label = label;
}

const Date &Article::getInStockSince() const {
    return inStockSince;
}

void Article::setInStockSince(const Date &inStockSince) {
    this->inStockSince = inStockSince;
}

double Article::getPrice() const {
    return price;
}

void Article::setPrice(double price) {
    this->price = price;
}
