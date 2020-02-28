/*************************************************************************
	> File Name: 104.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/28 17:47:17 2020
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

int maxDepth(struct TreeNode* root){
    if (!root) return 0;
    int ans = 1;
    ans += MAX(maxDepth(root->left), maxDepth(root->right));
    return ans;
}
