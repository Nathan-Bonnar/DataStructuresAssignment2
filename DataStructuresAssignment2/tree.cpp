//Nathan Bonnar - PROG72370 - Assignment 02
#include"tree.h"
//creating a function to traverse the tree in order 
void traverse(PNODE root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		traverse(root->left);
		printf("%s\n", root->data);
		traverse(root->right);
		return;
	}
}
//creating a function to add a node to the tree `
void addtotree(PNODE* root)
{
	char data[MAXSTRINGSIZE];
	strncpy(data, generatedata(), MAXSTRINGSIZE);
	PNODE funcroot = *root;
	PNODE newnode = (PNODE)malloc(sizeof(node));
	strncpy(newnode->data, data, MAXSTRINGSIZE);
	//if the tree is empty then make the root node
	if (funcroot == NULL)
	{
		funcroot = newnode;
		funcroot->left = NULL;
		funcroot->right = NULL;
		*root = funcroot;
		return;
	}
	//while the root isnt empty scope into the tree
	while (funcroot != NULL)
	{
		//if the new data is less then the data that is in the root move to the left of the tree
		if (strncmp(newnode->data, funcroot->data, MAXSTRINGSIZE) <= 0)
		{
			if (funcroot->left == NULL)
			{
				funcroot->left = newnode;
				funcroot->left->left = NULL;
				funcroot->left->right = NULL;
				return;
			}
			else
			{
				funcroot = funcroot->left;
			}
		}
		//if the new data is bigger then the data that is in the root move to the right
		else if (strncmp(newnode->data, funcroot->data, MAXSTRINGSIZE) >= 0)
		{
			if (funcroot->right == NULL)
			{
				funcroot->right = newnode;
				funcroot->right->left = NULL;
				funcroot->right->right = NULL;
				return;
			}
			else
			{
				funcroot = funcroot->right;
			}

		}

	}

	return;
}
//created a search function to find a node as per the requirements
PNODE search(char * target, PNODE* root)
{
	PNODE funcroot = *root;
	while (funcroot != NULL)
	{
		if (strncmp(target, funcroot->data, MAXSTRINGSIZE) <= 0) //funcroot->data >= target
		{
			if ((strncmp(target, funcroot->data, MAXSTRINGSIZE) == 0))
			{
				return funcroot;
			}
			else
			{
				funcroot = funcroot->left;
			}
		}
		else if (strncmp(target, funcroot->data, MAXSTRINGSIZE) >= 0)
		{
			if (strncmp(target, funcroot->data, MAXSTRINGSIZE) == 0)
			{
				return funcroot;
			}
			else
			{
				funcroot = funcroot->right;
			}

		}

	}

	return NULL;
}
//created a count function to count the nodes of the tree as per the function
int count(PNODE root)
{
	if (root == NULL)
	{
		return 1;
	}
	else
	{
		int amount = 0;
		amount += count(root->left);
		amount += count(root->right);
		return amount;
	}
}
//created a function to count the heigt of the tree as per the function
int Height(PNODE root)
{
	if (root == NULL)
	{
		return 1;
	}
	else
	{
		int left = 0;
		int right = 0;
		left += count(root->left);
		right += count(root->right);
		if (left >= right)
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//creating a function to free the nodes created 
void freenode(PNODE * root)
{
	PNODE funcroot = *root;

	if (funcroot == NULL)
	{
		return;
	}
	else if (funcroot->left == NULL && funcroot->right == NULL)
	{
		std::cout << "freeing node with data: " << funcroot->data << std::endl;
		free(funcroot);
		return;
	}
	else
	{
		freenode(&funcroot->left);
		freenode(&funcroot->right);
		std::cout << "freeing node with data: " << funcroot->data << std::endl;
		free(funcroot);
	}

}