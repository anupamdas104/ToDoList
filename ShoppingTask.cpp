/***************************************************************
Title: ShoppingTask.cpp
Author: Anupam Das
Description: provides function definition for the ShoppingTask class
***************************************************************/

#include "ShoppingTask.h"
#include "GenericTask.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


ShoppingTask::ShoppingTask(Date newDeadline, string newDescription, const vector<string> & newItems) : GenericTask(newDeadline, newDescription)
{
	for (unsigned int i = 0; i < newItems.size(); ++i)
	{
		shoppingItems.push_back(newItems[i]);
	}

}

void ShoppingTask::printTasksWithoutDetails(int taskNumber)
{
	cout << taskNumber << ". " << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
	cout << dueDate_.returnYear_() << " - " << "[ShoppingTask]" <<  taskDescription_ << endl;
	
}

void ShoppingTask::printTasksWithDetails(int taskNumber)
{
	printTasksWithoutDetails(taskNumber);
	
	cout << "ITEMS TO PURCHASE: " << endl;
	
	for (unsigned int i = 0; i < shoppingItems.size(); ++i)
	{
		cout<< shoppingItems.at(i) << endl;
	}
}

void ShoppingTask::printTasksInFile(ostream& output)
{
	output << "S" << "|" << dueDate_.returnMonth_() << "/" << dueDate_.returnDay_() << "/" ;
	output << dueDate_.returnYear_() << "|" <<  taskDescription_ << "|";
	
	for (unsigned int i = 0; i < shoppingItems.size(); ++i)
	{
		output<< shoppingItems.at(i) << "|";
	}
	
	output << endl;
}