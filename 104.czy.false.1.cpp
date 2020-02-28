/*************************************************************************
	> File Name: 104.czy.false.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/28 17:25:41 2020
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    int ans = 0;
    if (!root) return 0;
    else return 1;
    //int ans = 0;
    ans += (maxDepth(root->left) + maxDepth(root->right));
    return ans;
}
