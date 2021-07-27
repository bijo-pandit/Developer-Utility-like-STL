#ifndef DEV_UTIL_HPP_INCLUDED
#define DEV_UTIL_HPP_INCLUDED
#define ASC 0
#define DESC 1
namespace util
{
template <typename X>
class ArrayList
{
private:
    int capacity;
    int lastIndex;
    X *arr_ptr;

    void doubleArray(int);
    void halfArray(int);

public:
    ArrayList();
    ~ArrayList();
    void createArray(int);
    int indexOf(X, int = -1, int = -1);
    int bin_search(X);
    void bubble_sort(int = -1);
    void revList();
    //sorting function();
    void insert_front(X);
    void insert_back(X);
    void insertAt(int, X);
    void fillItem(X);
    void extend(ArrayList &);
    void update(int, X);

    X &operator[](int) const;
    X indexAt(int);

    X &frontItem() const;
    X &endItem() const;
    bool isListEmpty(); //Yes->1 No->0
    bool isListFull();

    void del(int = -1, int = -1);
    X pop(int);
    void removeItem(X);
    void remove_front();
    void remove_back();
    void removeAll(X);
    void release();

    int countItems();
    bool isEqualTo(ArrayList &);
    int totalMemCapacity();
    void viewList();
};

template <typename X>
class LinkedList
{
private:
    struct node
    {
        X info;
        node *next;
    };
    node *start;
    int lastIndex;
    void insertAfter(X, X);

public:
    LinkedList();
    ~LinkedList();

    int bin_search(X);
    int indexOf(X, int = -1, int = -1);
    //sorting function();
    void insert_front(X);
    void insert_back(X);
    void insertAt(int, X);

    void del(int = -1, int = -1);
    X pop(int);
    void removeItem(X);
    void remove_front();
    void remove_back();

    X &frontItem() const;
    X &endItem() const;
    bool isListEmpty(); //Yes->1 No->0

    int countItems();
    void fillItem(X);
    void extend(LinkedList &);

    X &operator[](int) const;
    void revList();

    void viewList();
};

template <typename X>
class DLL
{
private:
    struct node
    {
        node *prev;
        X info;
        node *next;
    };
    node *start;
    int lastIndex;
    void insertAfter(X, X);

public:
    DLL();
    ~DLL();
    int bin_search(X);
    int indexOf(X,int = -1, int = -1);
    //sorting function();
    void insert_front(X);
    void insert_back(X);
    void insertAt(int, X);

    void del(int = -1, int = -1);
    X pop(int);
    void removeItem(X);
    void remove_front();
    void remove_back();

    X &frontItem() const;
    X &endItem() const;
    bool isListEmpty(); //Yes->1 No->0
    int countItems();
    void fillItem(X);
    void extend(DLL &);
    X &operator[](int) const;
    void revList();
    void viewList();
};

template <typename X>
class CLL
{
private:
    struct node
    {
        X info;
        node *next;
    };
    node *last;
    int lastIndex;
    void insertAfter(X, X);

public:
    CLL();
    ~CLL();
    int bin_search(X);
    int indexOf(X,int = -1, int = -1);
        //sorting function(); like void sortItems(int = -1);
    void insert_front(X);
    void insert_back(X);
    void insertAt(int, X);
    void extend(CLL &);

    void del(int = -1, int = -1);
    X pop(int);
    void removeItem(X);
    void remove_front();
    void remove_back();

    X &frontItem() const;
    X &endItem() const;
    bool isListEmpty(); //Yes->1 No->0
    int countItems();
    void fillItem(X);
    X &operator[](int) const;
    void viewList();
};

template <typename X>
class CDLL
{
private:
    struct node
    {
        node *prev;
        X info;
        node *next;
    };
    node *start;
    int lastIndex;
    void insertAfter(X, X);

public:
    CDLL();
    ~CDLL();
    int bin_search(X);
    int indexOf(X,int = -1, int = -1);
       //sorting function(); like void sortItems(int = -1);
    void insert_front(X);
    void insert_back(X);
    void insertAt(int, X);
    void extend(CDLL &);

    void del(int = -1, int = -1);
    X pop(int);
    void removeItem(X);
    void remove_front();
    void remove_back();

    X &frontItem() const;
    X &endItem() const;
    bool isListEmpty(); //Yes->1 No->0
    int countItems();
    void fillItem(X);
    X &operator[](int) const;
    void viewList();
};

template <typename X1, typename X2>
class pairList
{
private:
    struct node
    {
        X1 T1;
        X2 T2;
        node *next;
    };
    node *last;
    int lastIndex;

public:
    pairList();
    ~pairList();
    void append(X1, X2);
    void remove_front();
    void remove_back();
    //void removeFrom(int = -1, int = -1);
    X1 &first() const;
    X2 &second() const;

    bool isListEmpty(); //Yes->1 No->0
    int countItems();
    void update(int,X1, X2);
    void viewList();
};

template <typename X>
class StackArray
{
private:
    int capacity;
    int top;
    X *arr_ptr;

    void doubleStack(int);
    void halfStack(int);

public:
    StackArray();
    ~StackArray();
    void createStack(int);
    void push(X);
    X pop();
    X &peek() const;
    void extend(StackArray &);
    void release();
    bool isStackEmpty();
    bool isStackFull();
    int countItems();
};

template <typename X>
class StackList
{
private:
    struct node
    {
        X info;
        node *next;
    };
    node *top;
    int lastIndex;

public:
    StackList();
    ~StackList();
    void push(X);
    X pop();
    X &peek() const;
    void extend(StackList &);
    bool isStackEmpty();
    int countItems();
};

template <typename X>
class TwoWayStack
{
private:
    int capacity;
    int top_left;
    int top_right;
    X *stk_ptr;
    void doubleStack(int);
    void halfStack(int);

public:
    TwoWayStack();
    ~TwoWayStack();

    void createStack(int);
    void push_left(X);
    void push_right(X);
    X &peek_left() const;
    X &peek_right() const;
    X pop_left();
    X pop_right();
    void leftFill(X);
    void rightFill(X);
    void extend(TwoWayStack &);
    void release();
    bool isEmptyLeft();
    bool isEmptyRight();
    bool isStackFull();
    int countItems();

    void viewLeftStack();
    void viewRightStack();
};

template <typename X>
class QueueArray
{
private:
    int capacity;
    int front, rear;
    X *arr_ptr;

    void doubleQueue(int);
    void halfQueue(int);

public:
    QueueArray();
    ~QueueArray();
    void createQueue(int);
    void insertion(X);
    void deletion();

    X &frontItem() const;
    X &endItem() const;
    void extend(QueueArray &);
    void release();

    bool isQueueEmpty();
    bool isQueueFull();
    X &peek() const;
    int countItems();
};

template <typename X>
class QueueList
{
private:
    struct node
    {
        X info;
        node *next;
    };
    node *front, *rear;
    int lastIndex;

public:
    QueueList();
    ~QueueList();
    void insertion(X);
    void deletion();
    X &peek() const;

    X &frontItem() const;
    X &endItem() const;
    void extend(QueueList &);

    bool isQueueEmpty();
    int countItems();
};
}
#include "iostream"
#include "dev_algo.cpp"
#include "dev_util.cpp"
#include "__arrayList__.cpp"
#include "__LinkedList__.cpp"
#include "__stackList__.cpp"
#include "__queueList__.cpp"
#endif // DEV_UTIL_HPP_INCLUDED
