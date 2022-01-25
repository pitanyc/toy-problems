/**
 * LEETCODE 100. Same Tree
 *
 * https://leetcode.com/problems/same-tree/
 *
 * Given the roots of two binary trees p and q, write a function to
 * check if they are the same or not.
 * 
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 */

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inOrder(std::ostream &os, TreeNode* root)
{
    if ( root )
    {
        os << root->val;
    }
    else
    {
        os << 0;
    }
    os << ", ";

    if ( root )
    {
        inOrder(os, root->left);
        inOrder(os, root->right);
    }
}

// Stream operator for Tree.
std::ostream& operator<<(std::ostream &os, TreeNode* root)
{
    os << "[";
    inOrder(os, root);
    os << "]";

    return os;
}

// SOLUTION:  Two pointer approach.  We have 2 pointers: p & q.
//            Do either BFS or DFS on both trees, check each value.
//            Stop and return false at the first difference.
//            Return true as default after BFS and DFS hasn't found any
//            difference.
// 
// Time: O(n)
// Space: O(1)
bool isSameTree(TreeNode* p, TreeNode* q)
{
    // sanity checks
    if (!p && !q)
    {
        // both null
        return true;
    }
    else if (p && !q)
    {
        // q is null
        return false;
    }
    else if (!p && q)
    {
        // p is null
        return false;
    }

    // at this point, both p and q aren't null

    // BFS
    queue<TreeNode*> pQueue;
    queue<TreeNode*> qQueue;
    pQueue.push(p);
    qQueue.push(q);
    while (!pQueue.empty() && !qQueue.empty())
    {
        p = pQueue.front();
        pQueue.pop();

        q = qQueue.front();
        qQueue.pop();

        // cout << "p: " << p << ", q: " << q << endl;

        // compare values
        if (p->val != q->val)
        {
            return false;
        }

        // push children
        if ((p->left && !q->left) || (q->left && !p->left) ||
            (p->right && !q->right) || (q->right && !p->right))
        {
            return false;
        }

        if (p->left)
        {
            pQueue.push(p->left);
            qQueue.push(q->left);
        }
        if (p->right)
        {
            pQueue.push(p->right);
            qQueue.push(q->right);
        }
    }

    // default case
    return true;
}

// Create TreeNode* from vector of int.
TreeNode* insertNode(const vector<int>& nums, TreeNode* root, int i)
{
    // sanity check
    if ( i < nums.size() && nums.at(i) > 0 )
    {
        root = new TreeNode(nums.at(i));
        root->left = insertNode(nums, root->left, 2 * i + 1);
        root->right = insertNode(nums, root->right, 2 * i + 2);
    }

    return root;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    vector<int> input = {1, 2, 3};
    TreeNode* p = insertNode(input, p, 0);
    TreeNode* q = insertNode(input, q, 0);
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    bool output = isSameTree(p, q);
    cout << "output: " << output << endl;
    
    // test case 2
    cout << "====" << endl;
    vector<int> i1 = {1, 2};
    vector<int> i2 = {1, 0, 2};
    p = insertNode(i1, p, 0);
    q = insertNode(i2, q, 0);
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    output = isSameTree(p, q);
    cout << "output: " << output << endl;

    // test case 3
    cout << "====" << endl;
    i1 = {1, 2, 1};
    i2 = {1, 1, 2};
    p = insertNode(i1, p, 0);
    q = insertNode(i2, q, 0);
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    output = isSameTree(p, q);
    cout << "output: " << output << endl;

    return 0;
}
