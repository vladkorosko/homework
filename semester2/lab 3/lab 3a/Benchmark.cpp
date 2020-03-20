#include "Background.h"

void benchmark()
{
	cout << white + "It takes some time. Please wait." << endl;
	vector<vector<time_t>> results;
	int n = 50;
	for (int i = 0; i < 6; i++)
	{
		n *= 2;
		vector <time_t> work_time;
		vector<string> First_list = auto_generator(n);
		vector<string> Second_list = First_list, Third_list = First_list, Forth_list = First_list, Fifth_list = First_list, Sixth_list = First_list;
		time_t start = time(NULL), finish = time(NULL), wasted_time = finish - start;

		start = clock();
		bubble_sort(First_list);
		finish = clock();
		wasted_time = finish - start;
		work_time.push_back(wasted_time);

		start = clock();
		insertion_sort(Second_list);
		finish = clock();
		wasted_time = finish - start;
		work_time.push_back(wasted_time);

		start = clock();
		selection_sort(Third_list);
		finish = clock();
		wasted_time = finish - start;
		work_time.push_back(wasted_time);

		start = clock();
		quick_sort(Forth_list, 0, Forth_list.size() - 1);
		finish = clock();
		wasted_time = finish - start;
		work_time.push_back(wasted_time);

		start = clock();
		merge_sort(Fifth_list, 0, Fifth_list.size() - 1);
		finish = clock();
		wasted_time = finish - start;
		work_time.push_back(wasted_time);

		start = clock();
		combine_sort(Sixth_list);
		finish = clock();
		wasted_time = finish - start;
		work_time.push_back(wasted_time);

		results.push_back(work_time);
	}

	system("cls");
	cout << white + "This results of benchmark(time in miliseconds)." << endl;

	cout << white + "Number of elements 100    200    400    800    1600    3200" << endl;
	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
			cout << green + "     Bubble sort    ";
			break;
		case 1:
			cout << blue + "   Insertion sort   ";
			break;
		case 2:
			cout << light_blue + "   Selection sort   ";
			break;
		case 3:
			cout << red + "     Quick sort     ";
			break;
		case 4:
			cout << yellow + "     Merge sort     ";
			break;
		default:
			cout << purple + "    Combine sort    ";
		}
		for (int j = 0; j < 6; j++)
			cout << results[j][i] << "     ";
		cout << endl;
	}
	isys_pause();
}