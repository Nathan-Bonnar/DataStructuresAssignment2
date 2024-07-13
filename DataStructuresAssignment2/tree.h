//Nathan Bonnar - PROG72370 - Assignment 02
#pragma once
#include"Data.h"
typedef struct node
{
	char data[MAXSTRINGSIZE];
	node* left;
	node* right;
}NODE, * PNODE;

void addtotree(PNODE* root);
void traverse(PNODE root);
PNODE search(char * target, PNODE* root);
int count(PNODE root);
int Height(PNODE root);
void freenode(PNODE* root);