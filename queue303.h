#include<iostream>
using namespace std;

template<typename T>
struct Node
{
    T val;
    Node *next;
    Node();
    Node(T _val);
};

//using a template T to use any type if data
template<typename T>
class myQueue
{
public:
//decalred my data members as pbulic
    myQueue();
    void Push(T item);
    void Pop();
    T Front();
    void move_to_rear();
    size_t Size();
    bool Empty();
private:
//declared the data fields as private
    Node<T> * head;
    Node<T> * tail;
    size_t num_items;
};
