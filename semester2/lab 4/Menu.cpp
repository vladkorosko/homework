#include "lab4.h"

void menu()
{
	string types[3]
	{
		"Interactive mode;",
		"Demonstrative mode;",
		"Exit."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << "    Choose the mode:" << endl;
		for (int i = 0; i < 3; i++)
		{
			if (i == position)
				cout << "->  " << types[i] << endl;
			else cout << "    " << types[i] << endl;
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
			switch (position)
			{
			case 1:
				system("cls");
				demo();
				break;
			case 0:
				system("cls");
				inter();
				break;
			case 2:
				system("cls");
				end = true;
				break;
			}
		}
	}
}