class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0,mx=0;int n=prices.size();
        for(int i=1;i<n;i++)
        {
            mx=max(mx,prices[i]-prices[mp]);
            if(prices[i]<prices[mp])
            mp=i;
        }
        return mx;
    }
};