#include "Functions.h"

int id = 0;
const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

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
				cout << red +  "->  " << light_blue + types[i] << endl;
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

string intString(int number)
{
	string inversedword = "";
	if (number == 0)
		return "0";
	while (number > 0)
	{
		int last_number = number % 10;
		inversedword += last_number + '0';
		number /= 10;
	}
	string word = "";
	for (int i = inversedword.length() - 1; i >= 0; i--)
		word += inversedword[i];
	return word;
}

string doubleString(double number)
{
	string word = "";
	if (number == 0)
		return "0";
	while (number == 0)
	{
		int last_number = number;
		word += last_number + '0';
		number *= 10;
	}
	return word;
}

string monterString(monster Monster)
{
	string line = "";
	line += intString(Monster.ID);
	line += " ";
	line += Monster.name;
	line += " ";
	line += intString(Monster.health) + " ";
	line += intString(Monster.strength) + " ";
	line += Monster.type_of_attack + " ";
	line += doubleString(Monster.chance) + " ";
	line += intString(Monster.date.day) + " ";
	line += intString(Monster.date.hour) + " ";
	line += intString(Monster.date.minute);
	return line;
}

void print_list(vector<monster> list_of_monsters)
{
	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		cout << green;
		list_of_monsters[i].Print();
		cout << yellow;
	}
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
		else if(word[i] != '1' && word[i] != '2' && word[i] != '3' && word[i] != '4' && word[i] != '5' &&
				word[i] != '6' && word[i] != '7' && word[i] != '8' && word[i] != '9' && word[i] != '0')
				number = false;
	if (number_of_point < 0)
		number = false;
	return number;
}

time enter_date()
{
	time date;
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
			else cout << red + "Value of health is out of range. Please enter the health of monster again(integer between 0 and 50000)."+ light_blue << endl;
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
		cout << red + "Not double. Please enter the chance of special attack(number between 0 and 1)." + light_blue << endl;
	}
	system("cls");

	new_monster.type_of_attack = choose_special_attack();
	system("cls");

	new_monster.date = enter_date();

	return new_monster;
}

void save_table(vector<monster> list_of_monsters, string file_path, string binary_file_path)
{
	ofstream file(file_path);
	ofstream binary_file(binary_file_path, ios_base::binary);
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
		binary_file.write((char*)& list_of_monsters[i], sizeof(monster));
	}
	file.close();
	binary_file.close();
}

void addMonster(vector<monster>& list_of_monsters, string file_path, string binary_file_path, monster new_monster = create_monster())
{
	new_monster.ID = id;
	id++;
	list_of_monsters.push_back(new_monster);
	save_table(list_of_monsters, file_path, binary_file_path);
}

void read_binary(int size, string binary_file_path)
{
	ifstream binary_file(binary_file_path, ios_base::binary);
	monster* read_monster = new monster();
	while (size > 0)
	{
		cout << green;
		binary_file.read((char*) read_monster, sizeof(monster));
		(*read_monster).Print();
		size--;
	}
	binary_file.close();
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

void find_by_name(string mark, string file_path)
{
	ifstream fin(file_path);
	string line;
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
			cout << green + line << endl;
			something_happend = true;
		}
	}
	if (!something_happend)
		cout << yellow + "I didn't find monstres with such criteria." << endl;
	fin.close();
}

void find_by_attack(string mark, int start, int finish, string file_path)
{
	ifstream fin(file_path);
	string line;
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
			cout << green + line << endl;
			something_happend = true;
		}
	}
	if (!something_happend)
		cout << yellow + "I didn't find monstres with such criterias." << endl;
	fin.close();
}

