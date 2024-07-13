//Nathan Bonnar - PROG72370 - Assignment 02
#include"tree.h"
#include<time.h>
int main()
{
	//seeding random so we get a different result each run of the program
	srand(time(NULL));
	PNODE root = NULL;
	//adding 10 nodes to the tree
	for (int i = 0; i < 10; i++)
	{
		addtotree(&root);
	}
	printf("PRINTING IN ALPHA ORDER\n");
	//traversing and printing the tree
	traverse(root);
	//finding the amount of nodes on the tree
	int amount = count(root) - 1;
	std::cout << "amount of nodes " << amount << std::endl;
	//finding the height of the tree
	int HeightofTree = Height(root);
	std::cout << "height of the tree is:  " << HeightofTree << std::endl;
	//freeing the nodes of the tree that was created
	freenode(&root);
	return 0;
}