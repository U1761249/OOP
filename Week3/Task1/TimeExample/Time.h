#pragma once
class Time
{
public:
	Time();
	~Time();
	void setTime(int, int, int); //method to set hour, minute and second
	void tickTime(); // method to increment the time by 1
	void printTime();
private:
	int hour;    //0-23
	int minute;  //0-59
	int second;  //0-59
};

