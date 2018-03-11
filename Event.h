/***************************************************************
Title: Event.h
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment #2
Description: provides function protocol for the Event class, and provides defintion
			for the inline functions
***************************************************************/
#ifndef _Event_H_
#define	_Event_H_

#include "Date.h"
#include<string>
#include "GenericTask.h"

using namespace std;

//derived form the GenericTask class

class Event: public GenericTask{
public:
	Event(Date newDeadline, string newDescription, string newLocation, string newTime) 
					: GenericTask(newDeadline, newDescription), eventLocation_(newLocation), eventTime_(newTime) {}
					
	virtual void printTasksWithoutDetails(int taskNumber);
	
	virtual void printTasksWithDetails(int taskNumber);
	
	virtual void printTasksInFile(ostream& output);

protected:
	string eventLocation_, eventTime_;
};

#endif