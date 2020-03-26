#pragma once
//Including libraries:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <chrono>
#include <random>

using namespace std;


//Colours:
const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

//Our structs:
struct worldtime {
	int day;
	int hour;
	int minute;

	void Print()
	{
		cout << day << " day, at " << hour << ":" << minute << endl << endl;
	}
};

struct monster {
	int ID;
	string name;
	int health;
	int strength;
	double chance;
	string type_of_attack;
	worldtime date;

	void Print()
	{
		cout << ID << " " << name << " " << health << " " << strength << " " << type_of_attack << " " << chance << " ";
		date.Print();
	}
};

//Correct input
bool check_int(string word);

//Creating empty files:
void create_file(string file_path);
void create_binary_file(string binary_file_path);


//Saving information into files:
void save_table_file(vector<monster> list_of_monsters, string file_path);
void save_table_binary_file(vector<monster> list_of_monsters, string binary_file_path);


//Creating monsters:
monster autogenerator();
monster create_monster();
monster choose_type_of_generation();
void addMonster(int& id, vector<monster>& list_of_monsters, string file_path, string binary_file_path, monster new_monster);


//Showing information:
void read_table(string file_path);
void print_list(vector<monster> list_of_monsters);
void read_binary(int size, string binary_file_path);
void show(vector<monster> list_of_monsters, string file_path, string binary_file_path);


//Editing information:
void quick_sort(vector<monster>& monsters, int first, int last, int position);
void counting_sort(vector<monster>& list_of_monsters);
void radix_sort(vector<monster>& monsters);
void choose_sort(vector<monster>& monsters, string file_path, string binary_file_path);
void delete_line(int monster_id, vector<monster>& list_of_monsters, string file_path, string binary_file_path);
void edit_line(int monster_id, vector<monster>& list_of_monsters, string file_path, string binary_file_path, monster updated_monster);


//Finding and showing information:
vector<string> find_by_name(string mark, string file_path);
vector<string> find_by_attack(string mark, int start, int finish, string file_path);
vector<string> find_by_date(worldtime date, string file_path);
void show_findedmonsters(vector<string> list_of_words);
void find(string file_path);


//Different modes:
void interactive_mode();
void demonstrative_mode();
void benchmark();
void menu();