

template <typename value_type>
Node<value_type>::Node(const value_type& entry, Node* nxt, Node* prev) :
  m_next(nxt), m_previous(prev), m_data(entry)
{}
template <typename value_type>
Node<value_type>::Node (const value_type& entry) :
  m_next(NULL), m_previous(NULL), m_data(entry)
{}

template <typename value_type>
Node<value_type>::~Node()
{}


template <typename value_type>
Node<value_type>* Node<value_type>::get_next()const { return m_next; }

template <typename value_type>
void Node<value_type>::set_next(Node<value_type>* entry) { m_next = entry; }

template <typename value_type>
Node<value_type>* Node<value_type>::get_previous()const { return m_previous; }

template <typename value_type>
void Node<value_type>::set_previous(Node<value_type>* entry) { m_previous = entry; }

template <typename value_type>
value_type Node<value_type>::get_data()const { return m_data; }
