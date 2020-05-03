#include "Structs.h"

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

int choose_list()
{
	string functions[5] =
	{
		"Vector list;",
		"Linked list;",
		"Binary tree;",
		"AVL tree",
		"2-3 tree"
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the type of list." << endl;
		for (int i = 0; i < 5; i++)
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
					else position = 4;
				}

				if ((int)key == 80)
				{
					if (position < 4)
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

void print_list(vector<PointXYZ> points)
{
	for (int i = 0; i < points.size(); i++)
		points[i].Print();
	cout << endl;
}

void Quick_sort(vector<PointXYZ> &vector_points, int first, int last)
{
	PointXYZ x = vector_points[first];
	int i = first, j = last;
	do
	{
		while (vector_points[i].Less_than(x))
			i++;
		while (vector_points[j].Bigger_than(x))
			j--;
		if (i <= j)
		{
			if (i < j)
				swap(vector_points[i], vector_points[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (first < j)
		Quick_sort(vector_points,first, j);
	if (last > i)
		Quick_sort(vector_points, i, last);
}
