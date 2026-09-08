class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int curr=0;
        for(auto& n:target )
        {
            if(n>curr)
            {
                ans+=n-curr;
                // curr=n;
            }
            // else if(n<curr)
            // {
            //     curr=n;
            // }
            curr=n;
        }
        return ans;
    }
};