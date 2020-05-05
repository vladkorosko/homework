#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <time.h>
#include <random>

using namespace std;

const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

int enter_number(string mark);
int choose(string types[3]);
int Min(int a, int b, int c);
int find_min(vector<int>& a);
void print_list(vector<int> list);
void print_table(vector<vector<int>> table);
void Sys_pause();

struct Graph 
{
	virtual void Autogenerate(int number_of_edges) = 0;

	virtual void Enter_Edge(int x_pos, int y_pos, int weight) = 0;

	virtual void Enter_Matrix() = 0;

	virtual void Change_Size(int size) = 0;

	virtual bool Check_Connected() = 0;

	virtual vector<int> Tops_in_depth(int number, int type) = 0;

	virtual vector<vector<int>> Minimal_way_table() = 0;

	virtual int Minimal_way(int first_top, int second_top) = 0;

	virtual vector<int> Minimal_ways_from_top(int top) = 0;

	virtual void Topological_sort() = 0;

	virtual vector<vector<int>> Tree(int number, int type) = 0;

	int Weigth_of_tree(vector<vector<int>> tree)
	{
		int weigth = 0;
		for (int i = 0; i < tree.size(); i++)
			weigth += tree[i][2];
		return weigth;
	}

	virtual vector<vector<int>> Minimal_spanning_Tree() = 0;

	virtual void Print() = 0;
};

struct Graph_List;

struct Graph_Matrix : Graph
{
	bool directed;
	vector<vector<int>> Matrix;

	Graph_Matrix(bool type, int size) {
		directed = type;
		vector<vector<int>> a(size, vector<int>(size, 0));
		Matrix = a;
	}

	void Autogenerate(int number_of_edges)override
	{
		if (((!directed && !(number_of_edges % 2) ) || directed) && number_of_edges <= (Matrix.size() * (Matrix.size() - 1)))
		{
			vector<vector<int>> a(Matrix.size(), vector<int>(Matrix.size(), 0));
			Matrix = a;
			while (number_of_edges > 0)
			{
				int x_pos = rand() % Matrix.size();
				int y_pos = rand() % Matrix.size();
				if (!Matrix[x_pos][y_pos] && x_pos != y_pos)
				{
					Matrix[x_pos][y_pos] = rand() % 20;
					number_of_edges--;
					if (!directed)
					{
						Matrix[y_pos][x_pos] = Matrix[x_pos][y_pos];
						number_of_edges--;
					}
				}
			}
			cout << green + "Successfully generated." << endl;
		}
		else
			cout << red + "Number of edges of graph is out of range." << endl;
	}

	void Enter_Edge(int x_pos, int y_pos, int weight)override
	{
		if (x_pos < Matrix.size() && x_pos >= 0 && y_pos < Matrix.size() && y_pos >= 0 && x_pos != y_pos)
		{
			Matrix[x_pos][y_pos] = weight;
			if (!directed)
				Matrix[y_pos][x_pos] = Matrix[x_pos][y_pos];
			cout << green + "Successfully added." << endl;
		}
		else
			cout << red + "Point is out of range." << endl;
	}

	void Enter_Matrix()override
	{
		directed = true;
		cout << light_blue;
		for (int i = 0; i < Matrix.size(); i++)
			for (int j = 0; j < Matrix.size(); j++)
			{
				cin >> Matrix[i][j];
				if (i == j)
					Matrix[i][i] = 0;
			}
		cout << green + "Successfully entered." << endl;
	}

	void Change_Size(int size)override
	{
		vector<vector<int>> New_Matrix(size, vector<int>(size, 0));
		if (size > Matrix.size())
		{
			for (int i = 0; i < Matrix.size(); i++)
				for (int j = 0; j < Matrix.size(); j++)
					New_Matrix[i][j] = Matrix[i][j];
		}
		else
		{
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					New_Matrix[i][j] = Matrix[i][j];
		}
		Matrix = New_Matrix;
	}

	vector<int> Tops_that_used()
	{
		vector<int> tops (Matrix.size(), 0);
		for (int i = 0; i < Matrix.size(); i++)
			for (int j = 0; j < Matrix.size(); j++)
				if (Matrix[i][j])
				{
					tops[i] = 1;
					tops[j] = 1;
				}
		return tops;
	}

	void Connected_tops(int type, vector<int> &tops, vector<int> &way, int index_of_top)
	{
		tops[index_of_top] = 2;
		way.push_back(index_of_top);
		if (type)
		{
			for (int i = 0; i < tops.size(); i++)
			{

				if (Matrix[index_of_top][i])
					if (tops[i] == 1)
						Connected_tops(type, tops, way, i);
			}
		}
		else
		{
			vector<int> a = Matrix[index_of_top];
			int min = find_min(a);
			while (min >= 0)
			{
				if (tops[min] == 1)
					Connected_tops(type, tops, way, min);
				min = find_min(a);
			}
		}
	}

