#include "Functions.h"


//Correct input:
bool check_int(string word)
{
	bool number = true;
	for (int i = 0; i < word.length(); i++)
		if (word[i] != '1' && word[i] != '2' && word[i] != '3' && word[i] != '4' && word[i] != '5' &&
			word[i] != '6' && word[i] != '7' && word[i] != '8' && word[i] != '9' && word[i] != '0')
			number = false;
	return number;
}

bool check_double(string word)
{
	bool number = true;
	int number_of_point = 1;
	for (int i = 0; i < word.length(); i++)
		if (word[i] == '.')
			number_of_point--;
		else if (word[i] != '1' && word[i] != '2' && word[i] != '3' && word[i] != '4' && word[i] != '5' &&
			word[i] != '6' && word[i] != '7' && word[i] != '8' && word[i] != '9' && word[i] != '0')
			number = false;
	if (number_of_point < 0)
		number = false;
	return number;
}


//Converting Functions:
string monterString(monster Monster)
{
	string line = "";
	line += to_string(Monster.ID);
	line += " ";
	line += Monster.name;
	line += " ";
	line += to_string(Monster.health) + " ";
	line += to_string(Monster.strength) + " ";
	line += Monster.type_of_attack + " ";
	line += to_string(Monster.chance) + " ";
	line += to_string(Monster.date.day) + " ";
	line += to_string(Monster.date.hour) + " ";
	line += to_string(Monster.date.minute);
	return line;
}

vector<string> split(string line)
{
	vector<string> information;
	string word = "";
	for (int i = 0; i < line.length(); i++)
		if (line[i] == ' ')
		{
			information.push_back(word);
			word = "";
		}
		else
			word += line[i];
	information.push_back(word);
	return information;
}


//Saving information into files:
void save_table_file(vector<monster> list_of_monsters, string file_path)
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
	file.close();
}

void save_table_binary_file(vector<monster> list_of_monsters, string binary_file_path)
{
	ofstream binary_file(binary_file_path, ios_base::binary);
	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		binary_file.write((char*)& list_of_monsters[i], sizeof(monster));
	}
	binary_file.close();
}


//Creating monster:
string create_name()
{
	string name = "";
	for (int i = 0; i < 6; i++)
	{
		name += (char)((int)'a' + rand() % 25);
	}
	return name;
}

monster autogenerator()
{
	monster newmonster;
	newmonster.name = create_name();
	newmonster.health = rand() % 50001;
	newmonster.strength = rand() % 1001;
	double ch = (double)(rand() % 100) / 100;
	newmonster.chance = ch;
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
	newmonster.date.day = rand() % 1000;
	newmonster.date.hour = rand() % 24;
	newmonster.date.minute = rand() % 60;
	return newmonster;
}

worldtime enter_date()
{
	worldtime date;
	bool st = true;
	cout << blue + "Enter the day of appearance in game." + light_blue << endl;
	while (st)
	{
		string day;
		cin >> day;
		bool is_number = check_int(day);
		if (is_number)
		{
			int number = stoi(day);
			date.day = number;
			st = false;
		}
		else cout << red + "Not number. Please enter the day again." + light_blue << endl;
	}
	system("cls");

	st = true;
	cout << blue + "Enter the hour of appearance in game(integer between 0 and 23)." + light_blue << endl;
	while (st)
	{
		string hour;
		cin >> hour;
		bool is_number = check_int(hour);
		if (is_number)
		{
			int number = stoi(hour);
			if (number >= 0 && number <= 23)
			{
				date.hour = number;
				st = false;
			}
			else cout << red + "Value of hour is out of range. Please enter the hour again(integer between 0 and 23)." + light_blue << endl;
		}
		else cout << red + "Not number. Please enter the hour again(integer between 0 and 23)." + light_blue << endl;
	}
	system("cls");

	st = true;
	cout << blue + "Enter the minute of appearance in game(integer between 0 and 59)." + light_blue << endl;
	while (st)
	{
		string minute;
		cin >> minute;
		bool is_number = check_int(minute);
		if (is_number)
		{
			int number = stoi(minute);
			if (number >= 0 && number <= 59)
			{
				date.minute = number;
				st = false;
			}
			else cout << red + "Value of hour is out of range. Please enter the hour again(integer between 0 and 59)." + light_blue << endl;
		}
		else cout << red + "Not a number. Please enter the hour again(integer between 0 and 59)." + light_blue << endl;
	}
	system("cls");
	return date;
}

string choose_special_attack()
{
	string types[4]
	{
		"Repeat attack;",
		"Increase damage;",
		"Cure yourself;",
		"Paralyze the enemy."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the type of special attack:" << endl;
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
				system("cls");
				return "repeat_attack";
				break;
			case 1:
				system("cls");
				return "increase_damage";
				system("pause");
				break;
			case 2:
				system("cls");
				return "cure_yourself";
				break;
			case 3:
				system("cls");
				return "paralyze_the_enemy";
				break;
			}
		}
	}
	cout << yellow;
}

