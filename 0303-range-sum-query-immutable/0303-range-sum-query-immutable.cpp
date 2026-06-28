class NumArray {
public:
    vector<int>mp;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        mp.resize(n,0);
        mp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            
            mp[i]=mp[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return mp[right];
        return mp[right]-mp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */