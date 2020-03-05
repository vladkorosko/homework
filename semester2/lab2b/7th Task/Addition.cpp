#include "7task.h"

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
			cout << red + "Not integer. Enter again.";
		}
	}
}

int enter_index(int length)
{
	bool end = false;
	while (!end)
	{
		int index = enter_number("index");
		if (index < length)
		{
			end = true;
			return index;
		}
		else
		{
			system("cls");
			error_wrong_index();
		}

	}
}

void error_no_elements()
{
	cout << red + "No elements." << endl;
}

void error_wrong_index()
{
	cout << red + "List index out of range." << endl;
}

string create_string()
{
	string name = "";
	for (int i = 0; i < 6; i++)
	{
		name += (char)((int)'a' + rand() % 25);
	}
	return name;
}

void Sys_pause()
{
	cout << yellow;
	system("pause");
	system("cls");
}
