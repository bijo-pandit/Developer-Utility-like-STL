//---------------------------------------------------------------- STACK with Dynamic-Array::

template <typename X>
void StackArray<X>::createStack(int capacity)
{
    arr_ptr = new X[capacity];
    this->capacity = capacity;
    top = -1;
}

template <typename X>
void StackArray<X>::push(X data)
{
    if (top == capacity - 1)
        doubleStack(capacity * 2);
    top += 1;
    arr_ptr[top] = data;
}

template <typename X>
X StackArray<X>::pop()
{
    if (top > -1)
    {
        X info = arr_ptr[top];
        top -= 1;
        if (top == capacity / 2)
            halfStack(capacity / 2);
        return info;
    }
    throw std::underflow_error("StackArray::pop from empty List");
}

template <typename X>
X &StackArray<X>::peek() const
{
    if (top > -1)
        return arr_ptr[top];
    throw std::underflow_error("StackArray::peek from empty List");
}


template <typename X>
void StackList<X>::push(X data)
{
    node *newNode = new node;
    newNode->info = data;
    newNode->next = top;
    top = newNode;
    lastIndex += 1;
}

//---------------------------------------------------------------- STACK with LinkedList::
template <typename X>
X StackList<X>::pop()
{
    if (top)
    {
        X info = top->info;
        node *rnode = top;
        top = top->next;
        lastIndex -= 1;
        delete rnode;
        return info;
    }
    throw std::underflow_error("StackList::pop from empty List");
}

template <typename X>
X &StackList<X>::peek() const
{
    if (top)
        return top->info;
    throw std::underflow_error("StackList::peek from empty List");
}

//---------------------------------------------------------------- TwoWayStack with Dynamic-Array::
template <typename X>
void TwoWayStack<X>::createStack(int capacity)
{
    this->capacity=capacity;
    top_right=capacity; //for right_stack which will act like -1 initially
    stk_ptr=new X[capacity];
}

template <typename X>
void TwoWayStack<X>::push_left(X data)
{
    if(top_left+1==top_right)
        doubleStack(capacity*2);
    top_left+=1;
    stk_ptr[top_left]=data;
}

template <typename X>
void TwoWayStack<X>::push_right(X data)
{
    if(top_right-1==top_left)
        doubleStack(capacity*2);
    top_right-=1;
    stk_ptr[top_right]=data;
}

template <typename X>
X& TwoWayStack<X>::peek_left() const
{
    if (top_left > -1)
        return stk_ptr[top_left];
    throw std::underflow_error("StackArray::peek from empty List");
}

template <typename X>
X& TwoWayStack<X>::peek_right() const
{
    if (top_right < capacity)
        return stk_ptr[top_right];
    throw std::underflow_error("StackArray::peek from empty List");
}

template <typename X>
X TwoWayStack<X>::pop_left()
{
    if (top_left > -1)
    {
        X info = stk_ptr[top_left];
        top_left -= 1;
        if((top_left)+capacity-top_right==capacity/2)
            halfStack(capacity/2);
        return info;
    }
    throw std::underflow_error("TwoWayStack::pop from empty List");
}

template <typename X>
X TwoWayStack<X>::pop_right()
{
    if (top_right< capacity)
    {
        X info = stk_ptr[top_right];
        top_right += 1;
        if((top_left)+capacity-top_right==capacity/2)
            halfStack(capacity/2);
        return info;
    }
    throw std::underflow_error("TwoWayStack::pop from empty List");
}
