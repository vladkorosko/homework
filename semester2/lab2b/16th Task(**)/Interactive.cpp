#include "sixteenth_task.h"

void interactive_mode()
{
	List_of_message my_messages;

	string functions[5] =
	{
		"Add new message;",
		"Add messages;",
		"Show all messages;",
		"Show some messages;",
		"Back."
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Hello user.\n    There are the functions you can do." << endl;
		for (int i = 0; i < 5; i++)
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
					else position = 4;
				}

				if ((int)key == 80)
				{
					if (position < 4)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			Message new_message;
			int k;
			system("cls");
			switch (position)
			{
			case 0:
				new_message.create_new_message();
				my_messages.add_new_message(new_message);
				Sys_pause();
				break;
			case 1:
				k = enter_number("number of messages");
				my_messages.add_messages(k);
				Sys_pause();
				break;
			case 2:
				my_messages.print_list();
				Sys_pause();
				break;
			case 3:
				k = enter_number_of_messages(my_messages.my_messages.size());
				my_messages.print_first_k_messages(k);
				Sys_pause();
				break;
			case 4:
				end = true;
				break;
			}
		}
	}
}