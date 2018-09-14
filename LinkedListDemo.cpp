//LinkedListDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of a linked list that stores student names and scores.
//It will demo the functions of a basic linked list.
//The program adds content to a linked list, removes individual nodes, among other functionalities.

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Student.h"
#include "Node.h"
using namespace std;

void initialize(LinkedList &l1, LinkedList &l2)
{
    Student c("Alex", 15);
    l1.addToTail(c);
    c.set_name("Peter"); c.set_score(10);
    l1.addToTail(c);
	c.set_name("John"); c.set_score(32);
    l1.addToTail(c);
    c.set_name("Mary"); c.set_score(50);
    l1.addToTail(c);
	c.set_name("Carol"); c.set_score(31);
    l1.addToTail(c);

	c.set_name("Michelle"); c.set_score(12);
    l2.addToTail(c);
    c.set_name("Carol"); c.set_score(27);
    l2.addToTail(c);
	c.set_name("Tim"); c.set_score(20);
    l2.addToTail(c);
	c.set_name("Michelle"); c.set_score(90);
    l2.addToTail(c);
	c.set_name("John"); c.set_score(75);
    l2.addToTail(c);
	c.set_name("Tony"); c.set_score(60);
    l2.addToTail(c);
}

int main()
{
    LinkedList firstList;
	LinkedList secondList;

	initialize(firstList, secondList);

	cout << "Start lists:" << endl;
	cout << "List 1: " << firstList  <<  endl;
	cout << "List 2: " << secondList <<  endl << endl;

	cout << "Concatenating the two lists onto list '1':" << endl;
	firstList += secondList;
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Removing student 'Alex' from list '1':" << endl;
  //cout << "size " << firstList.get_size() << endl;
    firstList.remove("Alex");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Removing student 'John' from list '2':" << endl;
    secondList.remove("John");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Removing student 'Michelle' from both lists:" << endl;
    firstList.remove("Michelle");
    secondList.remove("Michelle");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Removing student 'Fred' from list '2':" << endl;
    secondList.remove("Fred");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Average of list '1': ";
	cout << firstList.calcAverage() << endl;

	cout << "Average of list '2': ";
	cout << secondList.calcAverage() << endl << endl;

	cout << "Number of students named 'Carol': ";
	cout << (firstList.count("Carol") + secondList.count("Carol")) << endl << endl;

  //firstList.display_debug();

	cout << "Ordered lists: " << endl;
	firstList.order();
	//secondList.order();
	cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "The program has finished." << endl;
	return 0;
}
