#include "dev_util.hpp"
using namespace util;
template <typename X>
int ArrayList<X>::indexOf(X current_data, int begIndx, int endIndx)
{
    if (lastIndex > -1)
    {
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
        {
            for (int idx = begIndx + 1; idx <= endIndx - 1; idx++)
                if (arr_ptr[idx] == current_data)
                    return idx;
        }
        else if (begIndx > -1 && begIndx <= lastIndex)
        {
            for (int idx = begIndx + 1; idx <= lastIndex; ++idx)
                if (arr_ptr[idx] == current_data)
                    return idx;
        }
        else if (endIndx > -1 && endIndx <= lastIndex)
        {
            for (int idx = 0; idx <= endIndx - 1; ++idx)
                if (arr_ptr[idx] == current_data)
                    return idx;
        }
        else if (begIndx == -1 && endIndx == -1)
        {
            for (int idx = 0; idx <= lastIndex; ++idx)
                if (arr_ptr[idx] == current_data)
                    return idx;
            return -1;
        }
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
            return -1;
        throw std::out_of_range("ArrayList::indexOf");
    }
    throw std::underflow_error("ArrayList::indexOf from empty List");
}

template <typename X>
void ArrayList<X>::revList()
{
    if(lastIndex>-1)
        for(int idx=0; idx<=(lastIndex+1)/2; ++idx)
        {
            X valHolder=arr_ptr[idx];
            arr_ptr[idx]=arr_ptr[lastIndex-idx];
            arr_ptr[lastIndex-idx]=valHolder;
        }
}

template <typename X>
int ArrayList<X>::bin_search(X current_data)
{
    /*ArrayList _dataHolder;
    _dataHolder.createArray(capacity);
    _dataHolder.extend(*(this));    //passing current_object (this) reference Hai aur * laganeKeBaad ye current Object ho gya
    _dataHolder.sortItems(ASC);*/
    int _lowerIndx=0, _upperIndx=lastIndex, midIndx;
    while(_lowerIndx<=_upperIndx)
    {
        midIndx=(_lowerIndx+_upperIndx)/2;
        if(current_data==arr_ptr[midIndx])
            return midIndx;
        else if(current_data>arr_ptr[midIndx])  //for right traversing
            _lowerIndx=midIndx+1;
        else    //left traversing
            _upperIndx=midIndx-1;
    }
    return -1;
}

template <typename X>
void ArrayList<X>::bubble_sort(int ord)
{
    if(lastIndex>-1)
    {
        int round, idx, flag = 1;
        if(ord==ASC || ord==-1) //with default_arg
            for (round = 1; round <= lastIndex; ++round)
            {
                for (idx = 0; idx <= lastIndex - round; ++idx)
                    if (arr_ptr[idx] > arr_ptr[idx + 1])
                    {
                        X valHolder = arr_ptr[idx];
                        arr_ptr[idx] = arr_ptr[idx + 1];
                        arr_ptr[idx + 1] = valHolder;
                        flag = 0;
                    }
                if (flag == 1)
                    break;
            }
        else if (ord == DESC)
            for (round = 1; round <= lastIndex; ++round)
            {
                for (idx = 0; idx <= lastIndex - round; ++idx)
                    if (arr_ptr[idx] < arr_ptr[idx + 1])
                    {
                        X valHolder = arr_ptr[idx];
                        arr_ptr[idx] = arr_ptr[idx + 1];
                        arr_ptr[idx + 1] = valHolder;
                        flag = 0;
                    }
                if (flag == 1)
                    break;
            }
        else
            throw std::invalid_argument("ArrayList::sortItems");
    }
    else
        throw std::underflow_error("ArrayList::sortItems from empty List");
}

template <typename X>
X &ArrayList<X>::frontItem() const
{
    if (lastIndex > -1)
        return arr_ptr[0];
    throw std::underflow_error("ArrayList::frontItem access from empty List");
}

template <typename X>
X &ArrayList<X>::endItem() const
{
    if (lastIndex > -1)
        return arr_ptr[lastIndex];
    throw std::underflow_error("ArrayList::endItem access from empty List");
}

