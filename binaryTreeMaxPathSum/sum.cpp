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
    if ( i < nums.size() && nums.at(i) != 0 )
    {
        root = new TreeNode(nums.at(i));
        root->left = insertNode(nums, root->left, 2 * i + 1);
        root->right = insertNode(nums, root->right, 2 * i + 2);
    }

    return root;
}

// SOLUTION 1: We can only split (go left and right) at one node and one 
//             node only.  But we don't have to split at any node, it's
//             also fine to not split at all.
// 
//             The maximum value obtained from a left or right subtree is
//             optional, meaning we don't have to take any left or right subtree
//             if it's less than 0 (making the total sum smaller).
//
//             Here is the algorithm:
//             1. Have a global max, initialize it to the root's value.
//             2. Using DFS, calculate the max value of each subtree.  The
//                leaf value is just the node value on the leaf.
//             3. At each non-leaf, calculate 2 values:
//                * value if we split at this node = node val + leftTree + rightTree
//                * value if we didn't split at this node = node val + max(leftTree, rightTree, 0)
//             4. Update global max if any of those is bigger than current global max.
//             5. Return to caller the unsplit value (which means the most)
//                we can get from this subtree without a split).
//
// Time:  O(n)
// Space: O(1)
int dfs(TreeNode* root, int& maxSum)
{
    // base case
    if (!root)
    {
        return 0;
    }

    // root isn't null at this point

    // calculate left and right subtree values
    int leftTree = dfs(root->left, maxSum);
    int rightTree = dfs(root->right, maxSum);

    // check if we did split at this node
    int splitValue = root->val + leftTree + rightTree;
    maxSum = max(maxSum, splitValue);

    int unsplitValue = root->val + max(max(leftTree, rightTree), 0);

    return unsplitValue;
}

int maxPathSum(TreeNode* root)
{
    int maxSum = INT32_MIN;
    dfs(root, maxSum);
    return maxSum;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> input = {1,2,3};
    TreeNode* root = insertNode(input, root, 0);
    cout << "root: " << root << endl;
    int output = maxPathSum(root);
    cout << "output: " << output << endl;

    // test case 2
    cout << "====" << endl;
    input = {-10,9,20,0,0,15,7};
    root = insertNode(input, root, 0);
    cout << "root: " << root << endl;
    output = maxPathSum(root);
    cout << "output: " << output << endl;

    return 0;
}