class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int up=prev[j];
                int left=prev[j-1];
                prev[j]=up+left;
            }
        }
        return prev[n-1];
    }
};