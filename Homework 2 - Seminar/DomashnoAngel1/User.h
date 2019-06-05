#pragma once
#include <iostream>

class User
{
private:
	char* name;
	int age;
	double budget;
	int numberOfWhiskeysToDrink;
	int numberOfVodkasToDrink;
	char* preferedMusic;

	void SetName(const char*);
	void SetAge(int);
	void SetNumberOfWhiskeysToDrink(int);
	void SetNumberOfVodkasToDrink(int);
	void SetPreferedMusic(const char*);

	void CopyFrom(const User&);
	void Free();

public:
	User();
	User(const char*, int, double, int, int, const char*);
	User(const User&);
	User& operator=(const User&);
	~User();

	void SetBudget(double);
	const char* GetName() const;
	double GetBudget() const;
	int GetAge() const;
	int GetNumberOfWhiskeysToDrink() const;
	int GetNumberOfVodkasToDrink() const;
	const char* GetPreferedMusic() const;
};