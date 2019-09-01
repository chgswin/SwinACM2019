class Solution {
private:
    unordered_map<int, int> judges;
    unordered_set<int> ignoreNodes;
    
    bool Compare (pair<int, int> p1, pair<int,int> p2) {
        return p1.second < p2.second;
    }
    
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int res = -1;
        int max = -1;
        
        if (N != 0 && trust.size() < 1) {
            return 1;
        }
    
        for (auto& v : trust) {
            ignoreNodes.insert(v[0]);
            if (judges.count(v[0]) == 0) {
                if (ignoreNodes.count(v[1]) == 0) {
                    judges[v[1]]++;
                }
            } else {
                judges.erase(v[0]);
            }
        }
        
        for (auto& it: judges) {
            if (it.second > max) {
                res = it.first;
                max = it .second;
            } else if (it.second == max) {
                return -1;
            }
        }
        
        return res;
    }
};
