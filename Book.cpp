#include "Book.hpp"
#include <iostream>
#include <iomanip>

// Constructor
Book::Book(const std::string& title, const std::string& author, long long int ISBN,
           int* icon, float price, const std::vector<std::string>& keywords, const std::string& blurb)
    : title_(title), author_(author), ISBN_(ISBN), icon_(icon), price_(price), keywords_(keywords), blurb_(blurb) {}

// Destructor
Book::~Book() {
    delete[] icon_;
}

// Print method
void Book::print() const {
    std::cout << "Title: " << title_ << std::endl;
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "ISBN: " << ISBN_ << std::endl;
    std::cout << "Icon: ";
    for (int i = 0; i < 80; ++i) {
        std::cout << icon_[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << price_ << std::endl;
    std::cout << "Keywords: ";
    for (const auto& keyword : keywords_) {
        std::cout << keyword << " ";
    }
    std::cout << std::endl;
    std::cout << "Blurb: " << blurb_ << std::endl;
}
