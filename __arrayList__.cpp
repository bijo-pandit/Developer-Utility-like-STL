#include "dev_util.hpp"
using namespace util;

template <typename X>
void ArrayList<X>::createArray(int capacity)
{
    arr_ptr = new X[capacity];
    this->capacity = capacity;
    lastIndex = -1;
}

template <typename X>
void ArrayList<X>::insert_front(X data)
{
    if (lastIndex == capacity - 1)
        doubleArray(capacity * 2);
    for (int idx = lastIndex + 1; idx >= 1; --idx)
        arr_ptr[idx] = arr_ptr[idx-1];
    lastIndex += 1;
    arr_ptr[0]=data;
}

template <typename X>
void ArrayList<X>::insertAt(int index_location, X data)
{
    if (index_location >= 0 && index_location <= lastIndex + 1)
    {
        if (lastIndex == capacity - 1)
            doubleArray(capacity * 2);
        for (int idx = lastIndex + 1; idx > index_location; --idx)
            arr_ptr[idx] = arr_ptr[idx - 1];
        arr_ptr[index_location] = data;
        lastIndex += 1;
    }
    else
        throw std::range_error("ArrayList::insertAt");
}

template <typename X>
void ArrayList<X>::insert_back(X data)
{
    if (lastIndex == capacity - 1)
        doubleArray(capacity * 2);
    lastIndex += 1;
    arr_ptr[lastIndex] = data;
}

template <typename X>
X &ArrayList<X>::operator[](int idx_data) const
{
    if (idx_data > -1 && idx_data <= lastIndex)
        return arr_ptr[idx_data];
    throw std::out_of_range("ArrayList::[]");
}

template <typename X>
X ArrayList<X>::indexAt(int index_location)
{
    if (index_location > -1 && index_location <= lastIndex)
        return arr_ptr[index_location];
    throw std::out_of_range("ArrayList::indexAt");
}

template <typename X>
void ArrayList<X>::del(int begIndx, int endIndx)
{
    if (lastIndex > -1)
    {
        if (begIndx > -1 && endIndx > -1)
        {
            for (int idx = begIndx+1, indx=0; endIndx+indx <= lastIndex; ++idx, ++indx)
                arr_ptr[idx] = arr_ptr[endIndx + indx];
            lastIndex-=endIndx-(begIndx+1);
        }
        else if (begIndx > -1)
        {
            for (int idx = begIndx; idx < lastIndex; ++idx)
                arr_ptr[idx] = arr_ptr[idx + 1];
            lastIndex -= 1;
        }
        else
            throw std::out_of_range("ArrayList::del");
        if (lastIndex == capacity / 2)
            halfArray(capacity / 2);
    }
    else
        throw std::underflow_error("ArrayList::delete from empty List");
}

template <typename X>
X ArrayList<X>::pop(int index_location)
{
    if (lastIndex > -1)
    {
        if(index_location>-1&&index_location<=lastIndex)
        {
            X valHolder=arr_ptr[index_location];
            for(int idx=index_location; idx<lastIndex; ++idx)
                arr_ptr[idx]=arr_ptr[idx+1];
            lastIndex-=1;
            if(lastIndex==capacity/2)
                halfArray(capacity/2);
            return valHolder;
        }
        throw std::out_of_range("ArrayList::pop");
    }
    else
        throw std::underflow_error("ArrayList::pop from empty List");
}

template <typename X>
void ArrayList<X>::removeItem(X current_data)
{
    if (lastIndex > -1)
        this->pop(this->indexOf(current_data));
    else
        throw std::underflow_error("ArrayList::removeItem from empty List");
}

template <typename X>
void ArrayList<X>::remove_front()
{
    if (lastIndex > -1)
    {
        for(int idx=0; idx<lastIndex; ++idx)
            arr_ptr[idx]=arr_ptr[idx+1];
        lastIndex-=1;
        if (lastIndex == capacity / 2)
            halfArray(capacity / 2);
    }
}

template <typename X>
void ArrayList<X>::removeAll(X data)
{
    if (lastIndex > -1)
        for(int idx=0; idx<=lastIndex; ++idx)
            if(arr_ptr[idx]==data)
            {
                removeItem(idx);
                idx-=1;
            }
}

template <typename X>
void ArrayList<X>::remove_back()
{
    if(lastIndex>-1)
    {
        lastIndex-=1;
        if(lastIndex==capacity/2)
            halfArray(capacity/2);
    }
}

template <typename X>
void ArrayList<X>::update(int index_location, X newData)
{
    if (index_location >= 0 && index_location <= lastIndex)
        arr_ptr[index_location] = newData;
    else
        throw std::out_of_range("ArrayList::update");
}

template <typename X>
void ArrayList<X>::viewList()
{
    if (lastIndex > -1)
        for (int idx = 0; idx <= lastIndex; ++idx)
            std::cout << " " << arr_ptr[idx];
}
