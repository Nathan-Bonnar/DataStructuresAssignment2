//Nathan Bonnar - PROG72370 - Assignment 02
#include"Data.h"
//creating a function to genreate a string between the sizes of 11 to 20 chars from all the lowercase letters of the alphabet
char* generatedata()
{
	char namearray[ALPABET] = { "abcdefghijklmnopqrstuvwxyz" };
	char name[MAXSTRINGSIZE] = {};
	int length = (rand() % (20 - 11)) + 11;
	for (int i = 0; i < length; i++)
	{
		int letterchoice = rand() % (25 + 1);
		name[i] = namearray[letterchoice];
	}
	return name;
}