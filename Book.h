#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
   //  enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title);
    /**
     * Input a Book
     */
   friend istream& operator >> (istream& in, Book& book);
    /**
     * Print a Book
     */
   friend ostream& operator << (ostream& out, Book& book);
    /**
     * Destructor.
     */
   //getter function
   string get_isbn();
   string get_last();
   string get_first();
   string get_title();
   // string get_category();
    ~Book();

    /***** Complete the public members. *****/

private:
   string isbn;
   string last;
   string first;
   string title;
   // Category category;
};

#endif /* EMPLOYEE_H_ */
