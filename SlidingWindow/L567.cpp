
class Solution
{
    
public:
    bool checkSameMap(map<char, int> & charMap1, map<char, int> & charMap2)
    {
        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (charMap1[c] != charMap2[c]) return false;
        }
        return true;
    }
public:
    
	bool checkInclusion(string s1, string s2)
	{
		int n1 = s1.size();
		map<char, int> charMapS1;
		map<char, int> charMapSliding;

		int i;

		for (i = 0; i < s1.size(); ++i)
		{
			++charMapS1[s1[i]];
		}

		for (i = 0; i < min(s1.size(), s2.size()); ++i)
		{
			charMapSliding[s2[i]]++;
		}
    
        if (checkSameMap(charMapSliding, charMapS1)) return true;
        
        i = n1;
        
		while (i < s2.size())
		{
			charMapSliding[s2[i - n1]]--;
			charMapSliding[s2[i]]++;
            if (checkSameMap(charMapSliding, charMapS1)) return true;
			++i;
		}
		return false;

	}
};
