class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int c=0 , mxc=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                c++;
                
            }
            else
            {
                mxc=max(mxc,c);
                c=0;
            }
            
        }
        mxc=max(mxc,c);
        return mxc;
        
    }
};