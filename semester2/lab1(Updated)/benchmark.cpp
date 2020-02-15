#include "Functions.h"

string create_name()
{
	string name = "";
	for (int i = 0; i < 6; i++)
	{
		name += (char)((int)'a' + rand() % 25);
	}
	return name;
}

monster autogenerator(int &id)
{
	monster newmonster;
	newmonster.ID = id;
	++id;
	newmonster.name = create_name();
	newmonster.health = rand() % 50001;
	newmonster.strength = rand() % 1001;
	newmonster.chance = (rand() % 10) / (rand() % 20 + 10);
	switch (rand() % 4)
	{
	case 0:
		newmonster.type_of_attack = "repeat_attack";
		break;
	case 1:
		newmonster.type_of_attack = "increase_damage";
		break;
	case 2:
		newmonster.type_of_attack = "cure_yourself";
		break;
	case 3:
		newmonster.type_of_attack = "paralyze_the_enemy";
		break;
	}
	newmonster.date.day = rand();
	newmonster.date.hour = rand() % 24;
	newmonster.date.minute = rand() % 60;
	return newmonster;
}

size_t memory_write(vector<monster> list_of_monsters, string file_path)
{
	ofstream file(file_path);
	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		file << list_of_monsters[i].ID << " ";
		file << list_of_monsters[i].name << " ";
		file << list_of_monsters[i].health << " ";
		file << list_of_monsters[i].strength << " ";
		file << list_of_monsters[i].type_of_attack << " ";
		file << list_of_monsters[i].chance << " ";
		file << list_of_monsters[i].date.day << " ";
		file << list_of_monsters[i].date.hour << " ";
		file << list_of_monsters[i].date.minute << endl;
	}
	size_t size = file.tellp();
	file.close();
	return size;
}

void benchmark()
{
	
	int n = 5;
	string file_path = "table.txt";
	int start = clock();
	int finish = clock();
	int wasted_time = finish - start;
	while (wasted_time < 1000)
	{
		n *= 2;
		int id = 0;
		create_file(file_path);
		vector<monster> monsters;
		vector<string> finded_monsters;
		start = clock();
		for (int i = 0; i < n; i++)
		{
			monster newmonster = autogenerator(id);
			monsters.push_back(newmonster);
		}
		size_t size = memory_write(monsters, file_path);
		finded_monsters = find_by_name("a", file_path);
		finish = clock();
		wasted_time = finish - start;
		cout << green;
		cout << wasted_time << "      " << n  << "     " << size << endl;
	}

	int m = n;
	while (wasted_time < 10000)
	{
		int id = 0;
		create_file(file_path);
		vector<monster> monsters;
		vector<string> finded_monsters;
		start = clock();
		for (int i = 0; i < n; i++)
		{
			monster newmonster = autogenerator(id);
			monsters.push_back(newmonster);
		}
		size_t size = memory_write(monsters, file_path);
		finded_monsters = find_by_name("a", file_path);
		finish = clock();
		wasted_time = finish - start;
		cout << wasted_time << "      " << n << "     " << size << endl;
		n += m;
	}
}