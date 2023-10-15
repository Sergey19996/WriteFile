#include <iostream> 

template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void clear();
	void push_back(T data);
	int GetSize() { return Size; }
	void push_front( T data);
	void insert(T value, int index);
	void removeAt(int index);
	void Pop_Back();

	T& operator[](const int index);




private:


	template<typename T>
	class Node // узел
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)   //pointer on next Node
		{
			this->data = data;
			this->pNext = pNext;
		}
	};



	int Size;
	Node<T> *head;
	
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head =nullptr;

}
template<typename T>
List<T>::~List()
{
	clear();

}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* Temp = head;
	head = head->pNext;

	Size--;
	delete Temp;

}

template<typename T>
void List<T>::clear()
{
	while (Size!=0)
	{
		Node<T>* Temp = head;
		head = head->pNext;

		Size--;
		delete Temp;
	}
	

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
	
		head= new Node<T>(data);         //поинтер указывает на место в памяти класса, который хронит data и ссылку 
	}
	else
	{
		Node<T>* current = this->head;         //We add adres from head to out new peremennaia
		while (current->pNext !=nullptr)	   //so if we create something from this adress and than it's destroy 
		{									   //the changes will be with our first file
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);        //create new dara on pnext
		
	}

	Size++;
}

template<typename T>
void List<T>::push_front( T data)
{

	Node<T>* current = new Node<T>(data);

	current->pNext = head;
	head = current;

	Size++;


}

template<typename T>
void List<T>::insert(T value, int index)
{

	int counter = 0;
	Node<T>* current = this->head;
	//Node<T>* change = new Node<T>(value);
	
	while (current != nullptr)
	{
		if (counter == index-1)
		{
			//Node<T>* change = new Node<T>(value, current->pNext);

			

			current->pNext = new Node<T>(value, current->pNext);
			Size++;
		}
		current = current->pNext;
		counter++;
	}
	
}

template<typename T>
void List<T>::removeAt(int index)
{
	Node<T>* current = this->head;
	int counter = 0;
	while (current !=nullptr)
	{
		if (index ==0)
		{
			pop_front();
		}

		if (counter == index-1)
		{
			
			Node<T>* previous = current;
		
			current = current->pNext;

			previous->pNext = current->pNext;
			Size--;
			delete current;
			break;
		}

		
		counter++;

		current = current->pNext;
	}


}

template<typename T>
void List<T>::Pop_Back()
{
	Node<T>* current = this->head;
	while (current !=nullptr)
	{
		for (int i = 0; i < Size-2; i++)
		{
			current = current->pNext;
		}
		
		delete current->pNext;
		current->pNext = nullptr;
		break;
		Size--;


	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current !=nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}



int main()
{

	List < int> st;

	st.push_back(5);
	st.push_back(10);
	st.push_back(12);


	st.push_front(7);
	//std::cout << st.GetSize() << std::endl;
	for (int i = 0; i < st.GetSize(); i++)
	{
	
		std::cout<<st[i] << std::endl;
	}

	st.insert(99, 1);
	std::cout << std::endl;
	for (int i = 0; i < st.GetSize(); i++)
	{

		std::cout << st[i] << std::endl;
	}
	st.removeAt(2);
 		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	for (int i = 0; i < st.GetSize(); i++)
	{

		std::cout << st[i] << std::endl;
	}

	st.Pop_Back();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < st.GetSize(); i++)
	{

		std::cout << st[i] << std::endl;
	}

	return 0;
}