#include"7task.h"

int choose_list()
{
	string functions[3] =
	{
		"Array list;",
		"Vector list;",
		"Linked list;",
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the type of list." << endl;
		for (int i = 0; i < 3; i++)
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
					else position = 2;
				}

				if ((int)key == 80)
				{
					if (position < 2)
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

	string functions[8] =
	{
		"Create empty;",
		"Append;",
		"Remove;",
		"Filter;",
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
		cout << blue + "    Hello user.\n    There are the functions you can do and new function filter." << endl;
		for (int i = 0; i < 8; i++)
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
					else position = 7;
				}

				if ((int)key == 80)
				{
					if (position < 7)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			string new_element;
			int index;
			system("cls");
			switch (position)
			{
			case 0:
				My_list->create_empty();
				Sys_pause();
				break;
			case 1:
				cin >> new_element;
				My_list->append(new_element);
				Sys_pause();
				break;
			case 2:
				if (My_list->length())
				{
					index = enter_index(My_list->length());
					My_list->remove(index);
				}
				else
					error_no_elements();
				Sys_pause();
				break;
			case 3:
				My_list->filter_interactive();
				Sys_pause();
				break;
			case 4:
				cout << green + "Length is " << My_list->length() << endl;
				Sys_pause();
				break;
			case 5:
				My_list->enter_list();
				Sys_pause();
				break;
			case 6:
				My_list->Print_list();
				Sys_pause();
				break;
			case 7:
				end = true;
				break;
			}
		}
	}
}

void demonstrative_mode()
{
	cout << blue + "Hello user." << endl;
	cout << "Now i show you what i can do." << endl;
	Sys_pause();
	array_list Array_list;
	vector_list Vector_list;
	Linked_list linked_list;

	cout << blue + "Now i create list with 20 elements." << endl;
	int n = 20;
	while (n > 0)
	{
		string new_string = create_string();
		Array_list.append(new_string);
		Vector_list.append(new_string);
		linked_list.append(new_string);
		n--;
	}
	Sys_pause();

	cout << blue + "Now i show you length and information in array list." << endl;
	cout << green + "Length is " << Array_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in vector list." << endl;
	cout << green + "Length is " << Vector_list.length() << "." << endl;
	Vector_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in linked list." << endl;
	cout << green + "Length is " << linked_list.length() << "." << endl;
	linked_list.Print_list();
	Sys_pause();

	cout << blue + "Now i filter information in array list by begining ''." << endl;
	Array_list.filter("");
	Sys_pause();

	cout << blue + "Now i filter information in vector list by begining ''." << endl;
	Vector_list.filter("");
	Sys_pause();

	cout << blue + "Now i filter information in linked list by begining ''." << endl;
	linked_list.filter("");
	Sys_pause();

	cout << blue + "Now i filter information in array list by begining 'a'." << endl;
	Array_list.filter("a");
	Sys_pause();

	cout << blue + "Now i filter information in vector list by begining 'a'." << endl;
	Vector_list.filter("a");
	Sys_pause();

	cout << blue + "Now i filter information in linked list by begining 'a'." << endl;
	linked_list.filter("a");
	Sys_pause();

	cout << blue + "Now i filter information in array list by begining 'r'." << endl;
	Array_list.filter("r");
	Sys_pause();

	cout << blue + "Now i filter information in vector list by begining 'r'." << endl;
	Vector_list.filter("r");
	Sys_pause();

	cout << blue + "Now i filter information in linked list by begining 'r'." << endl;
	linked_list.filter("r");
	Sys_pause();

	cout << blue + "Thank you for using." << endl;
	Sys_pause();
}

void seventh_task()
{
	string types[3]
	{
		"Interactive dialog mode;",
		"Demonstrative mode;",
		"Exit."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the mode:" << endl;
		for (int i = 0; i < 3; i++)
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
					else position = 2;
				}

				if ((int)key == 80)
				{
					if (position < 2)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			system("cls");
			switch (position)
			{
			case 0:
				interactive_mode();
				break;
			case 1:
				demonstrative_mode();
				break;
			case 2:
				end = true;
				break;
			}
		}
	}
}
