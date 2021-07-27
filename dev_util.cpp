#include "dev_util.hpp"
using namespace util;
template <typename X>
ArrayList<X>::ArrayList()
{
    capacity = 0;
    arr_ptr = NULL;
}

template <typename X>
ArrayList<X>::~ArrayList()
{
    delete[] arr_ptr;
}

template <typename X>
void ArrayList<X>::doubleArray(int capacity)
{
    X *ralloc = new X[capacity];
    for (int idx = 0; idx <= lastIndex; ++idx)
        ralloc[idx] = arr_ptr[idx];
    delete[] arr_ptr;
    arr_ptr = ralloc;
    this->capacity = capacity;
}

template <typename X>
void ArrayList<X>::halfArray(int capacity)
{
    X *dalloc = new X[capacity];
    for (int idx = 0; idx <= lastIndex; ++idx)
        dalloc[idx] = arr_ptr[idx];
    delete[] arr_ptr;
    arr_ptr = dalloc;
    this->capacity = capacity;
}

//----------------------------------------------------------------pairList<X>::
template <typename X1, typename X2>
pairList<X1, X2>::pairList()
{
    last = NULL;
    lastIndex = -1;
}

template <typename X1, typename X2>
pairList<X1, X2>::~pairList()
{
    while (last)
        remove_front();
}

template <typename X1, typename X2>
void pairList<X1, X2>::append(X1 T1, X2 T2)
{
    node *newNode = new node;
    newNode->T1 = T1;
    newNode->T2 = T2;
    if (last == NULL)
        newNode->next = newNode;
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
    last = newNode;
    lastIndex += 1;
}

template <typename X1, typename X2>
void pairList<X1, X2>::remove_front()
{
    if (last != NULL)
    {
        node *rnode = last->next;
        if (last == last->next)
            last = NULL;
        else
            last->next = rnode->next;
        lastIndex -= 1;
        delete rnode;
    }
}

template <typename X1, typename X2>
void pairList<X1, X2>::remove_back()
{
    if (last != NULL)
    {
        node *rnode = last->next;
        if (last == last->next)
            last = NULL;
        else
        {
            node *nptr = last->next;
            while (nptr->next != last)
                nptr = nptr->next;
            nptr->next = last->next;
            rnode = last;
            last = nptr;
        }
        lastIndex -= 1;
        delete rnode;
    }
}

/*template <typename X1, typename X2>
void pairList<X1, X2>::removeFrom(int begIndx, int endIndx)
{
    if (last)
    {
        node *current_node = last->next;
        do
        {
            if (current_node->info == current_data)
            {
                node *nptr = last->next;
                for (nptr; nptr->next != current_node; nptr = nptr->next)
                    ;
                if (last == last->next)
                    last = NULL;
                nptr->next = current_node->next;
                if (current_node == last)
                    last = nptr;
                lastIndex -= 1;
                delete current_node;
                break;
            }
            current_node = current_node->next;
        } while (current_node != last->next);
    }
}*/


template <typename X1, typename X2>
void pairList<X1,X2>::update(int index_node_location, X1 new_T1, X2 new_T2)
{
    if (index_node_location >= 0 && index_node_location <= lastIndex)
    {
        node *nptr=last->next;
        for(int idx=0; idx<index_node_location; ++idx, nptr=nptr->next);
        nptr->T1=new_T1;
        nptr->T2=new_T2;
    }
    else
        throw std::out_of_range("pairList::update");
}


template <typename X1, typename X2>
void pairList<X1, X2>::viewList()
{
    if (last != NULL)
    {
        node *nptr = last->next;
        do
        {
            std::cout << " " << nptr->T1 << " " << nptr->T2;
            nptr = nptr->next;
        }
        while (nptr != last->next);
    }
}

//----------------------------------------------------------------LinkedList<X>::
template <typename X>
LinkedList<X>::LinkedList()
{
    start = NULL;
    lastIndex = -1;
}

template <typename X>
LinkedList<X>::~LinkedList()
{
    while (start)
        remove_front();
}

template <typename X>
void LinkedList<X>::insertAfter(X current_data, X data)
{
    if (start)
        for (node *nptr = start; nptr; nptr = nptr->next)
            if (nptr->info == current_data)
            {
                node *newNode = new node;
                newNode->info = data;
                newNode->next = nptr->next;
                nptr->next = newNode;
                lastIndex += 1;
                break;
            }
}

//---------------------------------------------------------------- DLL<X>::
template <typename X>
DLL<X>::DLL()
{
    start = NULL;
    lastIndex = -1;
}

template <typename X>
DLL<X>::~DLL()
{
    while (start)
        remove_front();
}

template <typename X>
void DLL<X>::insertAfter(X current_data, X data)
{
    if (start)
        for (node *nptr = start; nptr; nptr = nptr->next)
            if (nptr->info == current_data)
            {
                node *newNode = new node;
                newNode->info = data;
                newNode->next = nptr->next;
                newNode->prev = nptr;
                if (nptr->next != NULL)
                    newNode->next->prev = newNode;
                nptr->next = newNode;
                lastIndex += 1;
                break;
            }
}


