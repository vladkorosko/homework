#include"lab4.h"

void demo()
{
	cout << "Hello user.\n Now i show what this program can do." << endl;
	Tree* tree = new Tree();
	Tree* deleted_tree = new Tree();
	Binary_Tree* binary_tree = new Binary_Tree();
	Symetric_Tree* symetric_tree = new Symetric_Tree(binary_tree);
	system("pause");
	system("cls");

	cout << "Now add(3 task) '1' to tree and show you information(7 task)." << endl;
	tree->add_new_interactive(1, nullptr);
	tree->print(tree->root);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Now add(3 task) '2' and '3' to tree first node('1') and show you information(7 task)." << endl;
	tree->add_new_interactive(2, tree->root);
	tree->add_new_interactive(3, tree->root);
	tree->print(tree->root);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Now add(3 task) '4' and '5' to tree node('1->2'), '6' to node('1') and show you information(7 task)." << endl;
	tree->add_new_interactive(4, tree->root->next[0]);
	tree->add_new_interactive(5, tree->root->next[0]);
	tree->add_new_interactive(6, tree->root);
	tree->print(tree->root);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Now delete(14 task) tree with root 2 and show you information(7 task)." << endl;
	deleted_tree = tree->remove(2, tree->root);
	cout << "This tree: ";
	tree->print(tree->root);
	cout << endl;
	cout << "This deleted tree: ";
	deleted_tree->print(deleted_tree->root);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Now delete(14 task) tree with root 10 and show you information(7 task)." << endl;
	deleted_tree = tree->remove(10, tree->root);
	tree->print(tree->root);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Now i add next elements to binary tree(task 18): 5,3,7,2,4,9,4." << endl;
	binary_tree->add(5, binary_tree->root);
	binary_tree->add(3, binary_tree->root);
	binary_tree->add(7, binary_tree->root);
	binary_tree->add(2, binary_tree->root);
	binary_tree->add(4, binary_tree->root);
	binary_tree->add(9, binary_tree->root);
	binary_tree->add(4, binary_tree->root);
	cout << "Added success." << endl;
	system("pause");
	system("cls");

	cout << "This is information in binary tree(task 18)." << endl;
	binary_tree->print(binary_tree->root);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Now I create Symetric tree from binary tree and show information(in order)(task 18)." << endl;
	symetric_tree->create(binary_tree);
	symetric_tree->symetric_write(symetric_tree->root);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Thank you for using. Goodbye." << endl;
	system("pause");
}
