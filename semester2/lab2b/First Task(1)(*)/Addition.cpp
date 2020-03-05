#include "lab2b.1.h"

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
	for (int i = res.length() - 1; i >= 0; i--)
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
		bool positive = true;
		string word;
		int number;
		cout << light_blue;
		cin >> word;
		if (word[0] == '-')
		{
			positive = false;
			for (int i = 0; i < word.length() - 1; i++)
				word[i] = word[i + 1];
			word.pop_back();
		}
		bool is_int = check_int(word);
		if (is_int)
		{
			number = stoi(word);
			end = true;
		}
		else
		{
			system("cls");
			cout << red + "Not integer. Enter again.";
		}

		if (!positive)
			number *= -1;
		return number;
	}
}

int enter_index(int length)
{
	bool end = false;
	while (!end)
	{
		int index = enter_number("index");
		if (index < 0)
			index += length;
		if (index < length && index >= 0)
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

int choose_list()
{
	string functions[3] =
	{
		"Array list;",
		"Vector list;",
		"Linked list;",
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the type of list." << endl;
		for (int i = 0; i < 3; i++)
		{
			if (i == position)
				cout << red + "->  " << light_blue + functions[i] << endl;
			else cout << "    " << light_blue + functions[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{
			if ((int)key == -32)
			{
				key = _getch();
				if ((int)key == 72)
				{
					if (position > 0)
						position--;
					else position = 2;
				}

				if ((int)key == 80)
				{
					if (position < 2)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			system("cls");
			end = true;
			return position;
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
