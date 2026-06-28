class NumArray {
public:
    unordered_map<int,int>mp;
    NumArray(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            mp[i]=s;
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