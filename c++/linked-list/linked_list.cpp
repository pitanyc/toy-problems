/**
 * Simple linked list implementation.
 */

#include <vector>

class Node
{
    public:
        int value;
        Node* next;

        Node();
        Node(int value, Node* next);
        ~Node();
};

Node::Node()
    : value(0), next(0)
{
    // no-op
}

Node::Node(int value, Node* next)
    : value(value), next(next)
{
    // no-op
}

Node::~Node()
{
    // no-op
}

//////////////

class LinkedList
{
    public:
        Node* head;
        Node* tail;

        LinkedList();
        LinkedList(const std::vector<int> values);
        ~LinkedList();

        void prepend(int value);
        void append(int value);
};

LinkedList::LinkedList()
    : head(0),
      tail(0)
{
    // no-op
}

LinkedList::LinkedList(const std::vector<int> values)
    : head(0),
      tail(0)
{
    for (unsigned int i = 0; i < values.size(); i++)
    {
        append(values.at(i));
    }
}

LinkedList::~LinkedList()
{
    // potentially de-allocate linked list
}

void LinkedList::prepend(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    if (!tail)
    {
        tail = newNode;
    }
}

void LinkedList::append(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = 0;
    if (tail)
    {
        // tail & head both non-null
        tail->next = newNode;
    }
    else
    {
        // tail & head both null
        tail = newNode;
        head = newNode;
    }
}
