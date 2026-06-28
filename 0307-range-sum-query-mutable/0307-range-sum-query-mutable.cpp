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
    
    void update(int index, int val) {
        int n=mp.size();
        int prev;
        if(index==0) prev=mp[0];
        else prev=mp[index]-mp[index-1];
        
        for(int i=index;i<n;i++)
        {
            mp[i]=mp[i]+val-prev;
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
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */