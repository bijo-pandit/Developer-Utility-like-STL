//----------------------------------------------------------------QueueArray::
template <typename X>
void QueueArray<X>::createQueue(int capacity)
{
    this->capacity = capacity;
    front = rear = -1;
    arr_ptr = new X[capacity];
}

template <typename X>
void QueueArray<X>::doubleQueue(int capacity)
{
    X *ralloc = new X[capacity];
    int idx, idx_data;
    for (idx = 0, idx_data = front; idx <= this->capacity - 1; ++idx)
    {
        ralloc[idx] = arr_ptr[idx_data];
        if (idx_data == this->capacity - 1 && rear != this->capacity - 1)
            idx_data = 0;
        else
            ++idx_data;
    }
    delete[] arr_ptr;
    arr_ptr = ralloc;
    this->capacity = capacity;
    front = 0;
    rear = this->capacity / 2 - 1;
}

template <typename X>
void QueueArray<X>::halfQueue(int capacity)
{
    X *dalloc = new X[capacity];
    int idx, idx_data;
    for (idx = 0, idx_data = front; idx <= this->capacity - 1; ++idx)
    {
        dalloc[idx] = arr_ptr[idx_data];
        if (idx_data == this->capacity - 1 && rear != this->capacity - 1)
            idx_data = 0;
        else
            ++idx_data;
    }
    delete[] arr_ptr;
    arr_ptr = dalloc;
    this->capacity = capacity;
    front = 0;
    rear = this->capacity - 1;
}

template <typename X>
void QueueArray<X>::insertion(X data)
{
    if ((front == 0 && rear == capacity - 1) || rear + 1 == front)
        doubleQueue(capacity * 2);
    if (rear == -1)
    {
        front = rear = 0;
        arr_ptr[rear] = data;
    }
    else if (rear == capacity - 1)
    {
        rear = 0;
        arr_ptr[rear] = data;
    }
    else
    {
        rear += 1;
        arr_ptr[rear] = data;
    }
}

template <typename X>
void QueueArray<X>::deletion()
{
    if (front != -1)
    {
        if (front == rear)
            front = rear = -1;
        else if (front == capacity - 1)
            front = 0;
        else
            front += 1;
        int size = 0;
        for (int idx = front; idx != rear;)
        {
            ++size;
            if (idx == capacity - 1)
                idx = 0;
            else
                ++idx;
        }
        ++size;
        if (size == capacity / 2)
            halfQueue(capacity / 2);
    }
    else
        throw std::underflow_error("QueueArray::deletion from empty List");
}

template <typename X>
X &QueueArray<X>::peek() const
{
    if (front != -1)
        return arr_ptr[front];
    throw std::underflow_error("QueueArray::peek from empty List");
}

//----------------------------------------------------------------QueueLinkedList::
template <typename X>
void QueueList<X>::insertion(X data)
{
    node *newNode = new node;
    newNode->info = data;
    newNode->next = NULL;
    if (front == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    lastIndex += 1;
}

template <typename X>
void QueueList<X>::deletion()
{
    if (front != NULL)
    {
        node *rnode = front;
        front = front->next;
        lastIndex -= 1;
        delete rnode;
    }
}

template <typename X>
X &QueueList<X>::peek() const
{
    if (front != NULL)
        return front->info;
    throw std::underflow_error("QueueList::peek from empty List");
}
