/***************************************************************
Title: Homework.cpp
Author: Anupam Das
Description: provides function definition for the Homework class
***************************************************************/
#include "Homework.h"
#include <iostream>
#include <fstream>

using namespace std;


void Homework::printTasksWithoutDetails(int taskNumber)
{
	cout << taskNumber << ". " << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
	cout << dueDate_.returnYear_() << " - " <<  "[Homework]" << taskDescription_ << endl;
	
}

void Homework::printTasksWithDetails(int taskNumber)
{
	printTasksWithoutDetails(taskNumber);
	
	cout << "SUBJECT: " << homeworkSubject << endl;
}

void Homework::printTasksInFile(ostream& output)
{
	output << "H" << "|" << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
	output << dueDate_.returnYear_() << "|" <<  taskDescription_ << "|" << homeworkSubject << endl;
	
}