#include "Structs.h"

void bench()
{
	Vector_list vector_list;
	Linked_list linked_list;
	Binary_tree_list binary_tree;
	AVL_tree avl_tree;
	Two_three_tree two_three_tree;

	time_t start = clock();
	time_t finish = clock();
	time_t wasted_time = clock();
	vector<vector<int>> Time(5, vector<int>(5, 0));
	PointXYZ new_centre;
	new_centre.Set_point(50, 50, 50);

	cout << blue + "Processing.Please, Wait." << endl;
	int n = 200;
	for (int i = 0; i < 5; i++)
	{
		start = clock();
		vector_list.Create_empty();
		vector_list.Autogenerate(n);
		Find_by_x(vector_list.vector_points, 0);
		Find_by_x_in_range(vector_list.vector_points, 0, 50);
		vector_list.Change_centre_position(new_centre);
		finish = clock();
		wasted_time = finish - start;
		Time[0][i] = wasted_time;
		n *= 2;
	}

	n = 200;
	for (int i = 0; i < 5; i++)
	{
		start = clock();
		linked_list.Create_empty();
		linked_list.Autogenerate(n);
		Find_by_x(linked_list.Convert_to_Vector().vector_points, 0);
		Find_by_x_in_range(linked_list.Convert_to_Vector().vector_points, 0, 50);
		linked_list.Change_centre_position(new_centre);
		finish = clock();
		wasted_time = finish - start;
		Time[1][i] = wasted_time;
		n *= 2;
	}

	n = 200;
	for (int i = 0; i < 5; i++)
	{
		start = clock();
		binary_tree.Create_empty();
		binary_tree.Autogenerate(n);
		binary_tree.Convert_to_vector(vector_list, binary_tree.root);
		Find_by_x(vector_list.vector_points, 0);
		Find_by_x_in_range(vector_list.vector_points, 0, 50);
		binary_tree.Change_centre_position(new_centre);
		finish = clock();
		wasted_time = finish - start;
		Time[2][i] = wasted_time;
		n *= 2;
	}

	n = 200;
	for (int i = 0; i < 5; i++)
	{
		start = clock();
		avl_tree.Create_empty();
		avl_tree.Autogenerate(n);
		avl_tree.Convert_to_vector(vector_list, avl_tree.root);
		Find_by_x(vector_list.vector_points, 0);
		Find_by_x_in_range(vector_list.vector_points, 0, 50);
		avl_tree.Change_centre_position(new_centre);
		finish = clock();
		wasted_time = finish - start;
		Time[3][i] = wasted_time;
		n *= 2;
	}

	n = 200;
	for (int i = 0; i < 5; i++)
	{
		start = clock();
		two_three_tree.Create_empty();
		two_three_tree.Autogenerate(n);
		two_three_tree.Convert_to_vector(vector_list, two_three_tree.root);
		Find_by_x(vector_list.vector_points, 0);
		Find_by_x_in_range(vector_list.vector_points, 0, 50);
		two_three_tree.Change_centre_position(new_centre);
		finish = clock();
		wasted_time = finish - start;
		Time[4][i] = wasted_time;
		n *= 2;
	}

	cout << "Number of elements  200  400  800  1600  3200" << endl;
	cout << red + "    Vector list      " << Time[0][0] << "    " << Time[0][1] << "    " << Time[0][2] << "    " << Time[0][3] << "     " << Time[0][4] << endl;
	cout << yellow + "    Linked list      " << Time[1][0] << "    " << Time[1][1] << "    " << Time[1][2] << "    " << Time[1][3] << "     " << Time[1][4] << endl;
	cout << green + "    Binary tree     " << Time[2][0] << "    " << Time[2][1] << "   " << Time[2][2] << "  " << Time[2][3] << "  " << Time[2][4] << endl;
	cout << light_blue + "     AVL tree       " << Time[3][0] << "   " << Time[3][1] << "   " << Time[3][2] << "   " << Time[3][3] << "   " << Time[3][4] << endl;
	cout << blue + "     2-3 tree       " << Time[4][0] << "   " << Time[4][1] << "   " << Time[4][2] << "    " << Time[4][3] << "    " << Time[4][4] << endl;
	Sys_pause();
}