class Solution {
public:
    int total(vector<int>& nums, int k)
    {
        if(k==0) return 0;
        int r=0,l=0,n=nums.size(),cnt=0,d=0;
        // unordered_map<int,int> mp;
        vector<int> mp(n+1,0);
        while(r<n)
        {
            if(mp[nums[r]]==0) d++;
            mp[nums[r]]++;

            while(d>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) d--;
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return total(nums,k)-total(nums,k-1);
    }
};