/***************************************************************
Title: Date.h
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment #2
Description: provides function protocol for the Date class, and provides defintion
			for the inline functions
***************************************************************/

#ifndef _Date_H_
#define _Date_H_

//this class takes in three different integer for month, day, amd year and sets the private variable 
class Date{
public:
	Date(int newMonth, int newDay, int newYear) : month_(newMonth), day_(newDay), year_(newYear) {}
	
	bool operator < (Date rhs);
	bool operator == (Date rhs);
	bool operator > (Date rhs);
	
	int returnMonth_() { return month_; }
	
	int returnDay_() { return day_; }
	
	int returnYear_() { return year_; }

private:
	int month_, day_, year_;
};

#endif