/*************************************************************************
	> File Name: LeetCode111.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/28 22:55:56 2020
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MIN(a, b) ({\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a < _b ? _a : _b;\
})

int minDepth(struct TreeNode* root){
    if (!root) return 0;
    int ans = 1;
    int min_depth_l = minDepth(root->left), min_depth_r = minDepth(root->right);
    if (!min_depth_l) return (ans + min_depth_r);
    else if (!min_depth_r) return (ans + min_depth_l);
    ans += MIN(min_depth_l, min_depth_r);
    return ans;
}
