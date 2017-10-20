/***** Complete this file. *****/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include "Book.h"

using namespace std;


Book::Book():isbn(""), last(""), first(""), title(""){}

Book::Book(string _isbn, string _last, string _first, string _title):isbn(_isbn), last(_last), first(_first), title(_title){}

// ostream& operator <<(ostream& outs, const Book::Category& category)
// {
//  switch (category)
//  {
//     case 0:  outs << "fiction";   break;
//     case 1:  outs << "history";   break;
//     case 2: outs << "technical";  break;
//     case 3:   outs << "none";     break;
//  }

//  return outs;
// }

ostream& operator << (ostream& out, Book& book)
{
   out << "Book{ISBN=" << book.isbn << ", last=" << book.last << ", first=" << book.first << ", title=" << book.title << "}" << endl;
   return out;
}

istream& operator >> (istream& in, Book& book)
{
//    in.get(); //skip the blank after the command
    getline (in, book.isbn, ',');
    getline (in, book.last, ',');
    getline (in, book.first, ',');
    getline (in, book.title);

    return in;
}

string Book::get_isbn() {return isbn;}

string Book::get_last() { return last; }

string Book::get_first()  { return first; }

string Book::get_title()  { return title; }

// Book::Category Book::get_category() const { return category; }

Book::~Book(){}



