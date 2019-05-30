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
	void SetBudget(double);
	void SetNumberOfWhiskeysToDrink(int);
	void SetNumberOfVodkasToDrink(int);
	void SetPreferedMusic(const char*);

	void CopyFrom(const User&);
	void Free();
public:
	User();
	User(char*, int, double, int, int, char*);
	User(const User&);
	User& operator=(const User&);
	~User();

	const char* GetName() const;
	int GetAge() const;
	double GetBudget() const;
	int GetNumberOfWhiskeysToDrink() const;
	int GetNumberOfVodkasToDrink() const;
	const char* GetPreferedMusic() const;
};