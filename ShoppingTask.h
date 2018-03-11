/***************************************************************
Title: ShoppingTask.h
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment #2
Description: provides function protocol for the ShoppingTask class, and provides defintion
			for the inline functions
***************************************************************/
#ifndef __ShoppingTask_H_
#define __ShoppingTask_H_

#include<string>
#include<vector>
#include "Date.h"
#include "GenericTask.h"

using namespace std;

//derived form the GenericTask class
class ShoppingTask : public GenericTask{
public:
	ShoppingTask(Date newDeadline, string newDescription, const vector<string>& newItems);
	
	virtual void printTasksWithoutDetails(int taskNumber);
	
	virtual void printTasksWithDetails(int taskNumber);
	
	virtual void printTasksInFile(ostream& output);
protected:

	//used to store all the shopping items
	vector<string> shoppingItems;
};


#endif