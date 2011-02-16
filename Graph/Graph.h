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

#ifndef TREES_H
#define TREES_H

/************************************************************
// Structure Name: node
// Description: Node Structure, contains a prerequisite class
// and a next pointer.
************************************************************/

struct node
{
	char * PreClassName;
	node * next;
};

/************************************************************
// Structure Name: vertex
// Description: Structure of the classes name and a pointer to 
// a array of nodes and a next pointer.
************************************************************/

struct vertex
{
	char * ClassName;
	node * nodehead;
	vertex * next;
};

/************************************************************
 // Structure Name: Graph
 // Description: Class contains all essential functions and 
 // variables for data structure.
 ************************************************************/

class Graph
	{
	public:
		Graph();
		int AddVert(char * sendclass);
		int AddEdge(char * sendclass, char * preclass);
		int RemoveVert(char * sendclass);
		int RemoveEdge(char * sendclass, char * preclass);
		void Display();
		~Graph();
		
	private:
		vertex * head;
		vertex * tail;
	};

#endif
