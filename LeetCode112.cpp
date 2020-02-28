/*************************************************************************
	> File Name: LeetCode112.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/28 23:26:39 2020
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if (!root) return false;
    int ans = root->val;
    sum -= ans;
    if (!root->left && !root->right) return (sum == 0);
    if (hasPathSum(root->left, sum)) return true;
    if (hasPathSum(root->right, sum)) return true;
    return false;
}
