#include "Background.h"

void demo()
{
	cout << blue + "Hello user. Now i show you what i can do." << endl;
	cout << "Firstly I create " + red + "6" + blue + " lists of " + red + "10" + blue + " words." << endl;
	vector<string> First_list = auto_generator(10);
	vector<string> Second_list = First_list, Third_list = First_list, Forth_list = First_list, Fifth_list = First_list, Sixth_list = First_list;
	isys_pause();
	cout << blue + "This is information in list." << endl;
	print_list(First_list);
	isys_pause();

	cout << blue + "Now i use bubble sort for first list." << endl;
	bubble_sort(First_list);
	isys_pause();
	cout << blue + "This is sorted information in first list" << endl;
	print_list(First_list);
	isys_pause();

	cout << blue + "Now i use insertion sort for second list." << endl;
	insertion_sort(Second_list);
	isys_pause();
	cout << blue + "This is sorted information in second list." << endl;
	print_list(Second_list);
	isys_pause();

	cout << blue + "Now i use selection sort for third list." << endl;
	selection_sort(Third_list);
	isys_pause();
	cout << blue + "This is sorted information in third list." << endl;
	print_list(Third_list);
	isys_pause();

	cout << blue + "Now i use quick(Hoare, first element) sort for forth list." << endl;
	quick_sort(Forth_list, 0, Forth_list.size() - 1);
	isys_pause();
	cout << blue + "This is sorted information in forth list." << endl;
	print_list(Forth_list);
	isys_pause();

	cout << blue + "Now i use merge(two arrays) sort for fifth list." << endl;
	merge_sort(Fifth_list, 0, Fifth_list.size() - 1);
	isys_pause();
	cout << blue + "This is sorted information in fifth list." << endl;
	print_list(Fifth_list);
	isys_pause();

	cout << blue + "Now i use insertion sort for sixth list." << endl;
	combine_sort(Sixth_list);
	isys_pause();
	cout << blue + "This is sorted information in sixth list." << endl;
	print_list(Sixth_list);
	isys_pause();

	cout << blue + "This is all. Goodbye(Good luck, have fun)." << endl;
	isys_pause();
}
