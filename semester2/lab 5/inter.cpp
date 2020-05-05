#include "structs and functions.h"

void interactive_mode()
{
	string types[3] = { "Undirected;", "Directed;", "Graph" };
	int type = choose(types);
	int size = enter_number("size");

	Graph_Matrix* Matrix = new Graph_Matrix(type, size);
	Graph_List* List = new Graph_List(type, size);
	Graph* graph;

	types[0] = "List;";
	types[1] = "Matrix;";
	int type_graph = choose(types);
	switch (type_graph)
	{
	case 0:
		graph = List;
		break;
	default:
		graph = Matrix;
		break;
	}

	string functions[17] =
	{
		"Autogenerator matrix;",
		"Add edge;",
		"Enter matrix;",
		"Change size;",
		"Convert graph;",
		"Print matrix;",
		"Check conected;",
		"Conected tops (in depth);",
		"Minimal distance between tops;",
		"Distance to all tops from selected;",
		"Table of minimal ways;",
		"Topological sorting;",
		"Tree;",
		"Weigth;",
		"Minimal tree;",
		"Weigth of Minimal tree;",
		"Back."
	};

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Hello user.\n    There are the functions you can do." << endl;
		for (int i = 0; i < 17; i++)
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
					else position = 17;
				}

				if ((int)key == 80)
				{
					if (position < 17)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			system("cls");
			Graph_Matrix Converted_Matrix = Graph_Matrix(List->directed, size);
			Graph_List Converted_List = Graph_List(Matrix->directed, size);
			int index_s;
			int index_f;
			int weight;
			switch (position)
			{
			case 0:
				graph->Autogenerate(enter_number("number of edges of graph"));
				Sys_pause();
				break;
			case 1:
				index_s = enter_number("start point");
				index_f = enter_number("finish point");
				weight = enter_number("weight");
				graph->Enter_Edge(index_s, index_f, weight);
				Sys_pause();
				break;
			case 2:
				graph->Enter_Matrix();
				Sys_pause();
				break;
			case 3:
				size = enter_number("new size");
				graph->Change_Size(size);
				break;
			case 4:
				switch (type_graph)
				{
				case 0:
					Converted_Matrix = Make_Matrix(*List);
					*Matrix = Converted_Matrix;
					graph = Matrix;
					type_graph++;
					break;
				default:
					Converted_List = Make_List(*Matrix);
					*List = Converted_List;
					graph = List;
					type_graph--;
					break;
				}
				break;
			case 5:
				graph->Print();
				Sys_pause();
				break;
			case 6:
				if (graph->Check_Connected())
					cout << green + "Graph is conected." << endl;
				else cout << green + "Graph isn't conected." << endl;
				Sys_pause();
				break;
			case 7:
				index_s = enter_number("index of top");
				types[1] = "In order;";
				types[0] = "By weight;";
				types[2] = "output";
				if (index_s < size)
				{
					vector<int> way = graph->Tops_in_depth(index_s, choose(types));
					for (int i = 0; i < way.size(); i++)
						cout << green << way[i] << " ";
					cout << endl;
				}
				else cout << red + "Index of top is out the range." << endl;
				Sys_pause();
				break;
			case 8:
				index_s = enter_number("start point");
				index_f = enter_number("finish point");
				if (index_f < size && index_s < size)
					cout << green + "Distance is " << (graph->Minimal_way(index_s, index_f)) << endl;
				else cout << red + "Index of top is out of range." << endl;
				Sys_pause();
				break;
			case 9:
				index_s = enter_number("start point");
				if (index_s < size)
					for (int i = 0; i < size; i++)
						cout << green << (graph->Minimal_ways_from_top(index_s)[i]) << " ";
				else cout << red + "Index of top is out of range.";
				cout << endl;
				Sys_pause();
				break;
			case 10:
				print_table(graph->Minimal_way_table());
				Sys_pause();
				break;
			case 11:
				graph->Topological_sort();
				cout << green + "Graph successfully sorted." << endl;
				Sys_pause();
				break;
			case 12:
				index_s = enter_number("start point");
				types[1] = "In order;";
				types[0] = "By weight;";
				types[2] = "output";
				print_table(graph->Tree(index_s,choose(types)));
				Sys_pause();
				break;
			case 13:
				index_s = enter_number("start point");
				types[1] = "In order;";
				types[0] = "By weight;";
				types[2] = "output";
				cout << green << graph->Weigth_of_tree(graph->Tree(index_s, choose(types))) << endl;
				Sys_pause();
				break;
			case 14:
				print_table(graph->Minimal_spanning_Tree());
				Sys_pause();
				break;
			case 15:
				cout << green << graph->Weigth_of_tree(graph->Minimal_spanning_Tree()) << endl;
				Sys_pause();
				break;
			case 16:
				end = true;
				break;
			}
		}
	}
}