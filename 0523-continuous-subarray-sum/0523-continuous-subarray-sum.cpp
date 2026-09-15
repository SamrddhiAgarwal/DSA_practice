class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // unordered_map<int,int>prefix;
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int target=sum%k;
            if(mp.find(target)!=mp.end() && i-mp[target]>1 ) return true;
            else if(mp.find(target)==mp.end())
            mp[target]=i;
        }
        return false;
    }
};