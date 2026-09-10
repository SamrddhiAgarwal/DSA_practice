class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,zeros=0,len=0,n=nums.size();
        for(int r=0;r<n;r++)
        {
           if( nums[r] ==0)
           zeros++;
        //    while(zeros>k)
        //    {
        //         if(nums[l]==0)
        //         zeros--;
        //         l++;
        //    }
            if(zeros>k)
           {
                if(nums[l]==0)
                zeros--;
                l++;
           }// an optimisationn
            
           if(zeros<=k)len=max(len,r-l+1);
        }
        return len;
    }
};
//in tjese type of questions try to find a window and cost of that window like the thing we are trying to eliminate use that only