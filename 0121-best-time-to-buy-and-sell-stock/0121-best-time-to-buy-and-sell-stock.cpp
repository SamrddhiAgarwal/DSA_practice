class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int mp=0;
        int mp=prices[0];
        int mx=0;int n=prices.size();
        for(int i=1;i<n;i++)
        {
            // mx=max(mx,prices[i]-prices[mp]);
            mx=max(mx,prices[i]-mp);
            // if(prices[i]<prices[mp])
            // mp=i;
            mp=min(mp,prices[i]);
        }
        return mx;
    }
};