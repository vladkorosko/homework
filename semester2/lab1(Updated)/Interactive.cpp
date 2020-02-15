#include "Functions.h"

void interactive_mode()
{
	int id = 0;
	string file_path = "table.txt";
	string binary_file_path = "table.bin";
	vector<monster> monsters;
	create_file(file_path);
	create_binary_file(binary_file_path);

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
			monster new_monster;
			switch (position)
			{
			case 0:
				system("cls");
				new_monster = create_monster();
				addMonster(id, monsters, file_path, binary_file_path,new_monster);
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
				new_monster = create_monster();
				edit_line(monster_id, monsters, file_path, binary_file_path, new_monster);
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