//---------------------------------------------------------------- CLL<X>::
template <typename X>
CLL<X>::CLL()
{
    last = NULL;
    lastIndex = -1;
}

template <typename X>
CLL<X>::~CLL()
{
    while (last)
        remove_front();
}

template <typename X>
void CLL<X>::insertAfter(X current_data, X data)
{
    if (last)
    {
        node *current_node = last->next;
        do
        {
            if (current_node->info == current_data)
            {
                node *newNode = new node;
                newNode->info = data;
                newNode->next = current_node->next;
                current_node->next = newNode;
                if (current_node == last)
                    last = newNode;
                lastIndex += 1;
                break;
            }
            current_node = current_node->next;
        }
        while (current_node != last->next);
    }
}


//------------------------------CDLL<X>::
template <typename X>
CDLL<X>::CDLL()
{
    start = NULL;
    lastIndex = -1;
}

template <typename X>
CDLL<X>::~CDLL()
{
    while (start)
        remove_front();
}

template <typename X>
void CDLL<X>::insertAfter(X current_data, X data)
{
    if (start)
    {
        node *current_node = start;
        do
        {
            if (current_node->info == current_data)
            {
                node *newNode = new node;
                newNode->info = data;
                newNode->next = current_node->next;
                newNode->prev = current_node;
                current_node->next = newNode;
                newNode->next->prev = newNode;
                lastIndex += 1;
                break;
            }
            current_node = current_node->next;
        }
        while (current_node != start);
    }
}

//---------------------------------------------------------------- STACK<X>::
template <typename X>
StackArray<X>::StackArray()
{
    capacity = 0;
    arr_ptr = NULL;
}

template <typename X>
StackArray<X>::~StackArray()
{
    delete[] arr_ptr;
}

template <typename X>
void StackArray<X>::doubleStack(int capacity)
{
    X *ralloc = new X[capacity];
    for (int idx = 0; idx <= top; ++idx)
        ralloc[idx] = arr_ptr[idx];
    delete arr_ptr;
    arr_ptr = ralloc;
    this->capacity = capacity;
}

template <typename X>
void StackArray<X>::halfStack(int capacity)
{
    X *dalloc = new X[capacity];
    for (int idx = 0; idx <= top; ++idx)
        dalloc[idx] = arr_ptr[idx];
    delete arr_ptr;
    arr_ptr = dalloc;
    this->capacity = capacity;
}

//----------------------------------------------------------------StackLinkedList<X>::
template <typename X>
StackList<X>::StackList()
{
    top = NULL;
    lastIndex = -1;
}

template <typename X>
StackList<X>::~StackList()
{
    while (top)
        pop();
}

//----------------------------------------------------------------QueueArray::
template <typename X>
TwoWayStack<X>::TwoWayStack()
{
    capacity=0;
    top_left=top_right=-1;
    stk_ptr=NULL;
}

template <typename X>
TwoWayStack<X>::~TwoWayStack()
{
    delete []stk_ptr;
}

template <typename X>
void TwoWayStack<X>::doubleStack(int capacity)
{
    X *ralloc = new X[capacity];
    for (int idx = 0; idx <= top_left; ++idx)
        ralloc[idx] = stk_ptr[idx];
    int idx=capacity-1,indx=this->capacity-1;
    for (idx, indx; idx >= capacity-top_right+1, indx>=top_right; --idx,--indx)
        ralloc[idx] = stk_ptr[indx];
    delete stk_ptr;
    stk_ptr = ralloc;
    top_right=idx+1;
    this->capacity = capacity;
}

template <typename X>
void TwoWayStack<X>::halfStack(int capacity)
{
    X *dalloc = new X[capacity];
    for (int idx = 0; idx <= top_right; ++idx)
        dalloc[idx] = stk_ptr[idx];
    int idx=this->capacity-1,indx=capacity-1;
    for (idx, indx; idx >= top_right, indx>=top_right-capacity; --idx, --indx)
        dalloc[idx] = stk_ptr[indx];
    delete stk_ptr;
    stk_ptr = dalloc;
    top_right=idx+1;
    this->capacity = capacity;
}

//----------------------------------------------------------------QueueArray::
template <typename X>
QueueArray<X>::QueueArray()
{
    capacity = 0;
    arr_ptr = NULL;
}

template <typename X>
QueueArray<X>::~QueueArray()
{
    delete[] arr_ptr;
}

//----------------------------------------------------------------QueueLinkedList::
template <typename X>
QueueList<X>::QueueList()
{
    front = rear = NULL;
    lastIndex = -1;
}

template <typename X>
QueueList<X>::~QueueList()
{
    while (front)
        deletion();
}
