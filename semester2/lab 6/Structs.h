#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <random>
#include <conio.h>

using namespace std;

const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

struct PointXYZ
{
	int x_pos;
	int y_pos;
	int z_pos;

	void Set_point(int x, int y, int z)
	{
		x_pos = x;
		y_pos = y;
		z_pos = z;
	}

	void Print()
	{
		cout << green + "(" << x_pos << ", " << y_pos << ", " << z_pos << ") ";
	}

	bool Bigger_than(PointXYZ another_element)
	{
		bool res = false;
		if (x_pos > another_element.x_pos)
			res = true;
		else
		{
			if (x_pos == another_element.x_pos)
			{
				if(y_pos > another_element.y_pos)
					res = true;
				else
				{
					if (y_pos == another_element.y_pos && z_pos > another_element.z_pos)
						res = true;
				}
			}
		}
		return res;
	}

	bool Less_than(PointXYZ another_element)
	{
		bool res = false;
		if (x_pos < another_element.x_pos)
			res = true;
		else
		{
			if (x_pos == another_element.x_pos)
			{
				if (y_pos < another_element.y_pos)
					res = true;
				else
				{
					if (y_pos == another_element.y_pos && z_pos < another_element.z_pos)
						res = true;
				}
			}
		}
		return res;
	}
};

struct List
{
	virtual void Create_empty() = 0;

	virtual void Append(PointXYZ element) = 0;

	virtual void Remove(PointXYZ point) = 0;

	virtual int Length() = 0;

	virtual vector<PointXYZ> Find_element() = 0;

	virtual vector<PointXYZ> Find_in_range() = 0;

	virtual void Print() = 0;

	void Autogenerate(int number_of_elements)
	{
		while (number_of_elements)
		{
			PointXYZ new_point;
			new_point.Set_point(rand() % 100, rand() % 100, rand() % 100);
			Append(new_point);
			number_of_elements--;
		}
	}

	virtual void Change_centre_position(PointXYZ new_centre) = 0;
};

void error_no_elements();
int enter_number(string mark);
void Quick_sort(vector<PointXYZ> &vector_points, int first, int last);
vector<PointXYZ> Find_by_x(vector<PointXYZ> vector_points, int x_position);
vector<PointXYZ> Find_by_y(vector<PointXYZ> vector_points, int y_position);
vector<PointXYZ> Find_by_z(vector<PointXYZ> vector_points, int z_position);
vector<PointXYZ> Find_by_x_in_range(vector<PointXYZ> vector_points, int x_first, int x_second);
vector<PointXYZ> Find_by_y_in_range(vector<PointXYZ> vector_points, int y_first, int y_second);
vector<PointXYZ> Find_by_z_in_range(vector<PointXYZ> vector_points, int z_first, int z_second);

struct Vector_list : List {
public:
	vector<PointXYZ> vector_points;

	void Create_empty()override
	{
		vector<PointXYZ> empty_vector;
		vector_points = empty_vector;
	}

	void Append(PointXYZ element)override
	{
		vector_points.push_back(element);
	}

	void Remove(PointXYZ point)override
	{
		for (int i = 0; i < vector_points.size(); i++)
			if (!point.Bigger_than(vector_points[i]) && !point.Less_than(vector_points[i]))
			{
				vector_points.erase(vector_points.begin() + i);
				i = vector_points.size();
			}
	}

	int Length()override
	{
		return vector_points.size();
	}

