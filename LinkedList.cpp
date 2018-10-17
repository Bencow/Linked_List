//Author: Benoit Coville
//email : covillebenoit@gmail.com
//Student number : c3316165
//Course: SENG1120

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(NULL), tail(NULL), current(NULL), size(0)
{}

LinkedList::~LinkedList()
{
  if(size == 1)
  {
    delete head;
  }
  else if(size > 1)
  {
    current = head;
    //Scan the entire list
    while(current->get_next() != NULL)
    {
      //Go forward
      current = current->get_next();
      //delete the previous
      delete current->get_previous();
    }
    //delete the last one
    delete tail;
  }
}

Node* LinkedList::get_head()const
{ return head; }

int LinkedList::get_size()const
{ return size; }

bool LinkedList::isEmpty()const
{
  //To make sure all is well implemented I triple-check
  if(size == 0 && head == NULL && tail == NULL )
    return true;
  else
    return false;
}

void LinkedList::addToTail(const value_type& entry)
{
  //create a new node
  Node* nd = new Node(entry, head, tail);

  //if the list is empty
  if(isEmpty())
  {
    head = nd;
    tail = nd;
    size++;
  }
  else
  {
    //assign current to the last object of the list
    current = tail;

    tail = nd;
    current->set_next(nd);
    nd->set_previous(current);
    nd->set_next(NULL);
    size++;
    }
}

void LinkedList::operator +=(const LinkedList& l2)
{
  Node* current = l2.get_head();//how to do that without public get_head ??
  while(current != NULL)
  {
    addToTail(current->get_data());
    current = current->get_next();
  }
}

void LinkedList::remove(std::string name)
{
  bool found = false;
  Node* temp;
  current = head;
  while (current != NULL)
  {
    temp = current->get_next();
	if(name == current->get_data().get_name())
    {
		found = remove_target(current);
    }
	current = temp;
  }
  if(!found)
    cout << "There's no student called " << name << " in this list" << endl;
}

bool LinkedList::remove_target(Node* target)
{
  if(isEmpty())
  {
      cout << "error, you try to remove a node from an empty list" << endl;
      return false;
  }
  else if(size == 1)
  {
    delete target;
    head = NULL;
    tail = NULL;
    size--;
    return true;
  }
  else //size > 1
  {
    if(target == head)
    {
      head->get_next()->set_previous(NULL);
      head = head->get_next();
    }
    else if(target == tail)
    {
      tail = target->get_previous();
      target->get_previous()->set_next(NULL);
    }
    else//Global case : in the middle
    {
      target->get_next()->set_previous( target->get_previous() );
      target->get_previous()->set_next( target->get_next() );
    }
    //Remove the node at the and in all cases when there's more than 1 node
    delete target;

    //target = NULL;
    size--;
    return true;
  }
}


//Note : i got an error before, the compiler wanted this method to be constant
//       and i didn't undertsand why, and don't understand why is it working now
double LinkedList::calcAverage()
{
  double sum = 0;
  current = head;

  if(!isEmpty())
  {
    while(current != NULL)
    {
      sum += current->get_data().get_score();
      current = current->get_next();
    }
    return sum/size;
  }
  else
  {
    cout << "error, you try to calulate the average of an empty list" << endl;
    return -1;
  }
}

int LinkedList::count(std::string name)
{
  int occurence = 0;
  current = head;
  while (current != NULL)
  {
    if(name == current->get_data().get_name())
    {
      occurence ++;
    }
    current = current->get_next();
  }
  return occurence;
}

void LinkedList::swapNodes(Node* v1, Node* v2)//note : v1 is before v2
{
  if(v1 != head)
  {
    v1->get_previous()->set_next(v2);
  }
  else//v1 is the head
  {
    head = v2;
  }
  if(v2 != tail )
  {
    v2->get_next()->set_previous(v1);
  }
  else//v2 is the tail
  {
    tail = v1;
  }

  Node *prev = v1->get_previous();
  Node *next = v2->get_next();

  v1->set_next(next);
  v1->set_previous(v2);

  v2->set_previous(prev);
  v2->set_next(v1);
}

void LinkedList::order()
{
  for(int i = 0 ; i < size ; ++i)
  {
    current = head;

    while(current != tail)
    {
      //if the current node is higher than the next one
      if(current->get_data().get_name() > current->get_next()->get_data().get_name())
      {
        //Swap the two nodes
        swapNodes(current, current->get_next());
      }
      else
      {
        current = current->get_next();
      }
      //display_debug();
      //Go to the next
    }
  }
}

void LinkedList::display_debug()
{
  Node *current_ = head;
  while(current_ != NULL)
  {
    display_pointer_node(current_->get_previous());
    display_pointer_node(current_);
    display_pointer_node(current_->get_next());
    std::cout << std::endl;
    current_ = current_->get_next();
  }
}

void LinkedList::display_pointer_node(Node* pt)
{
  if(pt == NULL)
  {
    std::cout << "(NULL)";
  }
  else
  {
    std::cout << "(" << pt->get_data().get_name() << ")";
  }
}

/*
void LinkedList::order1()
{
  Node* min = head;
  current = head;
  while(current != tail->get_previous())
  for(int i = 0 ; i < size ; i++)
  {
    for(int j = i ; j < size ; j++)
    if(min.get_data().get_name() > current)
      min = current;
    current = current->next();
  }
}
*/

//Non-member fonctions :
std::ostream& operator<<(std::ostream& out, const LinkedList& list)
{
  //Maybe i will have to change this to not use getter for the head, but i don't
  //know how can i do in another way
  Node* current = list.get_head();//how to do that without public get_head ??

  while(current != NULL)
  {
    out << current->get_data();
    current = current->get_next();
  }
  return out;
}
