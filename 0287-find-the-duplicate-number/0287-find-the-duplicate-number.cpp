class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //sorting
        //hashing 
        //with modyifying
                // for(auto &n:nums)
                // {
                //     int x=abs(n); //if we go by x=abs(x) we are colllecting refrences
                //     if(nums[x-1]<0)
                //     return x;
                //     nums[x-1]=-nums[x-1];
                // }
                // return -1;

        // need implemetation hare and tortoise
        // int slow=nums[0],fast=nums[nums[0]];
        // while(slow!=fast)
        // {
        //     slow=nums[slow];
        //     fast=nums[nums[fast]];
        // }
        int slow=0,fast=0;
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        // fast=0;
        int slow2=0;
        while(slow!=slow2)
        {
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow;
    }
};