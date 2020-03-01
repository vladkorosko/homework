#include "IP.h"

void error_wrong_index()
{
	cout << red + "List index out of range." << endl;
}

string int_to_string(int number)
{
	string res = "";
	while (number > 0)
	{
		char letter = '0' + number % 10;
		number /= 10;
		res += letter;
	}

	string res_word = "";
	for (int i = res.length()-1; i >= 0; i--)
	{
		res_word += res[i];
	}
	return res_word;
}

vector<int> split(string word)
{
	vector<int> numbers;
	string num = "";
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == '.')
			numbers.push_back(stoi(num));
		else
			num += word[i];
	}
	return numbers;
}

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

void Sys_pause()
{
	cout << yellow;
	system("pause");
	system("cls");
}

void error_no_elements()
{
	cout << red + "No elements." << endl;
}
