/**
 * LEETCODE 98. Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/
 *
 * Given a binary tree, determine if it is a valid binary search tree
 * (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than
 * the node's key. The right subtree of a node contains only nodes with
 * keys greater than the node's key. Both the left and right subtrees
 * must also be binary search trees.
 *
 *
 * Example 1:
 *
 *   2
 *  / \
 * 1   3
 *
 * Input: [2,1,3] Output: true
 * 
 * Example 2:
 *
 *    5
 *   / \
 *  1   4
 *     / \
 *    3   6
 *
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4
 */

#include <iostream>
#include <stack>
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

// SOLUTION: A tree is a BST if and only if all the nodes satisfy the
//           BST condition.  Thus, we need to iterate thru all of the nodes
//           using BFS or DFS and check the condition.
// 
// Time: O(n)
// Space: O(n)
bool isBST(TreeNode* root)
{
    // sanity check
    if ( !root )
    {
        return true;
    }

    // iterative DFS, using a stack
    std::stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {
        // pop the top from stack
        TreeNode* node = s.top();
        s.pop();
        std::cout << "node: " << node->val << std::endl;

        // check left
        if (node->left)
        {
            // has left child
            if (node->left->val > node->val)
            {
                // not a BST
                return false;
            }
            s.push(node->left);
        }

        // check right
        if (node->right)
        {
            // has right child
            if (node->right->val < node->val)
            {
                // not a BST
                return false;
            }
            s.push(node->right);
        }
    }

    // base case ==> it's a BST
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
    std::vector<int> input = {2, 1, 3};
    TreeNode* root = insertNode(input, root, 0);
    std::cout << "input = " << root << std::endl;
    bool output = isBST(root);
    std::cout << "output: " << output << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = {5,1,4,0,0,3,6};
    root = insertNode(input, root, 0);
    std::cout << "input = " << root << std::endl;
    output = isBST(root);
    std::cout << "output: " << output << std::endl;

    return 0;
}
