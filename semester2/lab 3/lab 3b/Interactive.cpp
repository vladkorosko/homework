#include "Functions.h"

void interactive_mode()
{
	int id = 0;
	string file_path = "table.txt";
	string binary_file_path = "table.bin";
	vector<monster> monsters;
	create_file(file_path);
	create_binary_file(binary_file_path);

	string functions[7] =
	{
		"Add monster;",
		"Show information about monsters;",
		"Sort monsters;",
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
		cout << blue + "    Hello user.\n    There are the functions you can do." << endl;
		for (int i = 0; i < 7; i++)
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
			string monster_id;
			monster new_monster;
			system("cls");
			switch (position)
			{
			case 0:
				new_monster = choose_type_of_generation();
				addMonster(id, monsters, file_path, binary_file_path, new_monster);
				cout << blue + "Monster added successfully." + yellow << endl;
				system("pause");
				break;
			case 1:
				show(monsters, file_path, binary_file_path);
				break;
			case 2:
				if (monsters.size() > 0)
					choose_sort(monsters, file_path, binary_file_path);
				else
				{
					cout << red + "No elements." + yellow << endl;
					system("pause");
				}
				break;
			case 3:
				find(file_path);
				break;
			case 4:
				cout << blue + "Enter id." + light_blue << endl;
				cin >> monster_id;
				if (check_int(monster_id))
				{
					new_monster = create_monster();
					edit_line(stoi(monster_id), monsters, file_path, binary_file_path, new_monster);
				}
				else
				{
					cout << red + "Not a number." + yellow << endl;
					system("pause");
				}
				break;
			case 5:
				cout << blue + "Enter id." + light_blue << endl;
				cin >> monster_id;
				if (check_int(monster_id))
					delete_line(stoi(monster_id), monsters, file_path, binary_file_path);
				else
				{
					cout << red + "Not a number." + yellow << endl;
					system("pause");
				}
				break;
			case 6:
				end = true;
				break;
			}
		}
	}
}
