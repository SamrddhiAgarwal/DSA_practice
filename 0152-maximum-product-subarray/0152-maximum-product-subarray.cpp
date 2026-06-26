class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro=1,pre=1;
        int mx=INT_MIN;
       // int n=nums
        for(auto n:nums)
        {
            pro=pro*n;
            if(pro<0)
            {
                if(pre<0)
                pro=pro*pre;
                pre=pro;
            }  
            else if(pro==0)
            {
                pre=1;
            } 

            mx=max(mx,pro);
            if(pro<=0) pro=1;
        }
        pro=1;
        pre=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            pro=pro*nums[i];
            if(pro<0)
            {
                if(pre<0)
                pro=pro*pre;
                pre=pro;
            }  
            else if(pro==0)
            {
                pre=1;
            } 

            mx=max(mx,pro);
            if(pro<=0) pro=1;
        }
        return mx;
    }
};