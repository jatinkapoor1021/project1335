#include "MoveAll.hpp"
#include "Book.hpp"
#include <vector>
#include <string>

int moveAll(std::vector<Book>& catalog, std::vector<Book>& cart, const std::string& keyword) {
    int books_moved = 0;
    auto it = catalog.begin();
    while (it != catalog.end()) {
        if (containsKeyword(*it, keyword)) {
            cart.push_back(std::move(*it)); // Move the book to the cart
            it = catalog.erase(it); // Remove the book from the catalog
            ++books_moved;
        } else {
            ++it;
        }
    }
    return books_moved;
}

bool containsKeyword(const Book& book, const std::string& keyword) {
    for (const auto& key : book.keywords_) {
        if (key == keyword) {
            return true;
        }
    }
    return false;
}
