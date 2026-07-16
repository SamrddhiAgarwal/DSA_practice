class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n2;i++)
        {
            mp[nums2[i]].push_back({i});
        }
        int mx=0;
        for(int i=0;i<n1;i++)
        {
            if(mp.find(nums1[i])!=mp.end())
            {
                for(int j=0;j<mp[nums1[i]].size();j++)
                {
                    int l1=mp[nums1[i]][j], l2=i; 
                    if(!(l1+mx<n2 && l2+mx <n1 && nums2[l1+mx]==nums1[l2+mx])) continue;
                    while(l1<n2 && l2<n1 && nums2[l1]==nums1[l2])
                    {
                        l1++;
                        l2++;
                    }
                    
                    mx=max(mx,l2-i);

                }
            }
        }
        return mx;
    }
};