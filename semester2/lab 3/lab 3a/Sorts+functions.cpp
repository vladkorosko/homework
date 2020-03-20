#include "Background.h"

void isys_pause()
{
	cout << yellow;
	system("pause");
	system("cls");
}

vector<string> auto_generator(int size)
{
	srand(time(NULL));
	vector<string> words;
	while (size > 0)
	{
		string word = "";
		int length = rand() % 10;
		while (length > 0)
		{
			word += (char)((int)'a' + rand() % 26);
			length--;
		}

		words.push_back(word);
		size--;
	}
	return words;
}

void bubble_sort(vector<string> &a)
{ 
	for (int i = 0; i < a.size(); i++)
		for (int j = i; j < a.size(); j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
}

void selection_sort(vector<string> &a)
{
	int min_ind;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min_ind = i;
		for (int j = i; j < a.size(); j++)
			if (a[j] < a[min_ind])
				min_ind = j;
		swap(a[min_ind], a[i]);
	}
}

void insertion_sort(vector<string> &a)
{
	int j;
	string value;
	for (int i = 0; i < a.size(); i++)
	{
		value = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > value)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = value;
	}
}

void quick_sort(vector<string> &a, int first, int last)
{
	string x = a[first];
	int i = first, j = last;
	do
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			if (i < j)
				swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if(first < j)
		quick_sort(a, first, j);
	if(last > i)
		quick_sort(a, i, last);
}

void merge(vector<string> &a, int index_of_first_element_of_first_part, int index_of_last_element_of_first_part, int index_of_last_element_second_part)
{
	int i, j, k;
	int n1 = index_of_last_element_of_first_part - index_of_first_element_of_first_part + 1;
	int n2 = index_of_last_element_second_part - index_of_last_element_of_first_part;

	vector<string> First_array (n1,""), Second_array (n2,"");

	for (i = 0; i < n1; i++)
		First_array[i] = a[index_of_first_element_of_first_part + i];
	for (j = 0; j < n2; j++)
		Second_array[j] = a[index_of_last_element_of_first_part + 1 + j];

	i = 0;
	j = 0;
	k = index_of_first_element_of_first_part;
	while (i < n1 && j < n2)
	{
		if (First_array[i] <= Second_array[j])
		{
			a[k] = First_array[i];
			i++;
		}
		else
		{
			a[k] = Second_array[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = First_array[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = Second_array[j];
		j++;
		k++;
	}
}

void merge_sort(vector<string> &a, int start, int finish)
{
	if (start < finish)
	{
		int m = start + (finish - start) / 2;
		merge_sort(a, start, m);
		merge_sort(a, m + 1, finish);

		merge(a, start, m, finish);
	}
}

void combine_sort(vector<string>& a)
{
	if (a.size() < 1000)
		selection_sort(a);
	else
		quick_sort(a, 0, a.size()-1);
}

void print_list(vector<string> a)
{
	for (int i = 0; i < a.size(); i++)
		cout << green + a[i] << endl;
	cout << endl;
}