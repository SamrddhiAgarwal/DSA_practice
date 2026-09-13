import java.util.*;
class Solution {
    public int smallestRangeII(int[] nums, int k) {
        Arrays.sort(nums);
        int n=nums.length;
        int ans=nums[n-1]-nums[0];
        int high,low;
        for(int i=0;i<n-1;i++)
        {
            high=Math.max(nums[i]+k,nums[n-1]-k);
            low=Math.min(nums[0]+k,nums[i+1]-k);
            ans=Math.min(ans,high-low);
        }
        return ans;
    }
}
