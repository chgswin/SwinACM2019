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
    void visit(TreeNode* node)
    {
        if (node!=NULL)
        {
            result.push_back(node->val);
        }
    }
    
    vector<int> result;
public:
    //
    //recursive version
    //
    // vector<int> postorderTraversal(TreeNode* root) 
    // {
    //     if (root)
    //     {
    //         postorderTraversal(root->left);
    //         postorderTraversal(root->right);
    //         visit(root);
    //     }
    //     return result;
    // }
    //
    //iterative version
    //
    vector<int> postorderTraversal(TreeNode * root)
    {
        stack<TreeNode*> nodeStack;
        stack<int> valueStack;
        if (!root) return result;

        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            TreeNode* curNode = nodeStack.top(); nodeStack.pop();

            if (curNode->left) nodeStack.push(curNode->left);
            
            if (curNode->right) nodeStack.push(curNode->right);
            
            valueStack.push(curNode->val);
        }
        while (valueStack.empty() == 0)
        {
            result.push_back(valueStack.top());valueStack.pop();
        }
        return result;
    }
};
