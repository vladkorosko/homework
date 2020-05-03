#include "Structs.h"

void demo()
{
	cout << blue + "Hello users. Now I show you all functions of this code." << endl;
	cout << "First of all I create empty list of every structs." << endl;
	Vector_list vector_list;
	vector_list.Create_empty();
	Linked_list linked_list;
	linked_list.Create_empty();
	Binary_tree_list binary_tree;
	binary_tree.Create_empty();
	AVL_tree avl_tree;
	avl_tree.Create_empty();
	Two_three_tree two_three_tree;
	two_three_tree.Create_empty();

	cout << endl << "This is information in list based on vector." << endl;
	vector_list.Print();
	cout << endl << blue + "This is information in list based on linked list." << endl;
	linked_list.Print();
	cout << endl << blue + "This is information in list based on binary tree." << endl;
	binary_tree.Print();
	cout << endl << blue + "This is information in list based on AVL tree." << endl;
	avl_tree.Print();
	cout << endl << blue + "This is information in list based on 2-3 tree." << endl;
	two_three_tree.Print();
	Sys_pause();

	cout << blue + "Now I add point (0,0,0) and (0,1,2) to each list." << endl;

	PointXYZ point;
	point.Set_point(0,0,0);
	vector_list.Append(point);
	linked_list.Append(point);
	binary_tree.Append(point);
	avl_tree.Append(point);
	two_three_tree.Append(point);
	point.Set_point(0, 1, 2);
	vector_list.Append(point);
	linked_list.Append(point);
	binary_tree.Append(point);
	avl_tree.Append(point);
	two_three_tree.Append(point);

	cout << endl << "This is information in list based on vector." << endl;
	vector_list.Print();
	cout << endl << blue + "This is information in list based on linked list." << endl;
	linked_list.Print();
	cout << endl << blue + "This is information in list based on binary tree." << endl;
	binary_tree.Print();
	cout << endl << blue + "This is information in list based on AVL tree." << endl;
	avl_tree.Print();
	cout << endl << blue + "This is information in list based on 2-3 tree." << endl;
	two_three_tree.Print();
	Sys_pause();

	cout << blue + "Now I generate 8 elements in every list." << endl;
	vector_list.Autogenerate(8);
	linked_list.Convert_from_vector_to_list(vector_list.vector_points);
	binary_tree.Convert_from_vector_to_tree(vector_list.vector_points);
	avl_tree.Convert_from_vector_to_tree(vector_list.vector_points);
	two_three_tree.Convert_from_vector_to_tree(vector_list.vector_points);

	cout << endl << "This is information in list based on vector." << endl;
	vector_list.Print();
	cout << endl << blue + "This is information in list based on linked list." << endl;
	linked_list.Print();
	cout << endl << blue + "This is information in list based on binary tree." << endl;
	binary_tree.Print();
	cout << endl << blue + "This is information in list based on AVL tree." << endl;
	avl_tree.Print();
	cout << endl << blue + "This is information in list based on 2-3 tree." << endl;
	two_three_tree.Print();
	Sys_pause();

	cout << blue + "Now I find elements that have X position 0 in every list." << endl;

	Vector_list vector_for_tree;

	cout << endl << "This is result of searching in list based on vector." << endl;
	print_list(Find_by_x(vector_list.vector_points, 0));

	cout << endl << blue + "This is result of searching in list based on linked list." << endl;
	print_list(Find_by_x(linked_list.Convert_to_Vector().vector_points, 0));

	cout << endl << blue + "This is result of searching in list based on binary tree." << endl;
	binary_tree.Convert_to_vector(vector_for_tree, binary_tree.root);
	print_list(Find_by_x(vector_for_tree.vector_points, 0));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on AVL tree." << endl;
	avl_tree.Convert_to_vector(vector_for_tree, avl_tree.root);
	print_list(Find_by_x(vector_for_tree.vector_points, 0));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on 2-3 tree." << endl;
	two_three_tree.Convert_to_vector(vector_for_tree, two_three_tree.root);
	print_list(Find_by_x(vector_for_tree.vector_points, 0));
	vector_for_tree.Create_empty();
	Sys_pause();

	cout << blue + "The program also have the same functions for Y and Z position." << endl;
	cout << "You can combine them to create searching by X and Y position or another combination." << endl;
	cout << "I show you searching by all positions. So it's point (0,0,0)." << endl;

	cout << endl << "This is result of searching in list based on vector." << endl;
	print_list(Find_by_x(Find_by_y(Find_by_z(vector_list.vector_points, 0), 0), 0));

	cout << endl << blue + "This is result of searching in list based on linked list." << endl;
	print_list(Find_by_x(Find_by_y(Find_by_z(linked_list.Convert_to_Vector().vector_points, 0), 0), 0));

	cout << endl << blue + "This is result of searching in list based on binary tree." << endl;
	binary_tree.Convert_to_vector(vector_for_tree, binary_tree.root);
	print_list(Find_by_x(Find_by_y(Find_by_z(vector_for_tree.vector_points, 0), 0), 0));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on AVL tree." << endl;
	avl_tree.Convert_to_vector(vector_for_tree, avl_tree.root);
	print_list(Find_by_x(Find_by_y(Find_by_z(vector_for_tree.vector_points, 0), 0), 0));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on 2-3 tree." << endl;
	two_three_tree.Convert_to_vector(vector_for_tree, two_three_tree.root);
	print_list(Find_by_x(Find_by_y(Find_by_z(vector_for_tree.vector_points, 0), 0), 0));

	vector_for_tree.Create_empty();
	Sys_pause();


	cout << blue + "Now I find elements that have Y position between 30 and 50 in every list." << endl;

	cout << endl << "This is result of searching in list based on vector." << endl;
	print_list(Find_by_y_in_range(vector_list.vector_points, 30, 50));

	cout << endl << blue + "This is result of searching in list based on linked list." << endl;
	print_list(Find_by_y_in_range(linked_list.Convert_to_Vector().vector_points, 30, 50));

	cout << endl << blue + "This is result of searching in list based on binary tree." << endl;
	binary_tree.Convert_to_vector(vector_for_tree, binary_tree.root);
	print_list(Find_by_y_in_range(vector_for_tree.vector_points, 30, 50));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on AVL tree." << endl;
	avl_tree.Convert_to_vector(vector_for_tree, avl_tree.root);
	print_list(Find_by_y_in_range(vector_for_tree.vector_points, 30, 50));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on 2-3 tree." << endl;
	two_three_tree.Convert_to_vector(vector_for_tree, two_three_tree.root);
	print_list(Find_by_y_in_range(vector_for_tree.vector_points, 30, 50));
	vector_for_tree.Create_empty();
	Sys_pause();

	cout << blue + "The program also have the same functions for X and Z position." << endl;
	cout << "You can combine them to create searching by X and Y position or another combination." << endl;
	cout << "I show you searching by all positions(X between (30,50), Y between (80,100) and Z between (0,50)." << endl;

	cout << endl << "This is result of searching in list based on vector." << endl;
	print_list(Find_by_x_in_range(Find_by_y_in_range(Find_by_z_in_range(vector_list.vector_points, 0, 50), 80, 100), 30, 50));

	cout << endl << blue + "This is result of searching in list based on linked list." << endl;
	print_list(Find_by_x_in_range(Find_by_y_in_range(Find_by_z_in_range(linked_list.Convert_to_Vector().vector_points, 0, 50), 80, 100), 30, 50));

	cout << endl << blue + "This is result of searching in list based on binary tree." << endl;
	binary_tree.Convert_to_vector(vector_for_tree, binary_tree.root);
	print_list(Find_by_x_in_range(Find_by_y_in_range(Find_by_z_in_range(vector_for_tree.vector_points, 0, 50), 80, 100), 30, 50));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on AVL tree." << endl;
	avl_tree.Convert_to_vector(vector_for_tree, avl_tree.root);
	print_list(Find_by_x_in_range(Find_by_y_in_range(Find_by_z_in_range(vector_for_tree.vector_points, 0, 50), 80, 100), 30, 50));
	vector_for_tree.Create_empty();

	cout << endl << blue + "This is result of searching in list based on 2-3 tree." << endl;
	two_three_tree.Convert_to_vector(vector_for_tree, two_three_tree.root);
	print_list(Find_by_x_in_range(Find_by_y_in_range(Find_by_z_in_range(vector_for_tree.vector_points, 0, 50), 80, 100), 30, 50));
	vector_for_tree.Create_empty();
	Sys_pause();

	cout << blue + "Now I remove point (0,0,0) to each list." << endl;

	point.Set_point(0, 0, 0);
	vector_list.Remove(point);
	linked_list.Remove(point);
	binary_tree.Remove(point);
	avl_tree.Remove(point);
	two_three_tree.Remove(point);

	cout << endl << "This is information in list based on vector." << endl;
	vector_list.Print();
	cout << endl << blue + "This is information in list based on linked list." << endl;
	linked_list.Print();
	cout << endl << blue + "This is information in list based on binary tree." << endl;
	binary_tree.Print();
	cout << endl << blue + "This is information in list based on AVL tree." << endl;
	avl_tree.Print();
	cout << endl << blue + "This is information in list based on 2-3 tree." << endl;
	two_three_tree.Print();
	Sys_pause();

	cout << blue + "Now I remove point (50,50,50) to each list." << endl;

	point.Set_point(50, 50, 50);
	vector_list.Change_centre_position(point);
	linked_list.Change_centre_position(point);
	binary_tree.Change_centre_position(point);
	avl_tree.Change_centre_position(point);
	two_three_tree.Change_centre_position(point);

	cout << endl << "This is information in list based on vector." << endl;
	vector_list.Print();
	cout << endl << blue + "This is information in list based on linked list." << endl;
	linked_list.Print();
	cout << endl << blue + "This is information in list based on binary tree." << endl;
	binary_tree.Print();
	cout << endl << blue + "This is information in list based on AVL tree." << endl;
	avl_tree.Print();
	cout << endl << blue + "This is information in list based on 2-3 tree." << endl;
	two_three_tree.Print();
	Sys_pause();

	cout << blue + "Thank you for using." << endl;
	Sys_pause();
}