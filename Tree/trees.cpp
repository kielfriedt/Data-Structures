
/*
 *	Copyright (C) 2011  Kiel Friedt
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/***********************************************************
Program 4
Name: Kiel Friedt
Class: CS163/online
***********************************************************/

#include "trees.h"
#include <iostream>
using namespace std;

/************************************************************
// Function Name: constructor of hash
// Parameters: none
// Description: allocates a fix size of node pointers then 
//set each one to NULL.
************************************************************/

trees::trees()
{
	root = NULL;
}

/************************************************************
// Function Name: destuctor of hash
// Parameters: none
// Description: Runs through the fixed size node pointer array
// and deallocated each node pointers linear link list then 
// sets that pointer to NULL.
************************************************************/

trees::~trees()
{
	destroytree(root);
}

/************************************************************
// Function Name: super
// Parameters: char * subject, int choice
// Description: 
************************************************************/

int trees::super(char * subject, int choice)
{
	switch(choice)
	{
		case 1:
			if(add(root,subject) == 1)
				return 1;
			break;
		case 2:
			search(root,subject);
			return 1;
			break;
		case 3:
			if(remove(root,root,subject) == 1)
				return 1;
			break;
		default:
			return 0;
			break;
	}
}

/************************************************************
// Function Name: super
// Parameters: int choice
// Description: 
************************************************************/

void trees::super(int choice)
{
	switch(choice)
	{
		case 4:
			display(root);
			break;
	}
}

/************************************************************
// Function Name: destroytree
// Parameters: node *& current
// Description: 
************************************************************/

void trees::destroytree(node *& current)
{
	if(current != NULL)
	{
		destroytree(current->left);
		destroytree(current->right);
		delete [] current -> data.subject;
		delete current;
		current = NULL;
	}
}

/************************************************************
// Function Name: add
// Parameters: node * & current, char * subject
// Description: Finds out the key to the hash table then adds
// the word to that array index and inserts it into the index
// via a stack.
************************************************************/

int trees::add(node *& current, char * subject)
{
	if(current == NULL)
	{
		current = new node;
		current -> data.subject = new char[strlen(subject) + 1];
		strcpy(current -> data.subject,subject);
		current->right = NULL;
		current->left = NULL;
		return 1;
	}
	else if(strcmp(current->data.subject,subject) > 0)
		add(current->left,subject);
	else if(strcmp(current->data.subject,subject) < 0)
		add(current->right,subject);
}

/************************************************************
// Function Name: remove
// Parameters: node *& current, node *& parent, char * subject
// Description:
************************************************************/

int trees::remove(node *& current, char * subject)
{
	node * temproot = NULL;
	node * currentroot = current;
	if(current)
	{
		if(strcmp(current->data.subject,subject) == 0) 
		{
			cout << "Found\n";
			if((current->left == NULL)&&(current->right == NULL))
			{
				cout << "children\n";
				if(strcmp(root->data.subject,subject) == 0)
				{
				temproot = current;
				current = NULL;
				delete [] temproot->data.subject;
				delete temproot;
				return 1;
				}
			else if((current->right == NULL)&&(current->left))
			{
				temproot = current;
				parent = parent->left;
				delete [] temproot->data.subject;
				delete temp;
				return 1;
			}
			else if((current->left == NULL)&&(current->right))
			{
				temproot = current;
				current = current->right;
				delete [] temproot->data.subject;
				delete temproot;
				return 1;
			}
			else
			{
				cout << "2 children\n";
				temproot = current;
				node * temprootleft = current->left;
				node * temprootright = current->right;
			
				tempreplace = temprootleft;
				while( !tempreplace->right)
				tempreplace = tempreplace->right;
				if(!(tempreplace->left))
				node * replacementleft = replacement->left;
				if(current == currentroot)
					current = replace->left;
				else 
				{
current = currentroot;
if(strcmp(replace->data.subject,current->data.subject) > 0)
current->left = replace;
else
current->right = replace;
}
replace->left = temprootleft;
if(temprootleft->right == temprootleft)
temprootleft->right = NULL;
if(temprootleft->left == temprootleft)
temprootleft->left = NULL;
if(!(replaceleft)
{
if(strcmp(replaceleft->data.subject,replace->data.subject) < 0)
replace->left = replaceleft;
else
replace->right = replaceleft;
}
replace->right = temprootright;
				delete [] temproot->data.subject;
				delete temproot;
				return 1;
			}
			}
			else if(strcmp(current->data.subject,subject) > 0)
				remove(current->left,current,subject);
			else if(strcmp(current->data.subject,subject) < 0)
				remove(current->right,current,subject);
		}
		return 0;
		
}

/************************************************************
// Function Name: seach
// Parameters: char * subject
// Description: 
************************************************************/

void trees::search(node * current, char * subject)
{
	if(current)
	{ 
		if(strcmp(current -> data.subject,subject) == 0) 
			cout << "found " << current -> data.subject << "\n";
		else if(strcmp(current->data.subject,subject) > 0)
			search(current->left,subject);
		else if(strcmp(root->data.subject,subject) < 0)
			search(current->right,subject);
	}
}

/************************************************************
// Function Name: display
// Parameters: none
// Description: 
************************************************************/

void trees::display(node * current)
{
	if(current)
	{
		display(current->left);
		cout << current->data.subject << "\n";
		display(current->right);
	}
}