	vector<PointXYZ> Find_element()override
	{
		string functions[7] =
		{
			"By X position;",
			"By Y position;",
			"By Z position;",
			"By X and Y position;",
			"By X and Z position;",
			"By Y and Z position;",
			"By X, Y and Z position;"
		};

		int position = 0;
		bool end = false;

		while (!end)
		{
			system("cls");
			cout << blue + "    Choose the criterias of finding." << endl;
			for (int i = 0; i < 7; i++)
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
						else position = 6;
					}

					if ((int)key == 80)
					{
						if (position < 6)
							position++;
						else position = 0;
					}
				}
			}
			else
			{
				system("cls");
				switch (position)
				{
				case 0:
					return Find_by_x(vector_points, enter_number("X position"));
					break;
				case 1:
					return Find_by_y(vector_points, enter_number("Y position"));
					break;
				case 2:
					return Find_by_z(vector_points, enter_number("Z position"));
					break;
				case 3:
					return Find_by_x(Find_by_y(vector_points, enter_number("X position")), enter_number("Y position"));
					break;
				case 4:
					return Find_by_x(Find_by_z(vector_points, enter_number("X position")), enter_number("Z position"));
					break;
				case 5:
					return Find_by_y(Find_by_z(vector_points, enter_number("Y position")), enter_number("Z position"));
					break;
				default:
					return Find_by_x(Find_by_y(Find_by_z(vector_points, enter_number("Z position")), enter_number("Y position")), enter_number("X position"));
					break;
				}
			}
		}
	}

	vector<PointXYZ> Find_in_range()override
	{
		string functions[7] =
		{
			"By X position;",
			"By Y position;",
			"By Z position;",
			"By X and Y position;",
			"By X and Z position;",
			"By Y and Z position;",
			"By X, Y and Z position;"
		};

		int position = 0;
		bool end = false;

		while (!end)
		{
			system("cls");
			cout << blue + "    Choose the criterias of finding." << endl;
			for (int i = 0; i < 7; i++)
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
						else position = 6;
					}

					if ((int)key == 80)
					{
						if (position < 6)
							position++;
						else position = 0;
					}
				}
			}
			else
			{
				system("cls");
				switch (position)
				{
				case 0:
					return Find_by_x_in_range(vector_points, enter_number("first X position"), enter_number("second X position"));
					break;
				case 1:
					return Find_by_y_in_range(vector_points, enter_number("first Y position"), enter_number("second Y position"));
					break;
				case 2:
					return Find_by_z_in_range(vector_points, enter_number("first Z position"), enter_number("second Z position"));
					break;
				case 3:
					return Find_by_x_in_range(Find_by_y_in_range(vector_points, enter_number("first Y position"), enter_number("second Y position")), 
						enter_number("first X position"), enter_number("second X position"));
					break;
				case 4:
					return Find_by_x_in_range(Find_by_z_in_range(vector_points, enter_number("first Z position"), enter_number("second Z position")), 
						enter_number("first X position"), enter_number("second X position"));
					break;
				case 5:
					return Find_by_y_in_range(Find_by_z_in_range(vector_points, enter_number("first Z position"), enter_number("second Z position")), 
						enter_number("first Y position"), enter_number("second Y position"));
					break;
				default:
					return Find_by_x_in_range(Find_by_y_in_range(Find_by_z_in_range(vector_points, enter_number("first Z position"), enter_number("second Z position")), 
						enter_number("first Y position"), enter_number("second Y position")),
						enter_number("first X position"), enter_number("second X position"));
					break;
				}
			}
		}
	}

	void Print()override
	{
		if (vector_points.size())
		{
			Quick_sort(vector_points, 0, vector_points.size() - 1);
			for (int i = 0; i < vector_points.size(); i++)
				vector_points[i].Print();
			cout << endl;
		}
		else error_no_elements();
	}

	void Change_centre_position(PointXYZ new_centre)override
	{
		for (int i = 0; i < vector_points.size(); i++)
		{
			vector_points[i].x_pos -= new_centre.x_pos;
			vector_points[i].y_pos -= new_centre.y_pos;
			vector_points[i].z_pos -= new_centre.z_pos;
		}
	}
};

struct ListNode
{
	PointXYZ value;
	ListNode* prev;
	ListNode* next;
};

struct Linked_list : List
{
public:
	ListNode* head;
	ListNode* tail;
	int size = 0;

	void Create_empty()override
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	Linked_list() {
		Create_empty();
	}

	void Append(PointXYZ element)override
	{
		ListNode* node = new ListNode;
		node->value = element;
		node->prev = tail;
		node->next = nullptr;
		if (tail)
		{
			tail->next = node;
			tail = node;
		}
		else
		{
			head = node;
			tail = node;
		}
		size++;
	}

	void Convert_from_vector_to_list(vector<PointXYZ> vector_points)
	{
		Create_empty();
		for (int i = 0; i < vector_points.size(); i++)
		{
			Append(vector_points[i]);
		}
	}

	Vector_list Convert_to_Vector()
	{
		Vector_list vector_points;
		ListNode* current_node = head;
		for (current_node; current_node; current_node = current_node->next)
			vector_points.vector_points.push_back(current_node->value);
		return vector_points;
	}

