#include "Background.h"

void menu()
{
	string types[3]
	{
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
			switch (position)
			{
			case 0:
				system("cls");
				demo();
				break;
			case 1:
				system("cls");
				benchmark();
				break;
			case 2:
				system("cls");
				cout << yellow;
				end = true;
				break;
			}
		}
	}
}