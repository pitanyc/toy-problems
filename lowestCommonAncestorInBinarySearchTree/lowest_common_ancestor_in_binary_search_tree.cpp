/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 *
 * Given a binary search tree (BST), find the lowest common ancestor
 * (LCA) of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common
 * ancestor is defined between two nodes p and q as the lowest node in T
 * that has both p and q as descendants (where we allow a node to be a
 * descendant of itself).”
 *
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 * Example 1:
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6. 
 * 
 * Example 2:
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a
 * descendant of itself according to the LCA definition.
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // sanity checks
    if (!root || !p || !q)
    {
        // shouldn't happen
        return NULL;
    }
    
    // go left or right in the tree
    bool found = false;
    while (!found)
    {
        if (root->val > max(p->val, q->val)) root = root->left;
        else if (root->val < min(p->val, q->val)) root = root->right;
        else found = true;
    }
    
    // return the root
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
    std::vector<int> input = {6,2,8,0,4,7,9,0,0,3,5};
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    TreeNode* root = insertNode(input, root, 0);
    std::cout << "input = " << root << ", p = " << p->val << ", q = " << q->val << std::endl;
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    std::cout << "lca: " << lca->val << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    p = new TreeNode(2);
    q = new TreeNode(4);
    std::cout << "input = " << root << ", p = " << p->val << ", q = " << q->val << std::endl;
    lca = lowestCommonAncestor(root, p, q);
    std::cout << "lca: " << lca->val << std::endl;

    return 0;
}