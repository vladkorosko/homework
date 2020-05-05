#include "structs and functions.h"

void demo()
{
	cout << blue + "Hello user. Now i show all functions i can use." << endl;

	cout <<  "Now I create Undirected Graph based on Matrix and List with 6 tops and add edge(First top, Second top, Weigth) (0,1,5)." << endl;
	Graph_Matrix Matrix(false, 6);
	Graph_List List(false, 6);
	Graph_Matrix Matrix_converted(false, 6);
	Graph_List List_converted(false, 6);
	Matrix.Enter_Edge(0, 1, 5);
	List.Enter_Edge(0, 1, 5);

	
	Sys_pause();
	cout << blue + "This is information in Matrix" << endl;
	Matrix.Print();
	cout << endl << blue + "This is information in List" << endl;
	List.Print();
	Sys_pause();

	cout << blue + "Now i generate 20 different edges in each Graph." << endl;
	Matrix.Autogenerate(20);
	List.Autogenerate(20);

	Sys_pause();
	cout << blue + "This is information in Matrix" << endl;
	Matrix.Print();
	cout << endl << blue + "This is information in List" << endl;
	List.Print();
	Sys_pause();

	cout << blue + "Now i converte Matrix to List and List to Matrix." << endl;
	List_converted = Make_List(Matrix);
	Matrix_converted = Make_Matrix(List);

	Sys_pause();
	cout << blue + "This is information in Matrix." << endl;
	Matrix.Print();
	cout << endl << blue + "This is information in matrix converted to list." << endl;
	List_converted.Print();

	Sys_pause();
	cout << blue + "This is information in List" << endl;
	List.Print();
	cout << endl << blue + "This is information in List converted to Matrix." << endl;
	Matrix_converted.Print();
	Sys_pause();

	cout << blue + "Now i chech that graph is connected." << endl;

	Sys_pause();
	cout << blue + "This is information about Matrix." << endl;
	cout << green << Matrix.Check_Connected() << endl;
	cout << endl << blue + "This is information about List." << endl;
	cout << green << List.Check_Connected() << endl;
	Sys_pause();
	
	cout << blue + "Now i change graph(size, number of edges) to (4, 2) (two edges are not connected) and chech that graph is connected." << endl;
	Matrix = Graph_Matrix(0, 4);
	Matrix.Enter_Edge(0, 1, 5);
	Matrix.Enter_Edge(2, 3, 10);
	List = Make_List(Matrix);

	Sys_pause();
	cout << blue + "This is information about Matrix." << endl;

	cout << green << Matrix.Check_Connected() << endl;
	Matrix.Print();
	cout << endl << blue + "This is information about List." << endl;
	cout << green << List.Check_Connected() << endl;
	List.Print();
	Sys_pause();

	cout << blue + "Now i generate 12 different edges in Graph and do traverse in depth in order from 0 top." << endl;
	Matrix.Autogenerate(12);
	List = Make_List(Matrix);

	Sys_pause();
	cout << blue + "This is information in Matrix" << endl;
	Matrix.Print();
	cout << endl;
	print_list(Matrix.Tops_in_depth(0, 1));
	cout << endl << blue + "This is information in List" << endl;
	List.Print();
	cout << endl;
	print_list(List.Tops_in_depth(0, 1));
	Sys_pause();

	cout << blue + "Now i do traverse in depth by weigth." << endl;

	Sys_pause();
	cout << blue + "This is information in Matrix" << endl;
	Matrix.Print();
	cout << endl;
	print_list(Matrix.Tops_in_depth(0, 0));
	cout << endl << blue + "This is information in List" << endl;
	List.Print();
	cout << endl;
	print_list(List.Tops_in_depth(0, 0));
	Sys_pause();

	cout << blue + "Now i show you table of minimal ways to different tops." << endl;

	Sys_pause();
	cout << blue + "This is information about Matrix(same for List)" << endl;
	Matrix.Print();
	cout << endl;
	print_table(Matrix.Minimal_way_table());
	Sys_pause();

	cout << blue + "Now i build spanning tree of graph for 0 top.." << endl;

	Sys_pause();
	cout << blue + "This is information about Matrix(same for List)" << endl;
	Matrix.Print();
	cout << endl;
	cout << blue + "This is spanning tree(in depth in order)" << endl;
	print_table(Matrix.Tree(0, 1));
	cout << blue + "His weigth "<< green << Matrix.Weigth_of_tree(Matrix.Tree(0, 1)) << endl;
	cout << endl;
	cout << blue + "This is spanning tree(in depth by weigth)" << endl;
	print_table(Matrix.Tree(0, 0));
	cout << blue + "His weigth " << green << Matrix.Weigth_of_tree(Matrix.Tree(0, 0)) << endl;

	cout << blue + "Now i build minimal spanning tree of graph." << endl;

	Sys_pause();
	cout << blue + "This is information about Matrix(same for List)" << endl;
	Matrix.Print();
	cout << endl;
	cout << blue + "This is minimal spanning tree." << endl;
	print_table(Matrix.Tree(0, 1));
	cout << blue + "His weigth " << green << Matrix.Weigth_of_tree(Matrix.Minimal_spanning_Tree()) << endl;
	Sys_pause();

	cout << blue + "Now I create Directed Graph based on Matrix and List with 6 tops and add edge(First top, Second top, Weigth) (0,1,5)." << endl;
	Matrix = Graph_Matrix(true, 6);
	List = Graph_List(true, 6);
	Matrix_converted = Matrix;
	List_converted = List;
	Matrix.Enter_Edge(0, 1, 5);
	List.Enter_Edge(0, 1, 5);


	Sys_pause();
	cout << blue + "This is information in Matrix" << endl;
	Matrix.Print();
	cout << endl << blue + "This is information in List" << endl;
	List.Print();
	Sys_pause();

	cout << blue + "Now i generate 20 different edges in each Graph." << endl;
	Matrix.Autogenerate(20);
	List.Autogenerate(20);

	Sys_pause();
	cout << blue + "This is information in Matrix" << endl;
	Matrix.Print();
	cout << endl << blue + "This is information in List" << endl;
	List.Print();
	Sys_pause();

	cout << blue + "Now i converte Matrix to List and List to Matrix." << endl;
	List_converted = Make_List(Matrix);
	Matrix_converted = Make_Matrix(List);

	Sys_pause();
	cout << blue + "This is information in Matrix." << endl;
	Matrix.Print();
	cout << endl << blue + "This is information in matrix converted to list." << endl;
	List_converted.Print();

	Sys_pause();
	cout << blue + "This is information in List" << endl;
	List.Print();
	cout << endl << blue + "This is information in List converted to Matrix." << endl;
	Matrix_converted.Print();
	Sys_pause();

	cout << blue + "Now i chech that graph is connected." << endl;

	Sys_pause();
	cout << blue + "This is information about Matrix." << endl;
	cout << green << Matrix.Check_Connected() << endl;
	cout << endl << blue + "This is information about List." << endl;
	cout << green << List.Check_Connected() << endl;
	Sys_pause();

	cout << blue + "Now i change graph(size, number of edges) to (4, 2) (two edges are not connected) and chech that graph is connected." << endl;
	Matrix = Graph_Matrix(0, 4);
	Matrix.Enter_Edge(0, 1, 5);
	Matrix.Enter_Edge(2, 3, 10);
	List = Make_List(Matrix);

	Sys_pause();
	cout << blue + "This is information about Matrix." << endl;

	cout << green << Matrix.Check_Connected() << endl;
	Matrix.Print();
	cout << endl << blue + "This is information about List." << endl;
	cout << green << List.Check_Connected() << endl;
	List.Print();
	Sys_pause();

	cout << blue + "Now i create graph with edges(Start point, Finish point, Weigth) (0,3,7), (3,1,8), (3,2,4), (2,1,2)." << endl;
	Matrix = Graph_Matrix(1, 4);
	Matrix.Enter_Edge(0, 3, 7);
	Matrix.Enter_Edge(3, 1, 8);
	Matrix.Enter_Edge(2, 1, 2);
	Matrix.Enter_Edge(3, 2, 4);
	List = Make_List(Matrix);

	Sys_pause();
	cout << blue + "This is information about Matrix." << endl;
	Matrix.Print();
	Matrix.Topological_sort();
	cout << endl << blue + "This is information in sorted Matrix." << endl;
	Matrix.Print();
	Sys_pause();



	cout << blue + "Thank you for using. Goodbye." << endl;
	Sys_pause();
}