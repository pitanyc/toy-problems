/**
 * LEETCODE 102. Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 *
 * Given the root of a binary tree, return the level order traversal of
 * its nodes' values. (i.e., from left to right, level by level).
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 * 
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 */

#include <cmath>
#include <iostream>
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
ostream& operator<<(ostream &os, const vector<vector<int>>& arr)
{
    os << "[";
    for ( vector<vector<int>>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << *it;
        if (it + 1 != arr.end()) os << ", ";
    }
    return os << "]";
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

// SOLUTION:  Run BFS on the entire tree.
//            To know when we switch levels:
//              * count all nodes (full tree), including null children
//              * when count on a level reaches 2^level, we increase level
// 
// Time:  O(n)
// Space: O(n)
vector<vector<int>> levelOrder(TreeNode* root)
{
    // what we return
    vector<vector<int>> returnValue;

    // locals
    int level = 0;
    int counter = 0;
    queue<TreeNode*> q;
    q.push(root);

    // run BFS
    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();

        // sanity check
        if (curr)
        {
            if (returnValue.size() < (level + 1))
            {
                // first element in a new vector
                vector<int> result;
                result.push_back(curr->val);
                returnValue.push_back(result);
            }
            else
            {
                // add curr's value to the last vector in returnValue
                returnValue.back().push_back(curr->val);
            }

            // push back children
            q.push(curr->left);
            q.push(curr->right);
        }

        // increase counters
        counter++;
        // cout << "counter: " << counter << ", pow: " << pow(2, level) << endl;
        if (counter == pow(2, level))
        {
            // reached all nodes on this level
            level++;
            counter = 0;
        }
    }

    // finally return
    return returnValue;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    vector<int> input = {3,9,20,0,0,15,7};
    TreeNode* root = insertNode(input, root, 0);
    cout << "root = " << root << endl;
    vector<vector<int>> output = levelOrder(root);
    cout << "output: " << output << endl;
    
    // test case 2
    cout << "====" << endl;
    input = {1};
    root = insertNode(input, root, 0);
    cout << "root = " << root << endl;
    output = levelOrder(root);
    cout << "output: " << output << endl;

    return 0;
}
