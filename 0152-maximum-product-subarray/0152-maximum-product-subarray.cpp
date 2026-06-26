class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //     int pro=1,pre=1;
    //     int mx=INT_MIN;
    //    // int n=nums
    //     for(auto n:nums)
    //     {
    //         pro=pro*n;
    //         if(pro<0)
    //         {
    //             if(pre<0)
    //             pro=pro*pre;
    //             pre=pro;
    //         }  
    //         else if(pro==0)
    //         {
    //             pre=1;
    //         } 

    //         mx=max(mx,pro);
    //         if(pro<=0) pro=1;
    //     }
    //     pro=1;
    //     pre=1;
    //     for(int i=nums.size()-1;i>=0;i--)
    //     {
    //         pro=pro*nums[i];
    //         if(pro<0)
    //         {
    //             if(pre<0)
    //             pro=pro*pre;
    //             pre=pro;
    //         }  
    //         else if(pro==0)
    //         {
    //             pre=1;
    //         } 

    //         mx=max(mx,pro);
    //         if(pro<=0) pro=1;
    //     }
    //     return mx;
    // }

    int maxProduct(vector<int>& nums) {
        int prefix=1,suffix=1,n=nums.size(), mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix*=nums[i];
            suffix*=nums[n-1-i];
            mx=max(mx,max(prefix,suffix));
        }
        return mx;
    }

};