	void Remove(PointXYZ point) override 
	{
		Vector_list vector_points = Convert_to_Vector();
		vector_points.Remove(point);
		size = vector_points.vector_points.size();
		Convert_from_vector_to_list(vector_points.vector_points);
	}

	int Length()override
	{
		return size;
	}

	vector<PointXYZ> Find_element()override
	{
		Vector_list vector_points = Convert_to_Vector();
		return vector_points.Find_element();
	}

	vector<PointXYZ> Find_in_range()override
	{
		Vector_list vector_points = Convert_to_Vector();
		return vector_points.Find_in_range();
	}

	void Print()override
	{
		Vector_list vector_points = Convert_to_Vector();
		vector_points.Print();
	}

	void Change_centre_position(PointXYZ new_centre)override
	{
		Vector_list vector_points = Convert_to_Vector();
		vector_points.Change_centre_position(new_centre);
		Convert_from_vector_to_list(vector_points.vector_points);
	}
};

struct Binary_Node
{
	PointXYZ value;
	Binary_Node* prev;
	Binary_Node* left;
	Binary_Node* right;

	Binary_Node(PointXYZ point)
	{
		left = nullptr;
		right = nullptr;
		value = point;
	}
};

struct Binary_tree_list :List
{
	Binary_Node* root;

	void Create_empty()override
	{
		root = nullptr;
	}

	Binary_tree_list() {
		Create_empty();
	}

	void add(PointXYZ point, Binary_Node* current_node)
	{
		Binary_Node* new_node = new Binary_Node(point);
		
		if (!root)
		{
			new_node->prev = nullptr;
			root = new_node;
		}
		else
		{
			if (current_node->value.Bigger_than(point))
			{
				if (current_node->left)
					add(point, current_node->left);
				else
				{
					new_node->prev = current_node;
					current_node->left = new_node;
				}
			}
			else {
				if (current_node->right)
					add(point, current_node->right);
				else
				{
					new_node->prev = current_node;
					current_node->right = new_node;
				}
			}
		}
	}

	void Append(PointXYZ point)override
	{
		add(point, root);
	}

	void Convert_from_vector_to_tree(vector<PointXYZ> vector_points)
	{
		Create_empty();
		for (int i = 0; i < vector_points.size(); i++)
		{
			Append(vector_points[i]);
		}
	}

	void Convert_to_vector(Vector_list &vector_points, Binary_Node* node)
	{
		if (node)
		{
			if (node->left)
				Convert_to_vector(vector_points, node->left);
			vector_points.Append(node->value);
			if (node->right)
				Convert_to_vector(vector_points, node->right);
		}
		else
			vector_points.Create_empty();
	}

	void Remove(PointXYZ point) override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Remove(point);
		Convert_from_vector_to_tree(vector_points.vector_points);
	}

	int Length() override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.vector_points.size();
	}

	vector<PointXYZ> Find_element()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.Find_element();
	}

	vector<PointXYZ> Find_in_range()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.Find_in_range();
	}

	void Print()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Print();
	}

	void Change_centre_position(PointXYZ new_centre)override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Change_centre_position(new_centre);
		Convert_from_vector_to_tree(vector_points.vector_points);
	}
};

struct AVL_tree_node
{
	PointXYZ value;
	int height;
	AVL_tree_node* left;
	AVL_tree_node* right;

	AVL_tree_node(PointXYZ point)
	{ 
		value = point; 
		left = right = 0; 
		height = 1;
	}

	int Balance()
	{
		int left_height = 0, right_height = 0;
		if (left)
			left_height = left->height;
		if (right)
			right_height = right->height;
		return left_height - right_height;
	}

	void Update_height()
	{
		int left_height = 0, right_height = 0;
		if (left)
			left_height = left->height;
		if (right)
			right_height = right->height;
		if (left_height > right_height)
			height = left_height;
		else
			height = right_height;
	}
};

struct AVL_tree:List
{
	AVL_tree_node* root;

	void Create_empty()override
	{
		root = nullptr;
	}

	AVL_tree()
	{
		Create_empty();
	}


	AVL_tree_node* Right_rotation(AVL_tree_node* current_node)
	{
		AVL_tree_node* left = current_node->left;
		current_node->left = left->right;
		left->right = current_node;
		current_node->Update_height();
		left->Update_height();
		return left;
	}

