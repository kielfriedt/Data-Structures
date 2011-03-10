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
 
 vertex:
	Contains the classes name, a pointer to a linear linked list of nodes and a next pointer.
 node:
	Contains the prerequisite classes name and a pointer to the next node.
 Graph:
	Sets Head and Tail to NULL;
 ~Graph:
	Travels the vertex nodes one by one
	Deallocates the linear link list of nodes.
	Deallocates the vertexes class.
 AddVert:
	Recieves a class.
	Creates a new class a the tail pointer.
	Allocates the classes name.
	Sets tail to the tails new class.
	Sets tails next to NULL.
 AddEdge:
	Recieves a class and a prerequisite class.
	Traverses the list of vertices until it matches the class recieved or until NULL.
	Creates a temp node then allocates the prerequisite class.
	Sets temp next to the head of the list.
	Sets head to temp.
 RemoveVert:
	Recieves a class.
	Traverses the list of vertices until it matches the class recieved or until NULL.
	If found it sets a temp pointer to the current vertex
	Traverses the linear linked list of nodes.
	Deallocates each node.
	Deallocates the class.
	Sets the previous classes next to the current classes next pointer.
 RemoveEdge:
	Recieves a class and a prerequisite class.
	Traverses the list of vertices until it matches the class recieved or until NULL.
	If found it sets a temp pointer to the current vertex
	Traverses the linear linked list of nodes.
	Deallocates the node.
	Sets the previous nodes next to the currents next pointer.
 Display:
	Traverses the list of vertices
	Prints out vertex
	Traverses the list of nodes on the current vertex.
	Displays each prerequisite class
 ***********************************************************/

#include <iostream>
#include "Graph.h"
using namespace std;

//prototypes
void signoff();
void welcome();

/************************************************************
 // Function Name: Main
 // Parameters: none
 // Description: Displays main menu and passes data through 
 // to data structure. 
 ************************************************************/

int main()
{
	Graph g;
	char tempname[256];
	char * sendclass;
	char * preclass;
	bool quit = false;
	int answer = 0;
	welcome();
	while(quit != true)
	{
		cout << "1) Adding class\n"
		<< "2) Adding prerequisite class\n"
		<< "3) Removing class\n"
		<< "4) Removing prerequisite class\n"
		<< "5) Display Graph\n"
		<< "6) Quit\n";
		cin >> answer;
		cin.ignore();
		switch(answer)
		{
			case 1:
				cout << "What is the class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.AddVert(sendclass) == 1)
					cout << "You have successfully added that class\n";
				else
					cout << "We were unable to add that class\n";
				break;
			case 2:
				cout << "What is the prerequisite class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				preclass = new char[strlen(tempname) + 1];
				strcpy(preclass,tempname);
				cout << "What is the class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.AddEdge(sendclass,preclass) == 1)
					cout << "You have successfully added that prerequisite class\n";
				else
					cout << "We were unable to add that prerequisite class\n";
				break;
			case 3:
				cout << "What class you would like to remove?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.RemoveVert(sendclass) == 1)
					cout << "You have successfully removed that class\n";
				else
					cout << "We were unable to remove that class\n";
				break;
			case 4:
				cout << "What prerequisite class you would like to remove?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				preclass = new char[strlen(tempname) + 1];
				strcpy(preclass,tempname);
				cout << "What is the class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.RemoveEdge(sendclass,preclass) == 1)
					cout << "You have successfully removed that prerequisite class\n";
				else
					cout << "We were unable to remove that prerequisite class\n";
				break;
			case 5:
				g.Display();
				break;
			case 6:
				quit = true;
				break;
			default:
				cout << "please enter in a valid option\n";
				break;
		}
	}
	signoff();
	return 0;
}

/************************************************************
 // Function Name: signoff
 // Parameters: none
 // Description: sign off message
 ************************************************************/

void signoff()
{
	cout << "Thank you for using this program!\n";
}

/************************************************************
 // Function Name: welcome
 // Parameters: none
 // Description: welcome message
 ************************************************************/

void welcome()
{
	cout << "Welcome\n";
}

