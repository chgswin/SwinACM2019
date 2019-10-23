/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void appendString(string & dest, string add)
    {
        for (char c: add) dest.push_back(c);
    }
    string serialize(TreeNode* root) {
        string result = "[";
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode * curNode = q.front();
            q.pop();
            if (curNode != NULL)
            {
                appendString(result, to_string(curNode->val) + ",");
                q.push(curNode->left);
                q.push(curNode->right);
            }
            else
            {
                appendString(result, "null,");    
            }
        }
        result.pop_back();
        result.push_back(']');
        return result;
    }
    
    vector<string> split(string data, char c)
    {
        int l = 0, r = l;
        vector<string> result;
        
        while (l < data.size())
        {
            string value = "";
            r = l;
            while (r < data.size() && data[r] != c) 
            {
                value.push_back(data[r++]);
            }
            l = ++r;
            result.push_back(value);
        
        }
        
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        data = data.substr(1, data.size() - 2);
        
        vector<string> string_value = split(data, ',');
        int i;
        int n = string_value.size();
        vector<TreeNode*> node_array(n, NULL);
        for (i = 0; i < n; ++i)
        {
            if (string_value[i] != "null") node_array[i] = new TreeNode(stoi(string_value[i]));
        }
        int left = 0;
        int right = 1;
        while (left < n)
        {
            while (left < n && node_array[left] == NULL) ++left;
            if (right < n) node_array[left]->left = node_array[right++];
            if (right < n) node_array[left]->right = node_array[right++];
            ++left;
        }

        if (n) return node_array[0];
        else return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