monster create_monster()
{
	monster new_monster;
	cout << blue + "Enter monster's name." + light_blue << endl;
	cin >> new_monster.name;
	system("cls");
	bool st = true;
	cout << blue + "Enter the health of monster(integer between 0 and 50000)." + light_blue << endl;
	while (st)
	{
		string hp;
		cin >> hp;
		bool is_number = check_int(hp);
		if (is_number)
		{
			int number = stoi(hp);
			if (number >= 0 && number <= 50000)
			{
				new_monster.health = number;
				st = false;
			}
			else cout << red + "Value of health is out of range. Please enter the health of monster again(integer between 0 and 50000)." + light_blue << endl;
		}
		else cout << red + "Not a number. Please enter the health of monster again(integer between 0 and 50000)." + light_blue << endl;
	}
	system("cls");

	st = true;
	cout << blue + "Enter the strength of monster(integer between 0 and 1000)." + light_blue << endl;
	while (st)
	{
		string strength;
		cin >> strength;
		bool is_number = check_int(strength);
		if (is_number)
		{

			int number = stoi(strength);
			if (number >= 0 && number <= 1000)
			{
				new_monster.strength = number;
				st = false;
			}
			else cout << red + "Value of health is out of range. Please enter the health of monster again(integer between 0 and 50000)." + light_blue << endl;
		}
		else cout << red + "Not a number. Please enter the strength of monster again(integer between 0 and 1000)." + light_blue << endl;
	}
	system("cls");

	st = true;
	cout << blue + "Enter the chance of special attack(number between 0 and 1)." + light_blue << endl;
	while (st)
	{
		string ch;
		cin >> ch;
		bool is_double = check_double(ch);
		if (is_double)
		{
			double number = stod(ch);
			if (number >= 0 && number <= 1)
			{
				new_monster.chance = number;
				st = false;
			}
			else cout << red + "Value of chance is out of range. Please enter the chance of special attack(number between 0 and 1)." + light_blue << endl;
		}
		else
			cout << red + "Not double. Please enter the chance of special attack(number between 0 and 1)." + light_blue << endl;
	}
	system("cls");

	new_monster.type_of_attack = choose_special_attack();
	system("cls");

	new_monster.date = enter_date();

	return new_monster;
}

monster choose_type_of_generation()
{
	string types[2]
	{
		"Random parametrs;",
		"Your parametrs;"
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the type of special attack:" << endl;
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
			end = true;
			switch (position)
			{
			case 0:
				return autogenerator();
				break;
			case 1:
				return create_monster();
				break;
			default:
				break;
			}
		}
	}
}

void addMonster(int& id, vector<monster>& list_of_monsters, string file_path, string binary_file_path, monster new_monster)
{
	new_monster.ID = id;
	id++;
	list_of_monsters.push_back(new_monster);
	save_table_file(list_of_monsters, file_path);
	save_table_binary_file(list_of_monsters, binary_file_path);
}

void show_findedmonsters(vector<string> list_of_words)
{
	if (list_of_words.size())
		for (int i = 0; i < list_of_words.size(); i++)
			cout << green + list_of_words[i] << endl;
	else
		cout << yellow + "No monsters with such criteria." << endl;
}



//Showing information:
void print_list(vector<monster> list_of_monsters)
{
	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		cout << green;
		list_of_monsters[i].Print();
		cout << yellow;
	}
}

void read_table(string file_path)
{
	ifstream fin(file_path);
	string information;
	while (getline(fin, information))
	{
		cout << green + information << endl;
	}
	fin.close();
}

void read_binary(int size, string binary_file_path)
{
	ifstream binary_file(binary_file_path, ios_base::binary);
	monster* read_monster = new monster();
	while (size > 0)
	{
		cout << green;
		binary_file.read((char*)read_monster, sizeof(monster));
		(*read_monster).Print();
		size--;
	}
	binary_file.close();
}

void show(vector<monster> list_of_monsters, string file_path, string binary_file_path)
{
	string ways[4]
	{
		"Array(vector);",
		"File 'table.txt';",
		"Binary file;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose a way of saving information:" << endl;
		for (int i = 0; i < 4; i++)
		{
			if (i == position)
				cout << red + "->  " << light_blue + ways[i] << endl;
			else cout << "    " << light_blue + ways[i] << endl;
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
			switch (position)
			{
			case 0:
				system("cls");
				print_list(list_of_monsters);
				cout << yellow;
				system("pause");
				break;
			case 1:
				system("cls");
				read_table(file_path);
				cout << yellow;
				system("pause");
				break;
			case 2:
				system("cls");
				read_binary(list_of_monsters.size(), binary_file_path);
				cout << yellow;
				system("pause");
				break;
			case 3:
				end = true;
				break;
			}
		}
	}
}


