#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <random>
#include <conio.h>

using namespace std;

const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";
const string purple = "\u001B[35m";
const string white = "\u001B[37m";

void isys_pause();
vector<string> auto_generator(int size);
void bubble_sort(vector<string>& a);
void selection_sort(vector<string>& a);
void insertion_sort(vector<string>& a);
void print_list(vector<string> a);
void quick_sort(vector<string>& a, int first, int last);
void merge_sort(vector<string>& a, int start, int finish);
void combine_sort(vector<string>& a);

void demo();
void benchmark();
void menu();