/*************************************************************************
	> File Name: 104.czy.false.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/28 17:31:18 2020
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
    if (!root) return 0;
    else return 1;
    return (maxDepth(root->left) + maxDepth(root->right));
}
