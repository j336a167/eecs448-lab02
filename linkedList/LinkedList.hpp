/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	Node<T>* temp = m_front;
	int count = 0;

	while(true)
	{
		if(temp == nullptr)
		{
			return(count);
			break;
		}
		else
		{
			count++;
			temp = temp->getNext();
		}
	}
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
Node<T>* temp = m_front;
bool isFound = false;

while(true)
{
	if(temp == nullptr)
	{
		return(false);
	}
	else if(temp->getValue() == value)
	{
		isFound = true;
		return(isFound);
	}
	else
	{
		temp = temp->getNext();
	}
}

return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* temp = m_front;
	bool isRemoved = false;

	if(size() == 0)
	{
		return(isRemoved);
	}
	else if(size() == 1)
	{
		delete m_front;
		m_front = nullptr;
		isRemoved = true;
		return(isRemoved);
	}
	else
	{
		while(true)
		{
			if(temp->getNext() == nullptr)
			{
				break;
			}
			lastNode = temp;
			temp = temp->getNext();
		}
		delete temp;
		lastNode->setNext(nullptr);
		m_size = m_size-1;
		return(true);
	}
}
template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
