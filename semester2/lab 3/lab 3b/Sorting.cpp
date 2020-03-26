#include "Functions.h"


//Quick sort
bool later(worldtime first_date, worldtime second_date)
{
	bool res = false;
	if (first_date.day > second_date.day)
		res = true;
	if (first_date.day == second_date.day)
	{
		if (first_date.hour > second_date.hour)
			res = true;

		if (first_date.hour == second_date.hour)
			if (first_date.minute > second_date.minute)
				res = true;
	}
	return res;
}

void quick_sort(vector<monster>& monsters, int first, int last, int position)
{
	monster x = monsters[first];
	int i = first, j = last;
	do
	{
		switch (position)
		{
		case 0:
			while (monsters[i].ID < x.ID)
				i++;
			while (monsters[j].ID > x.ID)
				j--;
			break;
		case 1:
			while (monsters[i].name < x.name)
				i++;
			while (monsters[j].name > x.name)
				j--;
			break;
		case 2:
			while (monsters[i].health < x.health)
				i++;
			while (monsters[j].health > x.health)
				j--;
			break;
		case 3:
			while (monsters[i].strength < x.strength)
				i++;
			while (monsters[j].strength > x.strength)
				j--;
			break;
		case 4:
			while (monsters[i].chance < x.chance)
				i++;
			while (monsters[j].chance > x.chance)
				j--;
			break;
		case 5:	
			while (monsters[i].type_of_attack < x.type_of_attack)
				i++;
			while (monsters[j].type_of_attack > x.type_of_attack)
				j--;
			break;
		default:
			while (later(x.date, monsters[i].date))
				i++;
			while (later(monsters[j].date, x.date))
				j--;
			break;
		}
		if (i <= j)
		{
			if (i < j)
				swap(monsters[i], monsters[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (first < j)
		quick_sort(monsters, first, j, position);
	if (last > i)
		quick_sort(monsters, i, last, position);
}

void choose_criteria_sort(vector<monster> &monsters)
{
	string types[7]
	{
		"Id;",
		"Name;",
		"Health;",
		"Strength;",
		"Chance;",
		"Type of special attack;",
		"Date."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the criteria of sorting:" << endl;
		for (int i = 0; i < 7; i++)
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
					else position = 6;
				}

				if ((int)key == 80)
				{
					if (position < 6)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			end = true;
			system("cls");
			quick_sort(monsters, 0, monsters.size() - 1, position);
		}
	}
}


//Counting sort
void counting_sort(vector<monster>& list_of_monsters)
{
	vector<monster> cure_yourself;
	vector<monster> repeat_attack;
	vector<monster> increase_damage;
	vector<monster> paralyze_the_enemy;

	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		if (list_of_monsters[i].type_of_attack == "cure_yourself")
			cure_yourself.push_back(list_of_monsters[i]);
		if (list_of_monsters[i].type_of_attack == "repeat_attack")
			repeat_attack.push_back(list_of_monsters[i]);
		if (list_of_monsters[i].type_of_attack == "increase_damage")
			increase_damage.push_back(list_of_monsters[i]);
		if (list_of_monsters[i].type_of_attack == "paralyze_the_enemy")
			paralyze_the_enemy.push_back(list_of_monsters[i]);
	}

	for (int i = 0; i < increase_damage.size(); i++)
		cure_yourself.push_back(increase_damage[i]);

	for (int i = 0; i < paralyze_the_enemy.size(); i++)
		cure_yourself.push_back(paralyze_the_enemy[i]);

	for (int i = 0; i < repeat_attack.size(); i++)
		cure_yourself.push_back(repeat_attack[i]);

	list_of_monsters = cure_yourself;
}


//Radix sort
int get_longest_double(vector<monster> monsters)
{
	string longest = to_string(monsters[0].chance);
	
	for (int i = 1; i < monsters.size(); i++)
	{
		if (to_string(monsters[i].chance).length() > longest.length())
			longest = to_string(monsters[i].chance);
	}
	return longest.length();
}

void addition_counting_sort(vector<monster> &monsters, double exp)
{
	vector<monster> res;
	vector<vector<monster>> count (10, vector<monster> ());

	for (int i = 0; i < monsters.size(); i++)
		count[(int)(monsters[i].chance * exp) % 10].push_back(monsters[i]);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < count[i].size(); j++)
			res.push_back(count[i][j]);
	monsters = res;
}

void radix_sort(vector<monster> &monsters)
{
	int m = get_longest_double(monsters);

	int exp = 1;
	for (int i = 0; i < m; i++)
		exp *= 10;
	for (exp; exp > 0; exp /= 10)
		addition_counting_sort(monsters, exp);

	
}



//Using sort
void choose_sort(vector<monster>& monsters, string file_path, string binary_file_path)
{
	string types[4]
	{
		"Quick sort;",
		"Counting sort (only type of special attack);",
		"Radix sort (only chance);",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the type of sorting:" << endl;
		for (int i = 0; i < 4; i++)
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
					else position = 3;
				}

				if ((int)key == 80)
				{
					if (position < 3)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			end = true;
			switch (position)
			{
			case 0:
				choose_criteria_sort(monsters);
				break;
			case 1:
				counting_sort(monsters);
				break;
			case 2:
				radix_sort(monsters);
				break;
			}
			save_table_file(monsters, file_path);
			save_table_binary_file(monsters, binary_file_path);
			system("cls");
			cout << blue + "Sorting success." << endl;
			cout << yellow;
			system("pause");
		}
	}
}