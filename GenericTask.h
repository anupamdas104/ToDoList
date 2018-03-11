/***************************************************************
Title: GenericTask.h
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment #2
Description: provides function protocol for the GenericTask class, and provides defintion
			for the inline functions
***************************************************************/

#ifndef __GenericTask_H_
#define	__GenericTask_H_
#include "Date.h"
#include <string>

using namespace std;

//Base class for all the task types

class GenericTask{
public:
	GenericTask(Date newDate, string newDescription) : dueDate_(newDate), taskDescription_(newDescription) {}
	
	//checks if the due date of rhs is earlier or later
	bool operator < (GenericTask& rhs);
	
	//prints task in order of due date
	virtual void printTasksWithoutDetails(int taskNumber);
	
	//prints tasks with details in order
	virtual void printTasksWithDetails(int taskNumber);
	
	//prints details in a user desired filed of different task types
	virtual void printTasksInFile(ostream& output);
	
	//This functor is used to compare two pointers to GenericTask objec and the returns the lowest
	struct  GenericTaskComparator{
		bool operator () (GenericTask* left, GenericTask* right) {return *left < *right ; }
	};

protected:
	Date dueDate_;
	string taskDescription_;

};

#endif