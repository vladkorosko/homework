#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>

using namespace std;

bool check_number(char sign);
int enter_number(string mark);

struct Node
{
	vector<Node*> path;
	int value;
	Node* prev;
	vector<Node*> next;
};

struct Tree
{
	Node* root;

	void create_empty()
	{
		root = nullptr;
	}

	Tree() {
		create_empty();
	}

	Node* choose_node(Node* current_node)
	{
		int position = 0;
		bool end = false;

		while (!end)
		{
			system("cls");
			cout << "Path:Root";
			for (int i = 0; i < current_node->path.size(); i++)
				cout << "-> " << current_node->path[i]->value;
			cout << endl;
			if (position == 0)
				cout << "-> Node " << current_node->value << endl;
			else cout << "   Node " << current_node->value << endl;
			if (position == 1)
				cout << "-> Back;" << endl;
			else cout << "   Back;" << endl;

			for (int i = 0; i < current_node->next.size(); i++)
			{
				if (i == position-2)
					cout << "-> " << current_node->next[i]->value << endl;
				else cout << "   " << current_node->next[i]->value << endl;
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
						else position = current_node->next.size()+1;
					}

					if ((int)key == 80)
					{
						if (position < current_node->next.size()+1)
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
					return current_node;
					break;
				case 1:
					if (current_node->prev)
						return choose_node(current_node->prev);
					else return choose_node(current_node);
					break;
				default:
					return choose_node(current_node->next[position-2]);
					break;
				}
			}
		}
	}

	void add_new_interactive(int number, Node* current_node)
	{
		Node* new_node = new Node();
		new_node->value = number;
		vector<Node*> a;
		new_node->next = a;
		if (!root)
		{
			new_node->path = a;
			new_node->prev = nullptr;
			root = new_node;
		}
		else
		{
			if (!current_node)
				current_node = choose_node(root);
			new_node->prev = current_node;
			new_node->path = current_node->path;
			new_node->path.push_back(current_node);
			current_node->next.push_back(new_node);
		}
	}

	void print(Node* current_node)
	{
		cout << current_node->value << " ";
		cout << "(";
		for (int i = 0; i < current_node->next.size(); i++)
			print(current_node->next[i]);
		cout << ") ";
	}

	Tree* remove(int number, Node* current_node)
	{
		if (current_node->value == number)
		{
			Tree* deleted_tree = new Tree();
			deleted_tree->root = current_node;
			if (current_node->prev)
			{
				for (int i = 0; i < current_node->prev->next.size(); i++)
					if (number == current_node->prev->next[i]->value)
					{
						current_node->prev->next.erase(current_node->prev->next.begin() + i);
						i = current_node->prev->next.size();
					}
			}
			else
				create_empty();
			return deleted_tree;
		}
		else
		{
			if (current_node->next.size())
			{
				for (int i = 0; i < current_node->next.size(); i++)
					return remove(number, current_node->next[i]);
			}
		}

		Tree* deleted_tree = new Tree();
		return deleted_tree;
	}
};

struct Binary_Node
{
	int value;
	Binary_Node* prev;
	Binary_Node* left;
	Binary_Node* right;
};

struct Binary_Tree
{
	Binary_Node* root;

	void create_empty()
	{
		root = nullptr;
	}

	Binary_Tree() {
		create_empty();
	}

	void add(int number, Binary_Node* current_node)
	{
		Binary_Node* new_node = new Binary_Node();
		new_node->left = nullptr;
		new_node->right = nullptr;
		new_node->value = number;
		if (!root)
		{
			new_node->prev = nullptr;
			root = new_node;
		}
		else
		{
			if (current_node->value > number)
			{
				if (current_node->left)
					add(number, current_node->left);
				else
				{
					new_node->prev = current_node;
					current_node->left = new_node;
				}
			}
			else {
				if (current_node->right)
					add(number, current_node->right);
				else
				{
					new_node->prev = current_node;
					current_node->right = new_node;
				}
			}
		}
	}

	void print(Binary_Node* current_node)
	{
		cout << current_node->value << " ";
		cout << "(";
		if (current_node->left)
			print(current_node->left);
		else cout << "() ";
		if (current_node->right)
			print(current_node->right);
		else cout << "()";
		cout << ")";
	}
};

struct Symetric_Node
{
	int value;
	Symetric_Node* left;
	Symetric_Node* right;
	bool have_left;
	bool have_right;
};

struct Symetric_Tree {
	Symetric_Node* root;

	Symetric_Node* build_symetric_tree(Binary_Node* current_node, Symetric_Node* sl, Symetric_Node* sr)
	{
		if (current_node)
		{
			Symetric_Node* root = new Symetric_Node;
			root->value = current_node->value;
			if ((root->have_left = (current_node->left != NULL)))
				root->left = build_symetric_tree(current_node->left, sl, root);
			else root->left = sl;
			if ((root->have_right = (current_node->right != NULL)))
				root->right = build_symetric_tree(current_node->right, root, sr);
			else root->right = sr;
			return root;
		}
		else root = nullptr;
	}

	void create(Binary_Tree* tree)
	{
		root = build_symetric_tree(tree->root, nullptr, nullptr);
	}

	Symetric_Tree(Binary_Tree* tree)
	{
		create(tree);
	}

	Symetric_Node* move(Symetric_Node* current_node) {
		Symetric_Node* next_node = current_node->right;
		if (current_node->have_right)
			while (next_node->have_left)  next_node = next_node->left;
		return next_node;
	}

	void symetric_write(Symetric_Node* current_node) {
		while (current_node->have_left) current_node = current_node->left;
		while (current_node) {
			cout << current_node->value << ", ";
			current_node = move(current_node);
		}
	}
};

void inter();
void demo();

void menu();