void find_by_date(time date, string file_path)
{
	ifstream fin(file_path);
	string line;
	bool something_happend = false;
	while (getline(fin, line))
	{
		vector<string>  ourline = split(line);
		if (stoi(ourline[6]) > date.day)
		{
			cout << green + line << endl;
			something_happend = true;
		}

		if (stoi(ourline[6]) == date.day)
		{
			if (stoi(ourline[7]) > date.hour)
			{
				cout << green + line << endl;
				something_happend = true;
			}

			if (stoi(ourline[7]) == date.hour)
			{
				if (stoi(ourline[8]) >= date.minute)
				{
					cout << green +  line << endl;
					something_happend = true;
				}
			}
		}
	}
	if (!something_happend)
		cout << yellow + "I didn't find monstres after this time." << endl;
	fin.close();
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
		system("cls");
		cout << blue + "    Choose a criteria:" << endl;
		for (int i = 0; i < 4; i++)
		{
			if (i == position)
				cout << red +  "->  " << light_blue + ways[i] << endl;
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
				find_by_name(mark, file_path);
				cout << yellow;
				system("pause");
				break;
			case 1:
				mark = choose_special_attack();
				cout << blue + "Enter a range." + light_blue << endl;
				int start, finish;
				cin >> start >> finish;
				system("cls");
				find_by_attack(mark,start,finish,file_path);
				cout << yellow;
				system("pause");
				break;
			case 2:
				time date = enter_date();
				find_by_date(date,file_path);
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

void delete_line(int monster_id, vector<monster>& list_of_monsters, string file_path, string binary_file_path)
{
	for (int i = 0; i < list_of_monsters.size(); i++)
		if (list_of_monsters[i].ID == monster_id)
			list_of_monsters.erase(list_of_monsters.begin() + i);
	for (int i = 0; i < list_of_monsters.size(); i++)
		list_of_monsters[i].ID = i;
	save_table(list_of_monsters, file_path, binary_file_path);
}

void edit_line(int monster_id, vector<monster>& list_of_monsters, string file_path, string binary_file_path, monster updated_monster = create_monster())
{
	updated_monster.ID = monster_id;
	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		if (list_of_monsters[i].ID == monster_id)
			list_of_monsters[i] = updated_monster;
	}
	save_table(list_of_monsters, file_path, binary_file_path);
}

void create_file(string file_path, string binary_file_path)
{
	ofstream fout(file_path);
	ofstream binary_file(binary_file_path);
	fout.close();
	binary_file.close();
}

void interactive_mode()
{
	id = 0;
	string file_path = "table.txt";
	string binary_file_path = "table.bin";
	vector<monster> monsters;
	create_file(file_path, binary_file_path);

	string functions[6] =
	{
		"Add monster;",
		"Show information about monsters;",
		"Search monsters;",
		"Edit monster;",
		"Delete monster;",
		"Back."
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Hello user.\n    There are the functions you can do."<< endl;
		for (int i = 0; i < 6; i++)
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
					else position = 5;
				}

				if ((int)key == 80)
				{
					if (position < 5)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			int monster_id;
			switch (position)
			{
			case 0:
				system("cls");
				addMonster(monsters, file_path, binary_file_path);
				break;
			case 1:
				system("cls");
				show(monsters, file_path, binary_file_path);
				break;
			case 2:
				system("cls");
				find(file_path);
				break;
			case 3:
				system("cls");
				cout << blue + "Enter id." + light_blue << endl;
				cin >> monster_id;
				edit_line(monster_id, monsters, file_path, binary_file_path);
				break;
			case 4:
				system("cls");
				cout << blue + "Enter id." + light_blue << endl;
				cin >> monster_id;
				delete_line(monster_id, monsters, file_path, binary_file_path);
				break;
			case 5:
				end = true;
				break;
			}
		}
	}

}

