#include "structs and functions.h"

void bench()
{
	cout << blue + "Processing. Please. Wait." << endl;
	vector<vector<int>> Time(4, vector<int>(6, 0));
	bool Conected;
	vector<int> tops;
	vector<vector<int>> table;
	time_t start = clock();
	time_t finish = clock();

	int n = 10;
	for (int i = 0; i < 6; i++)
	{
		start = clock();
		Graph_Matrix Matrix(false, n);
		Matrix.Autogenerate(n * (n - 1));
		Conected = Matrix.Check_Connected();
		tops = Matrix.Tops_in_depth(0, 1);
		table = Matrix.Minimal_way_table();
		finish = clock();
		Time[0][i] = finish - start;
		n *= 2;
	}

	n = 10;
	for (int i = 0; i < 6; i++)
	{
		start = clock();
		Graph_Matrix Matrix(true, n);
		Matrix.Autogenerate(n * (n - 1));
		Conected = Matrix.Check_Connected();
		tops = Matrix.Tops_in_depth(0, 1);
		table = Matrix.Minimal_way_table();
		finish = clock();
		Time[1][i] = finish - start;
		n *= 2;
	}

	n = 10;
	for (int i = 0; i < 6; i++)
	{
		start = clock();
		Graph_List List(false, n);
		List.Autogenerate(n * (n - 1));
		Conected = List.Check_Connected();
		tops = List.Tops_in_depth(0, 1);
		table = List.Minimal_way_table();
		finish = clock();
		Time[2][i] = finish - start;
		n *= 2;
	}

	n = 10;
	for (int i = 0; i < 6; i++)
	{
		start = clock();
		Graph_List List(true, n);
		List.Autogenerate(n * (n - 1));
		Conected = List.Check_Connected();
		tops = List.Tops_in_depth(0, 1);
		table = List.Minimal_way_table();
		finish = clock();
		Time[3][i] = finish - start;
		n *= 2;
	}

	cout << blue + "  Number of tops  10  20   40    80    160    320" << endl;
	cout << light_blue + "Matrix(undirected) " << Time[0][0] << "   " << Time[0][1] << "   " << Time[0][2] << "   " << Time[0][3] << "   " << Time[0][4] << "   " << Time[0][5] << endl;
	cout << green + " Matrix(directed)  " << Time[1][0] << "   " << Time[1][1] << "   " << Time[1][2] << "   " << Time[1][3] << "   " << Time[1][4] << "   " << Time[0][5] << endl;
	cout << yellow + " List(undirected)  " << Time[2][0] << "  " << Time[2][1] << "   " << Time[2][2] << "   " << Time[2][3] << "   " << Time[2][4] << "   " << Time[0][5] << endl;
	cout << red + "  List(directed)   " << Time[3][0] << "  " << Time[3][1] << "   " << Time[3][2] << "  " << Time[3][3] << "   " << Time[3][4] << "   " << Time[3][5] << endl;
	Sys_pause();
}