/***************************************************************
Title: GenericTask.cpp
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment#2
Description: provides function defintion for the GenericTask class
***************************************************************/

#include "GenericTask.h"

#include <iostream>
#include <fstream>

using namespace std;
/*
This class is a base class for other derived classes and contains 3 different virtual functions. Each class has
a slighlty  different different version of the functions.
*/

bool GenericTask::operator< (GenericTask& rhs)
{
	if (dueDate_ < rhs.dueDate_)
	{
		return true;
	}	
	return false;
}


void GenericTask::printTasksWithoutDetails(int taskNumber)
{
	cout << taskNumber << ". " << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
	cout << dueDate_.returnYear_() << " - " <<  taskDescription_ << endl;
	
}

void GenericTask::printTasksWithDetails(int taskNumber)
{
	printTasksWithoutDetails(taskNumber);
}

//outputs tasks in a separate file by using ostream

void GenericTask::printTasksInFile(ostream& output)
{
	output << "G" << "|" << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
	output << dueDate_.returnYear_() << "|" <<  taskDescription_ << endl;
	
}