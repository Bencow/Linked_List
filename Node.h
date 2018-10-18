//Author: Benoit Coville
//email : covillebenoit@gmail.com
//Student number : c3316165
//Course: SENG1120

#ifndef NODE_H
#define NODE_H

#include "Student.h"

template <typename value_type>
class Node
{
public:
  //Constructors and destructor
  Node (const value_type& entry, Node<value_type>* nxt, Node<value_type>* prev);
  Node (const value_type& entry);
  virtual ~Node ();

  //Accessors
  Node* get_next()const;
  void set_next(Node<value_type>* entry);
  Node* get_previous()const;
  void set_previous(Node<value_type>* entry);
  value_type get_data()const;


private:
  Node<value_type>* m_next;
  Node<value_type>* m_previous;
  value_type m_data;
};

#include "Node.hpp"
#endif
