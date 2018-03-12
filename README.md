# ToDoList

/************************************************************************************************
Title:README.txt
Author: Anupam Das
********************************************************************************************/
				
Project Overview:
		This program implements a to-do list program, that aks the user for a command and performs the action accordingly. This program also 
		has the option store different tasks. The commands of the to-do list application includes:
		
			1. ADD - This command creates a new task. There are 4 types of tasks (Generic, HOmework, Shopping, Event). The user enters task type, due 
					date, description. Additional information is required for the specialized tasks.
			
			2. PRINT - Prints all the incomplete tasks according to the order of due date.
			
			3. DETAILED - prints all the incomplete tasks in order with all the specialized information.
			
			4. REMOVE - Asks the user for a task number to be removed, and deletes the specific task.
			
			5. COMPLETE - Asks a user for a task number, marks the task complete and remove from the original list (list with all the incomplete tasts).
			
			6. COMPLETED - Prints all the completed tasks 
			
			7. SAVE - Save all the all the incomplete tasks in a existed file (name provided by the user).

			8. LOAD - Loads all the tasks from a file provided by the user
			
			9. EXIT - Exits the program.
			
Design:
	This program is designed in 2 steps:
			
			1. Soring all the task information
			
			2. Taking command and executing commands

	1. Soring all the task information : 
			
		After the user decides to add a tasks, they are asked to enter type, description and dute date. Specialized tasks also require additional 
		information. So, in order to record all the information about certain tasks, object for each type of created. Since there are 4 tasks, each 
		tasks have their own class. There is also a Date class to store the Date.
		
			Date.h:
				Has 3 private members for day, month, year. The constructor sets the value for day, month, and year. There are also 3 overloaded operators
					
						bool operator < (Date rhs) 
						bool operator == (Date rhs)
						bool operator > (Date rhs)
				
				There are also 3 functions to return day, month, and year:
					
						int returnMonth_()
	
						int returnDay_() 
	
						int returnYear_() 

			GenericTasks.h:
				Base class for all the other tasks. Has 2 protected members for duedate and description. the constructor sets the date and the description.
				Other functions include:
					
						bool operator < (GenericTask& rhs) - overloads the < operator
	
						string returnDescription() - returns description
	
						struct  GenericTaskComparator - a functor, also has a comparator and compares two pointers of type GenericTask 

			ShoppingTask.h:
				Derived from the GenericTask class. Has an additional protected member of a vector for the shopping items. Only has a constructor, and sets the 
				date, description, and the items.
			
			Event.h:
				Derived from the GenericTask class. Has two additional protected members of type string for even location and event time for the shopping items. 
				Constructor, and sets the date, description, location and time.

			Homework.h:
				Derived from the GenericTask class. Has an additional protected member of type String for the shopping items. Only has a constructor, and sets the 
				date, description, and the subject.
			

	2. Taking command and executing commands
		All the commands are inputed by the user and stored in a variable in the main file. The main file creates an object of type CommandDriver, and calls the 
		functions of desired tasks. The CommandDriver takes care of all the input and output necessary within the commands. This class has 2 private Data structures. 
		They are 2 sorted linked lists, one to store incomplete tasks, other one to store complete tasks. It also has another private memeber variable of type "GenericTask"
		and the pointer to object is used to pass through the information during the task addition process.
		
			CommandDriver.h:
				The functions in CommandDriver.h includes:
				
					void addTasks();
					
					void printTasks();
					
					void printDetailedTasks();
					
					void removeTasks();
					
					void completeTasks();
					
					void printCompletedTasks();
					
					void saveTasks();
					
					void loadTasks();
					
How to compile and run this code:
	This code can be complied using the make file.
	
	To compile, run, and clean object files this code in Linux or Mac os, use the following commands:
	
		1. make
		2. ./ToDoList
		3. make clean
	
	And to compile and run this code in Windows, run the following commands:
		1. mingw32-make
		2. ToDoList.exe
	Note: the above command is used for the mingw g++ compiler. 