//Finding information:
vector<string> find_by_name(string mark, string file_path)
{
	ifstream fin(file_path);
	string line;
	vector<string> finded_monsters;
	bool something_happend = false;
	while (getline(fin, line))
	{
		bool res = true;
		vector<string>  ourline = split(line);
		for (int i = 0; i < mark.length(); i++)
		{
			if (ourline[1].length() >= mark.length())
			{
				if (ourline[1][i] != mark[i])
					res = false;
			}
			else
				res = false;
		}
		if (res)
		{
			finded_monsters.push_back(line);
			something_happend = true;
		}
	}

	fin.close();
	return finded_monsters;
}

vector<string> find_by_attack(string mark, int start, int finish, string file_path)
{
	ifstream fin(file_path);
	string line;
	vector<string> finded_monsters;
	bool something_happend = false;
	while (getline(fin, line))
	{
		bool res = true;
		vector<string>  ourline = split(line);
		for (int i = 0; i < mark.length(); i++)
		{
			if (ourline[4].length() >= mark.length())
			{
				if (ourline[4][i] != mark[i])
					res = false;
			}
			else res = false;
		}
		if (res && stoi(ourline[3]) >= start && stoi(ourline[3]) <= finish)
		{
			finded_monsters.push_back(line);
			something_happend = true;
		}
	}

	fin.close();
	return finded_monsters;
}

vector<string> find_by_date(worldtime date, string file_path)
{
	ifstream fin(file_path);
	string line;
	vector<string> finded_monsters;
	bool something_happend = false;
	while (getline(fin, line))
	{
		vector<string>  ourline = split(line);
		if (stoi(ourline[6]) > date.day)
		{
			finded_monsters.push_back(line);
			something_happend = true;
		}

		if (stoi(ourline[6]) == date.day)
		{
			if (stoi(ourline[7]) > date.hour)
			{
				finded_monsters.push_back(line);
				something_happend = true;
			}

			if (stoi(ourline[7]) == date.hour)
			{
				if (stoi(ourline[8]) >= date.minute)
				{
					finded_monsters.push_back(line);
					something_happend = true;
				}
			}
		}
	}
	fin.close();
	return finded_monsters;
}

void find(string file_path)
{
	string ways[4]
	{
		"Begining of name;",
		"Type of special attack and range of strength;",
		"After date;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		vector<string> finded_monsters;
		system("cls");
		cout << blue + "    Choose a criteria:" << endl;
		for (int i = 0; i < 4; i++)
		{
			if (i == position)
				cout << red + "->  " << light_blue + ways[i] << endl;
			else cout << "    " << light_blue + ways[i] << endl;
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
			string mark;
			switch (position)
			{
			case 0:
				system("cls");
				cout << blue + "Enter the begining." + light_blue << endl;
				cin >> mark;
				finded_monsters = find_by_name(mark, file_path);
				show_findedmonsters(finded_monsters);
				cout << yellow;
				system("pause");
				break;
			case 1:
				mark = choose_special_attack();
				cout << blue + "Enter a range." + light_blue << endl;
				int start, finish;
				cin >> start >> finish;
				system("cls");
				finded_monsters = find_by_attack(mark, start, finish, file_path);
				show_findedmonsters(finded_monsters);
				cout << yellow;
				system("pause");
				break;
			case 2:
				worldtime date = enter_date();
				finded_monsters = find_by_date(date, file_path);
				show_findedmonsters(finded_monsters);
				cout << yellow;
				system("pause");
				break;
			case 3:
				end = true;
				break;
			}
		}
	}
}


//Editing and removing monsters:
void delete_line(int monster_id, vector<monster>& list_of_monsters, string file_path, string binary_file_path)
{
	for (int i = 0; i < list_of_monsters.size(); i++)
		if (list_of_monsters[i].ID == monster_id)
			list_of_monsters.erase(list_of_monsters.begin() + i);
	for (int i = 0; i < list_of_monsters.size(); i++)
		list_of_monsters[i].ID = i;
	save_table_file(list_of_monsters, file_path);
	save_table_binary_file(list_of_monsters, binary_file_path);

}

void edit_line(int monster_id, vector<monster>& list_of_monsters, string file_path, string binary_file_path, monster updated_monster)
{
	updated_monster.ID = monster_id;
	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		if (list_of_monsters[i].ID == monster_id)
			list_of_monsters[i] = updated_monster;
	}
	save_table_file(list_of_monsters, file_path);
	save_table_binary_file(list_of_monsters, binary_file_path);
}


//Creating empty files:
void create_file(string file_path)
{
	ofstream fout(file_path);
	fout.close();
}

void create_binary_file(string binary_file_path)
{
	ofstream binary_file(binary_file_path);
	binary_file.close();
}
