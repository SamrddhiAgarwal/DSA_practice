class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,jump=0,n=nums.size();
        
        while(r<n-1)
        {
            int last=0;
            for(int i=l;i<=r;i++)
            {
                last=max(last,i+nums[i]);
            }            
            jump++;
            l=r+1;
            r=last;
        }
        return jump;
        
    }
};