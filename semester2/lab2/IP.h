#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<random>
#include<chrono>

using namespace std;

const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

int enter_number(string mark);
void error_no_elements();
string int_to_string(int number);
vector<int> split(string word);

struct IP
{
	string ipv4 = "";

	void enter_IP()
	{
		bool end = false;
		int i = 0;
		string ip = "xxx.xxx.xxx.xxx";
		while (!(end))
		{
			if (i % 4 == 3 && i != 15)
				i++;
			else
			{
				cout << blue + "Enter IPv4" << endl;
				cout << light_blue + ip;
				if (i < 15)
					end = false;
				int key = _getch();
				switch (key)
				{
				case 13:
					end = true;
					if (i < 15)
						end = false;
					break;
				case 8:
					if (i == 15)
					{
						i = 14;
						ip[i] = 'x';
					}
					else {
						if (i == 0)
							ip[i] = 'x';
						else
						{
							if ((i-1) % 4 == 3)
							{
								i--;
								i--;
								ip[i] = 'x';
							}
							else
							{
								i--;
								ip[i] = 'x';
							}
						}
					}
					break;
				default:
					if (i < 15)
					{
						if (key >= 48 && key <= 57)
						{
							switch (i % 4)
							{
							case 0:
								if (key >= 48 && key <= 50)
								{
									ip[i] = int(key);
									i++;
								}
								break;
							case 1:
								if (ip[i - 1] == '2')
								{
									if (key >= 48 && key <= 53)
									{
										ip[i] = int(key);
										i++;
									}
								}
								else
								{
									ip[i] = int(key);
									i++;
								}
								break;
							case 2:
								if (ip[i - 1] == '5')
								{
									if (key >= 48 && key <= 54)
									{
										ip[i] = int(key);
										i++;
									}
								}
								else
								{
									ip[i] = int(key);
									i++;
								}
								break;
							}
						}
					}
				}
			}
			system("cls");
		}
		ipv4 = ip;
	}
};

struct all_lists
{
public:
	virtual void create_empty() = 0;

	virtual void append(IP element) = 0;

	virtual void insert(int index, IP element) = 0;

	virtual void remove(int index) = 0;

	virtual IP get(int index) = 0;

	virtual void set(int index, IP element) = 0;

	virtual int length() = 0;

	virtual void enter_list() = 0;

	virtual void Print_list() = 0;
};

struct vector_list : all_lists {
public:
	vector<IP> list_of_IPv4;

	void create_empty()override
	{
		vector<IP> empty_vector;
		list_of_IPv4 = empty_vector;
	}

	void append(IP element)override
	{
		list_of_IPv4.push_back(element);
	}

	void insert(int index, IP element)override
	{
		list_of_IPv4.push_back(element);
		int i = list_of_IPv4.size() - 1;
		while (i != index)
		{
			list_of_IPv4[i] = list_of_IPv4[i - 1];
			i--;
		}
		list_of_IPv4[i] = element;
	}

	void remove(int index)override
	{
		list_of_IPv4.erase(list_of_IPv4.begin() + index);
	}

	IP get(int index)
	{
		return list_of_IPv4[index];
	}

	void set(int index, IP element)override
	{
		list_of_IPv4[index] = element;
	}

	int length()override
	{
		return list_of_IPv4.size();
	}

	void enter_list()override
	{
		create_empty();
		int number = enter_number("number of elements");
		while (number > 0)
		{
			IP new_ip;
			new_ip.enter_IP();
			list_of_IPv4.push_back(new_ip);
			number--;
		}
	}

	void Print_list()override
	{
		for (int i = 0; i < list_of_IPv4.size(); i++)
			cout << green + list_of_IPv4[i].ipv4 << endl;
	}
};

struct array_list : all_lists {
public:
	int max_length = 32000;
	IP max_list[32000];
	int Length = 0;

	void create_empty()override
	{
		Length = 0;
	}

	void append(IP element)override
	{
		if (Length < max_length)
		{
			max_list[Length] = element;
			Length++;
		}
		else
			cout << "Max length." << endl;
	}

	void insert(int index, IP element)override
	{
		if (Length < max_length)
		{
			max_list[Length] = element;
			int i = Length;
			while (i != index)
			{
				max_list[i] = max_list[i - 1];
				i--;
			}
			max_list[i] = element;
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

	IP get(int index)override
	{
		return max_list[index];
	}

	void set(int index, IP element)override
	{
		max_list[index] = element;
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
			IP new_ip;
			new_ip.enter_IP();
			append(new_ip);
			number--;
		}
	}

	void Print_list()override
	{
		for (int i = 0; i < Length; i++)
			cout << green + max_list[i].ipv4 << endl;
	}
}; 

struct ListNode
{
	IP value;
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

	void append(IP element)override
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

	void insert(int index, IP element) override {
		ListNode* current_node = head;
		if (index == 0)
		{
			ListNode* r = head;
			head = new ListNode;
			head->value = element;
			head->prev = nullptr;
			r->prev = head;
			head->next = r;
		}
		else {
			for (int i = 0; i < index - 1; i++)
				current_node = current_node->next;
			ListNode* r = current_node->next;
			current_node->next = new ListNode;
			(current_node->next)->value = element;
			r->prev = current_node->next;
			(current_node->next)->next = r;
			(current_node->next)->prev = current_node;
		}
		size++;
	}

	void remove(int index) override{
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

	IP get(int index)override
	{
		ListNode* current_node = head;
		for (int i = 0; i < index; i++)
		{
			current_node = current_node->next;
		}
		return current_node->value;
	}

	void set(int index, IP element)override
	{
		ListNode* current_node = head;
		for (int i = 0; i < index; i++)
		{
			current_node = current_node->next;
		}
		current_node->value = element;

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
			IP new_ip;
			new_ip.enter_IP();
			append(new_ip);
			number--;
		}
	}

	void Print_list()override
	{
		ListNode* current_node = head;
		for (int i = 0; i < size; i++)
		{
			cout << green + current_node->value.ipv4 << endl;
			current_node = current_node->next;
		}
	}
};

int choose_list();
int enter_index(int length);
void Sys_pause();

void interactive_mode();
void demonstrative_mode();
void benchmark();

void menu();
