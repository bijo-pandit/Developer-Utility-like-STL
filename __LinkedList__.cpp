#include "dev_util.hpp"
using namespace util;
template <typename X>
void LinkedList<X>::insert_front(X data)
{
    node *newNode = new node;
    newNode->info = data;
    newNode->next = start;
    start = newNode;
    lastIndex += 1;
}

template <typename X>
void LinkedList<X>::insertAt(int index_node_location, X data)
{
    if(index_node_location>-1 && index_node_location<=lastIndex+1)
        if(start==NULL)
            insert_front(data);
        else
        {
            node *nptr=start;
            for(int idx=0; idx<index_node_location-1; ++idx, nptr=nptr->next);
            if(index_node_location-1==-1)
                insert_front(data);
            else
                insertAfter(nptr->info,data);
        }
    else
        throw std::range_error("LinkedList::insertAt");
}

template <typename X>
void LinkedList<X>::insert_back(X data)
{
    node *newNode = new node;
    newNode->info = data;
    newNode->next = NULL;
    if (start == NULL)
        start = newNode;
    else
    {
        node *nptr = start;
        for (nptr; nptr->next != NULL; nptr = nptr->next)
            ;
        nptr->next = newNode;
    }
    lastIndex += 1;
}

template <typename X>
void LinkedList<X>::remove_front()
{
    if (start)
    {
        node *rnode = start;
        start = start->next;
        lastIndex -= 1;
        delete rnode;
    }
}

template <typename X>
void LinkedList<X>::remove_back()
{
    if (start)
    {
        node *t1, *t2;
        for (t1 = start, t2 = NULL; t1->next != NULL; t1 = t1->next)
            t2 = t1;
        if (t2 != NULL)
            t2->next = NULL;
        else
            start = NULL;
        delete t1;
        lastIndex -= 1;
    }
}

template <typename X>
void LinkedList<X>::del(int begIndx, int endIndx)
{
    if (lastIndex > -1)
    {
        node *nptr = start;
        int idx;
        if (begIndx > -1 && endIndx > -1)
        {
            if (begIndx != -1)
                for (idx = 0; idx < begIndx; ++idx, nptr = nptr->next)
                    ;
            for (idx = begIndx + 1, nptr = nptr->next; idx <= endIndx - 1; idx++, nptr = nptr->next)
                nptr=nptr->next;
            lastIndex-=endIndx-(begIndx+1);
        }
        else if (begIndx > -1)
        {
            for (idx = begIndx + 1, nptr = nptr->next; idx <= lastIndex; ++idx, nptr = nptr->next)
                nptr=nptr->next;
            lastIndex -= 1;
        }
        else
            throw std::out_of_range("Linked::del");
    }
    else
        throw std::underflow_error("Linked::delete from empty List");
}

template <typename X>
X LinkedList<X>::pop(int index_location)
{
    if (start)
    {
        if(index_location>-1&&index_location<=lastIndex)
        {
            node nptr=start;
            while(index_location)
            {
                nptr=nptr->next;
                index_location-=1;
            }
            X valHolder=nptr->info;
            this->removeItem(nptr->info);
            return valHolder;
        }
        throw std::out_of_range("Linked::pop");
    }
    else
        throw std::underflow_error("Linked::pop from empty List");
}

template <typename X>
void LinkedList<X>::removeItem(X current_data)
{
    if (start)
    {
        node *rnode, *current_node;
        for (current_node = start; current_node; current_node = current_node->next)
            if (current_node->info == current_data)
                break;
        if (current_node != NULL)
        {
            if (start == current_node)
                start = current_node->next;
            else
            {
                for (rnode = start; rnode->next != current_node; rnode = rnode->next)
                    ;
                rnode->next = current_node->next;
            }
            lastIndex -= 1;
            delete current_node;
        }
    }

}

template <typename X>
X &LinkedList<X>::operator[](int idx_data) const
{
    if (idx_data > -1 && idx_data <= lastIndex)
    {
        node *nptr = start;
        for (nptr; idx_data; nptr = nptr->next, idx_data -= 1)
            ;
        return nptr->info;
    }
    throw std::out_of_range("LinkedList::[]");
}

template <typename X>
void LinkedList<X>::viewList()
{
    node *nptr = start;
    for (nptr; nptr; nptr = nptr->next)
        std::cout << " " << nptr->info;
}

template <typename X>
void DLL<X>::insert_front(X data)
{
    node *newNode = new node;
    newNode->info = data;
    newNode->prev = NULL;
    newNode->next = start;
    if (start != NULL)
        start->prev = newNode;
    start = newNode;
    lastIndex += 1;
}

