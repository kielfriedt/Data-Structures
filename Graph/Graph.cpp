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
 Program 5
 Name: Kiel Friedt
 Class: CS163/online
 ***********************************************************/

#include "Graph.h"
#include <iostream>
using namespace std;

/************************************************************
// Function Name: constructor of Graph
// Parameters: none
// Description: Sets the head and tail to NULL.
************************************************************/

Graph::Graph()
{
	head = 0;
	tail = 0;
}

/************************************************************
// Function Name: AddVert
// Parameters: char * sendclass
// Description: Creates a new tail node and allocates the 
// classes name. Sets the Tail to the new tails node and sets
// tails next to NULL.
************************************************************/

int Graph::AddVert(char * sendclass)
{
	if(!head)
	{
		head = new vertex;
		head->ClassName = new char[strlen(sendclass)+1];
		strcpy(head->ClassName,sendclass);
		head->nodehead = 0;
		head->next=0;
		tail = head;
		return 1;
	}
	else
	{
		tail->next = new vertex;
		tail = tail->next;
		tail->ClassName = new char[strlen(sendclass)+1];
		strcpy(tail->ClassName,sendclass);
		tail->nodehead =0;
		tail->next = 0;
		return 1;
	}
	return 0;
}

/************************************************************
// Function Name: AddEdge
// Parameters: char * sendclass, char * preclass
// Description: Traverses the list of classes until it matches
// the recieved class or hits NULL. If its found it creates a 
// temperary node and allocates the prerequisite classes name.
// Then sets the temperarys next to the current head of the 
// list. Then sets head to the temperary node.
************************************************************/

int Graph::AddEdge(char * sendclass, char * preclass)
{
	vertex * temp;
	node * tempnode;
	temp = head;
	while(temp)
	{
		if(strcmp(temp->ClassName, sendclass) == 0)
		{
			tempnode = new node;
			tempnode-> PreClassName = new char[strlen(preclass)+1];
			strcpy(tempnode->PreClassName,preclass);
			tempnode ->next = temp->nodehead;
			temp->nodehead = tempnode;
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

/************************************************************
// Function Name: RemoveVert
// Parameters: char * sendclass
// Description: Traverses the list of classes until it finds 
// it or NULL. If its found it traverses the list of nodes 
// and deallocates each node. Then deallocates the class and
// sets the previous next pointer to the current classes pointer.
************************************************************/

int Graph::RemoveVert(char * sendclass)
{
	vertex * currentvert;
	vertex * previousvert;
	node * tempnode;
	node * temp;
	currentvert = head;
	if(currentvert)
	{
		if(strcmp(currentvert->ClassName,sendclass) == 0)
		{
			cout << "found it at head\n";
			head = head->next;
			tempnode = currentvert->nodehead;
			while(tempnode)
			{
				temp = tempnode;
				tempnode = tempnode->next;
				delete [] temp->PreClassName;
				delete temp;
			}
			delete [] currentvert->ClassName;
			delete currentvert;
			return 1;
		}
		else
		{
			previousvert = currentvert;
			currentvert = currentvert->next;
			while((currentvert)&&(strcmp(currentvert->ClassName,sendclass) != 0))
			{
				previousvert = currentvert;
				currentvert = currentvert->next;
			}
			if(currentvert)
			{
				if(strcmp(currentvert->ClassName,tail->ClassName) == 0)
					tail = previousvert;
				previousvert->next = currentvert->next;
				tempnode = currentvert->nodehead;
				while(tempnode)
				{
					temp = tempnode;
					tempnode = tempnode->next;
					delete [] temp->PreClassName;
					delete temp;
				}
				delete [] currentvert->ClassName;
				delete currentvert;
				return 1;
			}
		}
	}
}

/************************************************************
// Function Name: RemoveEdge
// Parameters: char * sendclass, char * preclass
// Description: Traverses the class until it matches the 
// recieved class or until NULL. If found it tarveres the list
// of nodes until it finds a match or NULL. Deallocates the 
// nodes prerequisite class. Sets the previous nodes pointer
// to the currents next pointer.
************************************************************/

int Graph::RemoveEdge(char * sendclass, char * preclass)
{	
	vertex * temp;
	node * currentnode;
	node * previousnode;
	node * tempnode;
	temp = head;
	while((temp)&&(strcmp(temp->ClassName,sendclass) != 0))
		temp = temp -> next;
	if(temp)
	{
		currentnode = temp->nodehead;
		previousnode = currentnode;
		while((currentnode)&&(strcmp(currentnode->PreClassName, preclass) != 0))
			{
				previousnode = currentnode;
				currentnode = currentnode -> next;
			}
			if(currentnode)
			{
				previousnode->next = currentnode->next;
				delete [] currentnode->PreClassName;
				delete currentnode;
				return 1;
			}

	}
}

/************************************************************
// Function Name: Display
// Parameters: none
// Description: Traveres the list of classes, then tarverses
// the the list of nodes. Displays the class then each 
// prerequisite class.
************************************************************/

void Graph::Display()
{	
	vertex * temp = 0;
	node * tempnode = 0;
	temp = head;
	while(temp)
	{	
		cout << temp->ClassName << ":\n";
		tempnode = temp->nodehead;
		while(tempnode)
		{
			cout << tempnode->PreClassName << "\n";
			tempnode = tempnode->next;
		}
		cout << "\n";
		temp = temp->next;
	}
}

/************************************************************
// Function Name: Destructor of Graph
// Parameters: none
// Description: Traveres the list of classes, then tarverses
// the the list of nodes. Deallocates each node until NULL,
// then dealloctes the class and sets the head to the next class.
************************************************************/

Graph::~Graph()
{
	vertex * tempvert;
	node * tempnode;
	node * temp;
	while(head)
	{
		tempvert = head;
		head = head->next;
		tempnode = tempvert->nodehead;
		while(tempnode)
		{
			temp = tempnode;
			tempnode = tempnode->next;
			delete [] temp->PreClassName;
			delete temp;
		}
		delete [] tempvert->ClassName;
		delete tempvert;
	}
}
