#include<iostream>
#include"queue303.cpp"
using namespace std;

int main()
{
    myQueue<int> my_q1;//declared my queue of integer type
    //to push random 10 values in my queue
    my_q1.Push(1);
    my_q1.Push(2);
    my_q1.Push(3);
    my_q1.Push(4);
    my_q1.Push(5);
    my_q1.Push(6);
    my_q1.Push(7);
    my_q1.Push(8);
    my_q1.Push(9);
    my_q1.Push(10);
    
    cout<<"The queue:"<<endl;
    //print all values
    for(int i=my_q1.Size();i>0;--i){
        cout<<my_q1.Front()<<endl;
        my_q1.Pop();
    }
    cout<<endl;
    my_q1.Push(1);
    my_q1.Push(2);
    my_q1.Push(3);
    my_q1.move_to_rear();
    //print values in reverse
    for(int i=my_q1.Size();i>0;--i){
        cout<<my_q1.Front()<<endl;
        my_q1.Pop();
    }
}
