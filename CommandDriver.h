/***************************************************************
Title: CommandDriver.h
Author: Anupam Das
Description: provides function protocol for the CommandDriver class, and provides definition
			for the inline functions
***************************************************************/

#ifndef __CommandDriver_H_
#define __CommandDriver_H_


#include "GenericTask.h"
#include "ShoppingTask.h"
#include "Event.h"
#include "Homework.h"
#include "SortedLinkedList.h"
#include <iostream>


//All the functions commented out are incomplete

class CommandDriver{
public:
	void addTasks();
	void printTasks();
	void printDetailedTasks();
	void removeTasks();
	void completeTasks();
	void printCompletedTasks();
	void saveTasks();
	//void loadTasks();
	void helpCommand();
	
private:
	//StoreTasks newTaskToStore;
	
	GenericTask* storeCommands;
	
	//stores all the incomplete tasks
	SortedLinkedList<GenericTask*, GenericTask::GenericTaskComparator> allTasks;
	
	//stores completed tasks
	SortedLinkedList<GenericTask*, GenericTask::GenericTaskComparator> allCompletedTasks;
	

};

#endif
