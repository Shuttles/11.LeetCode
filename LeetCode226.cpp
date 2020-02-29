/*************************************************************************
	> File Name: LeetCode226.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/29 11:26:48 2020
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if (!root) return NULL;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}
