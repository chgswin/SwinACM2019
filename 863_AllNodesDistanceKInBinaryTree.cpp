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
    unordered_map<TreeNode*, TreeNode*> parent_map;
    unordered_set<TreeNode*> visited;
    unordered_map<TreeNode*, int> distance;
    
    void Find_Parent_DFS(TreeNode* node)
    {
        if (node)
        {
            if (node->left) parent_map[node->left] = node;
            if (node->right) parent_map[node->right] = node;
            Find_Parent_DFS(node->left);
            Find_Parent_DFS(node->right);
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        vector<int> res;
        Find_Parent_DFS(root);
        
        queue<TreeNode*> q;
        q.push(target);
        distance[target] = 0;
        
        while (q.empty() == false)
        {
            TreeNode* curNode = q.front();
            q.pop();
            if (curNode)
            {
                visited.insert(curNode);
                if (distance[curNode] == K) res.push_back(curNode->val);
                else if (distance[curNode] > K) break;
                if (curNode->left && !visited.count(curNode->left))
                {
                    distance[curNode->left] = distance[curNode] + 1;
                    q.push(curNode->left);
                }
                if (curNode->right && !visited.count(curNode->right))
                {
                    distance[curNode->right] = distance[curNode] + 1;
                    q.push(curNode->right);
                }
                if (parent_map[curNode] && !visited.count(parent_map[curNode]))
                {
                    distance[parent_map[curNode]] = distance[curNode] + 1;
                    q.push(parent_map[curNode]);
                }
            }
        }
        return res;
    }
};
