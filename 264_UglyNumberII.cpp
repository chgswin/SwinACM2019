class Solution {
public:
    void insertX (int temp, int a, vector<int> & res_vec, unordered_set<int> & res_set, vector <int> & temp_vec)
    {
        long long x = (long long)temp * (long long)a;
        if (x < 1e9)
        {
            if (!res_set.count(x))
            {
                res_set.insert(x);
                res_vec.push_back(x);
                temp_vec.push_back(x);
                //sort(temp_vec.rbegin(), temp_vec.rend());
            }
        }
    }
    
    int nthUglyNumber(int n) {
        vector<int> res_vec;
        //vector<int> temp_vec;
        set<int> temp_set;
        unordered_set<int> res_set;
        res_vec.push_back(1);
        temp_vec.push_back(1);
        res_set.insert(1);
        while (!temp_vec.empty())
        {
            if (n < 100)
            {
                if (res_set.size() > n + 50)
                    break;
            }
            
            else if (n >= 100 && n < 700)
            {
                if (res_set.size() > n + 120)
                    break;
            }
            else if (n >= 700 && n < 1400)
            {
                if (res_set.size() > n + 160)
                    break;
            }
            else
            {
                if (res_set.size() > n + 170)
                    break;
            }
            sort(temp_vec.rbegin(), temp_vec.rend());
            int temp = temp_vec.back();
            temp_vec.pop_back();
            insertX(temp, 2, res_vec, res_set, temp_vec);
            insertX(temp, 3, res_vec, res_set, temp_vec);
            insertX(temp, 5, res_vec, res_set, temp_vec);
        }
        sort(res_vec.begin(), res_vec.end());
        
        return res_vec[n-1];
    }
};
