#include "sixteenth_task.h"

void demonstrative_mode()
{
	cout << blue + "Hello user." << endl;
	cout << "Now i show you what i can do." << endl;
	Sys_pause();
	List_of_message messages;

	cout << blue + "Now i add new message. " << endl;
	Message new_message;
	new_message.appearence_time.create_date();
	new_message.text = "Hello world";
	cout << blue + "The message is:" << endl;
	new_message.print_message();
	messages.add_new_message(new_message);
	Sys_pause();

	cout << blue + "This information in our list of message." << endl;
	messages.print_list();
	Sys_pause();

	cout << blue + "Now i add 9 new messages. " << endl;
	Message First_message;
	First_message.appearence_time.create_date();
	First_message.text = "First_message";
	cout << blue + "The message is:" << endl;
	First_message.print_message();
	messages.add_new_message(First_message);
	Sys_pause();

	Message Second_message;
	Second_message.appearence_time.create_date();
	Second_message.text = "Second message";
	cout << blue + "The message is:" << endl;
	Second_message.print_message();
	messages.add_new_message(Second_message);
	Sys_pause();

	Message Third_message;
	Third_message.appearence_time.create_date();
	Third_message.text = "Third message";
	cout << blue + "The message is:" << endl;
	Third_message.print_message();
	messages.add_new_message(Third_message);
	Sys_pause();

	Message Forth_message;
	Forth_message.appearence_time.create_date();
	Forth_message.text = "Forth message";
	cout << blue + "The message is:" << endl;
	Forth_message.print_message();
	messages.add_new_message(Forth_message);
	Sys_pause();

	Message Fifth_message;
	Fifth_message.appearence_time.create_date();
	Fifth_message.text = "Fifth message";
	cout << blue + "The message is:" << endl;
	Fifth_message.print_message();
	messages.add_new_message(Fifth_message);
	Sys_pause();

	Message Sixth_message;
	Sixth_message.appearence_time.create_date();
	Sixth_message.text = "Sixth message";
	cout << blue + "The message is:" << endl;
	Sixth_message.print_message();
	messages.add_new_message(Sixth_message);
	Sys_pause();

	Message Seventh_message;
	Seventh_message.appearence_time.create_date();
	Seventh_message.text = "Seventh message";
	cout << blue + "The message is:" << endl;
	Seventh_message.print_message();
	messages.add_new_message(Seventh_message);
	Sys_pause();

	Message Eighth_message; 
	Eighth_message.appearence_time.create_date();
	Eighth_message.text = "Eighth message";
	cout << blue + "The message is:" << endl;
	Eighth_message.print_message();
	messages.add_new_message(Eighth_message);
	Sys_pause();

	Message Ninth_message;
	Ninth_message.appearence_time.create_date();
	Ninth_message.text = "Ninth message";
	cout << blue + "The message is:" << endl;
	Ninth_message.print_message();
	messages.add_new_message(Ninth_message);
	Sys_pause();

	cout << blue + "This information in our list of message." << endl;
	messages.print_list();
	Sys_pause();

	cout << blue + "Now the length is" + red + " 10 " + blue + "and max length is " + red + "10 "
		+ blue + "too. So if I now" + red + " add " + blue + "new message " + red + "the latest will be delete." << endl;
	cout << blue + "Now i add next message." << endl;

	Message Last_message;
	Last_message.appearence_time.create_date();
	Last_message.text = "This message will be first. The message" + green + " 'Hello world' " + red + "was deleted.";
	cout << blue + "The message is:" << endl;
	Last_message.print_message();
	messages.add_new_message(Last_message);
	Sys_pause();

	cout << blue + "This information in our list of message." << endl;
	messages.print_list();
	Sys_pause();

	cout << blue + "Now i use the function that show some messages from list. Now i show 15 messages(max length is 10)." << endl;
	Sys_pause();
	messages.print_first_k_messages(15);
	Sys_pause();

	cout << blue + "Now i show 7 messages(max length is 10)." << endl;
	Sys_pause();
	messages.print_first_k_messages(7);
	Sys_pause();

	cout << blue + "Now i show 10 messages(max length is 10)." << endl;
	Sys_pause();
	messages.print_first_k_messages(10);
	Sys_pause();

	cout << blue + "Thank you for using." << endl;
	Sys_pause();
}