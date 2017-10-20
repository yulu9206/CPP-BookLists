/*
 * BookList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: yulu9206
 */

#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include <string>
#include "BookNode.h"
#include "Book.h"
using namespace std;

class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);

    BookNode* get_head();
    /**
     * Print the list.
     */
    void print();

    void insert(Book book);

    int find(Book book);
    void merge_lists(BookList& list1);
private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
