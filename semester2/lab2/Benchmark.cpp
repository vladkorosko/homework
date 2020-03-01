#include "IP.h"

IP autogenerator()
{
	IP new_IP;
	int first_number = rand() % 256;
	int second_number = rand() % 256;
	int third_number = rand() % 256;
	int forth_number = rand() % 256;
	new_IP.ipv4 += int_to_string(first_number) + "." + int_to_string(second_number) + "." + int_to_string(third_number) + "." + int_to_string(forth_number);
	return new_IP;
}

void benchmark()
{
	cout << blue + "This array list." << endl;
	IP new_IP;
	int n = 1;
	int start = clock();
	int finish = clock();
	int wasted_time = finish - start;
	while (wasted_time < 1000)
	{
		n *= 2;
		start = clock();
		array_list Array_list;
		Array_list.create_empty();
		for (int i = 0; i < n; i++)
		{
			new_IP = autogenerator();
			Array_list.append(new_IP);
		}
		for (int i = 0; i < n; i++)
		{
			new_IP = Array_list.get(i);
			new_IP = autogenerator();
			Array_list.set(i, new_IP);
		}
		for (int i = n-1; i >= 0; i--)
		{
			Array_list.remove(i);
		}
		finish = clock();
		wasted_time = finish - start;
		cout << green;
		cout << wasted_time << "      " << n << endl;
	}

	int wasted_time_array = wasted_time;

	cout << endl << endl;
	cout << light_blue + "This vector list." << endl;
	n = 1;
	start = clock();
	finish = clock();
	wasted_time = finish - start;

	while (wasted_time < 1000)
	{
		n *= 2;
		start = clock();
		vector_list Vector_list;
		Vector_list.create_empty();
		for (int i = 0; i < n; i++)
		{
			new_IP = autogenerator();
			Vector_list.append(new_IP);
		}
		for (int i = 0; i < n; i++)
		{
			new_IP = Vector_list.get(i);
			new_IP = autogenerator();
			Vector_list.set(i, new_IP);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			Vector_list.remove(i);
		}
		finish = clock();
		wasted_time = finish - start;
		cout << green;
		cout << wasted_time << "      " << n << endl;
	}

	int wasted_time_vector = wasted_time;
	cout << endl << endl;

	cout << yellow + "This linked list." << endl;
	n = 1;
	start = clock();
	finish = clock();
	wasted_time = finish - start;

	while (wasted_time < 1000)
	{
		n *= 2;
		start = clock();
		Linked_list linked_list;
		linked_list.create_empty();
		for (int i = 0; i < n; i++)
		{
			new_IP = autogenerator();
			linked_list.append(new_IP);
		}
		for (int i = 0; i < n; i++)
		{
			new_IP = linked_list.get(i);
			new_IP = autogenerator();
			linked_list.set(i, new_IP);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			linked_list.remove(i);
		}
		finish = clock();
		wasted_time = finish - start;
		cout << green;
		cout << wasted_time << "      " << n << endl;
	}

	cout << red + "This is final result." << endl;
	cout << blue + "Array list: time " << wasted_time_array << "; number of elements is " << n << endl;
	cout << light_blue + "Vector list: time " << wasted_time_vector << "; number of elements is " << n << endl;
	cout << yellow + "Linked list: time " << wasted_time << "; number of elements is " << n << endl;
}