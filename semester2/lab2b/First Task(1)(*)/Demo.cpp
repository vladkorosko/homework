#include "lab2b.1.h"

void demonstrative_mode()
{
	cout << blue + "Hello user." << endl;
	cout << "Now i show you what i can do." << endl;
	Sys_pause();
	array_list Array_list;
	vector_list Vector_list;
	Linked_list linked_list;

	cout << blue + "Now i create empty list." << endl;
	Array_list.create_empty();
	Vector_list.create_empty();
	linked_list.create_empty();
	Sys_pause();

	cout << blue + "Now i show you length and information in array list." << endl;
	cout << green + "Length is " << Array_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in vector list." << endl;
	cout << green + "Length is " << Vector_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in linked list." << endl;
	cout << green + "Length is " << linked_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	IP our_IP;
	our_IP.ipv4 = "126.167.001.255";
	cout << blue + "Now i append IPv4 = 126.167.001.255." << endl;
	Array_list.append(our_IP);
	Vector_list.append(our_IP);
	linked_list.append(our_IP);
	Sys_pause();

	cout << blue + "Now i show you length and information in array list." << endl;
	cout << green + "Length is " << Array_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in vector list." << endl;
	cout << green + "Length is " << Vector_list.length() << "." << endl;
	Vector_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in linked list." << endl;
	cout << green + "Length is " << linked_list.length() << "." << endl;
	linked_list.Print_list();
	Sys_pause();

	IP Our_IP;
	Our_IP.ipv4 = "100.200.101.215";
	cout << blue + "Now i insert IPv4 = 100.200.101.215 before element with index 0." << endl;
	Array_list.insert(0, Our_IP);
	Vector_list.insert(0, Our_IP);
	linked_list.insert(0, Our_IP);
	Sys_pause();

	cout << blue + "Now i show you length and information in array list." << endl;
	cout << green + "Length is " << Array_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in vector list." << endl;
	cout << green + "Length is " << Vector_list.length() << "." << endl;
	Vector_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in linked list." << endl;
	cout << green + "Length is " << linked_list.length() << "." << endl;
	linked_list.Print_list();
	Sys_pause();

	cout << blue + "Now i get element with index -1 from array list." << endl;
	cout << green << Array_list.get(-1).ipv4 << endl;
	Sys_pause();

	cout << blue + "Now i get element with index -1 from vector list." << endl;
	cout << green << Vector_list.get(-1).ipv4 << endl;
	Sys_pause();

	cout << blue + "Now i get element with index -1 from linked list." << endl;
	cout << green << linked_list.get(-1).ipv4 << endl;
	Sys_pause();

	Our_IP.ipv4 = "101.102.123.129";
	cout << blue + "Now i set element with index -1 from array list as 101.102.123.129." << endl;
	Array_list.set(-1, Our_IP);
	Vector_list.set(-1, Our_IP);
	linked_list.set(-1, Our_IP);
	Sys_pause();

	cout << blue + "Now i show you length and information in array list." << endl;
	cout << green + "Length is " << Array_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in vector list." << endl;
	cout << green + "Length is " << Vector_list.length() << "." << endl;
	Vector_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in linked list." << endl;
	cout << green + "Length is " << linked_list.length() << "." << endl;
	linked_list.Print_list();
	Sys_pause();

	cout << blue + "Now i delete element with index -1." << endl;
	Array_list.remove(-1);
	Vector_list.remove(-1);
	linked_list.remove(-1);
	Sys_pause();

	cout << blue + "Now i show you length and information in array list." << endl;
	cout << green + "Length is " << Array_list.length() << "." << endl;
	Array_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in vector list." << endl;
	cout << green + "Length is " << Vector_list.length() << "." << endl;
	Vector_list.Print_list();
	Sys_pause();

	cout << blue + "Now i show you length and information in linked list." << endl;
	cout << green + "Length is " << linked_list.length() << "." << endl;
	linked_list.Print_list();
	Sys_pause();

	cout << blue + "Thank you for using." << endl;
	Sys_pause();
}