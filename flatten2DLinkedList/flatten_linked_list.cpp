/**
 * LEETCODE 430. Flatten a Multilevel Doubly Linked List
 *
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 *
 * Imagine a linked list with not just a next node, but a down node as
 * well. We want to write a function that would "Flatten" that linked
 * list by taking all the downward segments and merging them up between
 * their parent and their parent's next.
 *
 * If we have something like this:
 *
 * [1] -> [2] -> [3] -> [8] -> [10]
 *                |      |
 *                |     [9]
 *                |
 *               [4] -> [5] -> [6]
 *                              |
 *                             [7]
 * after flatten, it should look like this:
 *
 * [1] -> [2] -> [3] -> [4] -> [5] -> [6] -> [7] -> [8] -> [9] -> [10]
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stack>

struct Node
{
    Node* next;
    Node* down;
    int value;
};

std::ostream& operator<<(std::ostream &os, const std::stack<Node*>& arr)
{
    os << "size: " << arr.size() << std::endl;
    if (arr.size() > 0)
    {
        os << "top: " << arr.top() << std::endl;
    }
    return os;
}

// SOLUTION: Iterative, in place.
void flatten(Node* head)
{
    // to keep track of where to come back to
    std::stack<Node*> s;

    // sanity checks
    while (head)
    {
        // at this point, head is not null
        if (head->down)
        {
            // we have a down link
            if (head->next) s.push(head->next); // to save out head's next pointer
            head->next = head->down;            // next becomes down
            head->down = 0;                     // remove down link
        }

        // check if we need to pop from the stack
        // std::cout << "111 head->next: " << head->next << std::endl;
        if (!head->next && !s.empty())
        {
            head->next = s.top();
            s.pop();
        }

        // move on to the next node
        // std::cout << "222 head->next: " << head->next << std::endl;
        head = head->next;
    }
}

int main(int argc, char* argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* nodes[10];

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        Node* node = (Node*)malloc(sizeof(Node));
        memset(node, 0, sizeof(Node)); //clear all bytes;
        nodes[i] = node; //store it
        node->value = a[i];
    }

    //construct an 2d linked list

    /* level 1 */
    nodes[0]->next = nodes[1];
    nodes[1]->next = nodes[2];
    nodes[2]->down = nodes[3];
    nodes[2]->next = nodes[7];
    nodes[7]->down = nodes[8];
    nodes[7]->next = nodes[9];

    /* level 2 */
    nodes[3]->next = nodes[4];
    nodes[4]->next = nodes[5];

    /* level 3 */
    nodes[5]->down = nodes[6];

    Node* head = nodes[0];
    /* print all nodes BEFORE */
    printf("Before: ");
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");

    head = nodes[0];
    flatten(head);

    /* print all nodes AFTER*/
    printf("After: ");
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");

    return 0;
}