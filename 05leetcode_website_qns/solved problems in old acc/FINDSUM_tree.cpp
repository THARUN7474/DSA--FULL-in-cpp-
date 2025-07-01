#include <bits/stdc++.h>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    bool solve(TreeNode *&root, int &targetsum, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetsum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool rv = solve(root->right, targetsum, sum);
        bool lv = solve(root->left, targetsum, sum);

        return lv || rv;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};