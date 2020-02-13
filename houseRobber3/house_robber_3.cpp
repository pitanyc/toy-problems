/**
 * LEETCODE 337. House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/
 *
 * The thief has found himself a new place for his thievery again. There
 * is only one entrance to this area, called the "root." Besides the
 * root, each house has one and only one parent house. After a tour, the
 * smart thief realized that "all houses in this place forms a binary
 * tree". It will automatically contact the police if two
 * directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight
 * without alerting the police.
 *
 * Example 1:
 * 
 * Input: [3,2,3,null,3,null,1]
 *
 *   3
 *  / \
 * 2   3
 *  \   \ 
 *   3   1
 *
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * Example 2:
 * 
 * Input: [3,4,5,1,3,null,1]
 *
 *   3
 *  / \
 * 4   5
  / \   \ 
 * 1   3   1
 *
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 */

#include <iostream>
#include <queue>
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

std::ostream& operator<<(std::ostream &os, TreeNode* root)
{
    os << "[";
    inOrder(os, root);
    os << "]";

    return os;
}

// SOLUTION 1: BFS using a Queue.
// 
// If you want to use DFS, then you need to keep a track of the levels.
// With BFS, you can simply put in a counter while visiting each node on a level.
// Once the counter is a power of 2, we flip the flag from the previous state.
//
// But this algorithm requires nodes to be visited in level order, ie, BFS.
//
// Time: O(n)
// Space: O(n)
int bfs(TreeNode* root)
{
    // sanity check
    if ( !root )
    {
        return 0;
    }

    // what we return
    int value = 0;

    // locals
    bool flag = false;
    int count = 0;
    int level = 1;

    std::queue<TreeNode*> q;
    q.push(root);
    while ( !q.empty() )
    {
        TreeNode* node = q.front();
        q.pop();

        // update counters, flag state
        count++;
        if ( count >= level )
        {
            flag = !flag;
            level *= 2;
        }

        if ( node )
        {
            // only include this value if flag is currently set
            // std::cout << "node: " << node->val << " | flag: " << flag << ", count: " << count << ", level: " << level << std::endl;
            if ( flag )
            {
                value += node->val;
            }

            // push children to queue
            q.push(node->left);
            q.push(node->right);
        }
    }

    // finally return
    // std::cout << "value: " << value << std::endl;
    return value;
}

// SOLUTION: std::max() of the root or the sum of its 2 children.
int rob(TreeNode* root)
{
    // return dfs(root->left);
    return std::max(bfs(root),
                    bfs(root->left) + bfs(root->right));
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
    std::vector<int> input = {3, 2, 3, 0, 3, 0, 1};
    TreeNode* root = insertNode(input, root, 0);
    std::cout << "input = " << root << std::endl;
    int output = rob(root);
    std::cout << "output: " << output << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = {3, 4, 5, 1, 3, 0, 1};
    root = insertNode(input, root, 0);
    std::cout << "input: " << root << std::endl;
    output = rob(root);
    std::cout << "output: " << output << std::endl;

    return 0;
}
