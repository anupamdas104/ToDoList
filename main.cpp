/***************************************************************
Title: main.cpp
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment#2
Description: Asks for the command and calls the function necesarry to execute that task 
***************************************************************/
#include<iostream>
#include<string>
#include"CommandDriver.h"


using namespace std;

/*
Asks user for the command type. ALso creates an object for COmmandDrviver and uses the object to call the necessary function for desired command 
*/
int main()
{
		string commandInput;
		CommandDriver taskDriver;
		

		//cout << "Please enter  a valid command. Enter HELP for the list of Valid commands." << endl;
		
		
		do {
			cout << "Please enter  a valid command. Enter HELP for the list of Valid commands." << endl;
			cin >> commandInput;
			
			for (unsigned int i = 0; i < commandInput.size(); ++i)
			{
				commandInput.at(i) = toupper(commandInput.at(i));
			}
			
			if (commandInput == "ADD")
			{
				taskDriver.addTasks();
			}
			else if (commandInput == "PRINT")
			{
				taskDriver.printTasks();
			}
			else if (commandInput == "DETAILED")
			{
				taskDriver.printDetailedTasks();
			}
			else if (commandInput == "REMOVE")
			{
				taskDriver.removeTasks();
			}
			else if (commandInput == "COMPLETE")
			{
				taskDriver.completeTasks();
			}
			else if (commandInput == "COMPLETED")
			{
				taskDriver.printCompletedTasks();
			}
			else if (commandInput == "SAVE")
			{
				taskDriver.saveTasks();
			}
			/*else if (commandInput == "LOAD")
			{
				taskDriver.loadTasks();
			}*/
			else if (commandInput == "HELP")
			{
				
				taskDriver.helpCommand();
			}
			else if (commandInput == "EXIT")
			{
				cout << "THANK YOU FOR USING TO-DO LIST!" << endl;
				break;
			}else{
				cout << "Command invalid" << endl;
			}
		
		} while (true);
	
	return 0;

}