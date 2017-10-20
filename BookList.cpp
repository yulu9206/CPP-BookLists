#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include "BookList.h"
#include "BookNode.h"
#include "Book.h"

using namespace std;

BookList::BookList(const string name)
    : name(name), head(nullptr), tail(nullptr)
{
//    create();
}

BookNode* BookList::get_head()
{
	return head;
}


void BookList::print()
{
 cout << "Book list: " << name << endl << endl;
 int count = 0;
 if (head != nullptr)
    {
	 BookNode *cur = head;
	 Book cur_book = cur->get_book();
	 cout << cur_book;
	 count++;
	 while(cur->get_next())
	 {
//		cout << "printing the next book" << endl;
		 cur = cur->get_next();
		cur_book = cur->get_book();
		cout << cur_book;
		count++;
	 }
	 cout << "  (" << count << " books)" << endl << endl;
    }
}

int BookList::find(Book book)
{
	if (head == nullptr) return -1;
	else
	{
		string isbn = book.get_isbn();
		BookNode* cur = head;
		Book cur_book = cur->get_book();
		string cur_isbn = cur_book.get_isbn();
		if (cur_isbn == isbn) return 1;
		else if (head->get_next() == nullptr) return -1;
		else
		{
			while(cur->get_next() != nullptr)
			{
				cur = cur->get_next();
				cur_book = cur->get_book();
				cur_isbn = cur_book.get_isbn();
				if (cur_isbn == isbn) return 1;
			}
			return -1;
		}
	}
}

void BookList::insert(Book book)
{
	BookNode* booknode = new BookNode(book);
//	cout << "head is " << head << endl;
	if (head == nullptr)
	{
		head = booknode;
//		cout << "1" << endl;
		return;
	}
	else
	{
		string isbn = book.get_isbn();
		BookNode* cur = head;
		Book cur_book = cur->get_book();
		string cur_isbn = cur_book.get_isbn();
		BookNode* next = cur->get_next();
//		cout << "head next is " << head->get_next() << endl;
		if (isbn < cur_isbn)
		{
			head = booknode;
			head->set_next(cur);
//				cout << "2" << endl;
			return;
		}
		else
		{
			if (next == nullptr)
			{
				head->set_next(booknode);
		//				tail = &booknode;
		//				cout << "3" << endl;
		//				cout << "now head next is " << head->get_next() << endl;
				return;

			}
			else
			{
				BookNode* next = cur->get_next();
				Book next_book = next->get_book();
				string next_isbn = next_book.get_isbn();
				while(next->get_next())
				{
					if (next_isbn > isbn)
					{
						cur->set_next( booknode);
						booknode->set_next(next);
	//					cout << "4" << endl;
						return;
					}
					else
					{
						cur = next;
						next = next->get_next();
						next_book = next->get_book();
						next_isbn = next_book.get_isbn();
					}
				}
				if (next_isbn > isbn)
				{
					cur->set_next( booknode);
					booknode->set_next(next);
	//				cout << "5" << endl;
					return;
				}
				else
				{
					next->set_next(booknode);
	//				cout << "6" << endl;
					return;
				}
			}
		}


	}

}

void BookList::merge_lists(BookList& list1)
{
	BookNode* cur = list1.head;
	if (cur == nullptr) return;
	else
	{
		BookNode* next = cur->get_next();
		Book cur_book = cur->get_book();

		while(next != nullptr)
		{
			if (this->find(cur_book) == -1) this->insert(cur_book);
//			cout << "1 merging " << cur_book;
			cur = next;
			cur_book = cur->get_book();
			next = next->get_next();
		}

		if (this->find(cur_book) == -1) this->insert(cur_book);
//		cout << "2 merging " << cur_book;
	        return;
	}
}




