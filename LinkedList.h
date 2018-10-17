//Author: Benoit Coville
//email : covillebenoit@gmail.com
//Student number : c3316165
//Course: SENG1120
#ifndef LINKED_LIST_H
#define LINKED_LIST_H value

#include "Student.h"
#include "Node.h"

class LinkedList
{
private:
  Node* head;
  Node* tail;
  Node* current;
  int size; //Number of node stored in the list

public:
  typedef Node::value_type value_type;

  LinkedList ();
  virtual ~LinkedList ();

  Node* get_head()const;
  int get_size()const;


  bool isEmpty()const;
  //Pre condition : none
  //Post condition : Return True if there is no Node in the linked list
  //                 otherwise return false

  void addToTail(const value_type& entry);
  //Pre condition : constant reference of the "data type" contained in the Node
  //Post condition : A node is created with the data oject provided and add at
  //                 the end of the the list
  void operator += (const LinkedList& l2);
  //Pre condition : A list
  //Post condition : concatenate the two lists

  void remove(std::string name);
  //Pre condition : the name of a student as a string
  //Post condition : seek all the students whose name are the input string
  //                 Then call remove_target for each node found passing a
  //                 pointeur to the node as parameter

  bool remove_target(Node* target);
  //Pre condition : pointeur to the node to remove
  //Post condition : delete the node moving the required pointeurs and freeing
  //                 the allocated memory

  double calcAverage();
  //Pre condition : The list has to be not empty
  //Post condition : return the average of the marksof all students in the list

  int count(std::string name);
  //Pre condition : Student name
  //Post condition : Return the number of student whose name is the input string

  void order();
  void swapNodes(Node* v1, Node* v2);
  //Pre condition : v2 must be just after v1
  //Post condition :
  void display_debug();
  void display_pointer_node(Node* pt);


};

ostream& operator<<(ostream& out, const LinkedList& list);

#endif