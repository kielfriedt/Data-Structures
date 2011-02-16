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

#ifndef TREES_H
#define TREES_H

/************************************************************
// Structure Name: nodecontent
// Description: contains the subject of each picture for each
// node.
************************************************************/

struct nodecontent
{
	char * subject;
};

/************************************************************
// Structure Name: node
// Description: contains platform and left and right pointer.
************************************************************/

struct node
{
	nodecontent data;
	node * left;
	node * right;
};

/************************************************************
// Structure Name: trees
// Description: Class contains all essential functions and 
// variables for data structure.
************************************************************/

class trees
{
public:
	trees();
	int super(char * subject, int choice);
	void super(int choice);
	int add(node *& current, char * subject);
	int remove(node *& current, char * subject);
	void search(node * current, char * subject);
	void destroytree(node *& current);
	void display(node * current);
	~trees();
	
private:
	node * root;
};

#endif
