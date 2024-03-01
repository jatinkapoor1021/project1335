#include "Book.hpp"

// write and document all methods in this file.

// default constructor: Book::Book
Book::Book()
{
    title_ = "";
    author_ = "";
    ISBN_ = 0;
    icon_ = nullptr;
    price_ = 0.0;
    keywords_ = {};
    blurb_ = "";
}

// destructor Book::~Book()
Book::~Book()
{
    delete[] icon_;
    icon_ = nullptr;
}

// copy constructor Book::Book(const Book &rhs)
Book::Book(const Book &rhs)
{
    title_ = rhs.title_;
    author_ = rhs.author_;
    ISBN_ = rhs.ISBN_;

    if (rhs.icon_ != nullptr)
    {
        icon_ = new int[80];
        std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
    }
    else
        icon_ = nullptr;

    price_ = rhs.price_;
    keywords_ = rhs.keywords_;
    blurb_ = rhs.blurb_;
}

// copy assignment Book &Book::operator=(const Book &rhs)
Book &Book::operator=(const Book &rhs)
{
    Book temp = rhs;
    std::swap(*this, temp);
    return *this;
}

// moving the constructor Book::Book(Book &&rhs)
Book::Book(Book &&rhs)
{
    title_ = std::move(rhs.title_);
    author_ = std::move(rhs.author_);
    ISBN_ = rhs.ISBN_;

    icon_ = rhs.icon_;
    rhs.icon_ = nullptr;

    price_ = rhs.price_;

    keywords_ = std::move(rhs.keywords_);
    blurb_ = std::move(rhs.blurb_);
}

// moving assignment operator Book &Book::operator=(Book &&rhs)
Book &Book::operator=(Book &&rhs)
{
    if (this != &rhs)
    {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = rhs.ISBN_;

        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;

        price_ = rhs.price_;

        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
    }
    return *this;
}


//Book::getTitle()
const std::string &Book::getTitle() const
{
    return title_;
}

//void Book
void Book::setTitle(const std::string &title)
{
    title_ = title;
}


//getAuthor
const std::string &Book::getAuthor() const
{
    return author_;
}


//setAuthor
void Book::setAuthor(const std::string &author)
{
    author_ = author;
}

//int Book::getISBN()
long long int Book::getISBN() const
{
    return ISBN_;
}

//Book::setISBN
void Book::setISBN(long long int ISBN)
{
    ISBN_ = ISBN;
}
//getIcon
const int *Book::getIcon() const
{
    return icon_;
}
//setIcon
void Book::setIcon(int *icon)
{
    icon_ = icon;
}

//getPrice
float Book::getPrice() const
{
    return price_;
}

//setPrice
void Book::setPrice(float price)
{
    price_ = price;
}

//getKeywords
const std::vector<std::string> &Book::getKeywords() const
{
    return keywords_;
}


//setKeywords
void Book::setKeywords(const std::vector<std::string> &keywords)
{
    keywords_ = keywords;
}


//getBlurb
const std::string &Book::getBlurb() const
{
    return blurb_;
}

//setBlurb
void Book::setBlurb(const std::string &blurb)
{
    blurb_ = blurb;
}



// constructor  void Book::print()
void Book::print() const
{
    std::string keywords;
    for (auto kw = this->getKeywords().begin(); kw != this->getKeywords().end(); kw++)
    {
        if (kw == this->getKeywords().end() - 1)
        {
            keywords += (*kw);
        }
        else
        {
            keywords += (*kw + ", ");
        }
    }

    std::string icon;
    for (int i = 0; i < 80; i++)
    {
        if (i == 79)
        {
            icon += std::to_string(icon_[i]);
        }
        else
        {
            icon += std::to_string(icon_[i]) + " ";
        }
    }

    std::cout << "Title: " << title_; 
              << "Author: " << author_;
              << "ISBN: " << ISBN_; 
              << "Icon: " << icon;
              << "Price: $" << std::fixed << std::setprecision(2) << price_:
              << "Keywords: " << keywords: 
              << "Blurb: " << blurb_;
}
