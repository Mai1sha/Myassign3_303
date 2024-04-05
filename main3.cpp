#include<iostream>
using namespace std;


template<typename T>
struct my_Node
{
    T val;
    my_Node* next;
    my_Node* prev;

    my_Node(T my_val) // Parameterized constructor
    {
        val = my_val;
        next = nullptr;
        prev = nullptr;
    }
    my_Node()// Default constructor
    {
        next = nullptr;
        prev = nullptr;
    }
};

template <typename X>
class DoublyLinkedList
{
public :
    my_Node<X> * head;
    my_Node<X> * tail;

    void Insert(X val)//a function to insert values
    {
        my_Node<X> * newNode = new my_Node<X>(val);
        if(head== nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void Print()//a function to print values
    {
        my_Node<X> * curr_val = head;
        while(curr_val!=nullptr)
        {
            cout<<curr_val->val<<" ";
            curr_val = curr_val->next;
        }
        cout<<endl;
    }
    bool Search(X val)
    {
        my_Node<X> * curr_val = head;
        while(curr_val!=nullptr)
        {
            if(curr_val->val == val)
                return true;
            curr_val = curr_val->next;
        }
        return false;
    }
    void Delete(X val)//a function to delete the values
    {
        if(head == nullptr)
        {
            return;
        }
        if(head->val == val)
        {
            my_Node<X> * temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return;
        }
        if(tail->val  == val)
        {
            my_Node<X> * temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return;
        }
        my_Node<X> * curr_val = head;
        while( curr_val!= nullptr)
        {
            if(curr_val->next->val == val)
            {
                my_Node<X> * temp = curr_val->next;
                curr_val->next->next->prev = curr_val;
                curr_val->next = curr_val->next->next;
                delete temp;
                return;
            }
            curr_val = curr_val->next;
        }
    }
};

void InsertionSort(DoublyLinkedList<int> * dList)//modified the insertion sort
{
    int key;
    bool insertionNeeded = false;

    for (my_Node<int> * curr_val = dList->head; curr_val!= nullptr; curr_val = curr_val->next)
    {
        int key = curr_val->val;
        insertionNeeded = false;
        my_Node<int> * temp;

        for (temp=curr_val->prev; temp!=nullptr; temp=temp->prev)
        {
            if (key < temp->val)
            {
                temp->next->val = temp->val; //the larger values move right
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded) //Put key into its proper location
        {
            if(temp== nullptr)
            {
                dList->head->val = key;
            }
            else
            {
                temp->next->val = key;
            }
        }
    }
}


int main()
{
    DoublyLinkedList<int> * dbly = new DoublyLinkedList<int>();// Create a new DoublyLinkedList object with integer type.
    // to push values into the doubly linked list.
    dbly->Insert(50);
    dbly->Insert(25);
    dbly->Insert(10);
    dbly->Insert(20);
    dbly->Insert(40);
    dbly->Insert(1);
    //to print the initial values 
    dbly->Print();
    InsertionSort(dbly);
    //to print the sorted values 
    dbly->Print();

}
