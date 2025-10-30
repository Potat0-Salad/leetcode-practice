/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool check(TreeNode* root, long high, long low){

        if (root->val <= low || root->val >= high){
            return false;
        }

        // if(root->left && root->left->val >= root->val){
        //     return false;
        // }
        // if(root->right && root->right->val <= root->val){
        //     return false;
        // }

        bool leftCorrect;
        bool rightCorrect;
        if(root->left){
            leftCorrect = check(root->left, root->val, low);
        }
        else{
            leftCorrect = true;
        }
        if(root->right){
            rightCorrect = check(root->right, high, root->val);
        }
        else{
            rightCorrect = true;
        }
        return (leftCorrect && rightCorrect);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MAX, LONG_MIN);
    }
        
};