class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //sorting
        //hashing 
        //with modyifying
        for(auto &n:nums)
        {
            int x=abs(n); //if we go by x=abs(x) we are colllecting refrences
            if(nums[x-1]<0)
            return x;
            nums[x-1]=-nums[x-1];
        }
        return -1;
    }
};