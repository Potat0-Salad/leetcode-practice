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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<vector<TreeNode*>> next;

        if (root == nullptr) return {};

        vector<TreeNode*> start;
        start.push_back(root);
        next.push(start);

        while(!next.empty()){
            vector<TreeNode*> currentVec = next.front();
            next.pop();
            vector<int> toPrint;

            vector<TreeNode*> nextNodes;
            for(int i = 0; i < currentVec.size(); i++){
                toPrint.push_back(currentVec[i]->val);
                if(currentVec[i]->left != nullptr){
                    nextNodes.push_back(currentVec[i]->left);
                }
                if(currentVec[i]->right != nullptr){
                    nextNodes.push_back(currentVec[i]->right);
                }
            }
            if (!nextNodes.empty()) next.push(nextNodes);
            result.push_back(toPrint);
        }
        return result;
    }
};