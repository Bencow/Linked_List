#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node
{
public:
  typedef Student value_type;
  //Constructors and destructor
  Node (const value_type& entry, Node* nxt, Node* prev);
  virtual ~Node ();

  //Accessors
  Node* get_next()const;
  void set_next(Node* entry);
  Node* get_previous()const;
  void set_previous(Node* entry);
  value_type get_data()const;


private:
  Node* next;
  Node* previous;
  value_type data;
};

#endif
