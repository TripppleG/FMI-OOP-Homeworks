#pragma once
#include <string.h>

class User
{
private:
	char* name;
	int age;
	double budget;
	int numberOfWhiskeys;
	int numberOfVodkas;
	int musicGenre;

	void setName(const char*);
	void setAge(int);
	void setBudget(double);
	void setNumberOfWhiskeys(int);
	void setNumberOfVodkas(int);
	void setMusicGenre(int);

	void CopyFrom(const User&);
	void Free();
public:
	User();
	User(const char*, int, double, int, int, int);
	User(const User&);
	User& operator=(const User&);
	~User();
};