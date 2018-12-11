#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <class T>
class Node
{
	private:
		T value;
		Node<T>* next;
	
	public:
		Node(void);
		Node(T value,Node<T>* next);
		T GetValue(void);
		Node* GetNext(void);
		void SetValue(T value);
		void SetNext(Node<T>* next);
		void operator=(Node<T>* node);
};

template<typename T>
Node<T>::Node()
{
	this->next = NULL;
}

template<typename T>
Node<T>::Node(T value,Node* next)
{
	this->value = value;
	this->next = next;
}


template<typename T>
T Node<T>::GetValue(void)
{
	return value;
}

template<typename T>
Node<T>* Node<T>::GetNext(void)
{
	return next;
}

template<typename T>
void Node<T>::SetValue(T value)
{
	this->value = value;
}

template<typename T>
void Node<T>::SetNext(Node<T>* next)
{
	this->next = next;
}

template<typename T>
void Node<T>::operator=(Node<T>* node)
{
	this->next = node->next;
	this->value = node->value; 
}

template<typename T>
class Link_list
{
	private:
		Node<T>* head;
		Node<T>* tail;
		int length;
		Node<T>* _GetNode(int pos)
		{
			if(pos>=length) return NULL;
			Node<T>* tmp = head;
			for(int i=0;i<pos;i++)
			{
				tmp = tmp->GetNext();
			 } 
			return tmp;
		}
		
	public:
		Link_list(void)
		{
			head = NULL;
			tail = NULL;
			length = 0;
		}
		Link_list(Node<T>* head)
		{
			this->head = head;
			this->tail = head;
			length = 1;
		}
		void Insert(int pos,Node<T>* node)
		{
			if(pos==0)
			{
				node->SetNext(head);
				head = node;
				length++;
			}
			else if(pos<=length)
			{
				Node<T>* before = _GetNode(pos-1);
				Node<T>* current = before->GetNext();
				before->SetNext(node);
				node->SetNext(current); 
				if(pos==length) tail = node;
				length++;
			}
			else
			{
				cout << "Out of bound" << endl;
			}
		}
		void Replace(int pos,Node<T>* node)
		{
			if(pos==0)
			{
				node->SetNext(head->GetNext());
				head = node;
			}
			else
			{
				Node<T>* before = _GetNode(pos-1);
				Node<T>* current = _GetNode(pos);
				before->SetNext(node);
				node->SetNext(current->GetNext());
			}
		}
		void Delete(int pos)
		{
			Node<T>* before = _GetNode(pos-1);
			Node<T>* current = _GetNode(pos);
			before->SetNext(current->GetNext());
			length--;
		}
		void Append(Node<T>* node)
		{
			tail->SetNext(node);
			tail = node;
			length++;
		}
		int Find(Node<T>* node)
		{
			Node<T>* current = head;
			for(int i=0;i<length;i++)
			{
				if(current->GetValue() == head->GetValue()) return i;
			}
			return -1;
		}
		void Show(void)
		{
			Node<T>* current = head;
			while(current!=NULL)
			{
				cout << current->GetValue() << " ---> ";
				current = current->GetNext();
			}
			cout << endl;
		}
};



#endif

