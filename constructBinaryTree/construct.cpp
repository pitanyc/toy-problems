/**
 * LEETCODE 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * Given two integer arrays preorder and inorder where preorder is the
 * preorder traversal of a binary tree and inorder is the inorder traversal
 * of the same tree, construct and return the binary tree.
 * 
 * Example 1:
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * Example 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
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

// STREAM OPERATOR ==> vector of vector of int
ostream& operator<<(ostream& os, const vector<vector<int>>& arr)
{
    os << endl;
    for ( vector<vector<int>>::const_iterator it = arr.begin(); it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if ( it + 1 != arr.end() )
            os << endl;
    }
    return os;
}

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

// SOLUTION 1: Two observations:
//               * the root is ALWAYS the first element in the preorder array
//               * all left children of the root are in the inorder array before
//                 the root
//
//             Here is the algorithm:
//             1. Get the root from the preorder array
//             2. Get the index of the root in the inorder array
//             3. Get the left subtree from the inorder array
//             4. Get the right subtree from the inorder array
//
// Time:  O(n)
// Space: O(1)
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    // check if we reached a leaf node
    if ( preorder.empty() || inorder.empty() )
    {
        return 0;
    }

    // root is always the first element of the preorder array
    TreeNode* root = new TreeNode(preorder[0]);

    // find root in the inorder array
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder[0]);

    // cut inorder array in two parts
    vector<int> leftInorder(inorder.begin(), it);
    vector<int> rightInorder(it + 1, inorder.end());

    // cut preorder array in two parts
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftInorder.size() + 1);
    vector<int> rightPreorder(preorder.begin() + leftInorder.size() + 1, preorder.end());

    // build left subtree
    root->left = buildTree(leftPreorder, leftInorder);

    // build right subtree
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    cout << "preorder: " << preorder << endl;
    cout << "inorder: " << inorder << endl;
    TreeNode* output = buildTree(preorder, inorder);
    cout << "output: " << output << endl;

    // test case 2
    // cout << "====" << endl;
    // input = {3, 2, 1, 0, 4};
    // cout << "input: " << input << endl;
    // output = moveZeros(input);
    // cout << "output: " << output << endl;

    return 0;
}