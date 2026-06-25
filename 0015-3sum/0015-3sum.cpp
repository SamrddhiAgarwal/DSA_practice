class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        set<vector<int>> st;
        vector<int> temp;
        int k=0;
       for(int i=0;i<nums.size();i++)
        {
            int target=k-nums[i];
            for(int j=0;j<i;j++)
            {
                int min=target-nums[j];
                if(mp.find(min)!=mp.end() && mp[min]!=j)
                {
                    temp={nums[i],nums[j],min};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
            
           mp[nums[i]]=i;

        }
        vector<vector<int>> ans(st.begin(),st.end());

        return ans;
      
    }
};