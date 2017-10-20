/*
 * BookNode.h
 *
 *  Created on: Oct 17, 2017
 *      Author: yulu9206
 */

#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"

/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book);

    Book get_book();
    BookNode * get_next();
    void set_next(BookNode* nextptr);

private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};



#endif /* BOOKNODE_H_ */
