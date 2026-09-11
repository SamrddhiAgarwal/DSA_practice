class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        // find min element
        int mn=min_element(nums.begin(),nums.end())-nums.begin();
        int mx=nums[0];
        int n=nums.size();
        for(int i=0;i<=mn;i++)
        {
            mx=max(mx,nums[i]);
        }
        int l=n,nmx=mx;
        for(int i=mn+1;i<n;i++)
        {
            if(nums[i]>=mx)
            {l=min(l,i);
            nmx=nums[i];}
            if(nums[i]<mx)
            {
                mx=nmx;
                l=max(l,i+1);
            }
            
        }
        return l;
    }
};