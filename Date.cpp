/***************************************************************
Title: Date.cpp
Author: Anupam Das
Date Created: 4/7/2017
Class: Spring 2017, CSCI 235-04, Mon & Wed 7:00pm - 8:15pm
Professor:Aarsh Vora
Purpose: Assignment#2
Description: provides function defintion for the Date class
***************************************************************/
#include "Date.h"
//compares month, day, and year
bool Date::operator< (Date rhs)
{
	//if year is greater return true
	if ((year_ < rhs.year_))
	{
		return true;
	}
	
	if ((year_ == rhs.year_) && (month_ < rhs.month_) )
	{
		return true;
	}
	
	if ((month_ == rhs.month_) && (day_ < rhs.day_) && (year_ == rhs.year_))
	{
		return true;
	}
	
	if ((month_ < rhs.month_) && (day_ < rhs.day_) && (year_ < rhs.year_))
	{
		return true;
	}
	
	return false;
}

bool Date::operator> (Date rhs)
{
	if ((month_ > rhs.month_) && (day_ > rhs.day_) && (year_ > rhs.year_))
	{
		return true;
	}
	
	return false;
}

bool Date::operator== (Date rhs)
{
	if ((month_ == rhs.month_) && (day_ == rhs.day_) && (year_ == rhs.year_))
	{
		return true;
	}
	
	return false;
}