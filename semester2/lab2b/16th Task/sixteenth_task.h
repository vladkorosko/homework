#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

bool leap_year(int year);
string name_of_month(int& day, bool year_is_leap);
int enter_number(string mark);
int enter_number_of_messages(int max_size);
void Sys_pause();

struct our_time
{
	time_t localtime;
	int second;
	int minute;
	int hour;
	int day;
	string month;
	int year;

	void create_date()
	{
		localtime = time(NULL);
		localtime += 7200;
		second = localtime % 60;
		localtime /= 60;
		minute = localtime % 60;
		localtime /= 60;
		hour = localtime % 24;
		localtime /= 24;
		day = localtime;
		day++;
		year = 1970;
		while (day > -1)
		{
			if (leap_year(year))
				day -= 366;
			else
				day -= 365;
			year++;
		}
		year--;
		if (leap_year(year))
			day += 366;
		else
			day += 365;
		month = name_of_month(day, leap_year(year));
	}

	void print_date()
	{
		cout << blue + "The " + red << day << blue + " of " + green + month + blue + ", " + red << year << 
			blue + "; time: " + red << hour << ":" << minute << ":" << second << endl;
	}
};

struct Message
{
	string text = "";
	our_time appearence_time;

	void create_new_message()
	{
		system("cls");
		cout << blue + "Enter the text of message." << endl;
		cout << light_blue;
		getline(cin, text);
		appearence_time.create_date();
	}

	void print_message()
	{
		appearence_time.print_date();
		cout << green + text << endl;
	}
};

struct List_of_message
{
	int size_of_memory = 10;
	vector<Message> my_messages;

	void add_new_message(Message new_message)
	{
		my_messages.push_back(new_message);
		if (my_messages.size() > size_of_memory)
			my_messages.erase(my_messages.begin());
	}

	void add_messages(int number_of_messages)
	{
		cin.ignore();
		while (number_of_messages > 0)
		{
			Message new_message;
			new_message.create_new_message();
			add_new_message(new_message);
			number_of_messages--;
		}
	}

	void print_list()
	{
		system("cls");
		for (int i = my_messages.size()-1; i >= 0; i--)
		{
			my_messages[i].print_message();
			cout << endl;
		}
	}
	
	void print_first_k_messages(int k)
	{
		if (k <= my_messages.size())
		{
			int last = my_messages.size() - k;
			system("cls");
			for (int i = my_messages.size() - 1; i >= last; i--)
			{
				my_messages[i].print_message();
				cout << endl;
			}
		}
		else
		{
			cout << red + "Number of messages is bigger than size of list." << endl;
		}
	}
};

void interactive_mode();
void demonstrative_mode();

void menu();
