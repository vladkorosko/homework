#include "Structs.h"

void interactive_mode()
{
	Vector_list* vector_list = new struct Vector_list();
	Linked_list* linked_list = new struct Linked_list();
	Binary_tree_list* binary_tree = new struct Binary_tree_list();
	AVL_tree* avl_tree = new struct AVL_tree();
	Two_three_tree* two_three_tree = new struct Two_three_tree();
	List* My_list;

	int type = choose_list();
	switch (type)
	{
	case 0:
		My_list = vector_list;
		break;
	case 1:
		My_list = linked_list;
		break;
	case 2:
		My_list = binary_tree;
		break;
	case 3:
		My_list = avl_tree;
		break;
	case 4:
		My_list = two_three_tree;
		break;
	default:
		My_list = vector_list;
		break;
	}

	string functions[10] =
	{
		"Create empty;",
		"Append;",
		"Remove;",
		"Length;",
		"Find element;",
		"Find in range;",
		"Print list;",
		"Autogenerate;",
		"Change centre of coordinates;",
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
			PointXYZ point;
			system("cls");
			switch (position)
			{
			case 0:
				My_list->Create_empty();
				Sys_pause();
				break;
			case 1:
				point.Set_point(enter_number("X position"), enter_number("Y position"), enter_number("Z position"));
				My_list->Append(point);
				Sys_pause();
				break;
			case 2:
				if (My_list->Length())
				{
					point.Set_point(enter_number("X position"), enter_number("Y position"), enter_number("Z position"));
					My_list->Remove(point);
				}
				else
					error_no_elements();
				Sys_pause();
				break;
			case 3:
				cout << green << My_list->Length() << endl;
				Sys_pause();
				break;
			case 4:
				if (My_list->Length())
				{
					print_list(My_list->Find_element());
				}
				else error_no_elements();
				Sys_pause();
				break;
			case 5:
				if (My_list->Length())
				{
					print_list(My_list->Find_in_range());
				}
				else
					error_no_elements();
				Sys_pause();
				break;
			case 6:
				if (My_list->Length())
					My_list->Print();
				else error_no_elements();
				Sys_pause();
				break;
			case 7:
				My_list->Autogenerate(enter_number("number of points"));
				Sys_pause();
				break;
			case 8:
				point.Set_point(enter_number("X position"), enter_number("Y position"), enter_number("Z position"));
				My_list->Change_centre_position(point);
				Sys_pause();
				break;
			case 9:
				end = true;
				break;
			}
		}
	}
}
