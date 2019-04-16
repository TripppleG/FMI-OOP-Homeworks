#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);

	void SetDay(int);
	int GetDay() const;

	void SetMonth(int);
	int GetMonth() const;

	void SetYear(int);
	int GetYear() const;

	int DaysInMonth(int) const;
	bool IsLeapYear() const;
	void AddDays(int);
	void RemoveDays(int);
	int DaysToChristmas() const;
	bool IsLaterThan(const Date&) const;
};