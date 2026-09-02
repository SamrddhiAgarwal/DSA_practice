class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int last=0;
        sort(coins.begin(),coins.end());
        for(int i=0;i<coins.size();i++)
        {
            if(last+1<coins[i])
            {
                break;
            }
            
            last=last+coins[i];
            
            // ans=max(ans,last+1);
        }
        return last+1;
    }
};