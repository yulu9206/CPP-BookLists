#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include "BookNode.h"
#include "Book.h"

using namespace std;


BookNode::BookNode(Book book):book(book), next(nullptr){}
Book BookNode::get_book(){return book;}
BookNode * BookNode::get_next(){return next;}
void BookNode::set_next(BookNode* nextptr){next = nextptr;}
