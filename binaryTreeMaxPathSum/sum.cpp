/**
 * LEETCODE 124. Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only appear
 * in the sequence at most once. Note that the path does not need to pass
 * through the root.
 * 
 * The path sum of a path is the sum of the node's values in the path.
 * 
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 * 
 * Example 1:
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
 * 
 * Example 2:
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
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

// SOLUTION 1: 
//
// Time:  O(n)
// Space: O(1)
int maxPathSum(TreeNode* root)
{
    return 0;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> input = {3,9,20,0,0,15,7};
    TreeNode* root = insertNode(input, root, 0);
    cout << "root: " << root << endl;
    int output = maxPathSum(root);
    cout << "output: " << output << endl;

    // test case 2
    // cout << "====" << endl;
    // input = {3, 2, 1, 0, 4};
    // cout << "input: " << input << endl;
    // output = moveZeros(input);
    // cout << "output: " << output << endl;

    return 0;
}