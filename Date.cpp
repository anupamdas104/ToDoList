/***************************************************************
Title: Date.cpp
Author: Anupam Das
Description: provides function definition for the Date class
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