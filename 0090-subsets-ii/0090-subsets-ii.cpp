class Solution {
public:
    void helper(int j,vector<int>& temp, vector<vector<int>>&result, vector<int>&nums)
    {
        int n=nums.size();
        
        result.push_back(temp);
        
        for(int i=j;i<n;i++)
        {
            if(i>j && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(i+1,temp,result,nums);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>result;
        helper(0,temp,result,nums);
        return result;
    }
};