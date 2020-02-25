/**
 * 236. Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two
 * given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common
 * ancestor is defined between two nodes p and q as the lowest node in T
 * that has both p and q as descendants (where we allow a node to be a
 * descendant of itself).”
 *
 * Given the following binary tree: [3,5,1,6,2,0,8,null,null,7,4]
 *
 * Example 1:
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * Example 2:
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a
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

// SOLUTION: Look for both p and q starting at the root.
//           If the root is one of them, simply return the root.
//
//           Otherwise, look for them in BOTH the left and right subtrees.
//
//           If we found BOTH p and q in the left & right subtrees, then
//           the current node is the LCA.  Else, the LCA is on whichever
//           subtree has both p and q.
// 
// Time: O(logn)
// Space: O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // sanity checks
    if (!root)
    {
        return NULL;
    }
    
    // see if we found one of them
    if (root->val == p->val || root->val == q->val)
    {
        // yes, we found one of them
        return root;
    }
    
    // get both left and right LCA
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    // check the result
    if (left && right)
    {
        return root;    // this node is the LCA
    }
    else
    {
        return left ? left : right;     // LCA must be on the left or right
    }
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
    std::vector<int> input = {3,5,1,6,2,0,8,0,0,7,4};
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    TreeNode* root = insertNode(input, root, 0);
    std::cout << "input = " << root << ", p = " << p->val << ", q = " << q->val << std::endl;
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    std::cout << "lca: " << lca->val << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    p = new TreeNode(5);
    q = new TreeNode(4);
    std::cout << "input = " << root << ", p = " << p->val << ", q = " << q->val << std::endl;
    lca = lowestCommonAncestor(root, p, q);
    std::cout << "lca: " << lca->val << std::endl;

    return 0;
}