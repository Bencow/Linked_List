#include "Node.h"

Node::Node(const value_type& entry, Node* nxt, Node* prev) :
  m_next(nxt), m_previous(prev), m_data(entry)
{}
Node::Node (const value_type& entry) :
  m_next(NULL), m_previous(NULL), m_data(entry)
{}

Node::~Node()
{}


//Accessors
Node* Node::get_next()const { return m_next; }
void Node::set_next(Node* entry) { m_next = entry; }
Node* Node::get_previous()const { return m_previous; }
void Node::set_previous(Node* entry) { m_previous = entry; }
Node::value_type Node::get_data()const { return m_data; }
