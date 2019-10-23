/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    int ans = 0; 
    const int MAX = 1e4;
    set<TreeNode*> covered;
public:
    int minCameraCover(TreeNode* root) 
    {
        covered.insert(NULL);
        GreedyDFS(root, NULL);
        return ans;
    }
    
    void GreedyDFS(TreeNode * curNode, TreeNode * parent)
    {
        if (curNode != NULL)
        {
            GreedyDFS(curNode->left, curNode);
            GreedyDFS(curNode->right, curNode);
            
            if (!covered.count(curNode->right) || !covered.count(curNode->left) || (parent == NULL && !covered.count(curNode)))
            {
                ans++;
                covered.insert(curNode);
                covered.insert(parent);
                covered.insert(curNode->right);
                covered.insert(curNode->left);
            }
        }
    }
};