	bool Check_Connected()override
	{
		bool Connected_graph = true;
		vector<int> tops = Tops_that_used();
		vector<vector<int>> table = Matrix;
		if (directed)
		{
			for (int i = 0; i < Matrix.size(); i++)
				for (int j = 0; j < Matrix.size(); j++)
					if (table[i][j])
						table[j][i]= table[i][j];
		}
		int n = 0;
		while (!tops[n])
			n++;
		vector<int> way;
		Connected_tops(1, tops, way, n);
		for (int i = 0; i < tops.size(); i++)
			if (tops[i] == 1)
				Connected_graph = false;
		return Connected_graph;
	}

	vector<int> Tops_in_depth(int number, int type)override
	{
		vector<int> way;
		vector<int> tops = Tops_that_used();
		if (tops[number])
			Connected_tops(type, tops, way, number);
		return way;
	}

	vector<vector<int>> Minimal_way_table()override
	{
		vector<vector<int>> table_distance = Matrix;
		for (int i = 0; i < table_distance.size(); i++)
			for (int j = 0; j < table_distance.size(); j++)
				if (table_distance[i][j] == 0 && i != j)
					table_distance[i][j]--;
		for (int k = 0; k < table_distance.size(); k++)
			for (int i = 0; i < table_distance.size(); i++)
				for (int j = 0; j < table_distance.size(); j++)
					table_distance[i][j] = Min(table_distance[i][j], table_distance[i][k], table_distance[k][j]);
		return table_distance;
	}

	int Minimal_way(int start_top, int finish_top)override
	{
		return Minimal_way_table()[start_top][finish_top];
	}

	vector<int> Minimal_ways_from_top(int top)override
	{
		return Minimal_way_table()[top];
	}

	void Topological_sort()override
	{
		if (Check_Connected())
		{
			vector<int> way;
			way = Tops_in_depth(0, 1);
			vector<vector<int>> new_matrix(way.size(),vector<int>(way.size(),0));
			for (int i = 0; i < way.size(); i++)
				for (int j = 0; j < way.size(); j++)
					new_matrix[i][j] = Matrix[way[i]][way[j]];
			Matrix = new_matrix;
		}
	}

	void Add_edge(int type, vector<int>& tops, vector<vector<int>>& tree, int index_of_top)
	{
		tops[index_of_top] = 2;
		if (type)
		{
			for (int i = 0; i < tops.size(); i++)
			{

				if (Matrix[index_of_top][i])
					if (tops[i] == 1)
					{
						vector<int> edge;
						edge.push_back(index_of_top);
						edge.push_back(i);
						edge.push_back(Matrix[index_of_top][i]);
						tree.push_back(edge);
						Add_edge(type, tops, tree, i);
					}
			}
		}
		else
		{
			vector<int> a = Matrix[index_of_top];
			int min = find_min(a);
			while (min >= 0)
			{
				if (tops[min] == 1)
				{
					vector<int> edge;
					edge.push_back(index_of_top);
					edge.push_back(min);
					edge.push_back(Matrix[index_of_top][min]);
					tree.push_back(edge);
					Add_edge(type, tops, tree, min);
				}
				min = find_min(a);
			}
		}
	}

	vector<vector<int>> Tree(int number, int type)override
	{
		vector<vector<int>> tree;
		if (!directed && Check_Connected())
		{
			vector<int> tops = Tops_that_used();
			Add_edge(type, tops, tree, number);
		}
		return tree;
	}

	vector<vector<int>> Minimal_spanning_Tree()override
	{
		vector<vector<int>> min_tree = Tree(0, 0);
		for (int i = 1; i < Matrix.size(); i++)
		{
			vector<vector<int>> current_tree = Tree(i, 0);
			if (Weigth_of_tree(current_tree) < Weigth_of_tree(min_tree))
				min_tree = current_tree;
		}
		return min_tree;
	}

