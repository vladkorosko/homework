#include "structs and functions.h"

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

int choose(string types[3] )
{
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the type of" + types[2] + "." << endl;
		for (int i = 0; i < 2; i++)
		{
			if (i == position)
				cout << red + "->  " << light_blue + types[i] << endl;
			else cout << "    " << light_blue + types[i] << endl;
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
					else position = 1;
				}

				if ((int)key == 80)
				{
					if (position < 1)
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

Graph_List Make_List(Graph_Matrix Matrix)
{
	Graph_List List = Graph_List(Matrix.directed, Matrix.Matrix.size());
	for (int i = 0; i < List.number_of_tops; i++)
		for (int j = 0; j < List.number_of_tops; j++)
			if (Matrix.Matrix[i][j])
			{
				vector<int> edge(3, 0);
				edge[0] = i;
				edge[1] = j;
				edge[2] = Matrix.Matrix[i][j];
				List.List.push_back(edge);
			}
	return List;
}

Graph_Matrix Make_Matrix(Graph_List List)
{
	Graph_Matrix Matrix = Graph_Matrix(List.directed, List.number_of_tops);
	for (int i = 0; i < List.List.size(); i++)
	{
		Matrix.Matrix[List.List[i][0]][List.List[i][1]] = List.List[i][2];
	}
	return Matrix;
}

int Min(int a, int b, int c)
{
	if (b == -1 || c == -1)
		return a;
	else
	{
		if (a > -1 && a < b + c)
			return a;
		else return b + c;
	}
}

int find_min(vector<int>& a)
{
	int min = 0;
	int index = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] && !min)
		{
			min = a[i];
			index = i;
		}
		if(a[i] && min)
			if (min > a[i])
			{
				min = a[i];
				index = i;
			}
	}
	a[index] = 0;
	if (min == 0)
		index = -1;
	return index;
}

void print_table(vector<vector<int>> table)
{
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
			cout << green << table[i][j] << " ";
		cout << endl;
	}
}

void print_list(vector<int> list)
{
	for (int i = 0; i < list.size(); i++)
		cout << green << list[i] << " ";
	cout << endl;
}

void Sys_pause()
{
	cout << yellow;
	system("pause");
	system("cls");
}