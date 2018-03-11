/***************************************************************
Title: SortedLinkedList.cpp
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment#2
Description: provides function defintion for the SortedLinkedList class
***************************************************************/

#ifndef __LinkedList_CPP_
#define __LinkedList_CPP_

#include "SortedLinkedList.h"
#include <iostream>

using namespace std;

template<class typeName, class Comparator>
SortedLinkedList<typeName, Comparator>:: SortedLinkedList()
{
	head = NULL; 
	size_= 0;
}

template<class typeName, class Comparator>
void SortedLinkedList<typeName, Comparator>::insert (int pos, const typeName& newData)
{
	
		Node* temp =  new Node;
		
		temp->data = newData;
		
		//if there are no element in the lsit enter newData in the head
		if (pos == 0)
		{
			temp->next = head;
			head = temp;
			
			++size_;
			
			return;
		}
		else
		{
			Node* curr;
		
			curr = head;
		
			//moves up curr until the it goes the node before pos
			for (int i = 0; i < pos-1; ++i)
			{
				curr = curr->next;	
			}
		
			//sets tempm to curr's next, and curr's next to temp
			temp->next = curr->next;
			curr->next = temp;
			
			++size_;		
		}	
}

template<class typeName, class Comparator>
void SortedLinkedList<typeName, Comparator>::insert (const typeName& newData)
{
	Node* temp =  new Node;
		
	temp->data = newData;
		
	if (is_empty())
	{
		temp->next = NULL;
		head = temp;
		
		
		++size_;
			
		return;
	}
	
	Node* curr;
	
	curr = head;
	//cout << "1" << endl;
	Comparator genericTaskComparator;
	
	//cout << 2 << endl;
	for (int i = 0; i < size(); ++i)
	{
		//compares data, if new data is less than data calls insert, otherwise moves curr pointer to the next node
		if (genericTaskComparator(newData, curr->data))  
		{
			insert(i,newData);
			break;
		}
		else
		{	//enter newData in the last node if the due date is the latest of all other tasks
			if ( i == size()-1)
			{
				curr->next = temp;
				temp->next = NULL;
				
				++size_;
				
				break;
				
				//insert(i,newData);
			}
			curr = curr->next;	
		}
	}
}


template <class typeName, class Comparator>
bool SortedLinkedList<typeName, Comparator>::checkPos (int newPos) const
{
	if ( newPos < 0 || newPos > size_ )
	{
		return false;
	}

	return true;
}

template <class typeName, class Comparator>
typeName SortedLinkedList<typeName, Comparator>:: at( int newPos )
{
	Node* Temp;
	
	Temp = head;
	
	//moves tem pointer to pos node
	if (newPos >= 0 && newPos <= size_-1)
	{
		for (int i = 0; i < newPos ; ++i )
		{
		Temp = Temp->next;
		}
	}
	else if (newPos < 0 && newPos > size_-1)
	{
		return 0;
	}
	return Temp-> data;
	
}

template <class typeName, class Comparator>
bool SortedLinkedList<typeName, Comparator>::contains ( typeName newData )
{
	Node* curr = new Node;
	
	curr = head;
	
	for ( int i = 0; i < size_; ++i )
	{
		if ( curr->data == newData )
		{
			return true;
		}
		else
		{
			if ( i < size_-1 )
			{
			curr = curr->next;
			}
			else if ( i >= size_-1)
			{
				continue;
			}
		}
	}
	return false;
}

template <class typeName, class Comparator>
bool SortedLinkedList<typeName, Comparator>::erase (int newPos )
{
	Node* curr, *temp;
	
	curr = head;
	temp = head;
	
	if (newPos >= 0 && newPos <= size_-1)
	{
	//delete if pos is in the first element
	if (newPos == 0)
	{
		head = curr->next;
		delete curr; 
		
		--size_;
		return true;
	}
	else  
	{	
		for (int i = 0; i < newPos-1; ++i )
		{
			temp = temp->next;
			
		}
		
		if (newPos == size_-1)
		{
			curr = temp->next;
			
			temp->next = NULL;
			
			delete curr;
			
			--size_;
			return true;
		}
		else
		{
			curr =  temp-> next;
			temp->next = curr->next;
			delete curr;
			
			--size_;
			return true;
		}
	}
	}
	else if (newPos < 0 && newPos > size_-1)
	{
		return false;
	}
	
	return false;
}

template <class typeName, class Comparator>
void SortedLinkedList<typeName, Comparator>::push_back(typeName newData)
{

	Node* temp = new Node;
	
	temp->data = newData;
	
	Node* curr;
	curr = head;
	
	if (size_ == 0)
	{
		temp->next = NULL;
		head = temp;
			
		++size_;
	}
	else
	{
		for (int i = 0; i < size_; ++i)
		{
			curr = curr->next;
		}
	
		curr->next = temp;
		temp->next = NULL;
		++size_;
	}

}


#endif