template <typename X>
bool ArrayList<X>::isListFull()
{
    if (lastIndex == capacity - 1)
        return true;
    return false;
}

template <typename X>
void ArrayList<X>::fillItem(X data)
{
    for (int idx = 0; idx <= lastIndex; ++idx)
        arr_ptr[idx] = data;
}

template <typename X>
void ArrayList<X>::extend(ArrayList &T)
{
    if (T.lastIndex > -1)
        for (int idx = 0; idx <= T.lastIndex; ++idx)
            append(T.arr_ptr[idx]);
}

template <typename X>
void ArrayList<X>::release()
{
    delete[] arr_ptr;
    lastIndex = -1;
    capacity = 0;
}

template <typename X>
int ArrayList<X>::countItems()
{
    return lastIndex + 1;
}

template <typename X>
bool ArrayList<X>::isEqualTo(ArrayList &T)
{
    if (lastIndex == T.lastIndex)
    {
        int idx;
        for (int idx = 0; idx <= lastIndex; ++idx)
            if (arr_ptr[idx] != T.arr_ptr[idx])
                return false;
        if (idx == lastIndex + 1)
            return true;
    }
    return false;
}

template <typename X>
int ArrayList<X>::totalMemCapacity()
{
    if (lastIndex > -1)
        return sizeof(arr_ptr[0]) * (lastIndex + 1);
    return 0;
}

//----------------------------------------------------------------LinkedList<X>::
template <typename X1, typename X2>
bool pairList<X1,X2>::isListEmpty()
{
    if(lastIndex>-1)
        return false;
    return true;
}

template<typename X1, typename X2>
int pairList<X1,X2>::countItems()
{
    return lastIndex + 1;
}

//----------------------------------------------------------------LinkedList<X>::
template <typename X>
int LinkedList<X>::bin_search(X current_data)
{
    /*ArrayList _dataHolder;
    _dataHolder.createArray(capacity);
    _dataHolder.extend(*(this));    //passing current_object (this) reference Hai aur * laganeKeBaad ye current Object ho gya
    _dataHolder.sortItems(ASC);*/
    int _lowerIndx=0, _upperIndx=lastIndex, midIndx;
    while(_lowerIndx<=_upperIndx)
    {
        midIndx=(_lowerIndx+_upperIndx)/2;
        if(current_data==this[midIndx])
            return midIndx;
        else if(current_data>this[midIndx])  //for right traversing
            _lowerIndx=midIndx+1;
        else    //left traversing
            _upperIndx=midIndx-1;
    }
    return -1;
}

