#include "Functions.h"

size_t memory_write(vector<monster> list_of_monsters, string file_path)
{
	ofstream file(file_path);
	for (int i = 0; i < list_of_monsters.size(); i++)
	{
		file << list_of_monsters[i].ID << " ";
		file << list_of_monsters[i].name << " ";
		file << list_of_monsters[i].health << " ";
		file << list_of_monsters[i].strength << " ";
		file << list_of_monsters[i].type_of_attack << " ";
		file << list_of_monsters[i].chance << " ";
		file << list_of_monsters[i].date.day << " ";
		file << list_of_monsters[i].date.hour << " ";
		file << list_of_monsters[i].date.minute << endl;
	}
	size_t size = file.tellp();
	file.close();
	return size;
}

void benchmark()
{
	
	int n = 5;
	string file_path = "table.txt";
	int start = clock();
	int finish = clock();
	int wasted_time = finish - start;
	
	cout << blue + "Time      Number of elements       Size of memory" << endl;
	while (wasted_time < 1000)
	{
		n *= 2;
		create_file(file_path);
		vector<monster> monsters;
		vector<string> finded_monsters;
		start = clock();
		for (int i = 0; i < n; i++)
		{
			monster newmonster = autogenerator();
			newmonster.ID = i;
			monsters.push_back(newmonster);
		}
		size_t size = memory_write(monsters, file_path);
		finded_monsters = find_by_name("a", file_path);
		finish = clock();
		wasted_time = finish - start;
		cout << green;
		cout << wasted_time << "                " << n << "                   " << size << endl;
	}

	int m = n;
	while (wasted_time < 10000)
	{
		create_file(file_path);
		vector<monster> monsters;
		vector<string> finded_monsters;
		start = clock();
		for (int i = 0; i < n; i++)
		{
			monster newmonster = autogenerator();
			newmonster.ID = i;
			monsters.push_back(newmonster);
		}
		size_t size = memory_write(monsters, file_path);
		finded_monsters = find_by_name("a", file_path);
		finish = clock();
		wasted_time = finish - start;
		cout << wasted_time << "              " << n << "                 " << size << endl;
		n += m;
	}
	cout << endl << endl;
	
	vector<monster> monsters;
	n = 2000;
	for (int i = 0; i < n; i++)
	{
		monster newmonster = autogenerator();
		newmonster.ID = i;
		monsters.push_back(newmonster);
	}
	cout << blue + "Wait some time. Arrays are sorting now." << endl;
	vector<int> work_time;

	vector<monster> sorted_monsters = monsters;
	start = clock();
	quick_sort(sorted_monsters, 0, sorted_monsters.size() - 1, 0);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	quick_sort(sorted_monsters, 0, sorted_monsters.size() - 1, 1);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	quick_sort(sorted_monsters, 0, sorted_monsters.size() - 1, 2);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	quick_sort(sorted_monsters, 0, sorted_monsters.size() - 1, 3);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	quick_sort(sorted_monsters, 0, sorted_monsters.size() - 1, 4);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	quick_sort(sorted_monsters, 0, sorted_monsters.size() - 1, 5);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	quick_sort(sorted_monsters, 0, sorted_monsters.size() - 1, 6);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	counting_sort(sorted_monsters);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	sorted_monsters = monsters;
	start = clock();
	radix_sort(sorted_monsters);
	finish = clock();
	wasted_time = finish - start;
	work_time.push_back(wasted_time);

	cout << red + "                                 Quick sort                           " + blue + "Counting sort  " + yellow + "Radix sort" << endl;
	cout << red + "      Id   Name   Health   Strength   Chance   Type attack   Date     " << endl;
	cout << light_blue + "Time" + red + "  " << work_time[0] << "   " << work_time[1] << "     " << work_time[2] << "        " << work_time[3] << "       " << work_time[4]
		<< "         " << work_time[5] << "         " << work_time[6] << "           " + blue << work_time[7] << "           " + yellow << work_time[0] << endl;

}