template <typename X>
void DLL<X>::insertAt(int index_node_location, X data)
{
    if(index_node_location>-1 && index_node_location<=lastIndex+1)
        if(start==NULL)
            insert_front(data);
        else
        {
            node *nptr=start;
            for(int idx=0; idx<index_node_location-1; ++idx, nptr=nptr->next);
            if(index_node_location-1==-1)
                insert_front(data);
            else
                insertAfter(nptr->info,data);
        }
    else
        throw std::range_error("DLL::insertAt");
}

template <typename X>
void DLL<X>::insert_back(X data)
{
    node *newNode = new node;
    newNode->info = data;
    newNode->next = NULL;
    if (start == NULL)
    {
        newNode->prev = NULL;
        start = newNode;
    }
    else
    {
        node *nptr = start;
        for (nptr; nptr->next != NULL; nptr = nptr->next)
            ;
        newNode->prev = nptr;
        nptr->next = newNode;
    }
    lastIndex += 1;
}

template <typename X>
void DLL<X>::remove_front()
{
    if (start)
    {
        node *rnode = start;
        if (rnode->next != NULL)
            rnode->next->prev = NULL;
        start = start->next;
        lastIndex -= 1;
        delete rnode;
    }
}

template <typename X>
void DLL<X>::remove_back()
{
    if (start != NULL)
    {
        node *rnode = start;
        while (rnode->next != NULL)
            rnode = rnode->next;
        if (rnode != start)
            rnode->prev->next = NULL;
        else
            start = NULL;
        lastIndex -= 1;
        delete rnode;
    }
}

template <typename X>
X DLL<X>::pop(int index_location)
{
    if (start)
    {
        if(index_location>-1&&index_location<=lastIndex)
        {
            node nptr=start;
            while(index_location)
            {
                nptr=nptr->next;
                index_location-=1;
            }
            X valHolder=nptr->info;
            this->removeItem(nptr->info);
            return valHolder;
        }
        throw std::out_of_range("Linked::pop");
    }
    else
        throw std::underflow_error("Linked::pop from empty List");
}

template <typename X>
void DLL<X>::removeItem(X current_data)
{
    if (start)
    {
        node *current_node;
        for (current_node = start; current_node; current_node = current_node->next)
            if (current_node->info == current_data)
                break;
        if (current_node != NULL)
        {
            if (current_node->prev == NULL)
            {
                start = current_node->next;
                start->prev = NULL;
            }
            else if (current_node->next == NULL)
                current_node->prev->next = NULL;
            else
            {
                current_node->prev->next = current_node->next;
                current_node->next->prev = current_node->prev;
            }
            delete current_node;
        }
        lastIndex -= 1;
    }
}

template <typename X>
X &DLL<X>::operator[](int idx_data) const
{
    if (idx_data > -1 && idx_data <= lastIndex)
    {
        node *nptr = start;
        for (nptr; idx_data; nptr = nptr->next, idx_data -= 1)
            ;
        return nptr->info;
    }
    throw std::out_of_range("DLL::[]");
}

template <typename X>
void DLL<X>::viewList()
{
    node *nptr = start;
    for (nptr; nptr; nptr = nptr->next)
        std::cout << " " << nptr->info;
}

template <typename X>
void CLL<X>::insert_front(X data)
{
    node *newNode = new node;
    newNode->info = data;
    if (last == NULL)
        last = newNode;
    else
        newNode->next = last->next;
    last->next = newNode;
    lastIndex += 1;
}

template <typename X>
void CLL<X>::insertAt(int index_node_location, X data)
{
    if(index_node_location>-1 && index_node_location<=lastIndex+1)
        if(last==NULL)
            insert_front(data);
        else
        {
            node *nptr=last->next;
            for(int idx=0; idx<index_node_location-1; ++idx, nptr=nptr->next);
            if(index_node_location-1==-1)
                insert_front(data);
            else
                insertAfter(nptr->info,data);
        }
    else
        throw std::range_error("CLL::insertAt");
}

template <typename X>
void CLL<X>::insert_back(X data)
{
    node *newNode = new node;
    newNode->info = data;
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

template <typename X>
void CLL<X>::remove_front()
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

template <typename X>
void CLL<X>::remove_back()
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

template <typename X>
X CLL<X>::pop(int index_location)
{
    if (last)
    {
        if(index_location>-1&&index_location<=lastIndex)
        {
            node nptr=last->next;
            while(index_location)
            {
                nptr=nptr->next;
                index_location-=1;
            }
            X valHolder=nptr->info;
            this->removeItem(nptr->info);
            return valHolder;
        }
        throw std::out_of_range("Linked::pop");
    }
    else
        throw std::underflow_error("Linked::pop from empty List");
}

template <typename X>
void CLL<X>::removeItem(X current_data)
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
        }
        while (current_node != last->next);
    }
}

