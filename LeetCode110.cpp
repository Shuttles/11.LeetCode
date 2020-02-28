/*************************************************************************
	> File Name: LeetCode110.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/28 22:40:41 2020
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 #define MAX(a, b) ({\
     __typeof(a) _a = (a);\
     __typeof(b) _b = (b);\
    _a > _b ? _a : _b;\
 })

int get_height(struct TreeNode *root) {
    if (!root) return 0;
    int ans = 1;
    ans += MAX(get_height(root->left), get_height(root->right));
    return ans;
}

bool isBalanced(struct TreeNode* root){
    if (!root) return true;
    if (!isBalanced(root->left)) return false;
    if (!isBalanced(root->right)) return false;
    int height_l = get_height(root->left), height_r = get_height(root->right);
    if (abs(height_l - height_r) <= 1) return true;
    else return false;
}