template <typename X>
int LinkedList<X>::indexOf(X current_data, int begIndx, int endIndx)
{
    if (lastIndex > -1)
    {
        node *nptr = start;
        int idx;
        if (begIndx != -1)
            for (idx = 0; idx < begIndx; ++idx, nptr = nptr->next)
                ;
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= endIndx - 1; idx++, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx > -1 && begIndx <= lastIndex)
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (endIndx > -1 && endIndx <= lastIndex)
        {
            for (int idx = 0; idx <= endIndx - 1; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx == -1 && endIndx == -1)
        {
            for (idx = 0; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
            return -1;
        }
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
            return -1;
        throw std::out_of_range("LinkedList::indexOf");
    }
    throw std::underflow_error("LinkedList::indexOf from empty List");
}

template <typename X>
X &LinkedList<X>::frontItem() const
{
    if (lastIndex > -1)
        return start->info;
    throw std::underflow_error("LinkedList::frontItem access from empty List");
}

template <typename X>
X &LinkedList<X>::endItem() const
{
    if (lastIndex > -1)
    {
        node *nptr = start;
        for (nptr; nptr->next != NULL; nptr = nptr->next)
            ;
        return nptr->info;
    }
    throw std::underflow_error("LinkedList::endItem access from empty List");
}

template <typename X>
bool LinkedList<X>::isListEmpty()
{
    if (lastIndex > -1)
        return false;
    return true;
}

template <typename X>
int LinkedList<X>::countItems()
{
    return lastIndex + 1;
}

template <typename X>
void LinkedList<X>::fillItem(X data)
{
    node *nptr = start;
    while (nptr)
    {
        nptr->info = data;
        nptr = nptr->next;
    }
}

template <typename X>
void LinkedList<X>::extend(LinkedList &T)
{
    if (T.start != NULL)
    {
        node *nptr = T.start;
        for (nptr; nptr; nptr = nptr->next)
            append(nptr->info);
    }
}

template <typename X>
void LinkedList<X>::revList()
{
    node *t1, *t2;
    t1 = t2 = NULL;
    while (start)
    {
        t2 = start->next;
        start->next = t1;
        t1 = start;
        start = t2;
    }
    start = t1;
}

//---------------------------------------------------------------- DLL<X>::
template <typename X>
int DLL<X>::indexOf(X current_data, int begIndx, int endIndx)
{
    if (lastIndex > -1)
    {
        node *nptr = start;
        int idx;
        if (begIndx != -1)
            for (idx = 0; idx < begIndx; ++idx, nptr = nptr->next)
                ;
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= endIndx - 1; idx++, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx > -1 && begIndx <= lastIndex)
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (endIndx > -1 && endIndx <= lastIndex)
        {
            for (int idx = 0; idx <= endIndx - 1; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx == -1 && endIndx == -1)
        {
            for (idx = 0; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
            return -1;
        }
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
            return -1;
        throw std::out_of_range("DLL::indexOf");
    }
    throw std::underflow_error("DLL::indexOf from empty List");
}

template <typename X>
X &DLL<X>::frontItem() const
{
    if (lastIndex > -1)
        return start->info;
    throw std::underflow_error("DLL::frontItem access from empty List");
}

template <typename X>
X &DLL<X>::endItem() const
{
    if (lastIndex > -1)
    {
        node *nptr = start;
        for (nptr; nptr; nptr = nptr->next)
            ;
        return nptr->info;
    }
    throw std::underflow_error("DLL::endItem access from empty List");
}

template <typename X>
bool DLL<X>::isListEmpty()
{
    if (lastIndex > -1)
        return false;
    return true;
}

template <typename X>
int DLL<X>::countItems()
{
    return lastIndex + 1;
}

template <typename X>
void DLL<X>::fillItem(X data)
{
    node *nptr = start;
    while (nptr)
    {
        nptr->info = data;
        nptr = nptr->next;
    }
}

template <typename X>
void DLL<X>::extend(DLL &T)
{
    if (T.start != NULL)
    {
        node *nptr = T.start;
        for (nptr; nptr; nptr = nptr->next)
            append(nptr->info);
    }
}

template <typename X>
void DLL<X>::revList()
{
    node *t1, *t2;
    t1 = t2 = NULL;
    while (start)
    {
        t2 = start->next;
        start->next = t1;
        t1 = start;
        start = t2;
    }
    start = t1;
}

//---------------------------------------------------------------- CLL<X>::
template <typename X>
int CLL<X>::indexOf(X current_data, int begIndx, int endIndx)
{
    if (lastIndex > -1)
    {
        node *nptr = last->next;
        int idx;
        if (begIndx != -1)
            for (idx = 0; idx < begIndx; ++idx, nptr = nptr->next)
                ;
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= endIndx - 1; idx++, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx > -1 && begIndx <= lastIndex)
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (endIndx > -1 && endIndx <= lastIndex)
        {
            for (int idx = 0; idx <= endIndx - 1; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx == -1 && endIndx == -1)
        {
            for (idx = 0; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
            return -1;
        }
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
            return -1;
        throw std::out_of_range("CLL::indexOf");
    }
    throw std::underflow_error("CLL::indexOf from empty List");
}

template <typename X>
X &CLL<X>::frontItem() const
{
    if (lastIndex > -1)
        return last->next->info;
    throw std::underflow_error("CLL::frontItem access from empty List");
}

template <typename X>
X &CLL<X>::endItem() const
{
    if (lastIndex > -1)
        return last->info;
    throw std::underflow_error("CLL::endItem from empty List");
}

template <typename X>
bool CLL<X>::isListEmpty()
{
    if (lastIndex > -1)
        return false;
    return true;
}

template <typename X>
int CLL<X>::countItems()
{
    return lastIndex + 1;
}

template <typename X>
void CLL<X>::fillItem(X data)
{
    node *nptr = last->next;
    do
    {
        nptr->info = data;
        nptr = nptr->next;
    }
    while (nptr != last->next);
}

template <typename X>
void CLL<X>::extend(CLL &T)
{
    if (T.last != NULL)
    {
        node *nptr = T.last->next;
        do
        {
            append(nptr->info);
            nptr = nptr->next;
        }
        while (nptr != T.last->next);
    }
}

//------------------------------CDLL<X>::
template <typename X>
int CDLL<X>::indexOf(X current_data, int begIndx, int endIndx)
{
    if (lastIndex > -1)
    {
        node *nptr = start;
        int idx;
        if (begIndx != -1)
            for (idx = 0; idx < begIndx; ++idx, nptr = nptr->next)
                ;
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= endIndx - 1; idx++, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx > -1 && begIndx <= lastIndex)
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (endIndx > -1 && endIndx <= lastIndex)
        {
            for (int idx = 0; idx <= endIndx - 1; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
        }
        else if (begIndx == -1 && endIndx == -1)
        {
            for (idx = 0; idx <= lastIndex; ++idx, nptr = nptr->next)
                if (nptr->info == current_data)
                    return idx;
            return -1;
        }
        if ((begIndx > -1 && endIndx > -1) && (endIndx > begIndx && (begIndx <= lastIndex && endIndx <= lastIndex)))
            return -1;
        throw std::out_of_range("CDLL::indexOf");
    }
    throw std::underflow_error("CDLL::indexOf from empty List");
}

template <typename X>
X &CDLL<X>::frontItem() const
{
    if (lastIndex > -1)
        return start->info;
    throw std::underflow_error("CDLL::frontItem from empty List");
}

template <typename X>
X &CDLL<X>::endItem() const
{
    if (lastIndex > -1)
        return start->prev->info;
    throw std::underflow_error("CDLL::endItem from empty List");
}

template <typename X>
bool CDLL<X>::isListEmpty()
{
    if (lastIndex > -1)
        return false;
    return true;
}

template <typename X>
int CDLL<X>::countItems()
{
    return lastIndex + 1;
}

template <typename X>
void CDLL<X>::fillItem(X data)
{
    node *nptr = start;
    do
    {
        nptr->info = data;
        nptr = nptr->next;
    }
    while (nptr != start);
}

template <typename X>
void CDLL<X>::extend(CDLL &T)
{
    if (T.start != NULL)
    {
        node *nptr = T.start;
        do
        {
            append(nptr->info);
            nptr = nptr->next;
        }
        while (nptr != T.start);
    }
}

//---------------------------------------------------------------- STACK<X>::
template <typename X>
int StackArray<X>::countItems()
{
    return top + 1;
}

template <typename X>
bool StackArray<X>::isStackEmpty()
{
    if (top > -1)
        return false;
    return true;
}

template <typename X>
bool StackArray<X>::isStackFull()
{
    if (top == capacity - 1)
        return true;
    return false;
}

template <typename X>
void StackArray<X>::extend(StackArray &T)
{
    if (T.top > -1)
        for (int idx = 0; idx <= T.top; ++idx)
            push(T.arr_ptr[idx]);
}

template <typename X>
void StackArray<X>::release()
{
    delete[] arr_ptr;
    top = -1;
    capacity = 0;
}

template <typename X>
int StackList<X>::countItems()
{
    return lastIndex + 1;
}

template <typename X>
bool StackList<X>::isStackEmpty()
{
    if (lastIndex > -1)
        return false;
    return true;

}

template <typename X>
int TwoWayStack<X>::countItems()
{
    return (top_left+capacity-top_right)+1;
}

template<typename X>
void TwoWayStack<X>::release()
{
    delete []stk_ptr;
    top_left=top_right=-1;
    capacity=0;
}

template<typename X>
bool TwoWayStack<X>::isEmptyLeft()
{
    if(top_left>-1)
        return false;
    return true;
}

template<typename X>
bool TwoWayStack<X>::isEmptyRight()
{
    if(top_right<capacity)
        return false;
    return true;
}

template<typename X>
bool TwoWayStack<X>::isStackFull()
{
    if(top_left+1==top_right || top_right-1==top_left)
        return true;
    return false;
}

template <typename X>
void TwoWayStack<X>::leftFill(X data)
{
    for (int idx = 0; idx <= top_left; ++idx)
        stk_ptr[idx] = data;
}

template <typename X>
void TwoWayStack<X>::rightFill(X data)
{
    for (int idx = capacity-1; idx >= capacity-top_right; --idx)
        stk_ptr[idx] = data;
}

template <typename X>
void TwoWayStack<X>::extend(TwoWayStack &T)
{
    if (T.top_left>-1 || T.top_right < T.capacity)
    {
        if(T.top_left>-1)
            for(int idx=0; idx<=T.top_left; ++idx)
                push_left(T.stk_ptr[idx]);
        if(T.top_right<T.capacity)
            for (int idx = T.capacity-1; idx >= T.top_right; --idx)
                push_right(T.stk_ptr[idx]);
    }
}

template<typename X>
void TwoWayStack<X>::viewLeftStack()
{
    if(top_right>-1)
        for(int idx=0; idx<=top_left; ++idx)
            std::cout<<" "<<stk_ptr[idx];
}

template<typename X>
void TwoWayStack<X>::viewRightStack()
{
    if(top_right<capacity)
        for(int idx=capacity-1; idx>=top_right; --idx)
            std::cout<<" "<<stk_ptr[idx];
}


//----------------------------------------------------------------QUEUE::
template <typename X>
X &QueueArray<X>::frontItem() const
{
    if (front != -1)
        return arr_ptr[front];
    throw std::underflow_error("QueueArray::frontItem from empty List");
}

template <typename X>
X &QueueArray<X>::endItem() const
{
    if (front != -1)
        return arr_ptr[rear];
    throw std::underflow_error("QueueArray::endItem from empty List");
}

template <typename X>
bool QueueArray<X>::isQueueEmpty()
{
    if (front == -1)
        return true;
    return false;
}

template <typename X>
bool QueueArray<X>::isQueueFull()
{
    if ((front == 0 && rear == capacity - 1) || rear + 1 == front)
        return true;
    return false;
}

/*template <typename X>
void QueueArray<X>::extend(QueueArray &T)
{
    if (T.top > -1)
        for (int idx = 0; idx <= T.top; ++idx)
            push(T.arr_ptr[idx]);
}*/

template <typename X>
void QueueArray<X>::release()
{
    delete[] arr_ptr;
    front = rear = -1;
    capacity = 0;
}

template <typename X>
int QueueArray<X>::countItems()
{
    if (front != -1)
    {
        int size = -1;
        for (int idx = front; idx != rear;)
        {
            ++size;
            if (idx == capacity - 1)
                idx = 0;
            else
                ++idx;
        }
        return size + 2;
    }
}

//----------------------------------------------------------------QueueLinkedList::
template <typename X>
X &QueueList<X>::frontItem() const
{
    if (front != NULL)
        return front->info;
    throw std::underflow_error("QueueList::frontItem from empty List");
}

template <typename X>
X &QueueList<X>::endItem() const
{
    if (front != NULL)
        return rear->info;
    throw std::underflow_error("QueueList::endItem from empty List");
}

template <typename X>
void QueueList<X>::extend(QueueList &T)
{
    if (T.front != NULL)
    {
        node *nptr = T.front;
        for (nptr; nptr; nptr = nptr->next)
            insertion(nptr->info);
    }
}

template <typename X>
bool QueueList<X>::isQueueEmpty()
{
    if (front == NULL)
        return true;
    return false;
}
