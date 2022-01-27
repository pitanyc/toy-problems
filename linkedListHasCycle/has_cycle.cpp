/**
 * LEETCODE 141. Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Given head, the head of a linked list, determine if the linked list has
 * a cycle in it.
 *
 * There is a cycle in a linked list if there is some node in the list that
 * can be reached again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next
 * pointer is connected to. Note that pos is not passed as a parameter.
 *
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

// STREAM OPERATOR ==> vector of int
ostream& operator<<(ostream& os, const vector<int>& arr)
{
    os << "[";
    for ( vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++ )
    {
        os << *it;
        if ( it + 1 != arr.end() )
        {
            os << " ";
        }
    }
    os << "]";
    return os;
}

ListNode* buildLinkedList(const vector<int>& input)
{
    if (input.empty())
    {
        return 0;
    }

    ListNode* root = new ListNode(input.at(0));
    ListNode* prev = root;
    for (int i = 1; i < input.size(); i++)
    {
        ListNode* node = new ListNode(input.at(i));
        prev->next = node;
        prev = node;
    }

    prev->next = root;

    return root;
}

// SOLUTION 1: Use 2 pointers, a fast that moves 2 places each time, and
//             a slow that moves only 1 step each time.
//
//             One of 2 things will happen:
//             a) fast reaches the end (NULL) ==> no cycle
//             b) slow and fast point to the same node ==> cycle
//
// Time:  O(n)
// Space: O(1)
bool hasCycle(ListNode* head)
{
    // sanity checks
    if (!head || !head->next)
    {
        return false;
    }

    // at this point, the list has at least 2 elements

    // create 2 pointers, move them until either fast reaches the end
    // OR they point to the same node
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while (fast && slow != fast)
    {
        // advance pointers
        slow = slow->next;
        fast = fast->next;
        // need to be careful with fast (eg: linked list with just 2 elements)
        if (fast)
        {
            fast = fast->next;
        }
    }

    return (slow == fast);
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> input = {3, 2, 0, -4};
    ListNode* root = buildLinkedList(input);
    cout << "input: " << input << endl;
    bool output = hasCycle(root);
    cout << "output: " << output << endl;

    // test case 2
    // cout << "====" << endl;
    // input = {3, 2, 1, 0, 4};
    // cout << "input: " << input << endl;
    // output = moveZeros(input);
    // cout << "output: " << output << endl;

    return 0;
}