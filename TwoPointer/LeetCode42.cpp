class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> decreasingHeight;
  		
  		int result = 0;

  		int i;

  		int floor = 0;

  		for (i = 0; i < height.size(); ++i)
  		{
  			int curHeight = height[i];
  			while (!decreasingHeight.empty() && curHeight >= height[decreasingHeight.top() ] )
  			{
  				int width = i - decreasingHeight.top() - 1;
  				result += width * (height[decreasingHeight.top() ] - floor);

  				floor = height[decreasingHeight.top() ]; 

  				decreasingHeight.pop();
  			}

  			if (!decreasingHeight.empty())
  			{
  				result+= (i - decreasingHeight.top() - 1) * (height[i] - floor);
  				floor = height[i]; 
  			}	
			decreasingHeight.push(i); 
  		}

  		return result;
    }
};
