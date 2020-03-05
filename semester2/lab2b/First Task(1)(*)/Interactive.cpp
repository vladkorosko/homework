#include "lab2b.1.h"

void interactive_mode()
{
	array_list* Array_list = new struct array_list();
	vector_list* Vector_list = new struct vector_list();
	Linked_list* linked_list = new struct Linked_list();
	all_lists* My_list;

	int type = choose_list();
	switch (type)
	{
	case 0:
		My_list = Array_list;
		break;
	case 1:
		My_list = Vector_list;
		break;
	case 2:
		My_list = linked_list;
		break;
	default:
		My_list = Array_list;
		break;
	}

	string functions[10] =
	{
		"Create empty;",
		"Append;",
		"Insert;",
		"Remove;",
		"Get;",
		"Set;",
		"Length;",
		"Enter list;",
		"Print list;",
		"Back."
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Hello user.\n    There are the functions you can do." << endl;
		for (int i = 0; i < 10; i++)
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
					else position = 9;
				}

				if ((int)key == 80)
				{
					if (position < 9)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			IP new_ip;
			int index;
			system("cls");
			switch (position)
			{
			case 0:
				My_list->create_empty();
				Sys_pause();
				break;
			case 1:
				new_ip.enter_IP();
				My_list->append(new_ip);
				Sys_pause();
				break;
			case 2:
				if (My_list->length())
				{
					new_ip.enter_IP();
					index = enter_index(My_list->length());
					My_list->insert(index, new_ip);
				}
				else
					error_no_elements();
				Sys_pause();
				break;
			case 3:
				if (My_list->length())
				{
					index = enter_index(My_list->length());
					My_list->remove(index);
				}
				else
					error_no_elements();
				Sys_pause();
				break;
			case 4:
				if (My_list->length())
				{
					index = enter_index(My_list->length());
					new_ip = My_list->get(index);
					cout << green + "IPv4 is " << new_ip.ipv4 << endl;
				}
				else
					error_no_elements();
				Sys_pause();
				break;
			case 5:
				if (My_list->length())
				{
					index = enter_index(My_list->length());
					new_ip.enter_IP();
					My_list->set(index, new_ip);
				}
				else
					error_no_elements();
				Sys_pause();
				break;
			case 6:
				cout << green + "Length is " << My_list->length() << endl;
				Sys_pause();
				break;
			case 7:
				My_list->enter_list();
				Sys_pause();
				break;
			case 8:
				My_list->Print_list();
				Sys_pause();
				break;
			case 9:
				end = true;
				break;
			}
		}
	}
}