template <typename X>
X &CLL<X>::operator[](int idx_data) const
{
    if (idx_data > -1 && idx_data <= lastIndex)
    {
        node *nptr = last->next;
        while (idx_data)
        {
            nptr = nptr->next;
            idx_data -= 1;
        }
        return nptr->info;
    }
    throw std::out_of_range("CLL::[]");
}

template <typename X>
void CLL<X>::viewList()
{
    if (last != NULL)
    {
        node *nptr = last->next;
        do
        {
            std::cout<<" "<< nptr->info;
            nptr = nptr->next;
        }
        while (nptr != last->next);
    }
}

template <typename X>
void CDLL<X>::insert_front(X data)
{
    node *newNode = new node;
    newNode->info = data;
    if (start == NULL)
        start = newNode;
    else
    {
        newNode->prev = start->prev;
        newNode->prev->next = newNode;
    }
    newNode->next = start;
    start->prev = newNode;
    start = newNode; //start me newNodeKoAddKarneKeLiye after rest of mechanism
    lastIndex += 1;
}

template <typename X>
void CDLL<X>::insertAt(int index_node_location, X data)
{
    if(index_node_location>-1 && index_node_location<=lastIndex+1)
        if(start==NULL)
            insert_front(data);
        else
        {
            node *nptr=start->next;
            for(int idx=0; idx<index_node_location-1; ++idx, nptr=nptr->next);
            if(index_node_location-1==-1)
                insert_front(data);
            else
                insertAfter(nptr->info,data);
        }
    else
        throw std::range_error("CDLL::insertAt");
}

template <typename X>
void CDLL<X>::insert_back(X data)
{
    node *newNode = new node;
    newNode->info = data;
    if (start == NULL)
        start = newNode;
    else
    {
        newNode->prev = start->prev;
        newNode->prev->next = newNode;
    }
    newNode->next = start;
    start->prev = newNode;
    lastIndex += 1;
}

template <typename X>
void CDLL<X>::remove_front()
{
    if (start != NULL)
    {
        node *rnode = start;
        if (start->prev == start)
            start = NULL;
        else
        {
            start->next->prev = start->prev;
            start->prev->next = start->next;
            start = start->next;
        }
        lastIndex -= 1;
        delete rnode;
    }
}

template <typename X>
void CDLL<X>::remove_back()
{
    if (start != NULL)
    {
        node *rnode = start->prev;
        if (start->prev == start)
            start = NULL;
        else
        {
            start->prev->prev->next = start;
            start->prev = start->prev->prev;
        }
        lastIndex -= 1;
        delete rnode;
    }
}

template <typename X>
X CDLL<X>::pop(int index_location)
{
    if (start)
    {
        if(index_location>-1&&index_location<=lastIndex)
        {
            node nptr=start;
            while(index_location)
            {
                nptr=nptr->next;
                index_location-=1;
            }
            X valHolder=nptr->info;
            this->removeItem(nptr->info);
            return valHolder;
        }
        throw std::out_of_range("Linked::pop");
    }
    else
        throw std::underflow_error("Linked::pop from empty List");
}

template <typename X>
void CDLL<X>::removeItem(X current_data)
{
    if (start)
    {
        node *current_node = start;
        do
        {
            if (current_node->info == current_data)
            {
                if (start->prev == start)
                    start = NULL;
                else
                {
                    current_node->prev->next = current_node->next;
                    current_node->next->prev = current_node->prev;
                    if (current_node == start)
                        start = current_node->next;
                }
                lastIndex -= 1;
                delete current_node;
                break;
            }
            current_node = current_node->next;
        }
        while (current_node != start);
    }
}

template <typename X>
X &CDLL<X>::operator[](int idx_data) const
{
    if (idx_data > -1 && idx_data <= lastIndex)
    {
        node *nptr = start;
        while (idx_data)
        {
            nptr = nptr->next;
            idx_data -= 1;
        }
        return nptr->info;
    }
    throw std::out_of_range("CDLL::[]");
}

template <typename X>
void CDLL<X>::viewList()
{
    node *nptr = start;
    do
    {
        std::cout<<" "<< nptr->info;
        nptr = nptr->next;
    }
    while (nptr != start);
}
