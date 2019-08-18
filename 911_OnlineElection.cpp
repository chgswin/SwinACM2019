class TopVotedCandidate {
private: 
    vector<int> fTimes;
    vector<int> memory;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        fTimes = times;
        memory.resize(times.size());
        int i;
        vector<int> permem(persons.size() + 1, 0);
        int lead = 0;
        int wholead = -1;
        for (i = 0; i < memory.size(); ++i)
        {
            ++permem[persons[i]];
            if (permem[persons[i]]>=lead) 
            {
             wholead = persons[i];   
            }
            memory[i] = wholead;
            lead = permem[wholead];        
        }
    }
    
    int q(int t) {
        //if (t > fTimes.back()) return memory.back();
        return memory[lastless(t)];
    }
    
    int lastless(int key)
    {
        return upper_bound(fTimes.begin(), fTimes.end(), key) - fTimes.begin() - 1;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
