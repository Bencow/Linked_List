//Author: Benoit Coville
//email : covillebenoit@gmail.com
//Student number : c3316165
//Course: SENG1120

#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node
{
public:
  typedef Student value_type;
  //Constructors and destructor
  Node (const value_type& entry, Node* nxt, Node* prev);
  Node (const value_type& entry);
  virtual ~Node ();

  //Accessors
  Node* get_next()const;
  void set_next(Node* entry);
  Node* get_previous()const;
  void set_previous(Node* entry);
  value_type get_data()const;


private:
  Node* m_next;
  Node* m_previous;
  value_type m_data;
};

#endif
