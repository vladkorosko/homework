#include "sixteenth_task.h"

bool check_int(string word)
{
	bool number = true;
	for (int i = 0; i < word.length(); i++)
		if (word[i] != '1' && word[i] != '2' && word[i] != '3' && word[i] != '4' && word[i] != '5' &&
			word[i] != '6' && word[i] != '7' && word[i] != '8' && word[i] != '9' && word[i] != '0')
			number = false;
	return number;
}

int enter_number(string mark)
{
	bool end = false;
	while (!end)
	{
		cout << blue + "Enter the " + mark + "." << endl;
		string word;
		cout << light_blue;
		cin >> word;
		bool is_int = check_int(word);
		if (is_int)
		{
			int number = stoi(word);
			end = true;
			return number;
		}
		else
		{
			system("cls");
			cout << red + "Not integer. Enter again."<< endl;
		}
	}
}

int enter_number_of_messages(int max_size)
{
	bool end = false;
	while (!end)
	{
		int k = enter_number("number of messages");
		if (k < max_size)
		{
			return k;
			end = true;
		}
		else
		{
			system("cls");
			cout << red + "Number of messages is bigger than size of list. Enter number again." << endl;
		}
	}
}

bool leap_year(int year)
{

	bool leapyear = false;
	if (!(year % 4))
	{
		leapyear = true;
		if (!(year % 100))
		{
			leapyear = false;
			if (!(year % 400))
				leapyear = true;
		}
	}
	return leapyear;
}

string name_of_month(int &day, bool year_is_leap)
{
	bool end = false;
	int n = 1;
	while (!end)
	{
		if ((n % 2 && n <= 7) || ((n + 1) % 2 && n > 7))
		{
			day -= 31;
			if (day < 0)
			{
				day += 31;
				end = true;
			}
			else
				n++;
		}
		else
		{
			if (n == 2)
			{
				day -= 28;
				day -= year_is_leap;
				if (day < 0)
				{
					day += 28 + year_is_leap;
					end = true;
				}
				else
					n++;
			}
			else
			{
				day -= 30;
				if (day < 0)
				{
					day += 30;
					end = true;
				}
				else
					n++;
			}
		}
	}
	switch (n)
	{
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "Jule";
	case 8:
		return "Augest";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "Something go wrong";
	}
}

void Sys_pause()
{
	cout << yellow;
	system("pause");
	system("cls");
}