	void Print()override
	{
		for (int i = 0; i < Matrix.size(); i++)
		{
			for (int j = 0; j < Matrix.size(); j++)
			{
				cout << green << Matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

Graph_List Make_List(Graph_Matrix Matrix);
Graph_Matrix Make_Matrix(Graph_List List);

struct Graph_List : Graph
{
	bool directed;
	int number_of_tops;
	vector<vector<int>> List;

	Graph_List(bool type, int size) {
		directed = type;
		number_of_tops = size;
		vector<vector<int>> a;
		List = a;
	}

	void Autogenerate(int number_of_edges)override
	{
		if (((!directed && !(number_of_edges % 2)) || directed) && number_of_edges <= (number_of_tops * (number_of_tops - 1)))
		{
			Graph_Matrix Matrix = Graph_Matrix(directed, number_of_tops);
			vector<vector<int>> a;
			List = a;
			while (number_of_edges > 0)
			{
				int x_pos = rand() % number_of_tops;
				int y_pos = rand() % number_of_tops;
				if (!Matrix.Matrix[x_pos][y_pos] && x_pos != y_pos)
				{
					Matrix.Matrix[x_pos][y_pos] = rand() % 20;
					vector<int> edge(3, 0);
					edge[0] = x_pos;
					edge[1] = y_pos;
					edge[2] = Matrix.Matrix[x_pos][y_pos];
					List.push_back(edge);
					number_of_edges--;
					if (!directed)
					{
						Matrix.Matrix[y_pos][x_pos] = Matrix.Matrix[x_pos][y_pos];
						edge[1] = x_pos;
						edge[0] = y_pos;
						List.push_back(edge);
						number_of_edges--;
					}
				}
			}
			
			cout << green + "Successfully generated." << endl;
		}
		else
			cout << red + "Number of edges of graph is out of range." << endl;
	}

	void Enter_Edge(int x_pos, int y_pos, int weight)override
	{
		if (x_pos < number_of_tops && x_pos >= 0 && y_pos < number_of_tops && y_pos >= 0 && x_pos != y_pos)
		{
			Graph_List New_List = Graph_List(directed, number_of_tops);
			New_List.List = List;
			Graph_Matrix Matrix = Make_Matrix(New_List);
			Matrix.Matrix[x_pos][y_pos] = weight;
			if (!directed)
				Matrix.Matrix[y_pos][x_pos] = Matrix.Matrix[x_pos][y_pos];
			New_List = Make_List(Matrix);
			List = New_List.List;
			cout << green + "Successfully added." << endl;
		}
		else
			cout << red + "Point is out of range." << endl;
	}

	void Enter_Matrix()override
	{
		directed = true;
		Graph_Matrix Matrix = Graph_Matrix(directed, number_of_tops);
		cout << light_blue;
		for (int i = 0; i < Matrix.Matrix.size(); i++)
			for (int j = 0; j < Matrix.Matrix.size(); j++)
			{
				cin >> Matrix.Matrix[i][j];
				if (i == j)
					Matrix.Matrix[i][i] = 0;
			}
		Graph_List New_List = Make_List(Matrix);
		List = New_List.List;
		cout << green + "Successfully entered." << endl;
	}

	void Change_Size(int size)override
	{
		Graph_List New_List = Graph_List(directed, number_of_tops);
		New_List.List = List;
		Graph_Matrix Matrix = Make_Matrix(New_List);
		vector<vector<int>> New_Matrix(size, vector<int>(size, 0));
		if (size > number_of_tops)
		{
			for (int i = 0; i < number_of_tops; i++)
				for (int j = 0; j < number_of_tops; j++)
					New_Matrix[i][j] = Matrix.Matrix[i][j];
		}
		else
		{
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					New_Matrix[i][j] = Matrix.Matrix[i][j];
		}
		Matrix.Matrix = New_Matrix;
		New_List = Make_List(Matrix);
		List = New_List.List;
		number_of_tops = size;
	}

	bool Check_Connected()override
	{
		Graph_List New_List = Graph_List(directed, number_of_tops);
		New_List.List = List;
		Graph_Matrix Matrix = Make_Matrix(New_List);
		return Matrix.Check_Connected();
	}

	vector<int> Tops_in_depth(int number, int type)override
	{
		Graph_List New_List = Graph_List(directed, number_of_tops);
		New_List.List = List;
		Graph_Matrix Matrix = Make_Matrix(New_List);
		return Matrix.Tops_in_depth(number, type);
	}

	vector<vector<int>> Minimal_way_table()override
	{
		Graph_List New_List = Graph_List(directed, number_of_tops);
		New_List.List = List;
		Graph_Matrix Matrix = Make_Matrix(New_List);
		return Matrix.Minimal_way_table();
	}

	int Minimal_way(int start_top, int finish_top)override
	{
		return Minimal_way_table()[start_top][finish_top];
	}

	vector<int> Minimal_ways_from_top(int top)override
	{
		return Minimal_way_table()[top];
	}

	void Topological_sort()override
	{
		Graph_List New_List = Graph_List(directed, number_of_tops);
		New_List.List = List;
		Graph_Matrix Matrix = Make_Matrix(New_List);
		Matrix.Topological_sort();
		New_List = Make_List(Matrix);
		List = New_List.List;
	}

	vector<vector<int>> Tree(int number, int type)override
	{
		Graph_List New_List = Graph_List(directed, number_of_tops);
		New_List.List = List;
		Graph_Matrix Matrix = Make_Matrix(New_List);
		return Matrix.Tree(number,type);
	}

	vector<vector<int>> Minimal_spanning_Tree()override
	{
		Graph_List New_List = Graph_List(directed, number_of_tops);
		New_List.List = List;
		Graph_Matrix Matrix = Make_Matrix(New_List);
		return Matrix.Minimal_spanning_Tree();
	}

	void Print()override
	{
		for (int i = 0; i < List.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << green << List[i][j] << " ";
			}
			cout << endl;
		}
	}
};

void interactive_mode();
void demo();
void bench();

void menu();