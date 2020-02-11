#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct time {
	int day;
	int hour;
	int minute;

	void Print()
	{
		cout << day << " day, at " << hour << ":" << minute << endl << endl;
	}
};

struct monster {
	int ID;
	string name;
	int health;
	int strength;
	double chance;
	string type_of_attack;
	time date;

	void Print()
	{
		cout << "ID is " << ID << ". ";
		cout << "Name of monster is " << name << ". ";
		cout << "Characteristics:" << endl;
		cout << "Health - " << health << ";" << endl;
		cout << "Strength - " << strength << ";" << endl;
		cout << "It can use the " << type_of_attack << " with chance of " << chance*100 << "%." <<  endl;
		cout << "The date of appearence is ";
		date.Print();
	}
};

void menu();