class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0,mx=0;
        for(int i=1;i<prices.size();i++)
        {
            mx=max(mx,prices[i]-prices[mp]);
            if(prices[i]<prices[mp])
            mp=i;
        }
        return mx;
    }
};