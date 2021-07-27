#include "dev_util.hpp"
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
    ArrayList<int>l2;
    l2.createArray(5);
    l2.insert_front(49);
    l2.insert_front(48);
    l2.insert_front(60);
    l2.insert_front(10);
    l2.insert_front(20);
    l2.revList();
    l2.viewList();
    getch();
    return 0;
}

