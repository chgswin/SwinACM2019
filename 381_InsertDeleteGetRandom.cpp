class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int> > savedPosition;
    vector<int> array;
    int real_size;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() 
    {
        real_size = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
        bool result = (savedPosition[val].size() == 0);
        
        array.push_back(val);
        savedPosition[val].insert(real_size);
        real_size++;
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) 
    {
        if (savedPosition[val].size() == 0) //no longer containing that element
        {
            return false;
        }
        else //contain the element
        {
            if (array.size() == 1)
            {
                savedPosition[--real_size].erase(0);
                array.pop_back();
            }
            else
            {
                int replaceIndex = *savedPosition[val].begin();
                int replaceValue = array[replaceIndex];
                
                int lastIndex = --real_size;
                int lastValue = array.back();
                
                array[replaceIndex] = array[lastIndex];
                
                savedPosition[val].erase(replaceIndex);
                savedPosition[lastValue].erase(lastIndex);
                savedPosition[lastValue].insert(replaceIndex);
                array.pop_back();
            }
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // for (int i : array)
        // {
        //     cout << i << " ";
        // }
        cout << endl;
        int randIndex = ((double) rand() / (RAND_MAX)) * real_size;
        return array[randIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
