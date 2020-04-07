#include "lab4.h"

bool check_number(char sign)
{
	return (sign != '1' && sign != '2' && sign != '3' && sign != '4' && sign != '5' &&
		sign != '6' && sign != '7' && sign != '8' && sign != '9' && sign != '0');
}

bool check_int(string word)
{
	bool number = true;
	for (int i = 0; i < word.length(); i++)
		if (check_number(word[i]))
			number = false;
	return number;
}

int enter_number(string mark)
{
	bool end = false;
	while (!end)
	{
		cout << "Enter the " + mark + "." << endl;
		string word;
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
			cout << "Not integer. Enter again.";
		}
	}
}



