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
#include <math.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream &os, const std::vector<int> arr)
{
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

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

// SOLUTION 1: Sum up all values on the same level into a single number.
//             Create a vector of ints that shows the total value that
//             can be robbed at each level.  Then, simply run the 
//             house robber 1 algorithm to find the maximum amount that
//             can be robbed.
//
//             To sum up the values on each level, use BFS with a queue.
//
// Time: O(n)
// Space: O(n)
vector<int> bfs(TreeNode* root)
{
    // sanity check
    if ( !root )
    {
        return {0};
    }

    // what we return
    vector<int> returnValue;

    // locals
    int level = 0;
    int count = 0;
    int sum = 0;

    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeNode* node = queue.front();
        queue.pop();

        // update locals
        count++;
        if ( node )
        {
            sum += node->val;
            // always push left and right children
            queue.push(node->left);
            queue.push(node->right);
        }

        // cout << "count: " << count << ", sum: " << sum << endl;

        // figure out if this is a level change
        if ( count == (int)pow(2, level) )
        {
            // this is the last node on this level
            returnValue.push_back(sum);

            // re-init locals
            count = 0;
            sum = 0;
            level++;
        }
    }

    // finally return
    cout << "returnValue: " << returnValue << std::endl;
    return returnValue;
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

int house_robber_1(vector<int>& nums)
{
    // sanity checks
    unsigned int count = nums.size();
    if ( count == 0 )
    {
        return 0;
    }
    else if ( count == 1 )
    {
        return nums.at(0);
    }
    else if ( count == 2 )
    {
        return max(nums.at(0), nums.at(1));
    }

    // at this point, we have at least 3 points in the input vector

    int returnValue = max(nums.at(1), nums.at(0) + nums.at(2));

   // dynamic programming, bottom up
    vector<int> dp = {nums.at(0), nums.at(1), nums.at(0) + nums.at(2)};
    for (unsigned int i = 3; i < count; i++)
    {
        dp.push_back(nums.at(i) + max(dp.at(i - 2), dp.at(i - 3)));
        returnValue = max(returnValue, dp.back());
    }
 
    return returnValue;
}

int rob(TreeNode* root)
{
    // convert tree to vector
    vector<int> houses = bfs(root);

    // run house robber 1 algorithm
    return house_robber_1(houses);
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
