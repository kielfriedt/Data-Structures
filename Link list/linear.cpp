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
#include <iostream>
#include "linear.h"
using namespace std;

#ifndef LIST_H
#define LIST_H
list::list()
{
	head = 0;
}

int list::add(char * name)
{
	node * temp;
	cout << name;
	if(!head)
	{
		
		head = new node;
		head->name = new char[strlen(name)+1];
		head->next = 0;
		cout << head->name;
		return 1;
	}
	else
	{
		
	temp = new node;
	temp->name = new char[strlen(name)+1];
	temp->next = head;
		cout << temp->name;
	head = temp;
		cout <<head->name;
		return 1;
	}
}

void list::display()
{
	node * temp;
	temp = head;
	while(temp)
	{	
		cout << "display\n";
	cout << temp->name << "temp->name\n";
	temp = temp->next;
	}
}

list::~list()
{
	node * temp;
	while(head)
	{
		temp = head;
		++head;
		delete [] temp->name;
		delete temp;
	}
}

#endif