/**
 * Delete middle of linked list Given a singly linked list, delete
 * middle of the linked list.
 * 
 * For example: 1->2->3->4->5, pointer to 3
 * Output: 1->2->4->5 
 */

#include <iostream>

class Node
{
public:
  int value;
  Node *next;

public:
  Node();
  ~Node();
};

Node::Node()
    : value(0), next(0)
{
  // no-op
}

Node::~Node()
{
  // no-op
}

class LinkedList
{
private:
  Node *head;

public:
  LinkedList();
  ~LinkedList();

  Node *add(int value);
  void removeNode(Node *node);

  void asString() const;
};

LinkedList::LinkedList()
    : head(0)
{
  // no-op
}

LinkedList::~LinkedList()
{
  // potentially de-allocate linked list
}

Node *LinkedList::add(int value)
{
  Node *node = new Node();
  node->value = value;
  node->next = head;
  head = node;

  return node;
}

void LinkedList::removeNode(Node *node)
{
  while (node->next)
  {
    node->value = node->next->value;
    node->next = node->next->next;
    node = node->next;
  }
}

void LinkedList::asString() const
{
  Node *copy = head;
  while (copy)
  {
    std::cout << "value: " << copy->value << '\n';
    copy = copy->next;
  }
}

int main(int argc, char const *argv[])
{
  // create test case
  LinkedList list;
  list.add(5);
  list.add(4);
  Node *middle = list.add(3);
  list.add(2);
  list.add(1);

  // debug
  list.asString();

  // call routine
  list.removeNode(middle);

  // print after
  std::cout << "====" << '\n';
  list.asString();

  return 0;
}