	AVL_tree_node* Left_rotation(AVL_tree_node* current_node)
	{
		AVL_tree_node* right = current_node->right;
		current_node->right = right->left;
		right->left = current_node;
		current_node->Update_height();
		right->Update_height();
		return right;
	}

	AVL_tree_node* Balance(AVL_tree_node* current_node)
	{
		current_node->Update_height();
		if (current_node->Balance() == 2)
		{
			if (current_node->right->Balance() < 0)
				current_node->right = Right_rotation(current_node->right);
			return Left_rotation(current_node);
		}
		if (current_node->Balance() == -2)
		{
			if (current_node->left->Balance() > 0)
				current_node->left = Left_rotation(current_node->left);
			return Right_rotation(current_node);
		}
		return current_node;
	}

	AVL_tree_node* add(AVL_tree_node* current_node, PointXYZ point)
	{
		if (!current_node) 
			return new AVL_tree_node(point);
		if (point.Less_than(current_node->value))
			current_node->left = add(current_node->left, point);
		else
			current_node->right = add(current_node->right, point);
		return Balance(current_node);
	}

	void Append(PointXYZ point)override
	{
		root = add(root, point);
	}

	void Convert_from_vector_to_tree(vector<PointXYZ> vector_points)
	{
		Create_empty();
		for (int i = 0; i < vector_points.size(); i++)
		{
			Append(vector_points[i]);
		}
	}

	void Convert_to_vector(Vector_list& vector_points, AVL_tree_node* node)
	{
		if (node)
		{
			if (node->left)
				Convert_to_vector(vector_points, node->left);
			vector_points.Append(node->value);
			if (node->right)
				Convert_to_vector(vector_points, node->right);
		}
		else vector_points.Create_empty();
	}

	void Remove(PointXYZ point) override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Remove(point);
		Convert_from_vector_to_tree(vector_points.vector_points);
	}

	int Length() override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.vector_points.size();
	}

	vector<PointXYZ> Find_element()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.Find_element();
	}

	vector<PointXYZ> Find_in_range()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.Find_in_range();
	}

	void Print()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Print();
	}

	void Change_centre_position(PointXYZ new_centre)override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Change_centre_position(new_centre);
		Convert_from_vector_to_tree(vector_points.vector_points);
	}
};

struct Two_three_tree_node 
{
	int size;
	PointXYZ value[3];
	Two_three_tree_node* first;
	Two_three_tree_node* second;
	Two_three_tree_node* third;
	Two_three_tree_node* fourth; 
	Two_three_tree_node* parent; 

	bool find(PointXYZ point) 
	{
		for (int i = 0; i < size; ++i)
			if (!value[i].Bigger_than(point) || !value[i].Less_than(point) )
				return true;
		return false;
	}

	void swap(PointXYZ& x, PointXYZ& y)
	{
		PointXYZ r = x;
		x = y;
		y = r;
	}

	void sort2(PointXYZ& x, PointXYZ& y) 
	{
		if (x.Bigger_than(y))
			swap(x, y);
	}

	void sort3(PointXYZ& x, PointXYZ& y, PointXYZ& z) 
	{
		if (x.Bigger_than(y))
			swap(x, y);
		if (x.Bigger_than(z))
			swap(x, z);
		if (y.Bigger_than(z))
			swap(y, z);
	}

	void sort()
	{
		if (size == 1) return;
		if (size == 2) sort2(value[0], value[1]);
		if (size == 3) sort3(value[0], value[1], value[2]);
	}

	void insert_to_node(PointXYZ point) 
	{
		value[size] = point;
		size++;
		sort();
	}

	void become_node2(PointXYZ point, Two_three_tree_node* first_, Two_three_tree_node* second_)
	{
		value[0] = point;
		first = first_;
		second = second_;
		third = nullptr;
		fourth = nullptr;
		parent = nullptr;
		size = 1;
	}

	bool is_leaf() 
	{
		return (first == nullptr) && (second == nullptr) && (third == nullptr);
	}

	Two_three_tree_node(PointXYZ point) : 
		size(1), 
		value{point, NULL, NULL }, 
		first(nullptr), 
		second(nullptr),
		third(nullptr), 
		fourth(nullptr), 
		parent(nullptr) {}

