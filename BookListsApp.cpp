#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include "Book.h"
#include "BookNode.h"
#include "BookList.h"

using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt";

BookList creat_booklist(string category);

void sort_author(BookList& list, BookList& alist, BookList& nlist);

int main()
{
   cout << endl;
  ifstream input;
  input.open(CATEGORIES_FILE_NAME);
  if (input.fail())
  {
      cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
      return -1;
  }
  while (!input.fail())
  {
	  vector<string> categories;
	  string category;
	  while(getline(input, category))
          {
		  categories.push_back(category);
          }
	  input.close();
	  vector<BookList> lists;
	  for(auto category : categories)
	  {
		  BookList list = creat_booklist(category);
		  list.print();
		  lists.push_back(list);
	  }

	  BookList merge_list("MERGED");
	  for(auto list : lists)
	  {
//		  list.print();
		  merge_list.merge_lists(list);
	  }
	  merge_list.print();
	  BookList alist("AUTHORS A-M");
	  BookList nlist("AUTHORS N_Z");
	  sort_author(merge_list, alist, nlist);
	  alist.print();
	  nlist.print();
  }

    return 0;
}


BookList creat_booklist(string category)
{
	  BookList list(category);
	  string INPUT_FILE_NAME = category + ".txt";
	  ifstream input;
	  input.open(INPUT_FILE_NAME);
	  if (input.fail())
	  {
	      cout << "Failed to open " << INPUT_FILE_NAME << endl;
	  }
	  Book cur_book;
	  while (input >> cur_book)
	  {
		  if (list.find(cur_book) == -1)
		  {
			  list.insert(cur_book);
		  }
	  }
//	  list.print();
          input.close();
          return list;
}

void sort_author(BookList& list, BookList& alist, BookList& nlist)
{
	BookNode* cur = list.get_head();
	if (cur == nullptr) return;
	else
	{
		BookNode* next = cur->get_next();
		Book cur_book = cur->get_book();
		string cur_last = cur_book.get_last();
		char cur_ini = cur_last[0];
		while(next != nullptr)
		{
			if (cur_ini < 'N') alist.insert(cur_book);
			else nlist.insert(cur_book);
			cur = next;
			cur_book = cur->get_book();
			cur_last = cur_book.get_last();
			cur_ini = cur_last[0];
			next = next->get_next();
		}

		if (cur_ini < 'N') alist.insert(cur_book);
		else nlist.insert(cur_book);
	        return;
	}
}

