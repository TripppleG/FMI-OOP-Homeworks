#include <iostream>
#include "Date.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(int day, int month, int year)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

void Date::SetDay(int day)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
		{
			day = 1;
		}
	}
	else if (month == 2)
	{
		if (day < 1 || day > 28 + IsLeapYear())
		{
			day = 1;
		}
	}
	else
	{
		if (day < 1 || day > 30)
		{
			day = 1;
		}
	}
	this->day = day;
}

int Date::GetDay() const
{
	return day;
}

void Date::SetMonth(int month)
{
	if (month < 1 || month > 12)
	{
		month = 1;
	}
	this->month = month;
}

int Date::GetMonth() const
{
	return month;
}

void Date::SetYear(int year)
{
	if (year < 1)
	{
		year = 2000;
	}
	this->year = year;
}

int Date::GetYear() const
{
	return year;
}

int Date::DaysInMonth(int month) const
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	if (month == 2)
	{
		if (IsLeapYear())
		{
			return 29;
		}
		return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
}

bool Date::IsLeapYear() const
{
	return ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0);
}

void Date::AddDays(int n)
{
	while (n > 0)
	{
		while (n > 365)
		{
			year++;
			if (IsLeapYear())
			{
				n--;
			}
			n -= 365;
			continue;
		}
		day++;
		if (day > DaysInMonth(month))
		{
			day = 1;
			month++;
		}
		if (month > 12)
		{
			year++;
			month = 1;
		}
		n--;
	}
}

void Date::RemoveDays(int n)
{
	while (n > 0)
	{
		while (n > 365)
		{
			year--;
			if (IsLeapYear())
			{
				n--;
			}
			n -= 365;
			continue;
		}
		day--;
		if (day < 1)
		{
			month--;
			if (month < 1)
			{
				year--;
				month = 12;
			}
			day += DaysInMonth(month);
		}
		n--;
	}
}

int Date::DaysToChristmas() const
{
	int currMonth = month;
	int currDay = day;
	int counter = 0;

	while (currDay != 25 || currMonth != 12)
	{
		if (currMonth == 11)
		{
			if (currDay > 25)
			{
				counter += 31 - (currDay - 25);
				return counter;
			}
			else
			{
				counter += DaysInMonth(currMonth);
				currMonth++;
			}
		}
		if (currMonth == 12)
		{
			if (currDay > 25)
			{
				counter += DaysInMonth(currMonth);
				currMonth = 1;
			}
			else
			{
				counter += 25 - currDay;
				return counter;
			}
		}
		counter += DaysInMonth(currMonth);
		currMonth++;
	}
	return counter;
}

bool Date::IsLaterThan(const Date& date) const
{
	if (year > date.year)
	{
		return true;
	}
	if (year == date.year)
	{
		if (month > date.month)
		{
			return true;
		}
		if (month == date.month)
		{
			if (day > date.day)
			{
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}