	Two_three_tree_node(PointXYZ point, Two_three_tree_node* first_, Two_three_tree_node* second_, Two_three_tree_node* third_, Two_three_tree_node* fourth_, Two_three_tree_node* parent_) :
		size(1), 
		value{ point, NULL, NULL }, 
		first(first_), 
		second(second_),
		third(third_), 
		fourth(fourth_), 
		parent(parent_) {}
};

struct Two_three_tree:List
{
	Two_three_tree_node* root;

	void Create_empty()override
	{
		root = nullptr;
	}

	Two_three_tree()
	{
		Create_empty();
	}

	Two_three_tree_node* split(Two_three_tree_node* item) {
		if (item->size < 3) 
			return item;

		Two_three_tree_node* x = new Two_three_tree_node(item->value[0], item->first, item->second, nullptr, nullptr, item->parent);
		Two_three_tree_node* y = new Two_three_tree_node(item->value[2], item->third, item->fourth, nullptr, nullptr, item->parent);
		if (x->first)  x->first->parent = x;    
		if (x->second) x->second->parent = x;
		if (y->first)  y->first->parent = y;   
		if (y->second) y->second->parent = y;

		if (item->parent) {
			item->parent->insert_to_node(item->value[1]);

			if (item->parent->first == item) 
				item->parent->first = nullptr;
			else if (item->parent->second == item) 
				item->parent->second = nullptr;
			else if (item->parent->third == item) 
				item->parent->third = nullptr;

			if (item->parent->first == nullptr) 
			{
				item->parent->fourth = item->parent->third;
				item->parent->third = item->parent->second;
				item->parent->second = y;
				item->parent->first = x;
			}
			else if (item->parent->second == nullptr) {
				item->parent->fourth = item->parent->third;
				item->parent->third = y;
				item->parent->second = x;
			}
			else {
				item->parent->fourth = y;
				item->parent->third = x;
			}

			Two_three_tree_node* tmp = item->parent;
			delete item;
			return tmp;
		}
		else {
			x->parent = item;
			y->parent = item;
			item->become_node2(item->value[1], x, y);
			return item;
		}
	}

	Two_three_tree_node* add(Two_three_tree_node* current_node, PointXYZ point)
	{
		if (!current_node) 
			return new Two_three_tree_node(point);

		if (current_node->is_leaf()) 
			current_node->insert_to_node(point);
		else if (!point.Bigger_than(current_node->value[0]))
			add(current_node->first, point);
		else if ((current_node->size == 1) || ((current_node->size == 2) && !point.Bigger_than(current_node->value[1]))) 
			add(current_node->second, point);
		else add(current_node->third, point);

		return split(current_node);
	}

	void Append(PointXYZ point)
	{
		root = add(root, point);
	}

	void Convert_from_vector_to_tree(vector<PointXYZ> vector_points)
	{
		Create_empty();
		for (int i = 0; i < vector_points.size(); i++)
		{
			Append(vector_points[i]);
		}
	}

	void Convert_to_vector(Vector_list& vector_points, Two_three_tree_node* node)
	{
		if (node)
		{
			for (int i = 0; i < node->size; i++)
				vector_points.Append(node->value[i]);
			if (node->first)
				Convert_to_vector(vector_points, node->first);
			if (node->second)
				Convert_to_vector(vector_points, node->second);
			if (node->third)
				Convert_to_vector(vector_points, node->second);
		}
		else vector_points.Create_empty();
	}

	void Remove(PointXYZ point) override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Remove(point);
		Convert_from_vector_to_tree(vector_points.vector_points);
	}

	int Length() override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.vector_points.size();
	}

	vector<PointXYZ> Find_element()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.Find_element();
	}

	vector<PointXYZ> Find_in_range()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		return vector_points.Find_in_range();
	}

	void Print()override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Print();
	}

	void Change_centre_position(PointXYZ new_centre)override
	{
		Vector_list vector_points;
		Convert_to_vector(vector_points, root);
		vector_points.Change_centre_position(new_centre);
		Convert_from_vector_to_tree(vector_points.vector_points);
	}
};

void Sys_pause();
void error_no_elements();
void print_list(vector<PointXYZ> points);
int choose_list();

void interactive_mode();
void demo();
void bench();
void menu();