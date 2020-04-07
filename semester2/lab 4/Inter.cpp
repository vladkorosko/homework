#include "lab4.h"

void inter()
{
	Tree* tree = new Tree();
	Binary_Tree* binary_tree = new Binary_Tree();
	Symetric_Tree* symetric_tree = new Symetric_Tree(binary_tree);

	string functions[8] =
	{
		"Add interactive(3 task);",
		"Print(7 task);",
		"Print_interactive(12 task);",
		"Delete(14 task);",
		"Add(18 task);",
		"Print(18 task);",
		"Show symetric tree(20 task);",
		"Back."
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << "    Hello user.\n    There are the functions you can do." << endl;
		for (int i = 0; i < 8; i++)
		{
			if (i == 4)
				cout << "Binary tree:" << endl;
			if (i == position)
				cout << "->  " << functions[i] << endl;
			else cout << "    " << functions[i] << endl;
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
			system("cls");
			Tree* deleted_tree = new Tree();
			Node* node = nullptr;
			switch (position)
			{
			case 0:
				tree->add_new_interactive(enter_number("integer"), node);
				break;
			case 1:
				if (tree->root)
					tree->print(tree->root);
				else cout << "Have no elements";
				cout << endl;
				system("pause");
				break;
			case 2:
				if (tree->root)
					node = tree->choose_node(tree->root);
				else cout << "Have no elements" << endl;
				break;
			case 3:
				if (tree->root)
					deleted_tree = tree->remove(enter_number("integer"),tree->root);
				else cout << "Have no elements" << endl;
				break;
			case 4:
				binary_tree->add(enter_number("integer"), binary_tree->root);
				break;
			case 5:
				if (binary_tree->root)
					binary_tree->print(binary_tree->root);
				else cout << "Have no elements";
				cout << endl;
				system("pause");
				break;
			case 6:
				if (binary_tree->root)
				{
					symetric_tree->create(binary_tree);
					symetric_tree->symetric_write(symetric_tree->root);
				}
				else cout << "No elements";
				cout << endl;
				system("pause");
				break;
			case 7:
				end = true;
				break;
			}
		}
	}
}