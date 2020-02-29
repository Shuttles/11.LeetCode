/*************************************************************************
	> File Name: LeetCode235.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/29 11:09:06 2020
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    //if (!root) return NULL;
    //if (p->left == q || p->right == q) return p;
    //if (q->left == p || q->right == p) return q;
    if (root == p) return p;
    if (root == q) return q;
    if ((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val)) return root;
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return NULL;
}
