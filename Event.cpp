/***************************************************************
Title: Event.cpp
Author: Anupam Das
Date Created: 4/4/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment#2
Description: provides function defintion for the Event class
***************************************************************/
#include "Event.h"
#include <iostream>
#include <fstream>

using namespace std;

void Event::printTasksWithoutDetails(int taskNumber)
{
	cout << taskNumber << ". " << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
cout << dueDate_.returnYear_() << " - " <<  "[Event]" << taskDescription_ << endl;
	
}

void Event::printTasksWithDetails(int taskNumber)
{
	printTasksWithoutDetails(taskNumber);
	
	cout << "WHERE: " << eventLocation_ << endl;
	cout << "WHEN: "  << eventTime_ <<endl;
}

void Event::printTasksInFile(ostream& output)
{
	output << "E" << "|" << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
	output << dueDate_.returnYear_() << "|" <<  taskDescription_ << "|" << eventLocation_ << "|" << eventTime_ << endl;
	
}