void demonstrative_mode()
{
	int id = 0;
	cout << blue + "Hello user.\nNow i show what i can do.\n" << yellow;
	system("pause");
	system("cls");

	string file_path = "table.txt";
	string binary_file_path = "table.bin";
	vector<monster> monsters;
	create_file(file_path, binary_file_path);
	fstream file(file_path);
	cout << blue + "Now i add monster with next characteristics:" + light_blue + "\nName - zombie\nHealth - 100\nSterngth - 10" << endl;
	cout << "Special attack - paralyze the enemy\nChance - 0.1\nDay of appearence - 10, hour - 18, minute - 30" + yellow << endl;
	monster First_monster;
	First_monster.ID = id;
	id++;
	First_monster.health = 100;
	First_monster.strength = 10;
	First_monster.chance = 0.1;
	First_monster.type_of_attack = "paralyze_the_enemy";
	First_monster.name = "zombie";
	First_monster.date.day = 10;
	First_monster.date.hour = 18;
	First_monster.date.minute = 30;
	addMonster(monsters, file_path, binary_file_path, First_monster);
	system("pause");
	cout << blue + "Now i show you information in 'table.txt'." + green << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i show you information in array." + green << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i add mext monster with next characteristics:" + light_blue + "\nName - sceleton\nHealth - 200\nSterngth - 0" << endl;
	cout << "Special attack - repeat attack\nChance - 0.4\nDay of appearence - 5, hour - 10, minute - 30" + yellow << endl;
	First_monster.ID = id;
	id++;
	First_monster.health = 200;
	First_monster.strength = 0;
	First_monster.chance = 0.4;
	First_monster.type_of_attack = "repeat_attack";
	First_monster.name = "sceleton";
	First_monster.date.day = 5;
	First_monster.date.hour = 10;
	First_monster.date.minute = 30;
	addMonster(monsters, file_path, binary_file_path, First_monster);
	system("pause");
	cout << blue + "Now i show you information in 'table.txt'." + green << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i show you information in array." + green << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i edit monster with id = 1" << endl;
	read_table(file_path);
	cout << blue + "I will change name to skeleton and strength to 20." << endl;
	First_monster.name = "skeleton";
	First_monster.strength = 20;
	cout << yellow;
	system("pause");
	edit_line(1, monsters, file_path, binary_file_path, First_monster);
	cout << blue + "This is updated information in 'table.txt'." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	cout << blue + "This is updated information in array." << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i find monster with bedining 'zom'." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	find_by_name("zom", file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with bedining 'zombi'." << endl;
	cout << yellow;
	system("pause");
	find_by_name("zombi", file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with bedining 'a'." << endl;
	cout << yellow;
	system("pause");
	find_by_name("a", file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with bedining 's'." << endl;
	cout << yellow;
	system("pause");
	find_by_name("s", file_path);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i find monster with special attack 'paralyze_the_enemy' with attack between 10 and 100." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	find_by_attack("paralyze_the_enemy", 10, 100, file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with special attack 'cure_yourself' with attack between 10 and 100." << endl;
	cout << yellow;
	system("pause");
	find_by_attack("cure_yourself", 10, 100, file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with special attack 'paralyze_the_enemy' with attack between 0 and 9." << endl;
	cout << yellow;
	system("pause");
	find_by_attack("paralyze_the_enemy", 0, 9, file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with special attack 'repeat_attack' with attack between 20 and 100." << endl;
	cout << yellow;
	system("pause");
	find_by_attack("repeat_attack", 20, 100, file_path);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i find monster after 10th day 10:30." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	time date;
	date.day = 10;
	date.hour = 10;
	date.minute = 30;
	find_by_date(date, file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster after 10th day 19:30." << endl;
	date.hour = 19;
	cout << yellow;
	system("pause");
	find_by_date(date, file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster after 5th day 10:30." << endl;
	date.day = 5;
	date.hour = 10;
	cout << yellow;
	system("pause");
	find_by_date(date, file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster after 10th day 18:31." << endl;
	date.day = 10;
	date.hour = 18;
	date.minute = 31;
	cout << yellow;
	system("pause");
	find_by_date(date, file_path);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i delete monster with id 0." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	delete_line(0, monsters, file_path, binary_file_path);
	read_table(file_path);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "This is all. Thanks for using." << endl;
	cout << yellow;
	system("pause");
	system("cls");
	id = 0;
}

void menu()
{
	string types[4]
	{
		"Interactive dialog mode;",
		"Demonstrative mode;",
		"Benchmark;",
		"Exit."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the mode:" << endl;
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
			switch (position)
			{
			case 0:
				system("cls");
				interactive_mode();
				break;
			case 1:
				system("cls");
				demonstrative_mode();
				break;
			case 2:
				system("cls");
				//branch_mark;
				break;
			case 3:
				system("cls");
				cout << yellow;
				end = true;
				break;
			}
		}
	}
}
