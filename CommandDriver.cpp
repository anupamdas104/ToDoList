/***************************************************************
Title: CommandDriver.cpp
Author: Anupam Das
Description: provides function definition for the CommandDriver class
***************************************************************/

#include "CommandDriver.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "SortedLinkedList.h"

using namespace std;

void CommandDriver:: addTasks()
{
	char taskType;
	//StoreTasks newTaskToStore;
	
	cout << "What type of task is this? [G: GENERIC, S:SHOPPING, E:EVENT, H:HOMEWORK]" << endl;
	cin >> taskType;
	
	if (!(taskType == 'G' || taskType == 'S' || taskType == 'E' || taskType == 'H'))
	{
		cout << "Unrecognizable task type entered" << endl;
		return;
	}
		
	//GenericTask* storeCommands;
	string taskDueDate;
	
	int month, day, year;
	cin.ignore();
	cout << "When is this task due?" << endl;
	getline (cin, taskDueDate);
	
	string str2 ("/");

	//finds first instance of "/" in date provided by the user
	size_t found = taskDueDate.find(str2);
	   
	//finds second instances of "/"  
	size_t  found2=taskDueDate.find("/",found+1,1);
			
	int len = taskDueDate.length();
	
	//sets month calling substr and putting the string from begginning of string untill first case of "/"
	string month2 = taskDueDate.substr(0, found);
	
	//repeats same process of setting month
	string day2 = taskDueDate.substr(found+1, found2-found-1);
	string year2 = taskDueDate.substr(found2+1, found2-len-1);
	
	//	converts month, day, and year to ints
	month = atoi(month2.c_str());
	day = atoi(day2.c_str());
	year = atoi(year2.c_str());		
		
	//sets date by creating date object	
	Date inputDate (month, day, year);
	
	string description;

	cout << "How would you describe this task?" << endl;
	getline (cin, description);
		
	if (taskType == 'G')
	{	
		//points the GenericTask pointer to generic task with all the information
		storeCommands = new GenericTask(inputDate, description);	
	}
	else if (taskType == 'S')
	{
		vector<string> shoppingList;
		string shoppingListInput;
			
		cout << "What items do you need to buy?";
		cout<< "[Type your item and press ENTER to add another item. Type DONE to complete the list]" << endl;
		
		//user enters shopping item, and Done quits the loop
		do 
		{
			getline (cin, shoppingListInput);
			
			
			if (shoppingListInput == "DONE")
			{
				break;
			}
			else
			{
				shoppingList.push_back(shoppingListInput);
			}
		}	while(true);
		
		
		//points the GenericTask pointer to shopping task with all the information
		storeCommands = new ShoppingTask(inputDate, description, shoppingList);
	}
	else if (taskType == 'E')
	{
		string eventPlace, eventTime;
		cout << "Where is this event taking place?" << endl;
		getline(cin, eventPlace);
		cout << "When is this event taking place?" << endl;
		getline(cin, eventTime);
			
		//points the GenericTask pointer to Event with all the information	
		storeCommands = new Event(inputDate, description, eventPlace, eventTime);
	}
	else if(taskType == 'H')
	{
		string taskSubject;
		
		cout << "What subject is this homework task for?" <<endl; 
		getline (cin, taskSubject);
			
		//points the GenericTask pointer to homework with all the information	
		storeCommands = new Homework(inputDate, description, taskSubject);
	}
	
	//puts the task a in the list
		
	allTasks.insert(storeCommands);
		
	cout << "Task added Successfully" << endl;
}


void CommandDriver::printTasks()
{
	if (allTasks.size() == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
	}
	else 
	{
		//runs a for loop and calls the appropriate print function for appropriate type
		for (int i = 0; i < allTasks.size() ; ++i)
		{
			allTasks.at(i)->printTasksWithoutDetails(i+1);
		}
	}
}

//follows same idea as printTasks() functions
void CommandDriver::printDetailedTasks()
{
	if (allTasks.size() == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
	}
	else 
	{
		for (int i = 0; i < allTasks.size() ; ++i)
		{
			allTasks.at(i)->printTasksWithDetails(i+1);
		}
	}
	
}

void CommandDriver::removeTasks()
{
	int taskToBeRemoved;
	if (allTasks.size() == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
	}
	else
	{
		//takes user input for which task to be deleted, and deletes accordingly
		cout << "Which task would you like to remove?" << endl;
		cin >> taskToBeRemoved;
		
		if (taskToBeRemoved <= 0 && taskToBeRemoved > allTasks.size())
		{
			cout << "Invalid task number!" << endl;
			return;
		}
		
		allTasks.erase(taskToBeRemoved-1);
		
		cout << "Task removed successfully" << endl;
	}
}

void CommandDriver::completeTasks()
{
	int taskToBeCompleted;
	if (allTasks.size() == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
	}
	else 
	{
		cout << "Which task would you like to complete?" << endl;
		cin >> taskToBeCompleted;
		
		if (taskToBeCompleted <= 0 && taskToBeCompleted > allTasks.size())
		{
			cout << "Invalid task number!" << endl;
			return;
		}
		
		//puts the task located at "taskToBeCompleted" from incomplete tasks list to complete task list, and removes from the
		//incomplete tasks list
		allCompletedTasks.insert(allTasks.at(taskToBeCompleted-1));
		allTasks.erase(taskToBeCompleted-1);
		
		cout << "Task marked complete successfully." << endl;
	}
}

//same idea as printTasks functions
void CommandDriver::printCompletedTasks()
{
	if (allCompletedTasks.size() == 0)
	{
		cout << "You have no completed tasks!" << endl;
		
	}
	else 
	{
		for (int i = 0; i < allCompletedTasks.size() ; ++i)
		{
			allCompletedTasks.at(i)->printTasksWithoutDetails(i+1);
		}
	}
}

//saves tasks
void CommandDriver::saveTasks()
{
	if (allTasks.size() == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
	}
	else
	{
		string fileToSave;
		
		cin.ignore();
		
		cout << "Where would you like to save your outstanding tasks?" << endl;
		getline(cin,fileToSave);
		
		//gets the string 
		ofstream saveTasksFilename(fileToSave.c_str());
		
		//calls the proper print functions for the proper type
		for (int i = 0; i < allTasks.size(); ++i)
		{
			allTasks.at(i)->printTasksInFile(saveTasksFilename);
		}
		
		cout << "Tasks saved successfully!" << endl;
	}
}

void CommandDriver::helpCommand()
{
	
	cout << "ADD - This command creates a new task " << endl;
			
	cout << "PRINT - Prints all the incomplete tasks according to the order of due date" << endl;
			
	cout << "DETAILED - prints all the incomplete tasks in order with specialized informations" << endl;
			
	cout << "REMOVE - Asks the user for a task number to be removed, and deletes the specific task" << endl;
			
	cout << "COMPLETE - Asks a user for a task number, marks the task complete and remove from the original list" << endl;
			
	cout << "COMPLETED - Prints all the completed tasks" << endl;
		
	cout << "SAVE - Save all the all the incomplete tasks in a existed file (name provided by the user)" << endl;

	//cout << "LOAD - Loads all the tasks from a file provided by the user" << endl;
			
	cout << "EXIT - Exits the program" << endl;
}