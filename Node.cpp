#include "Node.h"

Node::Node(const value_type& entry, Node* nxt, Node* prev) :
  next(nxt), previous(prev), data(entry)
{}
Node::~Node()
{}


//Accessors
Node* Node::get_next()const
{ return next; }
void Node::set_next(Node* entry)
{ next = entry; }
Node* Node::get_previous()const
{ return previous; }
void Node::set_previous(Node* entry)
{ previous = entry; }
Node::value_type Node::get_data()const
{ return data; }
