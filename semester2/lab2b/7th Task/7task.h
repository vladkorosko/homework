#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

using namespace std;

const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

void Sys_pause();
int enter_number(string mark);
int enter_index(int length);
void error_wrong_index();
void error_no_elements();
string create_string();

struct all_lists
{
	virtual void create_empty() = 0;

	virtual void append(string element) = 0;

	virtual void remove(int index) = 0;

	virtual void filter_interactive() = 0;

	virtual void filter(string criteria) = 0;

	virtual int length() = 0;

	virtual void enter_list() = 0;

	virtual void Print_list() = 0;
};

struct vector_list : all_lists {
	vector<string> list_of_string;

	void create_empty()override
	{
		vector<string> empty_vector;
		list_of_string = empty_vector;
	}

	void append(string element)override
	{
		list_of_string.push_back(element);
	}

	void remove(int index)override
	{
		list_of_string.erase(list_of_string.begin() + index);
	}

	void filter(string criteria)override
	{
		cout << blue + "    The criteria is " + criteria << endl;
		if (criteria != "")
		{
			bool something_happend = false;
			for (int i = 0; i < list_of_string.size(); i++)
			{
				bool same = true;
				if (criteria.length() < list_of_string[i].length())
				{
					for (int j = 0; j < criteria.length(); j++)
						if (criteria[j] != list_of_string[i][j])
							same = false;
				}
				else same = false;

				if (same)
				{
					cout << green + list_of_string[i] << endl;
					something_happend = true;
				}
			}
			if (!something_happend)
				cout << red + "No element with same beginning." << endl;
		}
		else
			for (int i = 0; i < list_of_string.size(); i++)
				cout << green + list_of_string[i] << endl;
	}

	void filter_interactive()override
	{
		bool end = false;
		string criteria = "";
		while (!end)
		{
			system("cls");
			filter(criteria);

			char key;
			key = _getch();
			if ((int)key != 13)
			{
				if ((int)key == 8)
				{
					if (criteria.length() > 0)
						criteria.pop_back();
					else
						criteria = "";
				}
				else
					criteria += (char)key;
			}
			else
			{
				end = true;
				Sys_pause();
			}
		}
	}

	int length()override
	{
		return list_of_string.size();
	}

	void enter_list()override
	{
		create_empty();
		int number = enter_number("number of elements");
		while (number > 0)
		{
			system("cls");
			string new_element;
			cin >> new_element;
			append(new_element);
			number--;
		}
	}

	void Print_list()override
	{
		for (int i = 0; i < list_of_string.size(); i++)
			cout << green + list_of_string[i] << endl;
	}
};

struct array_list : all_lists {
public:
	int max_length = 32000;
	string max_list[32000];
	int Length = 0;

	void create_empty()override
	{
		Length = 0;
	}

	void append(string element)override
	{
		if (Length < max_length)
		{
			max_list[Length] = element;
			Length++;
		}
		else
			cout << "Max length." << endl;
	}

	void remove(int index)override
	{

		for (int i = index + 1; i < Length; i++)
			max_list[i - 1] = max_list[i];
		Length--;
	}

	void filter(string criteria)override
	{
		cout << blue + "    The criteria is " + criteria << endl;
		if (criteria != "")
		{
			bool something_happend = false;
			for (int i = 0; i < Length; i++)
			{
				bool same = true;
				if (criteria.length() < max_list[i].length())
				{
					for (int j = 0; j < criteria.length(); j++)
						if (criteria[j] != max_list[i][j])
							same = false;
				}
				else same = false;

				if (same)
				{
					cout << green + max_list[i] << endl;
					something_happend = true;
				}
			}
			if (!something_happend)
				cout << red + "No element with same beginning." << endl;
		}
		else
			for (int i = 0; i < Length; i++)
				cout << green + max_list[i] << endl;
	}

	void filter_interactive()override
	{
		bool end = false;
		string criteria = "";
		while (!end)
		{
			system("cls");
			filter(criteria);

			char key;
			key = _getch();
			if ((int)key != 13)
			{
				if ((int)key == 8)
				{
					if (criteria.length() > 0)
						criteria.pop_back();
					else
						criteria = "";
				}
				else
					criteria += (char)key;
			}
			else
			{
				end = true;
				Sys_pause();
			}
		}
	}

	int length()override
	{
		return Length;
	}

	void enter_list()override
	{
		create_empty();
		int number = enter_number("number of elements");
		while (number > 0)
		{
			system("cls");
			string new_element;
			cin >> new_element;
			append(new_element);
			number--;
		}
	}

	void Print_list()override
	{
		for (int i = 0; i < Length; i++)
			cout << green + max_list[i] << endl;
	}
};

struct ListNode
{
	string value;
	ListNode* prev;
	ListNode* next;
};

struct Linked_list : all_lists
{
public:
	ListNode* head;
	ListNode* tail;
	int size = 0;

	void create_empty()override
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	Linked_list() {
		create_empty();
	}

	void append(string element)override
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

	void remove(int index) override {
		if (size == 1)
		{
			create_empty();
		}
		else
		{
			if (index == 0)
			{
				ListNode* r = head;
				head = r->next;
				head->prev = nullptr;
				delete r;
			}
			else
			{
				if (index == size - 1)
				{
					ListNode* r = tail;
					tail = r->prev;
					tail->next = nullptr;
					delete r;
				}
				else
				{
					ListNode* current_node = head;
					for (int i = 0; i < index - 1; i++)
						current_node = current_node->next;
					ListNode* r = current_node->next;
					current_node->next = r->next;
					r->next->prev = current_node;
					delete r;
				}
			}
			size--;
		}
	}

	void filter(string criteria)override
	{
		cout << blue + "    The criteria is " + criteria << endl;
		if (criteria != "")
		{
			bool something_happend = false;
			ListNode* current_node = head;
			for (int i = 0; i < size; i++)
			{
				bool same = true;
				if (criteria.length() < current_node->value.length())
				{
					for (int j = 0; j < criteria.length(); j++)
						if (criteria[j] != current_node->value[j])
							same = false;
				}
				else same = false;

				if (same)
				{
					cout << green + current_node->value << endl;
					something_happend = true;
				}
				current_node = current_node->next;
			}
			if (!something_happend)
				cout << red + "No element with same beginning." << endl;
		}
		else
		{
			ListNode* current_node = head;
			for (int i = 0; i < size; i++)
			{
				cout << green + current_node->value << endl;
				current_node = current_node->next;
			}
		}
	}

	void filter_interactive()override
	{
		bool end = false;
		string criteria = "";
		while (!end)
		{
			system("cls");
			filter(criteria);

			char key;
			key = _getch();
			if ((int)key != 13)
			{
				if ((int)key == 8)
				{
					if (criteria.length() > 0)
						criteria.pop_back();
					else
						criteria = "";
				}
				else
					criteria += (char)key;
			}
			else
			{
				end = true;
				Sys_pause();
			}
		}
	}

	int length()override
	{
		return size;
	}

	void enter_list()override
	{
		int number = enter_number("number of elements");
		create_empty();
		while (number > 0)
		{
			system("cls");
			string new_element;
			cin >> new_element;
			append(new_element);
			number--;
		}
	}

	void Print_list()override
	{
		ListNode* current_node = head;
		for (int i = 0; i < size; i++)
		{
			cout << green + current_node->value << endl;
			current_node = current_node->next;
		}
	}
};

void seventh_task();