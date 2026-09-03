class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPos=-1,maxPos=-1,badPos=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==minK)
            minPos=i;

            if(nums[i]==maxK)
            maxPos=i;

            if(nums[i]<minK || nums[i]>maxK)
            badPos=i;

            long long temp=min(minPos,maxPos)-badPos;
            ans+=temp>0?temp:0;
        }
        return ans;
    }
};