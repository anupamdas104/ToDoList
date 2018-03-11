/***************************************************************
Title: SortedLinkedList.h
Author: Anupam Das
Description: provides function protocol for the SortedLinkedList class, and provides definition
			for the inline functions
***************************************************************/
#ifndef __SortedLinkedList_H_
#define __SortedLinkedList_H_


#include <iostream>
#include <string>


template<class typeName, class Comparator = std::less<typeName> >
class SortedLinkedList{
public:
	SortedLinkedList();
	
	//returns size of the list
	int size() { return size_; }
	
	//returns true if the list is empty
	inline bool is_empty () const { return (size_ == 0); }
	
	//inserts data by position
	void insert (int pos, const typeName& newData);
	
	//inserts data in sorted manner
	void insert (const typeName& newData);
	
	//return data in  newPos
	typeName at( int newPos );
 	
	//return true if data is in the list
	bool contains ( typeName newData );
	
	//delete node by position
	bool erase (int newPos );
	
	//enter data in the back
	void push_back(typeName newData);
	
	
	bool checkPos(int newPos) const;
private:

	
	struct Node{
		typeName data;
		Node* next;
	};
	
	Node* head;
	
	int size_;

};

#include "SortedLinkedList.cpp"		

#endif