/**
 * LEETCODE 429. N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 *
 * Given a binary tree, add a pointer to each node that points to the
 * next node in its same level.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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

// SOLUTION: We need to visit each node using a BFS.
//
//           If a node HAS a right sibling, then set node->next to that.
//           The key is to push into a queue a PAIR of things:
//           std::pair<level, Node*>.
// 
// Time: O(n)
// Space: O(n)
TreeNode* setNext(TreeNode* root)
{
    // sanity check
    if ( !root )
    {
        return NULL;
    }

    // locals
    int lastLevel = -1;
    TreeNode* lastNode = NULL;

    // iterative BFS, using a queue
    std::queue<std::pair<int, TreeNode*>> q;
    q.push(std::make_pair(0, root));
    while (!q.empty())
    {
        std::pair<int, TreeNode*> p = q.front();
        int level = p.first;
        TreeNode* node = p.second;
        q.pop();

        // check the level we are on
        if (level == lastLevel)
        {
            // same level as last level ==> create next pointer
            lastNode->next = node;
        }
        else
        {
            // new level
            lastLevel = level;
        }
        lastNode = node;

        // check left
        if (node->left)
        {
            // has left
            q.push(std::make_pair(level + 1, node->left));
        }

        // check right
        if (node->right)
        {
            // has right
            q.push(std::make_pair(level + 1, node->right));
        }
    }

    return root;
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
    root = setNext(root);
    std::cout << "output: " << root << std::endl;
    
    // test case 2
    // std::cout << "\n====\n" << std::endl;
    // input = {5,1,4,0,0,3,6};
    // root = insertNode(input, root, 0);
    // std::cout << "input = " << root << std::endl;
    // output = isBST(root);
    // std::cout << "output: " << output << std::endl;

    return 0;
}
