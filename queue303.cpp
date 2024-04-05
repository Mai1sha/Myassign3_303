#include "queue303.h"

template<typename T>
Node<T> :: Node()//a default constructor
{
    next = nullptr;
}

template<typename T>
Node<T> :: Node(T my_val)
{
    val = my_val;
    next = nullptr;
}


template<typename T>
myQueue<T> :: myQueue()//default constructor for my queue
{
    head = nullptr;
    tail = nullptr;
    num_items = 0;
}

template<typename T>
void myQueue<T> :: Push(T item)// a function to add/push values
{
    Node<T> * cur = new Node<T>(item);
    if(head ==nullptr)
    {
        head = cur;
        tail = cur;
    }
    else
    {
        tail->next = cur;
        tail =cur;
    }
    num_items++;
}

template<typename T>
void myQueue<T> :: Pop()//a function to delete/pop values
{
    if(head == nullptr)
    {
        throw out_of_range("The Queue is empty");
        return;
    }
    //store the head in another variable
    Node<T> * temp = head;
    head = head->next;
    //delete the temporary variable instead of head
    delete temp;
    num_items--;
}

template<typename T>
T myQueue<T> :: Front()//a function to print the first value
{
    if(head == nullptr)
    {
        throw out_of_range("The Queue is empty");
    }
    return head->val;
}

template<typename T>
void myQueue<T> :: move_to_rear()//a function to move the values to rear
{
    if(head == nullptr)
    {
        throw out_of_range("The Queue is empty");
    }
    T f = Front();
    Pop();
    Push(f);
}

template<typename T>
size_t myQueue<T> :: Size()//a function to return the size of my queue
{
    return num_items;
}

template<typename T>
bool myQueue<T> :: Empty()//a boolian function to return true if my queue is empty
{
    return num_items == 0;
}
