//Author: Benoit Coville
//email : covillebenoit@gmail.com
//Student number : c3316165
//Course: SENG1120

template <typename value_type>
LinkedList<value_type>::LinkedList() : m_head(NULL), m_tail(NULL), m_size(0)
{}

template <typename value_type>
LinkedList<value_type>::~LinkedList()
{
	Node<value_type>* current = m_head;

	if(m_size == 1)
	{
		delete m_head;
	}
	else if(m_size > 1)
	{
		//Scan the entire list
		while(current->get_next() != NULL)
		{
			//Go forward
			current = current->get_next();
			//delete the previous
			delete current->get_previous();
		}
		//delete the last one
		delete m_tail;
	}

}

template <typename value_type>
int LinkedList<value_type>::get_size()const
{ return m_size; }

template <typename value_type>
bool LinkedList<value_type>::isEmpty()const
{
  //To make sure all is well implemented I triple-check
  if(m_size == 0 && m_head == NULL && m_tail == NULL )
    return true;
  else
    return false;
}

template <typename value_type>
void LinkedList<value_type>::addToTail(const value_type& entry)
{
  Node<value_type> *current;
  //make a local copy of the node passed as parameter
  Node<value_type>* nd = new Node<value_type>(entry);//initialization of next and previous are useless and confusing here

  //if the list is empty
  if(isEmpty())
  {
    m_head = nd;
    m_tail = nd;
    m_size++;
  }
  else
  {
    //assign current to the last object of the list
    current = m_tail;

    m_tail = nd;
    current->set_next(nd);
    nd->set_previous(current);
    nd->set_next(NULL);
    m_size++;
    }
}

template <typename value_type>
void LinkedList<value_type>::operator +=(const LinkedList<value_type>& l)
{
	value_type* newDatas = l.getAllData();


	for(int i = 0 ; i < l.get_size() ; ++i)
	{
		addToTail(newDatas[i]);
	}
	delete[] newDatas;
}

//May not be the best solution because imply to copy all the data 2 times 
//one for the array and one adding the nodes to the next linked list (we need to free the array to not have memory leak)
//even if there's no real memory leak...
template <typename value_type>
value_type* LinkedList<value_type>::getAllData()const
{
	Node<value_type>* current = m_head;
	//allocate an array dedicated to store all the data of the linked list
	value_type* tab = new value_type[m_size];
	int i = 0;
	while(current != NULL)
	{
		tab[i] = current->get_data();
		current = current->get_next();
		i++;
	}
	return tab;
}

template <typename value_type>
void LinkedList<value_type>::remove(std::string name)
{
  bool found = false;
  Node<value_type>* temp;
  Node<value_type>* current = m_head;
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

template <typename value_type>
bool LinkedList<value_type>::remove_target(Node<value_type>* target)
{
  if(isEmpty())
  {
      cout << "error, you try to remove a node from an empty list" << endl;
      return false;
  }
  else if(m_size == 1)
  {
    delete target;
    m_head = NULL;
    m_tail = NULL;
    m_size--;
    return true;
  }
  else //size > 1
  {
    if(target == m_head)
    {
      m_head->get_next()->set_previous(NULL);
      m_head = m_head->get_next();
    }
    else if(target == m_tail)
    {
      m_tail = target->get_previous();
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
    m_size--;
    return true;
  }
}


//Note : i got an error before, the compiler wanted this method to be constant
//       and i didn't undertsand why, and don't understand why is it working now

template <typename value_type>
double LinkedList<value_type>::calcAverage()
{
  double sum = 0;
  Node<value_type>* current = m_head;

  if(!isEmpty())
  {
    while(current != NULL)
    {
      sum += current->get_data().get_score();
      current = current->get_next();
    }
    return sum/m_size;
  }
  else
  {
    cout << "error, you try to calulate the average of an empty list" << endl;
    return -1;
  }
}

template <typename value_type>
int LinkedList<value_type>::count(std::string name)
{
  int occurence = 0;
  Node<value_type>* current = m_head;
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

template <typename value_type>
void LinkedList<value_type>::swapNodes(Node<value_type>* v1, Node<value_type>* v2)//note : v1 is before v2
{
  if(v1 != m_head)
  {
    v1->get_previous()->set_next(v2);
  }
  else//v1 is the m_head
  {
    m_head = v2;
  }
  if(v2 != m_tail )
  {
    v2->get_next()->set_previous(v1);
  }
  else//v2 is the tail
  {
    m_tail = v1;
  }

  Node<value_type> *prev = v1->get_previous();
  Node<value_type> *next = v2->get_next();

  v1->set_next(next);
  v1->set_previous(v2);

  v2->set_previous(prev);
  v2->set_next(v1);
}

template <typename value_type>
void LinkedList<value_type>::order()
{
  Node<value_type>* current;
  for(uint i = 0 ; i < m_size ; ++i)
  {
    current = m_head;

    while(current != m_tail)
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

template <typename value_type>
void LinkedList<value_type>::display_debug()
{
  Node<value_type> *current_ = m_head;
  while(current_ != NULL)
  {
    display_pointer_node(current_->get_previous());
    display_pointer_node(current_);
    display_pointer_node(current_->get_next());
    std::cout << std::endl;
    current_ = current_->get_next();
  }
}

template <typename value_type>
void LinkedList<value_type>::display_pointer_node(Node<value_type>* pt)
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

template <typename value_type>
std::ostream& LinkedList<value_type>::display(std::ostream& out)const
{
	//create a stream
	Node<value_type>* current = m_head;
	//go through the entire list
	while(current != NULL)
	{
		//(add) each node's stream in the final output stream
		out << current->get_data();
		current = current->get_next();
	}
	//return the stream containing all the nodes' display data
	return out;
}


//Non-member fonctions :
template <typename value_type>
std::ostream& operator<<(std::ostream& out, const LinkedList<value_type>& list)
{
  return list.display(out);
}
