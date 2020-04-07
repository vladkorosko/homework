#include "Functions.h"

void clear_vector(vector<string>& list_of_monsters)
{
	while (list_of_monsters.size() > 0)
		list_of_monsters.erase(list_of_monsters.begin());
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
	vector<string> finded_monsters;
	create_file(file_path);
	create_file(binary_file_path);
	fstream file(file_path);
	cout << blue + "Now i add monster with next characteristics:" + light_blue + "\nName - zombie\nHealth - 100\nSterngth - 10" << endl;
	cout << "Special attack - paralyze the enemy\nChance - 0.1\nDay of appearence - 10, hour - 18, minute - 30" + yellow << endl;
	monster First_monster;
	First_monster.health = 100;
	First_monster.strength = 10;
	First_monster.chance = 0.1;
	First_monster.type_of_attack = "paralyze_the_enemy";
	First_monster.name = "zombie";
	First_monster.date.day = 10;
	First_monster.date.hour = 18;
	First_monster.date.minute = 30;
	addMonster(id, monsters, file_path, binary_file_path, First_monster);
	system("pause");
	cout << blue + "Now i show you information in 'table.txt'." + green << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i show you information in 'table.bin'." + green << endl;
	read_binary(1, binary_file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i show you information in array." + green << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i add mext monster with next characteristics:" + light_blue + "\nName - sceleton\nHealth - 200\nSterngth - 0" << endl;
	cout << "Special attack - repeat attack\nChance - 0.4\nDay of appearence - 5, hour - 10, minute - 30" + yellow << endl;
	First_monster.health = 200;
	First_monster.strength = 0;
	First_monster.chance = 0.4;
	First_monster.type_of_attack = "repeat_attack";
	First_monster.name = "sceleton";
	First_monster.date.day = 5;
	First_monster.date.hour = 10;
	First_monster.date.minute = 30;
	addMonster(id, monsters, file_path, binary_file_path, First_monster);
	system("pause");
	cout << blue + "Now i show you information in 'table.txt'." + green << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	cout << blue + "Now i show you information in 'table.bin'." + green << endl;
	read_binary(2, binary_file_path);
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
	cout << blue + "Now i show you information in 'table.bin'." + green << endl;
	read_binary(2, binary_file_path);
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
	finded_monsters = find_by_name("zom", file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with bedining 'zombi'." << endl;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_name("zombi", file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with bedining 'a'." << endl;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_name("a", file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with bedining 's'." << endl;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_name("s", file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i find monster with special attack 'paralyze_the_enemy' with attack between 10 and 100." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	finded_monsters = find_by_attack("paralyze_the_enemy", 10, 100, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with special attack 'cure_yourself' with attack between 10 and 100." << endl;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_attack("cure_yourself", 10, 100, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with special attack 'paralyze_the_enemy' with attack between 0 and 9." << endl;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_attack("paralyze_the_enemy", 0, 9, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster with special attack 'repeat_attack' with attack between 20 and 100." << endl;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_attack("repeat_attack", 20, 100, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i find monster after 10th day 10:30." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	worldtime date;
	date.day = 10;
	date.hour = 10;
	date.minute = 30;
	finded_monsters = find_by_date(date, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster after 10th day 19:30." << endl;
	date.hour = 19;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_date(date, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster after 5th day 10:30." << endl;
	date.day = 5;
	date.hour = 10;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_date(date, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	cout << blue + "Now i find monster after 10th day 18:31." << endl;
	date.day = 10;
	date.hour = 18;
	date.minute = 31;
	cout << yellow;
	system("pause");
	finded_monsters = find_by_date(date, file_path);
	show_findedmonsters(finded_monsters);
	clear_vector(finded_monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i delete monster with id 0." << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	delete_line(0, monsters, file_path, binary_file_path);
	cout << blue + "Now i show you information in 'table.txt'." + green << endl;
	read_table(file_path);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i create list with ten monsters." << endl;
	for (int i = 1; i < 10; i++)
		addMonster(id, monsters, file_path, binary_file_path, autogenerator());
	read_table(file_path);
	cout << yellow;
	system("pause");

	cout << blue + "Now i sort list by name of monsters." << endl;
	quick_sort(monsters, 0, monsters.size() - 1, 1);
	cout << blue + "Now i show you information in vector." + green << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i sort list by ID of monsters." << endl;
	quick_sort(monsters, 0, monsters.size() - 1, 0);
	cout << blue + "Now i show you information in vector." + green << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i use counting sort(type attack)." << endl;
	counting_sort(monsters);
	cout << blue + "Now i show you information in vector." + green << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "Now i use radix sort(chance)." << endl;
	radix_sort(monsters);
	cout << blue + "Now i show you information in vector." + green << endl;
	print_list(monsters);
	cout << yellow;
	system("pause");
	system("cls");

	cout << blue + "This is all. Thanks for using." << endl;
	cout << yellow;
	system("pause");
	system("cls");
}