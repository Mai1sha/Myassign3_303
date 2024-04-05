#include<iostream>
#include<vector>
using namespace std;

int linear_search(vector<int>& items, int target, size_t pos_first)
{
    //to check if the target is found at the current position
    if (target == items[pos_first])
        return pos_first;
    //to check if the target has reached the begining of the vector
    if (pos_first ==0)
        return -1;

    return linear_search(items, target, pos_first - 1);//a recursive call to continue searching 
}

int main()
{
    vector<int> my_vect;//using integer type of vector 
    //to push random values in my vector
    my_vect.push_back(15);
    my_vect.push_back(25);
    my_vect.push_back(35);
    my_vect.push_back(45);
    my_vect.push_back(55);
    my_vect.push_back(55);
    //to store the size of my vector
    size_t vect_size = my_vect.size();
    cout<<linear_search(my_vect, 10, vect_size-1)<<endl;//to show the last occurance of 10
                                                        //print -1 as 10 is not in te vector

    cout<<linear_search(my_vect, 55, vect_size-1)<<endl;//to show the last occurance of 55
    return 0;
}
