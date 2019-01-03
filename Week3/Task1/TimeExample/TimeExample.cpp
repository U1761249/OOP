// TimeExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Time.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Time t;	//new time object
	cout << "\nThe initial time is ";
	t.printTime();
	t.setTime(13, 25, 12); //set the time
	cout << "\nThe set time is ";
	t.printTime();
	for (int i = 0; i < 3600; i++){
		t.tickTime();
		cout << "\nThe ticked time is ";
		t.printTime();
	}
	return 0;
}

