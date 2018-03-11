/***************************************************************
Title: Homework.h
Author: Anupam Das
Description: provides function protocol for the Homework class, and provides definition
			for the inline functions
***************************************************************/
#ifndef  __Homework_H_
#define  __Homework_H_

#include "Date.h"
#include <string>
#include "GenericTask.h"

using namespace std;

//derived form the GenericTask class

class Homework : public GenericTask{
public:
	//sets member variables
	Homework (Date newDeadline, string newDescription, string newhomeworkSubject) 
					: GenericTask(newDeadline, newDescription), homeworkSubject (newhomeworkSubject) {}

	virtual void printTasksWithoutDetails(int taskNumber);
	
	virtual void printTasksWithDetails(int taskNumber);
	
	virtual void printTasksInFile(ostream& output);
protected:
	string homeworkSubject;
};

#endif