#include <iostream>
#include "Article.h"

void mainPart4 ();
void mainPart5 ();

int main() {
    mainPart4();
    mainPart5();

    std::cout << std::endl << "Article count at program end: " << Article::getInst() << std::endl;
    return 0;
}

void mainPart4 () {
    Article a1(1001, Article::HARDWARE, "Optical Mouse", 10, 8, 2012, 12.90);

    MyString name("NoVirus 2015");
    Date date(15, 9, 2015);
    Article a2(2001, Article::SOFTWARE, name, date, 39.49);

    Article* aPtr = new Article(3001);
    aPtr->setPrice(10.00);

    double totalSum = a1.getPrice() + a2.getPrice() + aPtr->getPrice();
    std::cout << "Total price: " << totalSum << " Euro" << std::endl << "Thank you." << std::endl;

    delete aPtr;
}

void mainPart5 () {
    std::cout << std::endl << "Current article instance count: " << Article::getInst() << std::endl;
    Article art1(1001, Article::HARDWARE, "Optical Mouse",
                 10, 8, 2012, 12.90);
    Article* artPtr = new Article[10];  //!!Default Constructor used
    std::cout << "Current article instance count: " << Article::getInst() << std::endl;
    delete[] artPtr;
    std::cout << "Current article instance count: " << Article::getInst() << std::endl;
}