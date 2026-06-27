class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=INT_MIN;
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            mx=max(mx,s);
            if(s<0) s=0;
        }
        s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            mx=max(mx,abs(s));
            if(s>0)
            s=0;
        }
        return mx;
    }
};