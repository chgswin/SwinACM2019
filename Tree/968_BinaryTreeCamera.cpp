/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//
//Specifying three states is crucial
//State 0: all nodes below is covered, but root is not covered.
//State 1: all nodes below + the root is covered, but no camera in the root.
//State 2: all nodes below + the root is covered, and there is a camera in the root.
//
class Solution {
private: 
    const int MAX = 1e4;
public:
    int minCameraCover(TreeNode* root) {
        vector<int> dpTotal = DPCalc(root);
        return min(dpTotal[1], dpTotal[2]);
    }
    
    vector<int> DPCalc(TreeNode* curNode)
    {
        if (curNode == NULL)
        {
            return {0, 0, MAX};
        }
        
        vector<int> dpLeft= DPCalc(curNode->left);
        vector<int> dpRight = DPCalc(curNode->right);
        
        int d0 = dpLeft[1] + dpRight[1];
        int minLeft12 = min(dpLeft[1], dpLeft[2]);
        int minRight12 = min(dpRight[1], dpRight[2]);
        
        int d1 = min(minLeft12 + dpRight[2], minRight12 + dpLeft[2]);
        
        int d2 = min(minLeft12, dpLeft[0]) + min(minRight12, dpRight[0]) + 1;
        return {d0, d1, d2};
    }
};
