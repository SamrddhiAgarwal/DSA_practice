class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows>0)
        ans.push_back({1});
        if(numRows>1)
        ans.push_back({1,1});
        int k=2;
        while(numRows>k)
        {
            vector<int> temp;
            temp.push_back(1);
            vector<int> last=ans.back();
            int n=last.size();
            for(int i=0;i<n-1;i++)
            {
                temp.push_back(last[i]+last[i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            k++;
        }
        return ans;
    }
};